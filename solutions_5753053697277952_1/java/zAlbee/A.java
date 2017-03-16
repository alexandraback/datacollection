import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.*;


/**
 * Template
 * @author Albert Choi
 */
public class A {
	static BufferedReader _reader = new BufferedReader(new InputStreamReader(System.in));
	static String _s;
	static StringTokenizer _st;
	static int _l;
	static String nline() throws IOException { _s = _reader.readLine(); ++_l; _st = new StringTokenizer(_s); return _s; }
	static String nword() 	{ return _st.nextToken(); }
	static int nint() 		{ return Integer.parseInt(nword()); }
	static long nlong() 	{ return Long.parseLong(nword()); }
	static double ndouble() { return Double.parseDouble(nword()); }
	static BigInteger nbig(){ return new BigInteger(nword()); }
	static PrintStream sout = System.out, serr = System.err;
	
	public static void main(String[] args) throws IOException {
		try {
			nline();
			int T = nint();
			for (int t=1; t<=T; t++) {
				sout.println("Case #" + t + ": " + String.valueOf(doProblem()));
			}
		} catch (Throwable t) {
			System.err.println("At input line " + _l + ": " + _s); throw t;
		}
	}
	
	static Object doProblem() throws IOException {
		nline();
		int N = nint();
		nline();
		int[] p = new int[N];
		int sum = 0;
		for (int i=0;i<N;i++){
			p[i]=nint();
			sum+=p[i];
		}
		StringBuilder ans = new StringBuilder();
		while (sum>0) {
			int max = 0;
			int max2 = 0;
			int maxA = 0;
			int maxB = 0;
			for (int i=0;i<N;i++){
				if (p[i]>max){
					max=p[i];
					maxA=i;
				}
			}
			p[maxA]--;
			sum--;
			ans.append((char)('A'+maxA));

			for (int i=0;i<N;i++){
				if (p[i]>max2){
					max2=p[i];
					maxB=i;
				}
			}
			if (max2 > sum/2) {
				p[maxB]--;
				sum--;
				ans.append((char)('A'+maxB));
			}
			ans.append(' ');
		}
		return ans;
	}

}
