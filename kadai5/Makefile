CC = cc
YACC = yacc -d

parser: y.tab.o lex.yy.o symtab.o llvmcommands.o
	$(CC) y.tab.o lex.yy.o -lm -ll -g -o parser symtab.o llvmcommands.o

y.tab.c: parser.y
	$(YACC) parser.y
	$(CC) -c -o y.tab.o y.tab.c
lex.yy.o: scanner.l
	lex scanner.l
	$(CC) -c -o lex.yy.o lex.yy.c
symtab.o: symtab.h symtab.c
	$(CC) -c symtab.c
llvmcommands.o: llvmcommands.h llvmcommands.c
		$(CC) -c llvmcommands.c