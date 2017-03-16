//Author: net12k44
import java.io.*;
import java.util.*;
//public
class Main{//}

int firstMethod(int[] a, int n){
	int res = 0;
	for(int i = 1; i < n; ++i)
		if (a[i] < a[i-1]) res += a[i-1] - a[i];
		
	return res;
}

int secondMethod(int[] a, int n){
	int res = 0;
	
	int maxGap = 0;
	for(int i = 1; i < n; ++i)
		maxGap = Math.max(maxGap, a[i-1] - a[i]);
	for(int i = 0; i+1 < n; ++i)
		if (a[i] < maxGap) res += a[i];
		else res += maxGap;
	return res;
}

void lam(){
	int n = in.nextInt();
	int[] a = new int[n];
	for(int i = 0; i < n; ++i) a[i] = in.nextInt();
	
	int res1 = firstMethod(a, n);
	int res2 = secondMethod(a, n);
	
	out.println(res1+" "+res2);
}

private void solve() {
	int test = in.nextInt();
	for(int t = 1; t <= test; ++t){
		out.printf("Case #%d: ", t);
		lam();
	}	
}
	
public static void main (String[] args) throws java.lang.Exception {		
	long startTime = System.currentTimeMillis();

	out = new PrintWriter(System.out);
	out = new PrintWriter("file.out");
	new Main().solve();	
	//out.println((String.format("%.2f",(double)(System.currentTimeMillis()-startTime)/1000)));
	out.close();
}
static PrintWriter out;
static void println(int[] a){
	for(int i = 0; i < a.length; ++i){
		if (i != 0) out.print(' ');
		out.print(a[i]);
	}
	out.println();
}
static class in {
	static BufferedReader reader = new BufferedReader( new InputStreamReader(System.in) ) ;
	static StringTokenizer tokenizer = new StringTokenizer("");				
	static String next() {		
		while ( !tokenizer.hasMoreTokens() )
			try { tokenizer = new StringTokenizer( reader.readLine() ); }
			catch (IOException e){
				throw new RuntimeException(e);			
			}		
		return tokenizer.nextToken();
	}
	static int nextInt() { return Integer.parseInt( next() ); }			
}
//////////////////////////////////////////////////
}//