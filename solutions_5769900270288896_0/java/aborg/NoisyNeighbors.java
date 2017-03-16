/*
 * 
 */
package codejam2015.round1b.b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Arrays;

/**
 *
 * @author Gabor Bakos
 */
public class NoisyNeighbors {
	private static final boolean easy = true;
	private static final String[] EMPTIES = {"",
		"0",//
		"00",//
		"000",//
		"0000",//
		"00000",//
		"000000",//
		"0000000",//
		"00000000",//
		"000000000",//
		"0000000000",//
		"00000000000",//
		"000000000000",//
		"0000000000000",//
		"00000000000000",//
		"000000000000000",//
		"0000000000000000",//
		"00000000000000000",//
		"000000000000000000",//
		"0000000000000000000",//
		"00000000000000000000",//
		"000000000000000000000",//
		"0000000000000000000000",//
		"00000000000000000000000",//
		"000000000000000000000000",//
		"0000000000000000000000000",//
		"00000000000000000000000000",//
		"000000000000000000000000000",//
		"0000000000000000000000000000",//
		"00000000000000000000000000000",//
		"000000000000000000000000000000",//
		"0000000000000000000000000000000",//
		"00000000000000000000000000000000",//
		"000000000000000000000000000000000",//
		"0000000000000000000000000000000000",//
		"00000000000000000000000000000000000",//
		"000000000000000000000000000000000000",//
		"0000000000000000000000000000000000000"//
		};

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		String lineSep = System.getProperty("line.separator");
		try (BufferedReader br = new BufferedReader(
				args.length > 0 ? new FileReader(args[0])
						: new InputStreamReader(System.in));
				Writer out = new BufferedWriter(
						args.length > 1 ? new FileWriter(args[1])
								: new OutputStreamWriter(System.out))) {
			int numCases = Integer.parseInt(br.readLine().trim());
			for (int i = 1; i <= numCases; ++i) {
				String[] rcn = br.readLine().split(" ");
				out.write("Case #"
						+ i
						+ ": "
						+ minUnhappiness(Integer.parseInt(rcn[0]), Integer.parseInt(rcn[1]), Integer.parseInt(rcn[2])) + lineSep);
			}
		}
	}

	private static int minUnhappiness(int r, int c,
			int n) {
		int min = Integer.MAX_VALUE;
		int max = (1 << (r*c));
		for (int i = max; i-->0;) {
			if (Integer.bitCount(i) == n) {
				min = Math.min(min, unhappiness(i, r, c));
			}
		}
		return min;
	}

	private static int unhappiness(int v, int r, int c) {
		String binaryString = fillTo(Integer.toBinaryString(v), r * c);
		String[] rows = new String[r + 2];
		rows[0] = rows[rows.length - 1] = EMPTIES[c + 2];
		for (int i = 1; i <= r; ++i) {
			rows[i] = "0" + binaryString.substring((i - 1) * c, i * c) + "0";
		}
		return computeAdjacent(rows);
	}

	private static String fillTo(String binaryString, int digitCount) {
		return EMPTIES[digitCount - binaryString.length()] + binaryString;
	}

	private static int computeAdjacent(String[] rows) {
		int count = 0;
		for (int i = 1; i < rows.length - 1; ++i) {
			for (int j = 1; j < rows[i].length() - 1; ++j) {
				if (rows[i].charAt(j) == '1') {
					if (rows[i - 1].charAt(j) == '1') {
						++count;
					}
					if (rows[i + 1].charAt(j) == '1') {
						++count;
					}
					if (rows[i].charAt(j - 1) == '1') {
						++count;
					}
					if (rows[i].charAt(j + 1) == '1') {
						++count;
					}
				}
			}
		}
		return count / 2;
	}
}
