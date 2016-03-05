
run: p1 sample2.pt sample.sfp
		./cfp.exe mytab.pt < sample.sfp

p1: lex.yy.c
	g++ -g -w  parser1.cpp lex.yy.c -ll -o cfp.exe --std=c++11


lex.yy.c: SFP.lex
		flex SFP.lex


clean:
		rm -f lex.yy.* cfp.exe
		rm sample.sfp.out
