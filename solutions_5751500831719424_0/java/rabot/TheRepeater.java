package gcj2014r1b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;

public class TheRepeater {
	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		TheRepeater obj = new TheRepeater();
		obj.solve(fileName);
	}

	public void solve(String fileName) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(fileName));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(fileName + ".out"));

		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			String str = br.readLine();
			int N = Integer.parseInt(str);

			String[] list = new String[N];
			for (int j = 0; j < N; j++) {
				list[j] = br.readLine();
			}
			String norm = "";
			int total = -1;
			boolean flg = true;
			int[][] nums = new int[N][200];
			for (int j = 0; j < N; j++) {
				char last = '*';
				int idx = -1;
				for (int k = 0; k < list[j].length(); k++) {
					if (last != list[j].charAt(k)) {
						idx += 1;
						if (j != 0) {
							if (norm.length() <= idx
									|| norm.charAt(idx) != list[j].charAt(k)) {
								flg = false;
								break;
							}
						} else {
							norm += list[j].charAt(k);
							total += 1;
						}
						last = list[j].charAt(k);
					}
					nums[j][idx] += 1;
				}
				if (total != idx) {
					flg = false;
				}
				if (flg == false) {
					break;
				}
			}

			int ans = 0;
			for (int j = 0; j <= total; j++) {
				int[] calc = new int[N];
				for (int k = 0; k < N; k++) {
					calc[k] = nums[k][j];
				}
				Arrays.sort(calc);
				int mid = calc[N / 2];
				for (int k = 0; k < N; k++) {
					ans += Math.abs(mid - calc[k]);
				}
			}

			if (flg == false) {
				bw.write("Case #" + (i + 1) + ": " + "Fegla Won");
			} else {
				bw.write("Case #" + (i + 1) + ": " + ans);
			}
			bw.write("\r\n");
		}
		bw.close();
		br.close();
	}
}
