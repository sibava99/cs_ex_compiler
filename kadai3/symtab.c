#include "symtab.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/* 記号表の実体をここで作成 */
/* parser.yからは，以下のinsert/lookup/deleteなどを通してアクセスする */

struct symboltable *head = NULL; 


/* insert, lookup, deleteの実装 */
void insert(char *name,Scope flag)
{
  struct symboltable *newnode;
  
  newnode = (struct symboltable *)malloc(sizeof(struct symboltable *));
  if(newnode == NULL){
    printf("can not malloc!!\n");
    return;
  }
  strcpy((newnode->name),name);
  newnode -> level = flag;
  newnode -> num = 0;
  if(head == NULL)
    {
      head = newnode;
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

void lookup(char *name){
  struct symboltable *p;
  p = head;

  while(p != NULL){
    if(strcmp(p->name,name) == 0){
      printf("look up:");
      print_row(p);
      break;
      }
    p = p->next;
  }
  return;
}


void delete()
{
  struct symboltable *p,*tmp;
  p = head;
  if(p == NULL){
    printf("symboltable is not exist\n");
    return;
  }
  while(p->level == LOCAL_VAR){
    tmp = p;
    p = p->next;
    free(tmp);
  }
  head = p;
  print_all();
}

void print_row(struct symboltable *row){
  Scope scope_level = row->level;
  if (row != NULL)
    {
      switch (scope_level)
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
	  
	  // case CONSTANT:
	  //     /* code */
	  //     break;
	  
        default:
	  printf("    %s %u !INVALID_INPUT!\n", row->name, row->num);
	  break;
        }
    }
}

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



