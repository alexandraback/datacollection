import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		new A().run();
	}

	BufferedReader br;
	StringTokenizer in;
	PrintWriter out;

	public String nextToken() throws IOException {
		while (in == null || !in.hasMoreTokens()) {
			in = new StringTokenizer(br.readLine());
		}
		return in.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public void solve() throws IOException {
		int r1 = nextInt() - 1;
		boolean[] good = new boolean[16];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int v = nextInt() - 1;
				if (i == r1)
					good[v] = true;
			}
		}
		int r2 = nextInt() - 1;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int v = nextInt() - 1;
				if (i != r2)
					good[v] = false;
			}
		}

		int cnt = 0;
		int ans = 0;
		for (int i = 0; i < good.length; i++) {
			if (good[i]) {
				cnt++;
				ans = i + 1;
			}
		}

		if (cnt == 0) {
			out.println("Volunteer cheated!");
			return;
		}
		if (cnt > 1) {
			out.println("Bad magician!");
			return;
		}
		out.println(ans);
	}

	public void run() {
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");

			int t = nextInt();
			for (int i = 0; i < t; i++) {
				out.print(String.format("Case #%d: ", i + 1));
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
