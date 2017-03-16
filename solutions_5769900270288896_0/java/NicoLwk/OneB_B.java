import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class OneB_B {
	public static void main(String[] args) throws IOException {
		Scanner sc2 = new Scanner(System.in);
		String inFile = sc2.nextLine();
		String outFile = inFile + ".out.txt";
		FileReader fr = new FileReader(inFile);
		Scanner sc = new Scanner(new BufferedReader(fr));
		FileWriter fw = new FileWriter(outFile);
		BufferedWriter bw = new BufferedWriter(fw);
		PrintWriter pw = new PrintWriter(bw);
		int T = sc.nextInt();
		for (int i = 0; i < T; i++)
			new Case(sc, pw, i + 1);
		sc.close();
		pw.close();
	}

	static class Case {
		int R, C, N;

		Case(Scanner sc, PrintWriter pw, int caseNo) {
			R = sc.nextInt();
			C = sc.nextInt();
			N = sc.nextInt();
			int cases = 1 << R * C;
			System.out.println(cases);
			int best = -1;
			boolean grid[][] = new boolean[R][C];
			for (int i = 0; i < cases; i++) {
				int tmp = 1, count = 0;
				for (int j = 0; j < R; j++) {
					for (int k = 0; k < C; k++) {
						boolean b = (i & tmp) > 0;
						grid[j][k] = b;
						if (b)
							count++;
						tmp <<= 1;
					}
				}
				if (count != N)
					continue;
				System.out.println("i=" + i);
				int unhap = 0;
				for (int j = 0; j < R; j++) {
					for (int k = 0; k < C - 1; k++) {
						if (grid[j][k] && grid[j][k + 1])
							unhap++;
					}
				}
				for (int j = 0; j < R - 1; j++) {
					for (int k = 0; k < C; k++) {
						if (grid[j][k] && grid[j + 1][k])
							unhap++;
					}
				}
				if (best == -1 || unhap < best)
					best = unhap;
			}
			pw.println("Case #" + caseNo + ": " + best);
			System.out.println("Case #" + caseNo + ": " + best);
		}
	}
}
