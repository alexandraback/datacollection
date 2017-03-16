import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class Repeater {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	
	static String[] strings;
	static int N;
    static ArrayList<ArrayList<Integer>> stat;
    static int[] index;

    static void solve() throws IOException {
    	printCase();
    	N = nextInt();
    	strings = new String[N];
    	for (int i = 0; i < N; i++) {
    		strings[i] = next();
    	}
    	stat = new ArrayList<ArrayList<Integer>>();
    	index = new int[N];
    	
    	boolean result = calList();
    	if (!result) {
    		out.println("Fegla Won");
    	}
    	else {
    		out.println(getMinMove());
    	}
    }
    
    static boolean calList() {
    	while (index[0] < strings[0].length() ) {
    		ArrayList<Integer> list = new ArrayList<Integer>();
    		char temp = strings[0].charAt(index[0]);
    		for (int i = 0; i < N; i++) {
    			int j = index[i];
    			while(j < strings[i].length() && strings[i].charAt(j) == temp) j++;
    			if (j == index[i]) return false;
    			list.add(j - index[i]);
    			index[i] = j;
    		}
    		stat.add(list);
    	}
    	for (int i = 0; i < N; i++) {
    		if (index[i] != strings[i].length() ) return false;
    	}
    	return true;
    }
    
    static int getMinMove() {
    	int move = 0;
    	
    	for (ArrayList<Integer> list : stat) move += getMinMove(list);
    	
    	return move;
    }
    
    static int getMinMove(ArrayList<Integer> list) {
    	int move = Integer.MAX_VALUE;
    	for (int c = 0; c <= 100; c++) move = Math.min(move, calDiff(list, c));
    	return move;
    }
    
    static int calDiff(ArrayList<Integer> list, int c) {
    	int diff = 0;
    	for (Integer i : list) diff += Math.abs(i - c);
    	return diff;
    }
  
    
    
    static class Assert{
    	static void check(boolean e){
    		if(!e) throw new Error();
    	}
    }

	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new FileReader("A-large.in"));
			out = new PrintWriter("A-large.out");
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}
