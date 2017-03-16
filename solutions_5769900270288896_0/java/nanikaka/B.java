package gcj2015.r1b;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class B {

	final boolean DEBUG = false;
	final boolean isSmall = true;
	final String PACKAGE = "gcj2015/r1b";
	final String PROBLEM = "B";
	
	int[][] d = {{-1,0},{0,1},{1,0},{0,-1}};
	
	void run(){
		if(!DEBUG){
			try {
				if(isSmall)System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small-attempt0.in")));
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
			int R = sc.nextInt(), C = sc.nextInt(), N = sc.nextInt();
			boolean[][] m = new boolean[R][C];
			int res = 1<<28;
			int n = R*C;
			for(int S=0;S<1<<n;S++){
				if(Integer.bitCount(S)==N){
					for(boolean[]b:m)Arrays.fill(b, false);
					for(int j=0;j<16;j++)if(((S>>j)&1)>0)m[j/C][j%C]=true;
					int c = 0;
					for(int i=0;i<R;i++)for(int j=0;j<C;j++)if(m[i][j]){
						for(int k=0;k<4;k++){
							int ni=i+d[k][0], nj=j+d[k][1];
							if(0<=ni&&ni<R&&0<=nj&&nj<C&&m[ni][nj])c++;
						}
					}
					res = Math.min(res, c/2);
				}
			}
			System.out.println("Case #"+CASE+": "+res);
		}
	}
	
	void debug(Object...o){
		System.out.println(Arrays.deepToString(o));
	}
	
	public static void main(String[] args) {
		new B().run();
	}
}
