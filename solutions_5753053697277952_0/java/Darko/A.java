import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.Scanner;

public class A {
	class Senator implements Comparable<Senator> {
		char p;
		int c;

		Senator(char p, int c) {
			this.p = p;
			this.c = c;
		}

		@Override
		public int compareTo(Senator s) {
			if (c > s.c)
				return -1;
			if (c < s.c)
				return 1;
			return p - s.p;
		}
	}

	private void work() throws Exception {
		String task = "A-small-attempt0";
		Scanner sc = new Scanner(new BufferedReader(
				new FileReader(task + ".in")));
		PrintWriter pw = new PrintWriter(new FileWriter(task + ".out"));

		PriorityQueue<Senator> pq = new PriorityQueue<Senator>();

		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			pw.printf("Case #%d:", tc);
			int n = sc.nextInt();
			pq.clear();
			for (int i = 0; i < n; i++) {
				pq.add(new Senator((char) (i + 'A'), sc.nextInt()));
			}
			while (!pq.isEmpty()) {
				Senator s = pq.poll();
				pw.printf(" %c", s.p);
				if (pq.size() == 1) {
					Senator s2 = pq.poll();
					if (s2.c == s.c) {
						pw.print(s2.p);
					}
					if (s2.c > 1) {
						s2.c--;
						pq.add(s2);
					}
				}
				if (s.c > 1) {
					s.c--;
					pq.add(s);
				}
			}
			pw.println();
		}

		sc.close();
		pw.close();
	}

	public static void main(String[] args) throws Exception {
		new A().work();
	}

}
