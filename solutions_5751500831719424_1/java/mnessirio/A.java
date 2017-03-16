
import java.util.Scanner;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class A {

    static Scanner in;
    static String path = "src/";
    static String taskname = "A-large";

    public static String solve() {
        int N = in.nextInt();
        String [] words = new String[N];
        for (int i=0; i< N; i++) {
        	words[i] = in.next();
        }
        
        String simple_word = cut_repeating_letters(words[0]);
        
        for (int i=1; i<N; i++) {
        	if ( ! simple_word.equals( cut_repeating_letters(words[i]) ) ) {
        		return "Fegla Won";
        	}
        }
        
        int [][] cl = new int[N][simple_word.length()];
        
        for (int i=0; i<N; i++) {
        	char previous_letter = '-';
        	int l = -1;
        	for ( int j=0; j<words[i].length(); j++ ) {   
        		char ch = words[i].charAt(j);        		
        		if ( previous_letter != ch) {
        			previous_letter = ch; 
        			l++;
        		}
        		cl[i][l] += 1;
        	}
        }
        
        int y = 0;
        
        for (int l = 0; l<simple_word.length(); l++) {
        	
        	//System.out.print(simple_word.charAt(l) + "\t");
        	
        	int all = 0;
        	for (int i=0; i<N;i++) {
        		all += cl[i][l];
        	}
        	int m = (int) Math.round( 1.0 * all / N);
        	//System.out.print("all=" + all +"\tm=" + m + "\t" );
        	
        	for ( int i=0; i<N; i++) {
        		y += Math.abs( cl[i][l] - m );
        	}       	
        	// System.out.println(y);
        }
        
        // System.out.println();
        
        // Compare all words
        
               
        return "" + y;
    }
    
    public static String cut_repeating_letters( String word) {
    	String w = "";
    	
    	char previous_letter = '-';
    	
    	for ( char ch: word.toCharArray() ) {    		
    		if ( previous_letter != ch) {
    			w += ch;
    			previous_letter = ch;
    		}
    	}
    	
    	return w;
    }
   
    public static void main(String[] args) {
        PrintWriter pW = null;

        try {
            pW = new PrintWriter(new FileOutputStream(path
                    + taskname + ".out"));
            try {
                in = new Scanner(new FileInputStream(path
                        + taskname + ".in"));
                int T = in.nextInt();
                for (int caseNumber = 1; caseNumber <= T; caseNumber++) {
                    pW.println("Case #" + caseNumber + ": " + solve());
                }
                in.close();
                pW.close();
            } catch (IOException e) {
                System.out.println("Can not find file " + taskname + ".in");
            }
        } catch (IOException e) {
            System.out.println("Open or create exception with "
                    + taskname + ".out");
        }
    }
}
