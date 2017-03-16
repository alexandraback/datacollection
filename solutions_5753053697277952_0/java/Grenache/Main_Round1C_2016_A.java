import java.util.*;


public class Main_Round1C_2016_A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int t = sc.nextInt();
		for (int casei = 1; casei <= t; casei++) {
			int n = sc.nextInt();
			List<Pair> p = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				p.add(new Pair(i, sc.nextInt()));
			}

			Collections.sort(p);

			StringBuilder ret = new StringBuilder();
			int cnt = p.get(p.size() - 1).b - p.get(p.size() - 2).b;
			for (int i = 0; i < cnt; i++) {
				ret.append((char)('A' + p.get(p.size() - 1).a));
				ret.append(' ');
			}
			p.get(p.size() - 1).b -= cnt;

			for (int i = 0; i < p.size() - 2; i++) {
				for (int j = 0; j < p.get(i).b; j++) {
					ret.append((char)('A' + p.get(i).a));
					ret.append(' ');
				}
			}
			for (int j = 0; j < p.get(p.size() - 1).b; j++) {
				ret.append((char)('A' + p.get(p.size() - 2).a));
				ret.append((char)('A' + p.get(p.size() - 1).a));
				ret.append(' ');
			}

			System.out.printf("Case #%d: %s\n", casei, ret);
		}

		sc.close();
	}

	private static class Pair implements Comparable<Pair> {
		int a;
		int b;

		Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}

		@Override
		public int compareTo(Pair o) {
			return Integer.compare(this.b, o.b);
		}
	}
}
