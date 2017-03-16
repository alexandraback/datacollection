package codejam_R1C;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;

public class a {
	public static void main(String[] args) throws IOException {
		FileInputStream in = null;
		PrintWriter out = null;

	      try {
	         in = new FileInputStream("A-large.in");
	         out = new PrintWriter( "outputA-large.txt" );

	         Scanner sc = new Scanner (in);
	         String line = sc.nextLine();
	           
	         int T = Integer.parseInt(line);
	         
	         for(int i=1; i<=T; i++) {
	        	 line = sc.nextLine();
	        	 int N = Integer.parseInt(line);
	        	 
	        	 Vector<CustomObject> vector = new Vector<CustomObject>();
	        	
	        	 int total = 0;
	        	 line = sc.nextLine();
        		 for (int j=0; j < N; j++) {
        			 int first = Integer.parseInt(line.split(" ")[j]);
        			 int second = j;
        			 CustomObject m = new CustomObject(first, (char) ('A'+j));
        			 vector.add(m);
        			 total += first;
        		 }
        		 
        		 String output = "Case #" + i + ":";
        		 while (total != 0 ) {
        			 Collections.sort(vector);
        			 if (total%2 == 0) {
        				 String a = " " + vector.elementAt(N-2).aCharacter + "" + vector.elementAt(N-1).aCharacter;
        				 output = output + a;
        				 
        				 --vector.elementAt(N-1).aInt;
        				 --vector.elementAt(N-2).aInt;
        				 total -= 2;
        			 } else {
        				 output += " " + vector.elementAt(N-1).aCharacter;
        				 --vector.elementAt(N-1).aInt;
        				 total -= 1;
        			 }
        		 }
        		 out.println(output);
         	}
        		        
	      } finally {
	         if (in != null) {
	            in.close();
	         }
	         if (out != null) {
	            out.close();
	         }
	      }
		}
}


class CustomObject implements Comparable<CustomObject> { 
    Character aCharacter;
    int aInt;
    CustomObject( int i, char s ) { 
        aInt = i;
        aCharacter = s;
    }
    
    public int compareTo(CustomObject two) {
        int diff = this.aInt - two.aInt;
        if( diff != 0 ) { 
            return diff;
        }

        return this.aCharacter.compareTo( two.aCharacter );
   }
}