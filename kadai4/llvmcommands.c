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
    printf("接続されたよ\n");
  }
}

void generate_decl(char *fname){
  Fundecl *decl = (Fundecl *)malloc(sizeof(Fundecl));
  strcpy(decl->fname,fname);
  codehd = NULL;
  codetl = NULL;
  decl->next = NULL;
  decl->codes = NULL;

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
  case Add:
    arg2 = factorpop();
    arg1 = factorpop();
    retval.type = LOCAL_VAR;
    retval.val = cntr;
    cntr ++;
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
    cntr ++;                   /* カウンタをインクリメント */
    (tmp->args).sub.arg1 = arg1; /* 命令の第1引数を指定 */
    (tmp->args).sub.arg2 = arg2; /* 命令の第2引数を指定 */
    (tmp->args).sub.retval = retval; /* 結果のレジスタを指定 */
    add_code(tmp); /* これまでのコードに今のコードを追加する関数を呼び出し */
    factorpush( retval ); /* 加算の結果をスタックにプッシュ */
		
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
  case BrUncond:
    printf("br label %d\n",(code->args).bruncond.arg1);
    break;
  case BrCond:
    printf("br i1 ");
    displayFactor((code->args).brcond.arg1);
    printf(", label %d, label %d\n",(code->args).brcond.arg2,(code->args).brcond.arg3);
    break;

  case Ret:
    printf("ret i32 ");
    displayFactor((code->args).ret.arg1);
    printf("\n");
    break;
    
  case Label:
    printf("; <label>:%d:\n",(code->args).label.l);
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
    printf(" = + nsw i32 ");
    displayFactor((code->args).sub.arg1);
    printf(", ");
    displayFactor((code->args).sub.arg2);
    printf("\n");
    break;
    
  case Div:
    displayFactor((code->args).div.retval);
    printf(" = + nsw i32 ");
    displayFactor((code->args).div.arg1);
    printf(", ");
    displayFactor((code->args).div.arg2);
    printf("\n");
    break;
    
  case Mult:
    displayFactor((code->args).mult.retval);
    printf(" = + nsw i32 ");
    displayFactor((code->args).mult.arg1);
    printf(", ");
    displayFactor((code->args).mult.arg2);
    printf("\n");
    break;
    
  default:
    break;
  }
  displayLlvmcodes(code->next);
}

void displayLlvmfundecl(Fundecl *decl){
  if(decl == NULL) return;
  printf("define i32 @%s() {\n",decl->fname);
  displayLlvmcodes(decl->codes);
  printf("}\n");
  if(decl->next != NULL){
    printf("\n");
    printf("\n");
    displayLlvmfundecl(decl->next);
  }
  return;
}
