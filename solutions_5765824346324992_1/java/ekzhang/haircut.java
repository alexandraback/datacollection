package gcj;

import java.io.*;
import java.util.*;

public class haircut {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(
				new FileReader("haircut.in"));
				//new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(
				new FileWriter("haircut.out")));
				//new OutputStreamWriter(System.out)));
		int t = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= t; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int b = Integer.parseInt(st.nextToken());
			int n = Integer.parseInt(st.nextToken());
			if (b == 1) {
				out.printf("Case #%d: 1\n", tc);
				continue;
			}
			int[] minutes = new int[b];
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < b; i++) {
				minutes[i] = Integer.parseInt(st.nextToken());
			}
			double avgSpeed = 0;
			for (int i = 0; i < b; i++) {
				avgSpeed += 1.0 / minutes[i];
			}
			n -= b;
			long timeBound = (long) Math.floor(n / avgSpeed);
			int[] times = new int[b];
			for (int i = 0; i < b; i++) {
				// put in the first few people with timeBound
				long div = timeBound / minutes[i];
				int mod = (int) (timeBound % minutes[i]);
				n -= div;
				times[i] = minutes[i] - mod;
			}
			if (n == 0) {
				out.printf("Case #%d: %d\n", tc, b);
				continue;
			}
			int ans = -1;
			while (true) {
				// find smallest time barber and do it as long as possible
				int smallest = times[0];
				int smallestIndex = 0;
				int second = times[1];
				if (smallest > second) {
					int temp = smallest;
					smallest = second;
					second = temp;
					smallestIndex = 1;
				}
				for (int i = 2; i < b; i++) {
					if (times[i] < smallest) {
						second = smallest;
						smallest = times[i];
						smallestIndex = i;
					}
					else if (times[i] < second) {
						second = times[i];
					}
				}
				int numTimes = (second - smallest - 1) / minutes[smallestIndex];
				if (numTimes < 0) numTimes = 0;
				n -= numTimes + 1;
				if (n <= 0) {
					ans = smallestIndex + 1;
					break;
				}
				int removing = smallest + minutes[smallestIndex] * numTimes;
				for (int i = 0; i < b; i++) {
					if (i == smallestIndex) {
						times[i] = minutes[i];
					}
					else {
						times[i] -= removing;
					}
				}
			}
			out.printf("Case #%d: %d\n", tc, ans);
		}
		out.flush();
		System.exit(0);
	}
	
}
