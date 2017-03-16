/*
ID: mkural31
LANG: JAVA
TASK: logging
*/
import java.io.*;
import java.util.*;

public class logging{//hmm test this on 1 case?
	public static void main (String [] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("logging.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("logging.out")));
		int t = Integer.parseInt(f.readLine());
		for(int waka = 0;waka<t;waka++){
			StringTokenizer st = new StringTokenizer(f.readLine());
			int n = Integer.parseInt(st.nextToken());
			long x[][] = new long[n][2];
			//System.out.println(n);
			for(int i = 0;i<n;i++){
				StringTokenizer sc = new StringTokenizer(f.readLine());
				x[i][0]=Long.parseLong(sc.nextToken());
				x[i][1]=Long.parseLong(sc.nextToken());
			//	System.out.println("m[" + i + "] is " + m[i]);
			}
			int min[] = new int[n];
			for(int i= 0;i<n;i++){
				min[i]=n-1;
			}
			for(int i = 0;i<n;i++){
				for(int j = 0;j<n;j++){
					if(j!=i){
						int first = 0;
						int second = 0;
						for(int k = 0;k<n;k++){
							if(k!=i&&k!=j){
								long a = twicearea(x[i],x[j],x[k]);
								if(i==4)System.out.println("area of " +i + " " + j + " " + k + " is " + a);
								if(a>0){
									first++;
								}
								if(a<0){
									second++;
								}
							}
						}
						min[i]=Math.min(min[i],Math.min(first,second));
						if(i==4)System.out.println(" at " + i + " and " + j + " --> " + first + " " + second + "  so the overall min is now " + min[i]);
					}
				}
			}
			out.println("Case #" + (waka+1) + ":");
			for(int i = 0;i<n;i++){
				out.println(min[i]);
			}
		}
		out.close();
		System.exit(0);
	}
	public static long twicearea(long x[], long y[], long z[]){
		return x[0]*y[1]+y[0]*z[1]+z[0]*x[1]-x[0]*z[1]-y[0]*x[1]-z[0]*y[1];
	}
}