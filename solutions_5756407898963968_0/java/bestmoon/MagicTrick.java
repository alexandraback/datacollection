package codejam2014;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.HashSet;

import util.InputReader;

public class MagicTrick implements Runnable{
	private InputReader in;
	private PrintWriter out;
	private static String delimiter = " ";

	public static void main(String[] args) {
		new Thread(new MagicTrick()).start();
	}

	public MagicTrick(){
		try{
			BufferedReader buffer = new BufferedReader(new FileReader("d:\\A-small-attempt0.in"));
			in = new InputReader(buffer);
			System.setOut(new PrintStream(new FileOutputStream("d:\\output.txt")));
			out = new PrintWriter(System.out);
		} catch (FileNotFoundException e) {
			throw new RuntimeException();
		}
	}

	@Override
	public void run() {
		int numTests = in.readInt();

		for (int testNumber = 0; testNumber < numTests; testNumber++) {
			out.print("Case #" + (testNumber + 1) + ": ");
			int c1 = in.readInt();
			int[][] m1 = new int[4][4];
			m1 = ReadMatrix(in);
			
			int c2 = in.readInt();
			int[][] m2 = new int[4][4];
			m2 = ReadMatrix(in);
			
			String flag = FindInMatrix(m1, c1, m2, c2);
			out.println(flag.trim());
		}
		out.close();
	}

	private String FindInMatrix(int[][] m1, int count1, int[][] m2, int count2) {
		HashSet<Integer> s = new HashSet<Integer>();
		int can = 0;
		for(int i: m1[count1-1]) {
			s.add(i);
		}
		for(int j: m2[count2-1]) {
			if(!s.add(j))
				can = j;
		}
		
		if(s.size() == 8) {
			return "Volunteer cheated!";
		}
		else if(s.size() == 7) {
			return Integer.toString(can);
		}
		else if(s.size() == 6 || s.size() == 5 || s.size() == 4) {
			return "Bad magician!";
		}
		return "";
	}

	private int[][] ReadMatrix(InputReader in) {
		int[][] m = new int[4][4];
		for(int i = 0; i<4; i++) {
			String str = in.readString();
			String[] elements = str.split(delimiter);

			for(int j = 0; j<4; j++) {
				m[i][j] = Integer.parseInt(elements[j]);
			}
		}
		return m;
	}

}
