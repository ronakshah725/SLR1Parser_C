


import java_cup.runtime.*;

%%

%public
%class Scanner
%implements mySym



%line
%column

%cup
%cupdebug


%{
  StringBuilder string = new StringBuilder();
 
  private Symbol symbol(int type) {
    return new JavaSymbol(type, yyline+1, yycolumn+1);
  }

  private Symbol symbol(int type, Object value) {
    return new JavaSymbol(type, yyline+1, yycolumn+1, value);
  }

%}


LineTerminator = \r|\n|\r\n

WhiteSpace = {LineTerminator} | [ \t\f]

Identifier = [a-z]+

Integer = [\-]?[ ]*((0)|([1-9][0-9]*))+

Float = {Integer} \.([0-9])+([E](\+|\-)[0-9]+)?


Number = {Integer} | {Float}





%%



  {Number}                       { return symbol(NUMBER);}

  "print"                        { return symbol(PRINT);}
  "loop"                         { return symbol(LOOP);}

  "{"                            { return symbol(LBRACE); }
  "}"                            { return symbol(RBRACE); }

  

  "="                            { return symbol(ASSIGN); }
  "+"                            { return symbol(FUNCTION); }
  "*"                            { return symbol(FUNCTION); }  
  {WhiteSpace}                   { /* ignore */ }

  /* identifiers */ 
  {Identifier}                   { return symbol(IDENTIFIER, yytext()); }  




/* error fallback */
[^]                              { throw new RuntimeException("Illegal character \""+yytext()+
                                                              "\" at line "+yyline+", column "+yycolumn); }
<<EOF>>                          { return symbol(EOF); }