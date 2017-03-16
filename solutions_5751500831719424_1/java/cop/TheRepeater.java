package cop.google;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;
import java.util.regex.Pattern;

public class TheRepeater {
	private static final Pattern COMPILE = Pattern.compile(" ");

	public static void main(String... args) throws Exception {
//		run("test");
//		run("A-small-attempt0");
		run("A-large");
	}

	private static void run(String fileName) throws Exception {
		try (BufferedReader in = new BufferedReader(new FileReader(new File(fileName + ".in")));
		     BufferedWriter out = new BufferedWriter(new FileWriter(new File(fileName + ".out")))) {

			for (int i = 0, T = Integer.parseInt(in.readLine()); i < T; i++)
				write(out, gatData(in), i);
		}
	}

	private static String gatData(BufferedReader in) throws IOException {
		int N = Integer.parseInt(in.readLine());
		String[] arr = readArray(N, in);
		String[] uniques = new String[arr.length];

		for (int i = 0; i < N; i++)
			uniques[i] = unique(arr[i]);

		boolean res = true;

		for (String str : arr)
			res &= str.equals(arr[0]);

		if (res)
			return "0";

		for (String unique : uniques)
			if (!unique.equals(uniques[0]))
				return "Fegla Won";

		int[][] code = new int[N][];

		for (int i = 0; i < N; i++)
			code[i] = getCode(arr[i]);

		int res1 = 0;

		for (int i = 0, total = uniques[0].length(); i < total; i++) {
			int[] tmp = new int[N];
			int res2 = Integer.MAX_VALUE;
			boolean eq = true;

			for (int j = 0; j < N; j++)
				eq &= (tmp[j] = code[j][i]) == tmp[0];

			if (!eq) {
				for (int j = 0; j < N; j++) {
					int aa = 0;

					for (int k = 0; k < N; k++)
						aa += Math.abs(tmp[j] - tmp[k]);

					res2 = Math.min(res2, aa);
				}

				res1 += res2;
			}
		}

		return Integer.toString(res1);
	}

	private static String[] readArray(int N, BufferedReader in) throws IOException {
		String[] arr = new String[N];

		for (int i = 0; i < N; i++)
			arr[i] = in.readLine();

		return arr;
	}

	private static int[] getCode(String str) {
		List<Integer> values = new ArrayList<>();
		char prv = '\0';
		int count = 0;

		for (char ch : str.toCharArray()) {
			if (prv == '\0' || prv == ch)
				count++;
			else {
				values.add(count);
				count = 1;
			}

			prv = ch;
		}

		if (count > 0)
			values.add(count);

		int i = 0;
		int[] arr = new int[values.size()];

		for (Integer val : values)
			arr[i++] = val;

		return arr;
	}

	private static String unique(String str) {
		StringBuilder buf = new StringBuilder();

		for (char ch : str.toCharArray())
			if (buf.length() == 0 || buf.charAt(buf.length() - 1) != ch)
				buf.append(ch);

		return buf.toString();
	}

	private static void write(BufferedWriter out, String res, int i) throws IOException {
		if (i > 0)
			out.write("\n");

		String str = String.format("Case #%d: %s", i + 1, res);
		out.write(str);

		System.out.println(str);
	}
}
