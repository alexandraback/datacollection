import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class GCJR1 {

	private static int max(int[] a) {
		int m = 0;
		for (int i = 1; i < a.length; ++i)
			if (a[m] < a[i])
				m = i;
		return m;
	}

	public static void main(String[] args) throws Exception {
		Scanner cin = new Scanner(new FileInputStream("A-small-attempt0 (2).in"));
		PrintWriter cout = new PrintWriter(new FileOutputStream("output.txt"));
		int T = cin.nextInt();
		for (int t = 0; t < T; ++t) {
			int N = cin.nextInt();
			int[] a = new int[N];
			int sum = 0;
			for (int i = 0; i < N; ++i)
				sum += a[i] = cin.nextInt();
			int ind1 = -1, ind2 = -1;
			cout.print("Case #" + (t + 1) + ": ");
			while (sum > 0) {
				if (ind1 == -1) {
					int m = max(a);
					for (int i = 0; i < N; ++i)
						if (i != m && a[i] == a[m]) {
							ind1 = i;
							ind2 = m;
							break;
						}
				}
				if (ind1 != -1) {
					int fnd = -1;
					for (int i = 0; i < N; ++i)
						if (i != ind1 && i != ind2 && a[i] > 0) {
							fnd = i;
							break;
						}
					if (fnd != -1) {
						cout.print((char) ('A' + fnd) + " ");
						a[fnd]--;
						sum--;
					} else {
						cout.print((char) ('A' + ind1) + "" + (char) ('A' + ind2) + " ");
						sum -= 2;
						a[ind1]--;
						a[ind2]--;
					}
				} else {
					int m = max(a);
					cout.print((char) ('A' + m) + " ");
					sum--;
					a[m]--;
				}
			}
			cout.println();
		}
		cout.flush();
	}

}
