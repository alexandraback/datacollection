import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class a {
    static BufferedReader in;
    static StringTokenizer tok;
    static int test;
    static String line = "";
    
    
    static void solve() throws Exception {
		int parties = nextInt();
		int[] array = new int[parties];
		int max = -1;
		int total = 0;
		boolean num = false;
		int pos1 = 0;
		int pos2 = 0;
		for(int i = 0 ; i<array.length;i++){
			array[i] = nextInt();
			if(array[i]>max){
				max = array[i];
				pos1 = i;
				num = false;
			}else if(array[i]==max){
				pos2 = i;
				num = true;
			}
			total += array[i];
		}
		
		while(max>0){
			char one = (char)(pos1+'A');
			char two = (char)(pos2+'A');
			if(num && total!=3){
				System.out.print(one);
				System.out.print(two + " ");
				array[pos1]--;
				array[pos2]--;
			}else{
				System.out.print(one+ " ");
				array[pos1]--;
			}
			max = -1;
			total = 0;
			for(int i = 0 ; i<array.length;i++){
				if(array[i]>max){
					max = array[i];
					pos1 = i;
					num = false;
				}else if(array[i]==max){
					pos2 = i;
					num = true;
				}
				total += array[i];
			}
		}
		System.out.println();
		
		
    }
    

    
    static void printCase() {
        System.out.print("Case #" + test + ": ");
    }
    
    static void printlnCase() {
        System.out.println("Case #" + test + ":");
    }
    
    static int nextInt() throws IOException {
        return parseInt(next());
    }

    static long nextLong() throws IOException {
        return parseLong(next());
    }

    static double nextDouble() throws IOException {
        return parseDouble(next());
    }
    
    static char nextChar() throws IOException {
        if(line.length() == 0){
            line = next();
        }
        char out = line.charAt(0);
        line = line.substring(1,line.length());
        return out;
    }
    static String next() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    public static void main(String[] args) {
        try {
            in = new BufferedReader(new InputStreamReader(System.in));
            int count = nextInt();
            for(test = 1 ; test<=count ; test++){
                printCase();
                solve();
            }
            in.close();
        } catch (Throwable e) {
            e.printStackTrace();
            exit(1);
        }
    }
}