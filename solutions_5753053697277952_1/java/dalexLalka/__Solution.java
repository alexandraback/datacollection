import java.io.*;
import java.util.*; // тут лежат все коллекции, Random

// имя начинается с двух подчеркиваний, чтобы был первым в списке (он сортится по алфавиту)
public class __Solution {

	// определяет, запускается решение "дома" или на CF/timus
	static final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;

	public static void main(String[] args) {
		new __Solution().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok;

	void init() throws FileNotFoundException {
		// иницилизация потоков вводилок/выводилок
		// System.in/System.out - стандартные потоки ввода/вывода на консоль

		if (ONLINE_JUDGE) {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		} else {
//			in = new BufferedReader(new InputStreamReader(System.in));
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
		}

		tok = new StringTokenizer("");
	}

	void run() {
		try {
			long timeStart = System.currentTimeMillis();

			init();

			int tests = readInt();
			for (int test = 1; test <= tests; ++test) {
				out.print("Case #" + test + ": ");
				solve();
			}

			out.close();

			long timeEnd = System.currentTimeMillis();
			System.err.println("Time = " + (timeEnd - timeStart));
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		}
	}

	// чтение строки вернет null, если ничего не осталось
	String readLine() throws IOException {
		return in.readLine();
	}

	char[] readCharArray() throws IOException {
		return readLine().toCharArray();
	}

	// содержит символы, являющиеся "разделителями ввода"
	// по умолчанию это пробел (перевод строки автоматом учитывается)
	String delimiter = " ";

	String readString() throws IOException {
		while (!tok.hasMoreTokens()) {
			String nextLine = readLine();
			if (null == nextLine)
				return null;

			tok = new StringTokenizer(nextLine);
		}

		return tok.nextToken(delimiter);
	}

	int readInt() throws IOException {
		return Integer.parseInt(readString());
	}

	long readLong() throws IOException {
		return Long.parseLong(readString());
	}
	
	String f(int index) {
		char l = (char)('A' + index);
		return "" + l;
	}

	// тут мы будем писать основное решение
	void solve() throws IOException {
		int n = readInt();
		int[] p = new int[n];
		for (int i = 0; i < n; ++i) {
			p[i] = readInt();
		}
		
		int a = -1, b = -1;
		int aP = 0, bP = 0;
		for (int i = 0; i < n; ++i) {
			if (aP < p[i]) {
				b = a;
				bP = aP;
				
				a = i;
				aP = p[i];
			} else if (bP < p[i]) {
				b = i;
				bP = p[i];
			}
		}
		
		while (aP > bP) {
			if (aP - bP == 1) {
				out.print(f(a) + " ");
				aP -= 1;
			} else {
				out.print(f(a) + f(a) + " ");
				aP -= 2;
			}
		}
		
		for (int i = 0; i < n; ++i) {
			if (i != a && i != b) {
				while (p[i] > 0) {
					if (p[i] == 1) {
						out.print(f(i) + " ");
						p[i] -= 1;
					} else {
						out.print(f(i) + f(i) + " ");
						p[i] -= 2;
					}
				}
			}
		}
		
		while (aP > 0) {
			out.print(f(a) + f(b) + " ");
			aP -= 1;
			bP -= 1;
		}
		
		out.println();
	}
}