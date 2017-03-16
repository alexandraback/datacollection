import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class B12014A {

	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;

	public static void main(String[] args) throws IOException {
		// Initializing ...
		new B12014A();
		// -------------------------------------------------------------------------
		int testCases = nextInt();
		int counter = 0;
		while (testCases-- > 0) {
			counter++;
			// Here put the code..:)

			int n = nextInt();
			s = new char[n][];
			for (int i = 0; i < s.length; i++) {
				s[i] = nextString().toCharArray();
			}
			if (can()) {
				int ret = 0;
				int [] index = new int[n];
				while(!finished(index)){
					char now = s[0][index[0]];
					int [] numbers = new int[n];
					for (int i = 0; i < index.length; i++) {
						while(s[i][index[i]]==now){
							index[i]++;numbers[i]++;
							if(index[i] == s[i].length) break;
						}
					}
					ret += norm(numbers);
				}
				writeln("Case #" + counter + ": "+ret);
			} else
				writeln("Case #" + counter + ": Fegla Won");
		}
		// -------------------------------------------------------------------------
		// closing up
		end();
		// --------------------------------------------------------------------------

	}

	private static int norm(int[] numbers) {
		int ret = Integer.MAX_VALUE;
		Arrays.sort(numbers);
		for (int i = numbers[0]; i <= numbers[numbers.length-1]; i++) {
			int ans = 0;
			for (int j = 0; j < numbers.length; j++) {
				ans += Math.abs(i - numbers[j]);
			}
			ret = Math.min(ret, ans);
		}
		return ret;
	}

	private static boolean finished(int[] index) {
		for (int i = 0; i < index.length; i++) {
			if(index[i] != s[i].length) return false;
		}
		return true;
	}

	static char[][] s;

	static boolean can() {
		HashSet<String> ss = new HashSet<String>();
		for (int i = 0; i < s.length; i++) {
			int count = 1;
			for (int j = 1; j < s[i].length; j++) {
				if (s[i][j] != s[i][j - 1])
					count++;
			}
			char[] res = new char[count];
			int ii = 1;
			res[0] = s[i][0];
			for (int j = 1; j < s[i].length; j++) {
				if (s[i][j] != s[i][j - 1])
					res[ii++] = s[i][j];
			}
			ss.add(new String(res));
		}
		return ss.size() == 1;
	}

	public B12014A() throws IOException {
		// Input Output for Console to be used for trying the test samples of
		// the problem
		in = new BufferedReader(new InputStreamReader(System.in));
//		out = new PrintWriter(System.out);
		// -------------------------------------------------------------------------
		// Input Output for File to be used for solving the small and large test
		// files
		// in = new BufferedReader(new FileReader("Template.in"));
		 out = new PrintWriter("B12014A.out");
		// -------------------------------------------------------------------------
		// Initalize Stringtokenizer input
		input = new StringTokenizer(in.readLine());
	}

	private static int nextInt() throws IOException {
		if (!input.hasMoreTokens())
			input = new StringTokenizer(in.readLine());
		return Integer.parseInt(input.nextToken());
	}

	private static long nextLong() throws IOException {
		if (!input.hasMoreTokens())
			input = new StringTokenizer(in.readLine());
		return Long.parseLong(input.nextToken());
	}

	private static double nextDouble() throws IOException {
		if (!input.hasMoreTokens())
			input = new StringTokenizer(in.readLine());
		return Double.parseDouble(input.nextToken());
	}

	private static String nextString() throws IOException {
		if (!input.hasMoreTokens())
			input = new StringTokenizer(in.readLine());
		return input.nextToken();
	}

	private static void write(String output) {
		out.write(output);
		out.flush();
	}

	private static void writeln(String output) {
		out.write(output + "\n");
		out.flush();
	}

	private static void end() throws IOException {
		in.close();
		out.close();
		System.exit(0);
	}

}
