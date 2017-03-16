
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;
import java.math.*;

/**
 * @author Xing Liu
 * 
 *         Google code jam 2014 template.
 **/
public class A {
	// competition logic !
	private String getResult(int N, String[] tks) {

		String can = null;
		char[] in = null;
		StringBuffer tmp = new StringBuffer();
		char c = '\0';

		// get cannonical form.
		can = getCan(tks[0]);
		int[][] repeat = new int[N][can.length()];

		for (int n = 0; n < N; n++) {
			if (!getCan(tks[n]).equals(can)) {
				return "Fegla Won";
			}
			c = '\0';
			int ct = -1;

			// get repeat information.
			for (int i = 0; i < tks[n].length(); i++) {
				if (c != tks[n].charAt(i)) {
					ct++;
					c = tks[n].charAt(i);
					repeat[n][ct] = 1;

				} else {
					repeat[n][ct]++;
				}
			}
		}

		// process repeat info.
		int result = 0;
		int[] sort = new int[N];// size N array.

		for (int l = 0; l < can.length(); l++) {
			// get min max.
			for (int n = 0; n < N; n++) {
				sort[n] = repeat[n][l];
			}
			Arrays.sort(sort);

			int sum = 0;
			int minsum = 0;

			for (int n = 0; n < N; n++) {
				minsum += Math.abs(sort[0] - sort[n]);
			}

			for (int i = sort[0] + 1; i <= sort[N-1]; i++) {
				sum = 0;
				for (int n = 0; n < N; n++) {
					sum += Math.abs(i - sort[n]);
				}

				if (sum < minsum) {
					minsum = sum;
				} else {
					break;
				}
			}
			result += minsum;
		}

		return String.valueOf(result);
	}

	private static String getCan(String in) {
		StringBuffer tmp = new StringBuffer();
		char c = '\0';
		char t ;
		for (int i = 0; i < in.length(); i++) {
			t= in.charAt(i);
			if (t != c) {
				tmp.append(t);
				c = t;
			}
		}

		return tmp.toString();
	}

	public static void main(String[] args) throws Exception {

		A me = new A();
		FileReader fr = new FileReader("A-small-attempt0.in");
		BufferedReader br = new BufferedReader(fr);
		FileWriter fw = new FileWriter("out");
		BufferedWriter bw = new BufferedWriter(fw);
		String result = null;

		int T = Integer.valueOf(br.readLine());
		int N = 0;
		String[] tks = null;
		for (int t = 1; t <= T; t++) {

			N = Integer.valueOf(br.readLine());
			tks = new String[N];
			for (int n = 0; n < N; n++) {
				tks[n] = br.readLine();
			}
			System.out.println("Case : " + t);
			bw.write("Case #" + t + ": " + me.getResult(N, tks));
			bw.write('\n');
		}

		br.close();
		fr.close();
		bw.close();
		fw.close();
	}

	// ================================================
	// helper functions.
	private int[] getIntTokens(String line) {
		String[] tokens = line.split(" +");

		int[] result = new int[tokens.length];
		for (int i = 0; i < tokens.length; i++) {
			result[i] = Integer.valueOf(tokens[i]);
		}
		return result;
	}

	private String[] getTokens(String line) {
		return line.split(" +");
	}

}
