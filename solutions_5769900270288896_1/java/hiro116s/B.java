
import java.io.*;
import java.util.*;

public class B {
	FastScanner in = new FastScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);

	/*
	public void run() {
		int T = in.nextInt();
		for (int caseN = 1; caseN <= T; caseN++) {
			int R = in.nextInt(), C = in.nextInt();
			int n = in.nextInt();
			
			int[] ecnt = new int[5];
			int[] ocnt = new int[5];
			
			int evenN = n, oddN = n;
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					int cnt = 0;
					if (i > 0) cnt++;
					if (i < R - 1) cnt++;
					if (j > 0) cnt++;
					if (j < C - 1) cnt++;
					
					if ((i + j) % 2 == 0) {
						ocnt[cnt]++;
						evenN--;
					} else {
						ecnt[cnt]++;
						oddN--;
					}
				}
			}
			
			int minO = 0, minE = 0;
//			System.out.println(R + " " + C + " " + n);
//			System.out.println(oddN + " " + pq_odd.size());
//			System.out.println(evenN + " " + pq_even.size());
			
			int one, two, three, four;

			one = Math.min(ecnt[1], evenN);
			minE += one;
			evenN -= one;
			
			two = Math.min(ecnt[2], evenN);
			minE += two * 2;
			evenN -= two;

			three = Math.min(ecnt[3], evenN);
			minE += three * 3;
			evenN -= three;
			
			four = Math.min(ecnt[4], evenN);
			minE += four * 4;
			evenN -= four;
			
		
			one = Math.min(ecnt[1], oddN);
			minO += one;
			oddN -= one;
			
			two = Math.min(ecnt[2], oddN);
			minO += two * 2;
			oddN -= two;

			three = Math.min(ecnt[3], oddN);
			minO += three * 3;
			oddN -= three;

			four = Math.min(ecnt[4], oddN);
			minO += four * 4;
			oddN -= four;

			System.out.println("Case #" + caseN + ": " + Math.min(minO, minE));
		}
		out.close();
	}
	*/
	
	public void run() {
		int T = in.nextInt();
		for (int caseN = 1; caseN <= T; caseN++) {
			int R = in.nextInt(), C = in.nextInt();
			int n = in.nextInt();
			
			PriorityQueue<Integer> pq_odd = new PriorityQueue<Integer>();
			PriorityQueue<Integer> pq_even = new PriorityQueue<Integer>();
			
			int evenN = n, oddN = n;
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					int cnt = 0;
					if (i > 0) cnt++;
					if (i < R - 1) cnt++;
					if (j > 0) cnt++;
					if (j < C - 1) cnt++;
					
					if ((i + j) % 2 == 0) {
						pq_odd.add(cnt);
						evenN--;
					} else {
						pq_even.add(cnt);
						oddN--;
					}
				}
			}
			
			int minO = 0, minE = 0;
//			System.out.println(R + " " + C + " " + n);
//			System.out.println(oddN + " " + pq_odd.size());
//			System.out.println(evenN + " " + pq_even.size());
			while (oddN > 0) {
				oddN--;
				minO += pq_odd.poll();
			}
			
			while (evenN > 0) {
				evenN--;
				minE += pq_even.poll();
			}
			
			out.println("Case #" + caseN + ": " + Math.min(minO, minE));
		}
		out.close();
	}

	public static void main(String[] args) {
		new B().run();
	}

	public void mapDebug(int[][] a) {
		System.out.println("--------map display---------");

		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				System.out.printf("%3d ", a[i][j]);
			}
			System.out.println();
		}

		System.out.println("----------------------------");
		System.out.println();
	}

	public void debug(Object... obj) {
		System.out.println(Arrays.deepToString(obj));
	}

	class FastScanner {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public FastScanner(InputStream stream) {
			this.stream = stream;
			//stream = new FileInputStream(new File("dec.in"));

		}

		int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		boolean isEndline(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		int[] nextIntArray(int n) {
			int[] array = new int[n];
			for (int i = 0; i < n; i++)
				array[i] = nextInt();

			return array;
		}

		int[][] nextIntMap(int n, int m) {
			int[][] map = new int[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextIntArray(m);
			}
			return map;
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		long[] nextLongArray(int n) {
			long[] array = new long[n];
			for (int i = 0; i < n; i++)
				array[i] = nextLong();

			return array;
		}

		long[][] nextLongMap(int n, int m) {
			long[][] map = new long[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextLongArray(m);
			}
			return map;
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		double[] nextDoubleArray(int n) {
			double[] array = new double[n];
			for (int i = 0; i < n; i++)
				array[i] = nextDouble();

			return array;
		}

		double[][] nextDoubleMap(int n, int m) {
			double[][] map = new double[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextDoubleArray(m);
			}
			return map;
		}

		String next() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		String[] nextStringArray(int n) {
			String[] array = new String[n];
			for (int i = 0; i < n; i++)
				array[i] = next();

			return array;
		}

		String nextLine() {
			int c = read();
			while (isEndline(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndline(c));
			return res.toString();
		}
	}
}
