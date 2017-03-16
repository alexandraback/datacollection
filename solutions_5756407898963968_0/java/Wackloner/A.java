import java.io.*;
import java.util.*;

public class A implements Runnable {
	
	private void solve() throws IOException {
		int t = nextInt();
		for (int testNumber = 1; testNumber <= t; testNumber++) {
			int firstAnswer = nextInt();
			int[][] firstArrangement = new int[4][4];
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					firstArrangement[i][j] = nextInt();
			int secondAnswer = nextInt();
			int[][] secondArrangement = new int[4][4];
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					secondArrangement[i][j] = nextInt();
			ArrayList<Integer> matches = new ArrayList<Integer>();
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					if (firstArrangement[firstAnswer - 1][i] == secondArrangement[secondAnswer - 1][j])
						matches.add(firstArrangement[firstAnswer - 1][i]);
			print("Case #");
			print(testNumber);
			print(": ");
			switch (matches.size()) {
			case 0:
				println("Volunteer cheated!");
				break;
			case 1:
				println(matches.get(0));
				break;
			default:
				println("Bad magician!");
				break;
			}
		}
	}
	
	public static void main(String[] args) {
		new A().run();
	}
	
	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;
	
	public void run() {
		try {
			String file = "";
//			file = "console";
			if (file.equals("console")) {
				reader = new BufferedReader(new InputStreamReader(System.in));
				writer = new PrintWriter(System.out);
			} else if (file.equals("")) {
				reader = new BufferedReader(new FileReader(new File("input.txt")));
				writer = new PrintWriter(new File("output.txt"));
			} else {
				reader = new BufferedReader(new FileReader(new File(file + ".in")));
				writer = new PrintWriter(new File(file + ".out"));
			}
			solve();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(261);
		}
	}
	
	void halt() {
		writer.close();
		System.exit(0);
	}
	
	void print(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0) writer.print(' ');
			writer.print(objects[i]);
		}
	}
	
	void println(Object... objects) {
		print(objects);
		writer.println();
	}
	
	String nextLine() throws IOException {
		return reader.readLine();
	}
	
	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens())
			tokenizer = new StringTokenizer(nextLine());
		return tokenizer.nextToken();
	}
	
	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}
	
	long nextLong() throws NumberFormatException, IOException {
		return Long.parseLong(nextToken());
	}
	
	double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(nextToken());
	}
}