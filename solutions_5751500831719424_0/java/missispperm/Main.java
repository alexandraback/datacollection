import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.*;
import java.util.Map.Entry;

public class Main {
	public static void main(String[] args) throws IOException {
		(new Main()).solve();
	}

	public Main() {
	}
	
	//MyReader in = new MyReader();
	//PrintWriter out = new PrintWriter(System.out);
	
	void solve() throws IOException {
		//BufferedReader in = new BufferedReader(new
		//InputStreamReader(System.in));
		//Scanner in = new Scanner(System.in);
		Scanner in = new Scanner(new FileReader("input.txt"));
		PrintWriter out = new PrintWriter("output.txt");
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			int n = in.nextInt();
			String[] a = new String[n];
			for (int j = 0; j < n; j++) {
				a[j] = in.next();
			}
			int[] ind = new int[n];
			int[] num = new int[n];
			boolean flag = true;
			int count = 0;
			while (flag && ind[0] < a[0].length()) {
				char ch = a[0].charAt(ind[0]);
				int min = Integer.MAX_VALUE;
				int max = 0;
				boolean end = false;
				for (int j = 0; j < n; j++) {
					int curInd = ind[j];
					while (curInd < a[j].length() && a[j].charAt(curInd) == ch) {
						curInd++;
					}
					num[j] = curInd - ind[j];
					ind[j] = curInd;
					if (num[j] == 0) {
						flag = false;
						break;
					}
					if (curInd == a[j].length()) {
						end = true;
					}
					if (num[j] < min) {
						min = num[j];
					}
					if (num[j] > max) {
						max = num[j];
					}
				}
				if (flag) {
					for (int j = 0; j < n; j++) {
						if (end && ind[j] != a[j].length()) {
							flag = false;
							break;
						}
					}
				}
				int best = Integer.MAX_VALUE;
				for (int j = min; j <= max; j++) {
					int cur = 0;
					for (int k = 0; k < n; k++) {
						cur += Math.abs(j - num[k]);
					}
					if (cur < best) {
						best = cur;
					}
				}
				count += best;
			}
			out.print("Case #" + (i + 1) + ": ");
			out.println(flag ? count : "Fegla Won");
		}
		out.close();
	}
	
	class MyReader {
		private BufferedReader in;
		String[] parsed;
		int index = 0;

		public MyReader() {
			in = new BufferedReader(new InputStreamReader(System.in));
		}

		public int nextInt() throws NumberFormatException, IOException {
			if (parsed == null || parsed.length == index) {
				read();
			}
			return Integer.parseInt(parsed[index++]);
		}

		public long nextLong() throws NumberFormatException, IOException {
			if (parsed == null || parsed.length == index) {
				read();
			}
			return Long.parseLong(parsed[index++]);
		}
		
		public double nextDouble() throws NumberFormatException, IOException {
			if (parsed == null || parsed.length == index) {
				read();
			}
			return Double.parseDouble(parsed[index++]);
		}
		
		public String nextString() throws IOException {
			if (parsed == null || parsed.length == index) {
				read();
			}
			return parsed[index++];
		}

		private void read() throws IOException {
			parsed = in.readLine().split(" ");
			index = 0;
		}

		public String readLine() throws IOException {
			return in.readLine();
		}
		
		public int read(char[] cbuf) throws IOException {
			return in.read(cbuf);
		}
	}

};