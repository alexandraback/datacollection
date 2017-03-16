package gcj2014.b1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Date;

public class a {
	public static void main(String[] args) {
//		readAndSolve("resource/gcj2014/b1/a/sample.in",
//				"resource/gcj2014/b1/a/sample.out");
		 readAndSolve("resource/gcj2014/b1/a/A-small-attempt1.in", "resource/gcj2014/b1/a/A-small-attempt1.out");
		 readAndSolve("resource/gcj2014/b1/a/A-large.in", "resource/gcj2014/b1/a/A-large.out");
	}

	/**
	 * @param inputName
	 * @param outputName
	 */
	private static void readAndSolve(String inputName, String outputName) {
		BufferedReader input = null;
		BufferedWriter output = null;
		Date d1 = new Date();
		try {
			input = new BufferedReader(new FileReader(inputName));
			output = new BufferedWriter(new FileWriter(outputName));
			String line1 = null;
			String line2 = null;
			String[] line3 = null;
			int expectedCases = 0;
			int actualCase = -1;
			line1 = input.readLine();
			expectedCases = Integer.parseInt(line1);
			for (actualCase = 1; actualCase <= expectedCases; actualCase++) {
				line2 = input.readLine();
				int stringCount = Integer.parseInt(line2);
				line3 = new String[stringCount];
				for (int i = 0; i < stringCount; i++) {
					line3[i] = input.readLine();
				}
				String result = solve(line3);
				output.write("Case #" + actualCase + ": " + result + "\n");
				System.out.println("Case #" + actualCase + ": " + result);
			}
			input.close();
			output.close();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {

		}
	}

	private static String solve(String[] line3) {
		int result = 0;
		while (line3[0].length() > 0) {
			String actc = line3[0].substring(0, 1);
			int[] actl = new int[line3.length];
			int minLength = Integer.MAX_VALUE;
			int maxLength = 0;
			for (int i = 0; i < line3.length; i++) {
				if (line3[i].length() == 0 || !actc.equals(line3[i].substring(0,1))) {
					return "Fegla Won";
				}
				actl[i] = 0;
				for (int j = 0; j < line3[i].length() && actc.equals(line3[i].substring(j, j+1)) ; j++) {
					actl[i]++;
				}
				line3[i] = line3[i].substring(actl[i]);
				if (minLength > actl[i]) {
					minLength = actl[i];
				}
				if (maxLength < actl[i]) {
					maxLength = actl[i];
				}
			}
			int actMinRes = Integer.MAX_VALUE;
			for (int i = minLength; i<=maxLength; i++ ){
				int actRes = 0;
				for (int j = 0; j < actl.length; j++) {
					actRes += Math.abs(i-actl[j]);
				}
				if (actMinRes > actRes) {
					actMinRes = actRes;
				}
			}
			result += actMinRes;
		}
		for (int i = 0; i < line3.length; i++) {
			if (line3[i].length()>0) {
				return "Fegla Won";
			}
		}
		return Integer.toString(result);
	}

	private static String reduce(String string) {
		StringBuffer r = new StringBuffer(string.length());
		String actc = string.substring(0, 1);
		r.append(actc);
		for (int i = 2; i <= string.length(); i++) {
			if (!actc.equals(string.substring(i - 1, i))) {
				actc = string.substring(i - 1, i);
				r.append(actc);
			}
		}
		String result = r.toString();
		return result;
	}

}
