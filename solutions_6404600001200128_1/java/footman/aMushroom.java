import static java.lang.System.in;
import static java.lang.System.out;

import java.io.*;
import java.util.*;

public class aMushroom {
	static final double EPS = 1e-10;
	static final double INF = 1 << 31;
	static final double PI = Math.PI;

	public static BufferedReader in;
	public static PrintWriter out;

	StringBuilder sb = new StringBuilder();


	public void run() throws IOException {
		in =new BufferedReader(new FileReader("in.txt"));
		out=new PrintWriter(new FileWriter("out.txt"));
		
		Scanner sc = new Scanner(in);
		StringBuilder sb = new StringBuilder();
		int T = sc.nextInt();
		
		for (int t=1; t<=T; t++){
			int n = sc.nextInt();
			int [] m = new int[n];
			for (int i=0; i<n; i++)
				m[i] = sc.nextInt();
			int sum1=0;
			int max = 0;
			for (int i=1; i<n; i++)
				if (m[i]<m[i-1]) {
					sum1+=m[i-1] - m[i];
					max = Math.max(max, m[i-1]- m[i]);
				}
			int sum2 = 0;
			for (int i=0; i<n-1; i++)
				if (m[i]<max){
					sum2+=m[i];
				} else sum2+=max;
			sb.append("Case #" + t + ": ");
			sb.append(sum1 + " " + sum2);
			sb.append("\n");
		}
		ln(sb);
		sc.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new aMushroom().run();
	}
	public static void ln(Object obj) {
		out.print(obj);
	}
}
