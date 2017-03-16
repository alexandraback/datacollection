package a;
import java.util.*;import java.text.*;import java.math.*;import java.util.regex.*;import java.awt.geom.*;import java.io.*;
import static java.lang.Math.*;import static java.lang.Character.*;import static java.lang.Integer.*;import static java.lang.Double.*;import static java.lang.Long.*;import static java.lang.System.*;import static java.util.Arrays.*; 

class Solver {
	public static final String FILE_NAME = "A"; 
//	public static final String FILE_NAME = "A-small-attempt0"; 
//	public static final String FILE_NAME = "A-large"; 
	
	public static final String FOLDER_NAME = "/Users/minh/Documents/workspace/GoogleCodeJam/src/a/";
	public static final String INPUT_FILE_NAME = FOLDER_NAME + FILE_NAME + ".in";
	public static final String OUTPUT_FILE_NAME = FOLDER_NAME + FILE_NAME + ".out";
	
	final int INF = Integer.MAX_VALUE/10;

	String ret = "";
	int res = Integer.MAX_VALUE/2;
	int temp = 0;
	int m;
	int n;
	String [] a;
	String [] b;
	int[][] c;
	
	public void input() throws Exception{
		n = new Integer (in.readLine());
		a = new String[n];
		b = new String[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.readLine();
			b[i] = simplify (a[i]);
			if (i!=0 && !b[i].equals(b[0]) ){
				ret = "Fegla Won";
				return;
			}
		}
		m = b[0].length();
		c = new int[n][m];
		for (int i = 0; i < n; i++) {
			int u = 0, count = 0;
			for (int j = 0; j < a[i].length(); j++) {
				if (a[i].charAt(j)!=b[i].charAt(u)) {
					c[i][u] = count;
					count = 1;
					u++;
				} else {
					count ++;
				}
			}
			c[i][m-1] = count;
		}
//		debug (c);
	}
	
	String simplify (String s) {
		String res = "";
		for (int i = 0; i < s.length()-1; i++) {
			if (s.charAt(i)!=s.charAt(i+1)) res += s.charAt(i);
		}
		res += s.charAt(s.length()-1);
		return res;
	}
	
	public void process() throws Exception{
		if (!ret.equals("")) return;
		res = 0;
		for (int i = 0; i < m; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				sum += c[j][i];
			}
			int mid = (int) Math.round(1.*sum/n);
//			debug(mid);
			for (int j = 0; j < n; j++) {
				res += abs (mid - c[j][i]);
			}
		}
	}

	public void output() throws IOException {
		if (res < Integer.MAX_VALUE/2) {
			ret = res+"";
		}
		out.write(outputString() + ret);
		out.newLine();
		
		System.out.println(outputString() + ret);
	}
	
	private String outputString () {
		return "Case #"+(A.CURRENT_TEST+1)+": ";
	}
	void debug(Object...os) { 
		System.err.println(Arrays.deepToString(os));
	} 

	BufferedReader in;
	BufferedWriter out;
	
	public Solver(BufferedReader in, BufferedWriter out ){
		this.in = in;
		this.out = out;
	}
	
	int[] parseArrInt (String s) {
		s = s.trim();
		ArrayList<Integer> list = new ArrayList<Integer> ();
		String[] ss = s.split("[ ]+");
		for(String x:ss) list.add(new Integer(x));
		int[] ret = new int[list.size()];
		for (int i = 0; i < ret.length; i++) {
			ret[i] = list.get(i);
		}
		return ret;
	}
	
	// Bit Operators
	int SET(int mask, int u) { return mask | (1 << u);}
	boolean CHECK(int mask, int u) {return (mask & (1 << u)) != 0;}
	int FLIP(int mask, int u) {return mask ^ (1 << u);}
	int CLEAR(int mask, int u) {if (CHECK(mask, u)) return FLIP(mask, u);return mask;}
	long SET(long mask, long u) { return mask | (1L << u);}
	boolean CHECK(long mask, long u) {return (mask & (1L << u)) != 0;}
	long FLIP(long mask, long u) {return mask ^ (1L << u);}
	long CLEAR(long mask, long u) {if (CHECK(mask, u)) return FLIP(mask, u);return mask;}
}

/**
 * @author minh
 *
 */
public class A {
	static BufferedReader in;
	static BufferedWriter out;
	static int NUMBER_OF_TEST, CURRENT_TEST;
	
	public static void main(String[] args) throws java.lang.Exception {
		in =  new BufferedReader(new FileReader(new File (Solver.INPUT_FILE_NAME)));
		out = new BufferedWriter(new FileWriter(new File (Solver.OUTPUT_FILE_NAME)));
		
//		int[] temp = solver.parseArrInt(in.readLine());
//		// code here
//		NUMBER_OF_TEST = temp[0];
//		Solver solver = new Solver(in, out);
//		solver.input();
//		for(CURRENT_TEST = 0;CURRENT_TEST<NUMBER_OF_TEST;CURRENT_TEST++) {
//			solver.process();
//			solver.output();
//		}
//		
		
		NUMBER_OF_TEST = new Integer(in.readLine());
		for(CURRENT_TEST = 0;CURRENT_TEST<NUMBER_OF_TEST;CURRENT_TEST++) {
			Solver solver = new Solver(in, out);
			solver.input();
			solver.process();
			solver.output();
		}
		
		in.close();
		out.close();
	}
}

