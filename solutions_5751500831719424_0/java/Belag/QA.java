package blah;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class QA {
	public static void main(String[] Args) throws IOException {
		Scanner sc = new Scanner(new FileReader("A-small-attempt2.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));

		int caseCnt = sc.nextInt();
		sc.nextLine();

		// Case number
		for (int caseNum = 1; caseNum <= caseCnt; caseNum++) {
			pw.write("Case #" + caseNum + ": ");
			System.out.println(caseNum);
			int N = sc.nextInt();
			String[] string = new String[N];
			for (int i = 0; i < N; i++) {
				string[i] = sc.next();
			}
			int[] indices = new int[N];
			Arrays.fill(indices, 0);
			boolean ok = true;
			int charCount = 0;
			while (ok && !isOver(indices, string)) {
				if (indices[0] >= string[0].length()) {
					ok = false;
					break;
				}
				charCount++;
				char c = string[0].charAt(indices[0]);
				for (int i = 0; i < N; i++) {
					if (indices[i] >= string[i].length()
							|| string[i].charAt(indices[i]) != c)
						ok = false;
					while (indices[i] < string[i].length()
							&& string[i].charAt(indices[i]) == c)
						indices[i]++;
				}
			}
			if (ok) {
				int result = 0;
				Arrays.fill(indices, 0);
				int[][] numberOfChar = new int[N][charCount];
				for (int i = 0; i < charCount; i++) {
					for (int j = 0; j < N; j++) {
						char c = string[j].charAt(indices[j]);
						while (indices[j] < string[j].length()
								&& string[j].charAt(indices[j]) == c) {
							numberOfChar[j][i]++;
							indices[j]++;
						}
					}
				}
				for (int i = 0; i < charCount; i++) {
//					for (int j = 0; j < N; j++) {
						result += Math.abs(numberOfChar[0][i] - numberOfChar[1][i]);
//					}
				}
				System.out.println(result);
				pw.print(result);
			} else {
				pw.print("Fegla Won");
				System.out.println("Fegla Won");
			}
			pw.print("\n");
		}

		pw.flush();
		pw.close();
		sc.close();
	}

	private static boolean isOver(int[] indices, String[] string) {
		for (int i = 0; i < indices.length; i++) {
			if (indices[i] != string[i].length())
				return false;
		}
		return true;
	}

}
