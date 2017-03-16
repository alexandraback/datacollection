package codejam.round1c;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class A {

	private static final String FILE = "C:\\temp\\A-small-attempt0";

	//////////////////////////////////////////////////
	private static void decreaseCount(Map<Character, Integer> senators, Map.Entry<Character, Integer> max) {

		if (max.getValue() == 1) {
			senators.remove(max.getKey());
			return;
		}
		senators.put(max.getKey(), max.getValue() - 1);
	}

	//////////////////////////////////////////////////
	private static String removeMax(Map<Character, Integer> senators) {

		Map.Entry<Character, Integer> max1 = null;
		Map.Entry<Character, Integer> max2 = null;
		Map.Entry<Character, Integer> max3 = null;

		for (Map.Entry<Character, Integer> entry : senators.entrySet()) {
			if (max1 == null || max1.getValue() < entry.getValue()) {
				max1 = entry;
				max2 = null;
				max3 = null;
				continue;
			}
			if (max1.getValue() == entry.getValue() && max2 == null) {
				max2 = entry;
				continue;
			}
			if (max1.getValue() == entry.getValue()) {
				max3 = entry;
			}
		}

		if (max3 != null) {
			max2 = null;
		}

		StringBuffer res = new StringBuffer();
		res.append(max1.getKey());
		decreaseCount(senators, max1);
		if (max2 != null) {
			res.append(max2.getKey());
			decreaseCount(senators, max2);
		}
		return res.toString();
	}

	//////////////////////////////////////////////////
	public static void main(String[] args) throws Exception {

		Scanner in = null;
		PrintStream out = null;

		try {

			in = new Scanner(new BufferedReader(new FileReader(new File(FILE + ".in"))));
			out = new PrintStream(new File(FILE + ".out"));

			// in = new Scanner(new BufferedReader(new
			// InputStreamReader(System.in)));
			// out = System.out;

			int t = in.nextInt();
			// Finish the line.
			in.nextLine();
			for (int i = 1; i <= t; ++i) {
				int parties = in.nextInt();
				Map<Character, Integer> senators = new HashMap<>(parties);
				for (int j = 0; j < parties; j++) {
					senators.put((char) ('A' + j), in.nextInt());
				}
				StringBuilder sb = new StringBuilder();
				while (!senators.isEmpty()) {
					if (sb.length() != 0) {
						sb.append(' ');
					}
					sb.append(removeMax(senators));
				}
				out.println("Case #" + i + ": " + sb.toString());
			}
		} finally {
			if (in != null) {
				in.close();
			}
			if (out != null) {
				out.close();
			}
		}
	}
}
