p1: lex.yy.o
		gcc parser1.c lex.yy.o -o cfp.exe -ll

lex.yy.o: lex.yy.c 

lex.yy.c: SFP.lex
		lex SFP.lex

clean:
		rm -f lex.yy.* cfp.exe
		rm sample.sfp.out
