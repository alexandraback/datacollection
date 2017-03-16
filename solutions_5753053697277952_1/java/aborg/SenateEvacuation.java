/*
 * 
 */
package codejam2016.round1c.a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 *
 * @author Gabor Bakos
 */
public class SenateEvacuation {
	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		String lineSep = System.getProperty("line.separator");
		try (BufferedReader br = new BufferedReader(
				args.length > 0 ? new FileReader(args[0]) : new InputStreamReader(System.in));
				Writer out = new BufferedWriter(
						args.length > 1 ? new FileWriter(args[1]) : new OutputStreamWriter(System.out))) {
			int numCases = Integer.parseInt(br.readLine().trim());
			for (int i = 1; i <= numCases; ++i) {
				br.readLine();
				String[] parts = br.readLine().split(" ");
				int[] parties = Arrays.stream(parts).mapToInt(Integer::parseInt).toArray();
				out.write("Case #" + i + ": " + evacuation(parties) + lineSep);
			}
		}
	}

	private static String evacuation(int[] parties) {
		return String.join(" ", evacuationList(parties));
	}
	private static List<String> evacuationList(int[] parties) {
		List<String> ret = new LinkedList<>();
		int sum = Arrays.stream(parties).sum();
		while (sum > 0) {
			long nonZeroes = countNonZero(parties);
			if (nonZeroes > 2) {
				int idx = findMaxIndex(parties);
				ret.add(party(idx));
				parties[idx]--;
				sum--;
			} else {
				int first = findNonZero(parties, 0), second = findNonZero(parties, 1);
				if (parties[first] != parties[second]) {
					throw new IllegalStateException();
				}
				parties[first]--;
				parties[second]--;
				ret.add(party(first)+ party(second));
				sum--;
				sum--;
			}
		}
		return ret;
	}

	private static String party(int idx) {
		return Character.toString((char) ('A' + idx));
	}

	private static int findNonZero(int[] parties, int nth) {
		int c = -1;
		for (int i = 0; i < parties.length; ++i) {
			if (parties[i] > 0) {
				c++;
			}
			if (c == nth) {
				return i;
			}
		}
		throw new IllegalStateException();
	}

	private static int findMaxIndex(int[] parties) {
		int maxIdx = 0, max = parties[maxIdx];
		for (int i = parties.length; i-->1;) {
			if (parties[i] > max) {
				max = parties[i];
				maxIdx = i;
			}
		}
		return maxIdx;
	}

	private static long countNonZero(int[] parties) {
		return Arrays.stream(parties).filter(v -> v > 0).count();
	}
}
