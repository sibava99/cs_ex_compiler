CC = cc
YACC = yacc -d

parser: y.tab.o lex.yy.o symtab.o
	$(CC) y.tab.o lex.yy.o symtab.o -ll -o parser

y.tab.o: parser.y
	$(YACC) parser.y
	$(CC) -c -o y.tab.o y.tab.c
lex.yy.o: scanner.l
	lex scanner.l
	$(CC) -c -o lex.yy.o lex.yy.c
symtab.o: symtab.h symtab.c
	$(CC) -c symtab.c
