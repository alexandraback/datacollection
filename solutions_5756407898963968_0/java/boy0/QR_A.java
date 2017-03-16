package boy0;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class QR_A {
	public static void main(String[] args) throws IOException {
		String strLine;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		QR_A me = new QR_A();

		// me.init();

		strLine = br.readLine();
		int T = Integer.parseInt(strLine);
		String[] as;
		int[] r1 = new int[4];
		int[] r2 = new int[4];
		String y;
		for (int x = 1; x <= T; x++) {
			// 1 round
			strLine = br.readLine();
			int row1 = Integer.parseInt(strLine);
			for (int i = 1; i <= 4; i++) {
				strLine = br.readLine();
				if (i == row1) {
					as = strLine.split(" ");
					for (int j = 0; j < as.length; j++) {
						r1[j] = Integer.parseInt(as[j]);
					}
				}
			}
			// 2 round
			strLine = br.readLine();
			int row2 = Integer.parseInt(strLine);
			for (int i = 1; i <= 4; i++) {
				strLine = br.readLine();
				if (i == row2) {
					as = strLine.split(" ");
					for (int j = 0; j < as.length; j++) {
						r2[j] = Integer.parseInt(as[j]);
					}
				}
			}
			y = me.exec1(r1, r2);
			System.out.println("Case #" + x + ": " + y);
		}
	}

	private int priv_length = 0;

	public void init() {

	}

	public String exec1(int[] r1, int[] r2) {
		String y = "";
		int match_count = 0;

		for (int i = 0; i < r1.length; i++) {
			for (int j = 0; j < r2.length; j++) {
				if (r1[i] == r2[j]) {
					match_count++;
					if (match_count == 1) {
						y = String.valueOf(r1[i]);
					}
				}
			}
		}

		if (match_count == 0) {
			y = "Volunteer cheated!";
		} else if (match_count > 1) {
			y = "Bad magician!";
		}

		return y;
	}

	private boolean func_priv(int offset) {
		return true;
	}

}
