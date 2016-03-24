
# run: p1 
# 	./parser.exe input.pt < my_test.sfp

all: lex.yy.c
	g++ -g -w  parser1.cpp lex.yy.c -ll -o parser.exe --std=c++11


lex.yy.c: SFP.lex
		flex SFP.lex


clean:
		rm -f lex.yy.* parser.exe

