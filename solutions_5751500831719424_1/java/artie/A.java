import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;


public class A {

	public static void main(String[] args) throws Exception {
		new A().run();
	}
	
	int n;

	private void run() throws Exception {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new File("src\\input.txt"));
		PrintWriter pw = new PrintWriter("output.txt");
		int tc = sc.nextInt();
		String[] s = new String[100];
		char[][] c = new char[100][100];
		int[][] cnt = new int[100][100];
		int[] num = new int[100];
		for (int t = 1; t <= tc; t++) {
			n = sc.nextInt();
			for (int i = 0; i < n; i++) {
				s[i] = sc.next();
				char[] tmp = s[i].toCharArray();
				int ind = 0;
				num[i] = 0;
				while (ind < tmp.length) {
					int j = ind;
					while (j < tmp.length && tmp[ind] == tmp[j])
						j++;
					c[i][num[i]] = tmp[ind];
					cnt[i][num[i]] = j - ind;
					num[i]++;
					ind = j;
				}
			}		
			boolean can = true;
			for (int i = 0; i < n; i++) {
				String si = new String(c[i], 0, num[i]);
				for (int j = i + 1; j < n; j++) {
					String sj = new String(c[j], 0, num[j]);
					if (!si.equals(sj))
						can = false;
				}
			}
			if (can) {
				int res = 0;
				for (int i = 0; i < num[0]; i++) {
					int best = Integer.MAX_VALUE;
					for (int j = 1; j <= 100; j++) {
						int cur = 0;
						for (int k = 0; k < n; k++)
							cur += Math.abs(cnt[k][i] - j);
						best = Math.min(best, cur);
					}
					res += best;
				}
				pw.printf("Case #%d: %d\n", t, res);
			} else {
				pw.printf("Case #%d: Fegla Won\n", t);
			}
		}
		pw.close();
		sc.close();
	}

}
