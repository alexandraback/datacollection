import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class a {
	public static class node implements Comparable<node> {
		int index;
		int val;

		node(int index, int val) {
			this.index = index;
			this.val = val;
		}

		@Override
		public int compareTo(node o) {
			if (o.val < val)
				return 1;
			else if (o.val > val)
				return -1;
			else if (o.index < index)
				return 1;
			else
				return -1;
		}

	}

	public static void main(String[] args) throws IOException {
		//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		 BufferedReader in = new BufferedReader(new FileReader(
		 "A-large.in"));
		StringBuilder q = new StringBuilder();
		//PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		 PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
		int n = Integer.parseInt(in.readLine());
		for (int i = 0; i < n; i++) {
			int k = Integer.parseInt(in.readLine());
			String a[] = new String[k];
			for (int j = 0; j < a.length; j++) {
				a[j] = in.readLine();
			}

			int ans = 0;
			ArrayList<node> one[] = new ArrayList[k];
			for (int j = 0; j < k; j++) {
				one[j] = new ArrayList();
			}
			for (int j = 0; j < k; j++) {
				int num = 1;
				for (int l = 1; l < a[j].length(); l++) {
					if (a[j].charAt(l) != a[j].charAt(l - 1)) {
						one[j].add(new node(num, a[j].charAt(l - 1)));
						num = 1;
					} else
						num++;
				}

				one[j].add(new node(num, a[j].charAt(a[j].length() - 1)));
			}

			out.print("Case #" + (i + 1) + ": ");
			boolean flag = true;
			for (int j = 1; j < one.length; j++) {
				if (one[j].size() != one[j - 1].size()) {
					flag = false;
					break;
				}
			}

			if (flag) {
				for (int j = 0; j < one[0].size(); j++) {
					for (int j2 = 1; j2 < k; j2++) {
						if (one[j2 - 1].get(j).val != one[j2].get(j).val) {
							flag = false;
							break;
						}
					}
					if (!flag)
						break;
				}
			}

			if (!flag) {
				out.println("Fegla Won");
			} else {
				ans = 0;
				int sum = 0;

				for (int j = 0; j < one[0].size(); j++) {
					int min = Integer.MAX_VALUE;
					for (int j2 = 0; j2 < k; j2++) {
						sum = 0;
						for (int l = 0; l < k; l++) {
							sum += Math.abs(one[j2].get(j).index
									- one[l].get(j).index);
						}
						min = Math.min(sum, min);

					}

					ans += min;

				}

				if (!flag)
					out.println("Fegla Won");
				else
					out.println(ans);

			}

		}

		out.close();

	}
}