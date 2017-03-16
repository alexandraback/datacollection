package R1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws IOException,
			FileNotFoundException {
		String file = "B-large";

		Scanner scan = new Scanner(new BufferedReader(new FileReader(file
				+ ".in")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(file
				+ ".out")));

		int T = Integer.parseInt(scan.nextLine());
		for (int t = 1; t <= T; t++) {
			String[] info = scan.nextLine().split(" ");
			int B = Integer.parseInt(info[0]);
			int N = Integer.parseInt(info[1]);
			info = scan.nextLine().split(" ");
			int[] num = new int[B];
			for (int i = 0; i < B; i++)
				num[i] = Integer.parseInt(info[i]);

			long left = -1, right = 1000000000000000L;
			while (left + 1 < right) {
				long mid = (left + right) / 2;
				long cnt = 0;
				for (int i = 0; i < B; i++)
					cnt += (mid + num[i]) / num[i];
				if (cnt >= N)
					right = mid;
				else
					left = mid;
			}

			int cnt = 0;
			for (int i = 0; i < B; i++)
				cnt += (right - 1 + num[i]) / num[i];
			for (int i = 0; i < B; i++) {
				if (right % num[i] == 0)
					cnt++;
				if (cnt == N) {
					pw.println("Case #" + t + ": " + (i + 1));
					break;
				}
			}

		}

		scan.close();
		pw.close();
	}

}
