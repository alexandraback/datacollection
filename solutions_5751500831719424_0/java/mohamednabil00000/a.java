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
		// BufferedReader in = new BufferedReader(new
		 //InputStreamReader(System.in));
		BufferedReader in = new BufferedReader(new FileReader(
				"A-small-attempt2.in"));
		StringBuilder q = new StringBuilder();
		// PrintWriter out = new PrintWriter(new
		// OutputStreamWriter(System.out));
		PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
		int n = Integer.parseInt(in.readLine());
		for (int i = 0; i < n; i++) {
			int k = Integer.parseInt(in.readLine());
			String a = in.readLine();
			String b = in.readLine();
		
			int ans = 0;
			ArrayList<node> one = new ArrayList();
			ArrayList<node> two = new ArrayList();
			int num = 1;
			for (int j = 1; j < a.length(); j++) {
				if (a.charAt(j) != a.charAt(j - 1)) {
					one.add(new node(num, a.charAt(j - 1)));
				//	System.out.println(num+" "+a.charAt(j-1));
					num = 1;
				} else
					num++;
			}

			one.add(new node(num, a.charAt(a.length() - 1)));
			num = 1;
			for (int j = 1; j < b.length(); j++) {
				if (b.charAt(j) != b.charAt(j - 1)) {
					two.add(new node(num, b.charAt(j - 1)));
					num = 1;
				} else
					num++;
			}

			two.add(new node(num, b.charAt(b.length() - 1)));
			

			out.print("Case #" + (i + 1) + ": ");
			if (one.size() != two.size()) {
				out.println("Fegla Won");
			} else {
				boolean flag = true;
				ans = 0;
				for (int j = 0; j < one.size(); j++) {
					if (one.get(j).val != two.get(j).val) {
						flag = false;
						break;
					} else {
						if (one.get(j).index != two.get(j).index)
							ans+=Math.abs(one.get(j).index-two.get(j).index);
					}
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