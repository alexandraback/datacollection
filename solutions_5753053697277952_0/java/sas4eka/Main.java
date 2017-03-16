import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader reader;
	static PrintWriter writer;
	static StringTokenizer tokenizer;

	static String task = "A-small";

	static String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	static int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}

	public static void main(String[] args) throws IOException {
		reader = new BufferedReader(new InputStreamReader(new FileInputStream(task + ".in")));
		writer = new PrintWriter(task + ".out");
		solve();
		reader.close();
		writer.close();
	}

	static void solve() throws NumberFormatException, IOException {
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			writer.print("Case #" + (i + 1) + ": ");
			banana();
		}
	}

	static void banana() throws NumberFormatException, IOException {
		int n = nextInt();
		ArrayList<Party> al = new ArrayList<>();
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int p = nextInt();
			Party pa = new Party();
			pa.num = p;
			pa.let = (char) ('A' + i);
			al.add(pa);
			sum += p;
		}
		String x = "";
		while (true) {
			Collections.sort(al);
			if (sum % 2 == 1) {
				al.get(n - 1).num = al.get(n - 1).num - 1;
				writer.print(x);
				writer.print(al.get(n - 1).let);
				sum--;
			} else {
				if (al.get(n - 1).num > 0 && al.get(n - 2).num > 0) {
					al.get(n - 1).num = al.get(n - 1).num - 1;
					al.get(n - 2).num = al.get(n - 2).num - 1;
					writer.print(x);
					writer.print(al.get(n - 1).let);
					writer.print(al.get(n - 2).let);
					sum -= 2;
				} else if (al.get(n - 1).num > 0) {
					al.get(n - 1).num = al.get(n - 1).num - 1;
					writer.print(x);
					writer.print(al.get(n - 1).let);
					sum--;
				} else {
					break;
				}
			}
			x = " ";
		}
		writer.println();
	}
}

class Party implements Comparable<Party> {
	int num;
	char let;

	@Override
	public int compareTo(Party o) {
		return Integer.compare(num, o.num);
	}
}
