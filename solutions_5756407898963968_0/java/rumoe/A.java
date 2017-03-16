package j2014.qual;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Scanner;

@SuppressWarnings("all")
public class A {

	private static final String FILE_NAME = "A-small-attempt0";	
	
	private static final String RELATIVE_PATH;
	static {
		String p = A.class.getPackage().getName();
		p = p.replace('.', '\\');
		RELATIVE_PATH = "src\\" + p + "\\" + FILE_NAME;
	}
	
	private Scanner in;
	private PrintStream out;
	
	public A () throws FileNotFoundException {
		in = new Scanner(new File(RELATIVE_PATH + ".in"));	
		out = new PrintStream(RELATIVE_PATH + ".out"); 
			
		int cases = nextInt();	
		for (int i = 1; i <= cases; i++) {
			print("Case #" + i + ": ");
			solve();
			println();
		}	

		out.close();
		System.out.println("\nDONE!");
	}
	
	private void solve() {
		int[] row1 = getRow(nextInt());
		int[] row2 = getRow(nextInt());
		
		int number = 0, sameCount = 0;
		for (int i = 0; i < row1.length; i++) {
			for (int j = 0; j < row2.length; j++) {
				if (row1[i] == row2[j]) {
					number = row1[i];
					sameCount++;
				}
			}
		}
		
		if (sameCount == 0) {
			print("Volunteer cheated!");
		} else if (sameCount == 1) {
			print(number);
		} else {
			print("Bad magician!");
		}
	}
	
	int[] getRow(int r) {
		int[] row = new int[4];
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 4 ; j++) {
				int t = nextInt();
				if (r == i) {
					row[j] = t;
				}
			}
		}
		return row;
	}
	
	
	
	/*
	 * Manage input
	 */
	private String next() {
		return in.next();
	}
	private int nextInt() {
		return in.nextInt();
	}
	private long nextLong() {
		return in.nextLong();
	}

	/*
	 * Manage output
	 */
	private void print(String s) { 
		System.out.print(s);
		out.print(s); 
	}	
	private void print(int i) { 
		System.out.print(i);
		out.print(i); 
	}	
	private void print(Object o) {
		System.out.print(o);
		print(o);
	}
	private void println() { 
		System.out.println();
		out.println(); 
	}
	
	public static void main(String[] args) {
		try {
			new A();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
