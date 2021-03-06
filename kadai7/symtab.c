#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "symtab.h"
/* 記号表の実体をここで作成 */
/* parser.yからは，以下のinsert/lookup/deleteなどを通してアクセスする */
extern int cntr;
extern int arity;
struct symboltable *head = NULL; 


/* insert, lookup, deleteの実装 */
void insert(char *name,Scope flag)
{
  struct symboltable *newnode; //新しいノード
  
  newnode = (struct symboltable *)malloc(sizeof(struct symboltable));
  if(newnode == NULL){
    printf("can not malloc!!\n");
    return;
  }

  newnode->name = (char *)malloc(strlen(name));
  
  strcpy((newnode->name),name);
  newnode -> type = flag;
  switch(flag){
  case LOCAL_VAR:
    newnode -> num = cntr;
    break;
  case PROC_NAME:
    newnode ->num = arity;
    break;
  default:
    newnode ->num = 0;
    break;
  }
  if(head == NULL)
    {
      head = newnode; //初回のみ
    }
  else
    {
      newnode->next = head; //新しいノードのnextを今までの先頭にする
      head = newnode; //先頭を新しいノードに変更
    }
  printf("insert:%s\n",name);
  print_all();
  return;
}

struct symboltable *lookup(char *name){
  struct symboltable *p,*r;
  r = NULL;
  p = head;
  
   while(p != NULL){
     if(strcmp(p->name,name) == 0){
       printf("look up:");
       print_row(p);
       r = p;
       return p; //新しい要素から順に確認し同じnameが見つかればbreak
     }
     p = p->next;
   }
   return r; //見つからない場合はNULL
}

struct symboltable *type_lookup(char *name,Scope type){
    // 記号表から関数情報を取得
		struct symboltable *p,*tmp;
		p = head;
		while(1){
			if((strcmp(p->name,name) == 0) && (p->type == type)){
				return p;
			}
			p = p->next;
			if(p == NULL){
				printf("記号表内に存在しません\n");
				exit(1);
			}
    }
}

void delete()
{
  struct symboltable *p,*tmp;
  p = head;
  if(p == NULL){
    printf("symboltable is not exist\n");
    return;
  }
  while(p->type == LOCAL_VAR){
    tmp = p;
    p = p->next;
    free(tmp);  //記号表を新しい順に読んでいきLACAL_VARを全て削除する
  }
  head = p;
  printf("local var is deleted\n");
  print_all();
}

//記号表を一行出力する関数
void print_row(struct symboltable *row){
  Scope scope_type = row->type;
  if (row != NULL)
    {
      switch (scope_type)
        {
          case GLOBAL_VAR:
            printf("    %s %u GLOBAL \n", row->name, row->num);
            break;
	  
          case LOCAL_VAR:
            printf("    %s %u LOCAL\n", row->name, row->num);
            break;
	  
          case PROC_NAME:
            printf("    %s %u PROC\n", row->name, row->num);
            break;
          
          case FUNC_NAME:
            printf("    %s %u FUNC\n", row->name, row->num);
            break;
          default:
            printf("    %s %u !INVALID_INPUT!\n", row->name, row->num);
            break;
        }
    }
}

//現在の記号表を出力する関数
void print_all()
{
  struct symboltable *row;
  row  = head;
  printf("Current SymbolTable\n");
  while(1){
    print_row(row);
    if((row->next) == NULL){break;}
    row = row -> next;
  }
}



