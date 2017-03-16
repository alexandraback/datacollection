package round1A;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Scanner;


public class A {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new BufferedReader(new FileReader("A.in")));
		PrintStream out = new PrintStream("A.out");
		int T = in.nextInt();
		for(int k=1; k<=T; k++){
			int N = in.nextInt();
			int[] m = new int[N];
			for(int i=0;i<N;i++){
				m[i] = in.nextInt();
			}
			int maxDec = 0;
			int sumDec = 0;
			for(int i=0;i<N-1;i++){
				if (m[i]-m[i+1]>maxDec) maxDec = m[i]-m[i+1];
				if (m[i]>m[i+1]) sumDec+= m[i]-m[i+1];
			}
			int sumRate = 0;
			for(int i=0;i<N-1;i++){
				if (m[i]<maxDec) sumRate += m[i];
				else sumRate += maxDec;
			}
			out.println("Case #"+k+": "+sumDec+" "+sumRate);
		}
		in.close();
		out.close();
	}
}
