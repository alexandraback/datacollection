import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class R1B_2014_A_large {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
		FileWriter fw = new FileWriter("A-large.out");
		int T = new Integer(in.readLine());
		for (int cases = 1; cases <= T; cases++) {
			int N = new Integer(in.readLine());
			int y = 0;
			String[] input = new String[N];
			for(int i=0; i<N; i++){
				input[i] = in.readLine();
			}
				
				char[][] iChar0 = new char [100][100];
				int[][] iNum0 = new int [100][100];
				
				int countDistChar = 0;
				for(int i=0; i<N; i++){
					char[] iChar = input[i].toCharArray();
					char lastChar = iChar[0];
					int lastCharCount = 1;
					countDistChar = 0;
					for(int j=1; j<iChar.length; j++){
						char curChar = iChar[j];
						if(curChar == lastChar){
							lastCharCount++;
						}
						else{
							iChar0[i][countDistChar] = lastChar;
							iNum0[i][countDistChar] = lastCharCount;
							lastCharCount = 1;
							lastChar = curChar;
							countDistChar++;
						}
					}
					iChar0[i][countDistChar] = lastChar;
					iNum0[i][countDistChar] = lastCharCount;
					countDistChar++;
				}
					
				

				if(sameCharList(iChar0, N)){ //possible
					//sum step
					y = 0;
					for(int i=0; i< countDistChar; i++){
						int[] m = new int[N];
						for(int j=0; j< N; j++){
							m[j] = iNum0[j][i];
						}
						Arrays.sort(m);
						
						int median = median(m);
						for(int j=0; j< N; j++){
							y += Math.abs(iNum0[j][i] - median);
						}
						
					}
					
					
					fw.write("Case #" + cases + ": " + y + "\n");
				}
				else{  //not possible
					fw.write("Case #" + cases + ": Fegla Won\n");
					
				}
				
				
			
			
			
		}
		fw.flush();
		fw.close();
		
		System.out.println("Done!");
	}

	private static boolean sameCharList(char[][] c, int N){
		for(int i=0; i< N; i++){
			for(int j=0; j< c[0].length; j++){
				if(c[i][j] != c[0][j])
					return false;
			}
		}
		
		return true;
	}
	public static int median(int[] m) {
	    int middle = m.length/2;
	    if (m.length%2 == 1) {
	        return m[middle];
	    } else {
	        return (m[middle-1] + m[middle]) / 2;
	    }
	}
}

