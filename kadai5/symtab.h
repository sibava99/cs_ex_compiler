#ifndef __SYMBOLS_H__
#define __SYMBOLS_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 記号表の管理 + 変数・定数の区別用 */
typedef enum { 
  GLOBAL_VAR, /* 大域変数 */
  LOCAL_VAR,  /* 局所変数 */
  PROC_NAME,  /* 手続き   */
  CONSTANT    /* 定数     */
} Scope;


/* 記号表の構造体の宣言 */
struct symboltable
{
  char *name;
  int num; /* 変数はレジスタ番号を保存、関数,手続きは引数の数を保存 */
  Scope type;
  struct symboltable *next;
};

/* insert, lookup, deleteのプロトタイプ宣言 */
void insert(char *name,Scope flag);
struct symboltable *lookup(char *name);
void delete();
void print_row(struct symboltable *row);
void print_all();

#endif
