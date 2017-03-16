package qa;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class QA {

	public static void main(String[] args) {
		(new QA()).go();
	}

	boolean debug = true;
	String line = null;
	String ret = null;
	int caseId = 0;

	public void print(String p) {
		if (debug)
			System.out.println(p);
	}

	LinkedList<Integer> list = new LinkedList<Integer>();

	private void go() {

		BufferedReader in = null;
		PrintWriter pw = null;
		StringTokenizer tk = null;
		int row[][];
		int result;

		try {
			in = new BufferedReader(new FileReader("A-small-attempt0.in"));
			pw = new PrintWriter(new FileWriter("output.txt"));

			int cases = Integer.parseInt(in.readLine());

			for (caseId = 0; caseId < cases; caseId++) {

				row = new int[2][4];
				result = -1;

				for (int p = 0; p < 2; p++) {
					line = in.readLine();
					int pick = Integer.parseInt(line);

					for (int i = 0; i < 4; i++) {
						line = in.readLine();
						if (i == (pick - 1)) {
							print(line);
							tk = new StringTokenizer(line, " ");

							for (int t = 0; t < 4; t++) {
								row[p][t] = Integer.parseInt(tk.nextToken());

							}
						}
					}
				}

				for (int i = 0; i < 4; i++) {
					for (int t = 0; t < 4; t++) {
						if (row[0][t] == row[1][i]) {
							if (result == -1) {
								result = row[0][t];
								break;
							} else {
								result = -2;
								break;
							}

						}
					}
					if (result == -2)
						break;

				}

				if (result == -1) {
					ret = "Volunteer cheated!";
				} else if (result == -2) {
					ret = "Bad magician!";
				} else {
					ret = "" + result;
				}

				System.out.println("Case #" + (caseId + 1) + ": " + ret);
				pw.println("Case #" + (caseId + 1) + ": " + ret);

			}
			in.close();
			pw.flush();
			pw.close();
		} catch (Exception e) {
			System.out.println("Main Loop Exception");
			e.printStackTrace();
		}
	}
}
