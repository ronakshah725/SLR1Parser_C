
import java.io.*;
import java_cup.runtime.Symbol;
import Scanner;


/**
 * Simple test driver for the java lexer. Just runs it on some
 * input files and produces debug output. Needs symbol class from
 * parser. 
 */
public class TestLexer {

 

  public static void main(String argv[]) {


      try {
        System.out.println("Lexing ");
        Scanner scanner = new Scanner(new FileReader("sample.sfp"));
                
        Symbol s;
        do {
          s = scanner.debug_next_token();
          System.out.println("token: "+s);
        } while (s.sym != mySym.EOF);
        
        System.out.println("No errors.");
      }
      catch (Exception e) {
        e.printStackTrace(System.out);
        System.exit(1);
      }
    }
  
}
