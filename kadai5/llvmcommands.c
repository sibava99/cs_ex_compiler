#include <stdio.h>
#include <stdlib.h>
#include "llvmcommands.h"
#include "symtab.h"
#include <string.h>

LLVMcode *codehd = NULL; /* 命令列の先頭のアドレスを保持するポインタ */
LLVMcode *codetl = NULL; /* 命令列の末尾のアドレスを保持するポインタ */
Fundecl *declhd = NULL; /* 関数定義の線形リストの先頭の要素のアドレスを保持するポインタ */
Fundecl *decltl = NULL; /* 関数定義の線形リストの末尾の要素のアドレスを保持するポインタ */
Factorstack fstack; /* 整数もしくはレジスタ番号を保持するスタック */
Brstack brstack; /*Br命令を保持するスタック*/
Labelstack lstack; /*labelを保持するスタック*/

int cntr = 1; /* レジスタ番号を保持する変数 */

void init_fstack(){ /* fstackの初期化 */
  fstack.top = 0;
  return;
}
void displayfstack() {
    int i;
    for (i = 1; i <= fstack.top; i++) {
        displayFactor(fstack.element[i]);
    }
    printf("\nend\n");
    return;
}
Factor factorpop() {
  Factor tmp;
  tmp = fstack.element[fstack.top];
  fstack.top --;
  displayfstack();
  return tmp;
}

void factorpush(Factor x) {
  fstack.top ++;
  fstack.element[fstack.top] = x;
  displayfstack();
  return;
}

void factorgenerate(char *name)	{	
		struct symboltable *st = lookup(name);
		if( st == NULL){
			printf("未定義の変数です\n");
			exit(1);
		}	
		Factor tmp;
		strcpy(tmp.vname,name);
		tmp.type = st->type;
		tmp.val = st->num;
		factorpush(tmp);
}   

void init_brstack(){
  brstack.top = 0;
  return;
}
void brpush(LLVMcode* tmp){
  brstack.top ++;
  brstack.element[brstack.top] = tmp;
}

LLVMcode *brpop(){
  LLVMcode *tmp;
  tmp = brstack.element[brstack.top];
  brstack.top--;
  return tmp;
}

void init_lstack(){
  lstack.top = 0;
  return;
}
void labelpush(int label){
  lstack.top ++;
  lstack.element[lstack.top] = label;
}

int labelpop(){
  int label;
  label = lstack.element[lstack.top];
  lstack.top --;
  return label;
}

void generate_icmp(Cmptype type){
  LLVMcode *tmp;
  Factor arg1,arg2,retval;
  tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
  tmp->next = NULL;
  tmp->command = Icmp;
  arg1 = factorpop();
  arg2 = factorpop();
  retval.type = LOCAL_VAR;
  retval.val = cntr;
  cntr++;
  (tmp->args).icmp.arg1 = arg1;
  (tmp->args).icmp.arg2 = arg2;
  (tmp->args).icmp.retval = retval;
  (tmp->args).icmp.type= type;
  factorpush(retval);
  add_code(tmp);
  return;
}   

void generate_call(Factor f,rtype type,Factor args[5]){
  LLVMcode *tmp;
  Factor retval;
  int i;
  tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
  tmp->command = Call;
  tmp->next = NULL;
  (tmp->args).call.f = f;
  (tmp->args).call.type = type;
  for(i = 0;i < f.val;i++){
    (tmp->args).call.args[i] = args[i];
  }
  if(type != VOID){
    retval.type = LOCAL_VAR;
    retval.val = cntr;
    cntr++;
  }
  (tmp->args).call.retval = retval;
  add_code(tmp);
}
void add_code(LLVMcode* tmp){
  if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
    if( decltl == NULL ){   /* 解析中の関数がない場合 */
      /* 関数宣言を処理する段階でリストが作られているので，ありえない */
      fprintf(stderr,"unexpected error!!!\n");
    }
    decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
    codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
  } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
    codetl->next = tmp; /* 命令列の末尾に追加 */
    codetl = tmp;       /* 命令列の末尾の命令として記憶 */
  }
}

void generate_decl(char *fname,rtype type){
  Fundecl *decl = (Fundecl *)malloc(sizeof(Fundecl));
  strcpy(decl->fname,fname);
  codehd = NULL;
  codetl = NULL;
  decl->next = NULL;
  decl->codes = NULL;
  decl->type = type;
  if(declhd == NULL){
    declhd = decl;/* 初回のみ */
    decltl = decl;
  }
  else{
    decltl->next = decl;
    decltl = decl;
  }
  cntr = 1;
  return;
}

void generate_code(LLVMcommand command){
  LLVMcode *tmp;
  Factor arg1,arg2,arg3,retval;
  int iarg1,iarg2,iarg3;
  tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
  tmp->next = NULL;
  tmp->command = command;
  switch(command){
  case Alloca:
    retval.type = LOCAL_VAR;
    retval.val = cntr;
    cntr++;
    (tmp->args).alloca.retval = retval;
    add_code(tmp);
    break;
  case Store:
    arg2 = factorpop();
    arg1 = factorpop(); 
    (tmp->args).store.arg2 = arg2;
    (tmp->args).store.arg1 = arg1;
    add_code(tmp);
    break;
  case Load:
    arg1 = factorpop();
    retval.type = LOCAL_VAR;
    retval.val = cntr;
    cntr++;
    (tmp->args).load.arg1 = arg1;
    (tmp->args).load.retval = retval;
    factorpush(retval);
    add_code(tmp);
    break;
  case BrUncond:
    (tmp->args).bruncond.arg1 = cntr;
    brpush(tmp);
    add_code(tmp);
    break;
  case BrCond:
    arg1 = factorpop();
    iarg2 = cntr;
    (tmp->args).brcond.arg1 = arg1;
    (tmp->args).brcond.arg2 = iarg2;
    brpush(tmp);
    add_code(tmp);
    break;
  case Label:
    iarg1 = cntr;
    cntr++;
    (tmp->args).label.l = iarg1;
    add_code(tmp);
    labelpush(iarg1);
    break;
  case Add:
    arg2 = factorpop();
    arg1 = factorpop();
    retval.type = LOCAL_VAR;
    retval.val = cntr;
    cntr++;
    (tmp->args).add.arg1 = arg1;
    (tmp->args).add.arg2 = arg2;
    (tmp->args).add.retval = retval;
    add_code(tmp);
    factorpush(retval);
    break;
  case Sub:
    arg2 = factorpop();        /* スタックから第2引数をポップ */
    arg1 = factorpop();        /* スタックから第1引数をポップ */
    retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
    retval.val = cntr;         /* 新規のレジスタ番号を取得 */
    cntr++;                   /* カウンタをインクリメント */
    (tmp->args).sub.arg1 = arg1; /* 命令の第1引数を指定 */
    (tmp->args).sub.arg2 = arg2; /* 命令の第2引数を指定 */
    (tmp->args).sub.retval = retval; /* 結果のレジスタを指定 */
    add_code(tmp); /* これまでのコードに今のコードを追加する関数を呼び出し */
    factorpush(retval); /* 加算の結果をスタックにプッシュ */
		break;
  case Div:
    arg2 = factorpop();        /* スタックから第2引数をポップ */
    arg1 = factorpop();        /* スタックから第1引数をポップ */
    retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
    retval.val = cntr;         /* 新規のレジスタ番号を取得 */
    cntr ++;                   /* カウンタをインクリメント */
    (tmp->args).div.arg1 = arg1; /* 命令の第1引数を指定 */
    (tmp->args).div.arg2 = arg2; /* 命令の第2引数を指定 */
    (tmp->args).div.retval = retval; /* 結果のレジスタを指定 */
    add_code(tmp); /* これまでのコードに今のコードを追加する関数を呼び出し */
    factorpush( retval ); /* 加算の結果をスタックにプッシュ */
    break;
  case Mult:
    arg2 = factorpop();        /* スタックから第2引数をポップ */
    arg1 = factorpop();        /* スタックから第1引数をポップ */
    retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
    retval.val = cntr;         /* 新規のレジスタ番号を取得 */
    cntr ++;                   /* カウンタをインクリメント */
    (tmp->args).mult.arg1 = arg1; /* 命令の第1引数を指定 */
    (tmp->args).mult.arg2 = arg2; /* 命令の第2引数を指定 */
    (tmp->args).mult.retval = retval; /* 結果のレジスタを指定 */
    add_code(tmp); /* これまでのコードに今のコードを追加する関数を呼び出し */
    factorpush( retval ); /* 加算の結果をスタックにプッシュ */
    break;
  case Ret:
    arg1 = factorpop();
    (tmp->args).ret.arg1 = arg1;
    add_code(tmp);
    break;
  default:  
    break;  
  }
}

void displayFactor(Factor factor){
  switch (factor.type)
  {
  case GLOBAL_VAR:
    printf("@%s",factor.vname);
    break;
  case LOCAL_VAR:
    printf("%%%d",factor.val);
    break;
  case CONSTANT:
    printf("%d",factor.val);
    break;
  case PROC_NAME:
    printf("@%s",factor.vname);
    break;
  default:
    break;
  }
  return;
}

void displayLlvmcodes(LLVMcode *code){
  if(code == NULL) return;
  printf("  ");
  switch (code->command)
  {
  case Alloca:
    displayFactor((code->args).alloca.retval);
    printf(" = alloca i32, align 4\n");
    break;

  case Store:
    printf("store i32 ");
    displayFactor((code->args).store.arg1);
    printf(", i32* ");
    displayFactor((code->args).store.arg2);
    printf(", align 4\n");
    break;
  case Load:
    displayFactor((code->args).load.retval);
    printf(" = load i32, i32* ");
    displayFactor((code->args).load.arg1);
    printf(", align4\n");
    break;
  case Label:
    printf("\n%d:\n",(code->args).label.l);
    break;
  case BrUncond:
    printf("br label %%%d\n",(code->args).bruncond.arg1);
    break;
  case BrCond:
    printf("br i1 ");
    displayFactor((code->args).brcond.arg1);
    printf(", label %%%d, label %%%d\n",(code->args).brcond.arg2,(code->args).brcond.arg3);
    break;
  case Call:
    if(strcmp((code->args).call.f.vname,"read") == 0){
      displayFactor((code->args).call.retval);
      printf(" = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i32* ");
      displayFactor((code->args).call.args[0]);
      printf(")\n");
      break;
    }
    if(strcmp((code->args).call.f.vname,"write") == 0){
      displayFactor((code->args).call.retval);
      printf(" = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i32 ");
      displayFactor((code->args).call.args[0]);
      printf(")\n");
      break;
    }
    printf("call ");
    switch((code->args).call.type){
      case I32:
        printf("i32 ");
        break;
      case VOID:
        printf("void ");
        break;
      default:
        break;
    }
    displayFactor((code->args).call.f);
    printf("(");
    int i;
    for(i = 0;i < (code->args).call.f.val; i++){
      printf("i32 ");
      displayFactor((code->args).call.args[i]);
    }
    printf(")");
    displayFactor((code->args).call.retval);
    printf("\n");
    break;
  case Add:
    displayFactor((code->args).add.retval);
    printf(" = add nsw i32 ");
    displayFactor((code->args).add.arg1);
    printf(", ");
    displayFactor((code->args).add.arg2);
    printf("\n");
    break;
    
  case Sub:
    displayFactor((code->args).sub.retval);
    printf(" = sub nsw i32 ");
    displayFactor((code->args).sub.arg1);
    printf(", ");
    displayFactor((code->args).sub.arg2);
    printf("\n");
    break;
    
  case Div:
    displayFactor((code->args).div.retval);
    printf(" = sdiv nsw i32 ");
    displayFactor((code->args).div.arg1);
    printf(", ");
    displayFactor((code->args).div.arg2);
    printf("\n");
    break;
    
  case Mult:
    displayFactor((code->args).mult.retval);
    printf(" = mul nsw i32 ");
    displayFactor((code->args).mult.arg1);
    printf(", ");
    displayFactor((code->args).mult.arg2);
    printf("\n");
    break;
  
  case Icmp:
    displayFactor((code->args).icmp.retval);
    printf(" = icmp ");
    switch((code->args).icmp.type){
      case EQUAL:
        printf("eq");
        break;
      case NE:
        printf("ne");
        break;
      case SGT:
        printf("sgt");
        break;
      case SGE:
        printf("sge");
        break;
      case SLT:
        printf("slt");
        break;
      case SLE:
        printf("sle");
        break;
      default:
        break;
    }   
    printf(" i32 ");
    displayFactor((code->args).icmp.arg1);
    printf(", ");
    displayFactor((code->args).icmp.arg2);
    printf("\n");
    break;

  case Ret:
    if((strcmp((code->args).ret.arg1.vname,"void") == 0) && (strlen((code->args).ret.arg1.vname) > 0)){
      printf("ret void\n");
      break;
    }
    printf("ret i32 ");
    displayFactor((code->args).ret.arg1);
    printf("\n");
    break;
  
  default:
    break;
  }
  displayLlvmcodes(code->next);
}

void displayLlvmfundecl(Fundecl *decl){
  if(decl == NULL) return;
  printf("define ");
  switch(decl->type){
    case VOID:
      printf("void ");
      break;
    case I32:
      printf("i32 ");
      break;
    default:
      break;
  }
  printf("@%s() {\n",decl->fname);
  displayLlvmcodes(decl->codes);
  printf("}\n");
  if(decl->next != NULL){
    printf("\n");
    printf("\n");
    displayLlvmfundecl(decl->next);
  }
  return;
}
