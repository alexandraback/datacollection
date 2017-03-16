//Author: net12k44
import java.io.*;
import java.util.*;
//public
class Main{//}

long cal(long value, int a[], int b){
	if (value < 0) return 0;
	long res = 0;
	for(int i = 0; i < b; ++i){
		res = res + value/a[i] + 1;
		if (res < 0) System.err.println("Aaaaaaaaaaa");
	}
	
	return res;
}

private void lam(){
	int b = in.nextInt(), n = in.nextInt();
	int[] a = new int[b];
	for(int i = 0; i < b; ++i) a[i] = in.nextInt();
	
	long dau = 0, cuoi = (long)1e15;
	while (dau <= cuoi){
		long k = (dau + cuoi) >> 1;
		if (cal(k, a, b) < n) dau = k+1;
		else cuoi = k-1;
	}
	
	long serve = cal(dau, a, b);
	for(int i = b-1; i >= 0; --i)
		if (dau % a[i] == 0){
			if (serve == n){
				out.println(i+1);
				break;
			} 
			serve--;
		}
	
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