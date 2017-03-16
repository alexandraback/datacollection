import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class A2 {
	public static void main(String[] args) throws IOException {
		BufferedReader buf = new BufferedReader(new FileReader("A-small-attempt1.in"));
		PrintWriter writer = new PrintWriter("A-small.out");
		int tCases = Integer.parseInt(buf.readLine());
		for (int t = 1; t <= tCases; t++) {
			int n = Integer.parseInt(buf.readLine());
			char[][] c = new char[n][];
			for (int i = 0; i < c.length; i++)
				c[i] = buf.readLine().toCharArray();
			ArrayList<Integer> rank1 = new ArrayList<>();

			for (int j = 0; j < c[0].length; j++) {
				int x = c[0][j];
				rank1.add(x);
				while (j < c[0].length && c[0][j] == x)
					j++;
				j--;
			}
			ArrayList<Integer>[] freq = new ArrayList[rank1.size()];
			for (int i = 0; i < freq.length; i++)
				freq[i] = new ArrayList<Integer>();
			boolean check = true;
			for (int i = 1; i < n; i++) {
				ArrayList<Integer> rank2 = new ArrayList<Integer>();
				for (int j = 0; j < c[i].length; j++) {
					int x = c[i][j];
					rank2.add(x);
					while (j < c[i].length && c[i][j] == x)
						j++;
					j--;
				}
				if (rank1.size() != rank2.size()) {
					check = false;
					break;
				}
				for (int j = 0; j < rank1.size() && check; j++)
					if (rank1.get(j) != rank2.get(j))
						check = false;
			}
			if (!check) {
				writer.printf("Case #%d: Fegla Won\n", t);
			} else {
				for (int i = 0; i < n; i++) {
					int index = 0;
					for (int j = 0; j < c[i].length; j++) {
						int x = c[i][j];
						int cnt = 0;
						while (j < c[i].length && c[i][j] == x) {
							j++;
							cnt++;
						}
						j--;
						freq[index++].add(cnt);
					}
				}
				int tot = 0;
				for (int i = 0; i < freq.length; i++) {
					int min = Integer.MAX_VALUE;
					for (int j = 1; j <= 100; j++) {
						int current = 0;
						for (int k = 0; k < freq[i].size(); k++)
							current += Math.abs(j - freq[i].get(k));
						min = Math.min(min, current);
					}
					tot += min;
				}
				writer.printf("Case #%d: %d\n", t, tot);
			}
		}
		writer.close();
	}

}
