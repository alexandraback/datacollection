import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/B-large.in"))));

		String output = "";
		int t = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= t; i++) {
			int b = sc.nextInt();
			int n = sc.nextInt();
			int[] m = new int[b];
			for (int j = 0; j < b; j++) {
				m[j] = sc.nextInt();
			}
			long minute = binSearch(0, 100000000000000000l, m, n, b);
			long check = b;
			for (int j = 0; j < b; j++) {
				check += (minute-1)/m[j];
			}
			int barber = -1;
			for (int j = 0; j < b; j++) {
				if (minute%m[j]==0) {
					check++;
					if (check == n) {
						barber = j+1;
					}
				}
			}
			output += "Case #" + i + ": " + barber + "\n";
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/B-large.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
	
	public static long binSearch(long min, long max, int[] m, int n, int b) {
		if (min == max)
			return min;
		long mid = (min+max)/2;
		long check = b;
		for (int i = 0; i < b; i++) {
			check += mid/m[i];
		}
		if (check < n) {
			return binSearch(mid+1, max, m, n, b);
		} else {
			return binSearch(min, mid, m, n, b);
		}
	}
}