p1: lex.yy.o
		gcc -g -Wall parser1.c lex.yy.o -o cfp.exe -ll

lex.yy.o: lex.yy.c 

lex.yy.c: SFP.lex
		lex SFP.lex
run: p1 sample2.pt sample.sfp
		./cfp.exe sample2.pt < sample.sfp
clean:
		rm -f lex.yy.* cfp.exe
		rm sample.sfp.out
