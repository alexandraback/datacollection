import static java.lang.System.in;
import static java.lang.System.out;

import java.io.*;
import java.util.*;

public class Repeater {
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
			String [] s = new String[n]; 
			for (int i=0; i<n; i++)
				s[i] = sc.next();
			sb.append("Case #" + t + ": ");
			boolean lost = false;
			int ans =0;
			while(s[0].length()>0){
				char c = s[0].charAt(0);
				int [] b = new int [101];
				
				for (int i=0; i<n; i++){
					int k=0;
					while (k<s[i].length() && s[i].charAt(k)==c) k++;
					if (k ==0) {
						lost = true;
						break;
					}
					s[i] = s[i].substring(k);
					b[k]++;
				}
				if (lost) break;
				int m = 10000000;
				for (int i=1; i<101; i++){
					int sum = 0;
					for (int k=1; k<101; k++)
						sum+=Math.abs(i-k)*b[k];
					m = Math.min(m, sum);
				}
				ans +=m;
			}
			for (int i=1; i<n; i++)
				if (s[i].length()>0) lost = true;
			
			if (lost) sb.append("Fegla Won");
			else sb.append(ans);
			sb.append("\n");
		}
		ln(sb);
		sc.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Repeater().run();
	}
	public static void ln(Object obj) {
		out.print(obj);
	}
}
