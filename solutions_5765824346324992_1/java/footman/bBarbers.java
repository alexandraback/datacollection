import static java.lang.System.in;
import static java.lang.System.out;

import java.io.*;
import java.util.*;

public class bBarbers {
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
			int b = sc.nextInt();
			long n = sc.nextLong();
			int [] m = new int[b];
			for (int i=0; i<b; i++)
				m[i] = sc.nextInt();
			long l = -1L, r=100000L*n;
			while (l+1<r){
				long mid = (l+r)/2;
				long count = 0L;
				for (int i=0; i<b; i++)
					count+=mid/(long)m[i]+1;
				if (count>=n) r = mid;
				else l = mid;
			}
			long countL = 0L;
			for (int i=0; i<b; i++)
				countL+=l/(long)m[i]+1;
			if (l==-1) countL=0;
			int ans=-1;
			long k;
			int i;
			for (i=0,k=0; i<b; i++)
				if ((r % (long)m[i])==0){
					k++;
					if (countL+k==n){
						ans=i;
						break;
					}
				}
			sb.append("Case #" + t + ": ");
			sb.append(ans+1);
			sb.append("\n");
		}
		ln(sb);
		sc.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new bBarbers().run();
	}
	public static void ln(Object obj) {
		out.print(obj);
	}
}
