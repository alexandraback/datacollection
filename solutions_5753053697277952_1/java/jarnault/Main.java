package CodeJam.CJ2016R1C_1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
	private static InputReader in;
	private static PrintWriter out;
	public static boolean SUBMIT = true;
	public static final String NAME = "./src/CodeJam/CJ2016R1C_1/A-large";

	private static void main2()throws IOException{
		int n = in.nextInt();
		int[]  arr = new int[n];
		int tot = 0;
		for (int i = 0 ; i < n ; i++){
			arr[i] = in.nextInt();
			tot += arr[i];
		}

		while(tot > 0){
			int max = 0;
			int indexMax = 0;
			for (int i = 0 ; i < n ; i++){
				if (arr[i] > max){
					max = arr[i];
					indexMax = i;
				}
			}
			out.print((char) (indexMax + 65));
			arr[indexMax]--;
			tot--;
			if (tot != 2){
				int max2 = 0;
				int indexMax2 = 0;
				for (int i = 0 ; i < n ; i++){
					if (arr[i] > max2){
						max2 = arr[i];
						indexMax2 = i;
					}
				}
				out.print((char) (indexMax2 + 65) + " ");
				arr[indexMax2]--;
				tot--;
			}else{
				out.print(" ");
			}
		}
		out.println();

	}


	public static void main(String[] args) throws IOException {
		in = new InputReader(new FileInputStream(new File(NAME + ".in")));
		if (SUBMIT) {
			out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));
		} else {
			out = new PrintWriter(System.out, true);
		}

		int numCases = in.nextInt();
		for (int test = 1; test <= numCases; test++) {
			out.print("Case #" + test + ": ");
			main2();
		}

		out.close();
		System.exit(0);
	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while ((tokenizer == null) || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}
