package round1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * @author Oliver
 * 
 */
public class TheRepeater {

	private static BufferedReader br;
	private static BufferedWriter bw;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			// Open input file.
			br = new BufferedReader(new FileReader("A-small-attempt1.in"));

			// Open output file.
			bw = new BufferedWriter(new FileWriter("output.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			return;
		} catch (IOException e) {
			e.printStackTrace();
		}

		try {
			// Initialise input and read number of cases.
			int testCases = Integer.parseInt(br.readLine());

			// For each test case.
			analyseTestCases(testCases);
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				br.close();
				bw.flush();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	private static void analyseTestCases(int testCases) throws IOException {
		for (int i = 1; i <= testCases; i++) {
			int n = Integer.parseInt(br.readLine());

			char[][] cs = new char[n][];

			for (int j = 0; j < n; j++) {
				cs[j] = br.readLine().toCharArray();
			}
			
			int[][] counts = getCharCounts(cs);

			if (counts != null) {
				int m = getMinMoves(counts);

				write("Case #" + i + ": " + m + "\n");
			}
			else {
				write("Case #" + i + ": Fegla Won\n");
			}
		}
	}

	private static int[][] getCharCounts(char[][] cs) {
		int[][] n = new int[cs.length][];

		List<Character> l = new ArrayList<Character>();

		char[] s = cs[0];

		char c = s[0];

		l.add(c);

		int index = 1;

		List<Integer> n2 = new ArrayList<Integer>();

		n2.add(1);

		while (index < s.length) {
			if (s[index] != s[index - 1]) {
				l.add(s[index]);

				n2.add(1);
			} else {
				int count = n2.size();

				n2.set(count - 1, n2.get(count - 1) + 1);
			}

			index++;
		}

		n[0] = new int[n2.size()];

		for (int i = 0; i < n2.size(); i++) {
			n[0][i] = n2.get(i);
		}

		for (int i = 1; i < cs.length; i++) {
			s = cs[i];

			n2 = new ArrayList<Integer>();

			n2.add(1);

			if (s[0] != l.get(0)) {
				return null;
			}

			int j = 0;

			index = 1;

			while (index < s.length) {
				if (s[index] == l.get(j)) {
					int count = n2.size();

					n2.set(count - 1, n2.get(count - 1) + 1);
				} else {
					j++;

					if (j == l.size()) {
						return null;
					}

					if (s[index] == l.get(j)) {
						n2.add(1);
					} else {
						return null;
					}
				}

				index++;
			}
			
			if (n2.size() != l.size()) {
				return null;
			}
			
			n[i] = new int[n2.size()];

			for (int k = 0; k < n2.size(); k++) {
				n[i][k] = n2.get(k);
			}
		}

		return n;
	}
	
	private static int getMinMoves(int[][] n) {
		int m = 0;
		
		for (int i = 0; i < n.length; i++) {
			if (n[0].length != n[i].length) {
				return 0;
			}
		}
		
		for (int i = 0; i < n[0].length; i++) {
			int[] col = getCol(n, i);
			
			m += getMinMoves(col);
		}
		
		return m;
	}
	
	private static int[] getCol(int[][] n, int colNum) {
		int[] col = new int[n.length];
		
		for (int i = 0; i < col.length; i++) {
			col[i] = n[i][colNum];
		}
		
		return col;
	}
	
	private static int getMinMoves(int[] n) {
		int m = Integer.MAX_VALUE;

		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		
		for (int i = 0; i < n.length; i++) {
			min = Math.min(min, n[i]);
			max = Math.max(max, n[i]);
		}
		
		for (int i = min; i <= max; i++) {
			int count = 0;
			
			for (int j = 0; j < n.length; j++) {
				count += Math.abs(i - n[j]);
			}
			
			m = Math.min(m, count);
		}
		
		return m;
	}

	private static void write(String s) {
		try {
			bw.write(s);
			System.out.print(s);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
