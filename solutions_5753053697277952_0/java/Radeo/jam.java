import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class jam {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int cases = sc.nextInt();
		for (int i = 0; i < cases; i++) {
			System.out.println("Case #" + (i + 1));
			pw.print("Case #" + (i + 1) + ": ");
			solve(sc, pw);
			pw.println("");
		}
		pw.flush();
		pw.close();
		sc.close();
		System.out.println("DONE");

	}

	static void solve(Scanner sc, PrintWriter pw) {
		int N = sc.nextInt();
		int[] arr = new int[27];
		int s = 0;

		int i1 = 0, i2 = 0, max1 = 0, max2 = 0;
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < N; i++) {
			arr[i] = sc.nextInt();
			s += arr[i];
		}
		while (s > 0) {
			max1 = 0;
			max2 = 0;
			for (int i = 0; i < N; i++) {
				if (arr[i] >= max2) {
					if (arr[i] >= max1) {
						i2 = i1;
						max2 = max1;
						i1 = i;
						max1 = arr[i];
					} else {
						i2 = i;
						max2 = arr[i];
					}
				}
			}
			//
			sb.append((char) (i1 + 65));
			arr[i1]--;
			s--;
			if (s != 2) {
				sb.append((char) (i2 + 65));
				arr[i2]--;
				s--;
			}
			sb.append(" ");
		}

		pw.print(sb.toString());
	}
}
