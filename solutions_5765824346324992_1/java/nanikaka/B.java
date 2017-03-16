package gcj2015.r1a;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class B {

	final boolean DEBUG = false;
	final boolean isSmall = false;
	final String PACKAGE = "gcj2015/r1a";
	final String PROBLEM = "B";
	
	void run(){
		if(!DEBUG){
			try {
				if(isSmall)System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small.in")));
				else System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large.in")));
				if(isSmall)System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small_out.txt")));
				else System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large_out.txt")));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int CASE=1;CASE<=T;CASE++){
			int B = sc.nextInt(), N = sc.nextInt();
			int[] m = new int[B];
			for(int i=0;i<B;i++)m[i]=sc.nextInt();
			long res = 0;
			if (N <= B) {
				res = N;
			} else {
				long L = 0, R = 1L<<60;
				while(R-L>1){
					long M = (L+R)/2;
					long sum = 0, c = 0;
					for(int i=0;i<B;i++){
						sum+=(M-1)/m[i]+1;
						if (M%m[i]==0)c++;
					}
					if (N <= sum) R = M;
					else if (sum+c < N)L=M;
					else {
						long p = sum;
						for(int i=0;i<B;i++)if(M%m[i]==0){
							p++;
							if (p == N){
								res = i+1;
								break;
							}
						}
						break;
					}
				}
			}
			System.out.println("Case #"+CASE+": "+res);
		}
		
	}
	
	public static void main(String[] args) {
		new B().run();
	}
}
