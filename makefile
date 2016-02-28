p1: lex.yy.o
		gcc lex.yy.o -o cfp.exe -ll

lex.yy.o: lex.yy.c 

lex.yy.c: FP.lex
		lex FP.lex

clean:
		rm -f lex.yy.* cfp.exe
