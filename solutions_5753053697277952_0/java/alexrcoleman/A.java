import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws FileNotFoundException {
//		 Scanner scan = new Scanner(System.in);
//		 PrintWriter out = new PrintWriter(System.out);
		Scanner scan = new Scanner(new FileInputStream(new File("A.in")));
		PrintWriter out = new PrintWriter(new FileOutputStream(new File("A.out")));
		char[] chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".toCharArray();
		int T = scan.nextInt();
		for (int t = 1; t <= T; t++) {
			int n = scan.nextInt();
			out.printf("Case #%d: ", t);
			int[] cnts = new int[n];
			for (int i = 0; i < n; i++) {
				cnts[i] = scan.nextInt();
			}
			StringBuilder sb = new StringBuilder();
			do {
				int maxi = -1;
				int maxCount = -1;
				for (int i = 0; i < n; i++) {
					if (cnts[i] > maxCount) {
						maxi = i;
						maxCount = cnts[i];
					}
				}
				int tieCount = 0;
				for (int i = 0; i < n; i++) {
					if(cnts[i] == maxCount)
						tieCount++;
				}
				if(maxCount == 0) break;
				
				if (tieCount == 2) {
					for (int i = 0; i < n; i++) {
						if (cnts[i] == maxCount) {
							sb.append(chars[i]);
							cnts[i]--;
						}
					}
					sb.append(" ");
					continue;

				}
				sb.append(chars[maxi]);
				sb.append(" ");
				cnts[maxi]--;
			} while (true);
			out.println(sb.toString().trim());

		}
		out.close();
	}

	static class ST {
		int[] vs;
		int[] is;
		int[] back;
		int s;

		public ST(int size) {
			s = size;
			vs = new int[4 * s + 1];
			is = new int[4 * s + 1];
		}

		void update(int l, int r, int v) {
			update(l, r, v, 0, s - 1, 1);
		}

		void update(int lq, int rq, int v, int li, int ri, int c) {
			if (rq < li || ri < lq)
				return;
			if (lq <= li && ri <= rq) {
				vs[c] = v;
				is[c] = li;
				return;
			}
			int m = li + (ri - li) / 2;
			update(lq, rq, v, li, m, 2 * c);
			update(lq, rq, v, m + 1, ri, 2 * c + 1);
			if (vs[2 * c] > vs[2 * c + 1]) {
				vs[c] = vs[2 * c];
				is[c] = is[2 * c];
			} else {
				vs[c] = vs[2 * c + 1];
				is[c] = is[2 * c + 1];
			}
		}

		Pair query(int l, int r) {
			return query(l, r, 0, s - 1, 1);
		}

		Pair query(int lq, int rq, int li, int ri, int c) {
			if (rq < li || ri < lq)
				return null;
			if (lq <= li && ri <= rq) {
				return new Pair(is[c], vs[c]);
			}
			int m = li + (ri - li) / 2;
			Pair op1 = query(lq, rq, li, m, 2 * c);
			Pair op2 = query(lq, rq, m + 1, ri, 2 * c + 1);
			if (op1 == null)
				return op2;
			if (op2 == null)
				return op1;
			if (op1.b < op2.b) {
				return op1;
			}
			return op2;
		}
	}

	static class Pair {
		int a, b;

		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
			// TODO Auto-generated constructor stub
		}
	}
}
