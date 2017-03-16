import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class gcj implements Runnable {
	
	///////////////////////
	// File name variables
	final String problem = "A";
	
	// final String filename = problem + "-sample";

	//final String filename = problem + "-small-attempt0";

	//final String filename= problem+"-small-attempt3";
	final String filename= problem+"-large";
	
	// Output Float format
	// e.g. out.write(df.format(T0));
	//DecimalFormat df = new DecimalFormat("0.000000");
	
	//////////////////////////////////////////
	// Hard core function
	public void solve() throws Exception {
		int numInputs = iread();
		int[] inputList = new int[numInputs];
		
		for (int i = 0; i < numInputs; i++) {
			inputList[i] = iread();
		}
		
		// Compute for method one
		int totalEatenInMethodOne = 0, maxDiff = 0;
		for (int i = 1; i < numInputs; i++) {
			if (inputList[i] < inputList[i-1]) {
				totalEatenInMethodOne += inputList[i-1] - inputList[i];
				if (inputList[i-1] - inputList[i] > maxDiff) {
					maxDiff = inputList[i-1] - inputList[i];
				}
			}
		}
		
		// Computer for method two
		int totalEatenInMethodTwo = 0;
		for (int i = 0; i < numInputs - 1; i++) {
			if (inputList[i] < maxDiff) {
				totalEatenInMethodTwo += inputList[i];
			} else {
				totalEatenInMethodTwo += maxDiff;
			}
		}
		
		out.write(totalEatenInMethodOne + " " + totalEatenInMethodTwo);
	}
	
	
	//////////////////////////////////////////
	/// Helper functions
	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			out.write("Case #" + test + ": ");
			solve();
			out.write("\n");
		}
	}

	public void run() {
		try {
			// Helper in-&-out for local test
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new BufferedWriter(new OutputStreamWriter(System.out));
			
			// For real file input and output
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new BufferedWriter(new FileWriter(filename + ".out"));
			solve_gcj();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	/////////////////////////
	// Main Function
	public static void main(String[] args) {
		try {
			Locale.setDefault(Locale.US);
		} catch (Exception e) {

		}
		new Thread(new gcj()).start();
	}
}
