import java.util.*;

public class A {

	private class Pair implements Comparable<Pair> {

		int pn;
		int num;

		public Pair(int p, int n) {
			pn = p;
			num = n;
		}

		public int compareTo(Pair x) {
			return x.num - this.num;
		}
	}

	public static void main(String[] args) {
		A a = new A();
		a.run();
	}

	public void run() {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		for (int a=0; a<cases; a++) {
			int nump = Integer.parseInt(in.nextLine());
			int total = 0;
			PriorityQueue<Pair> q = new PriorityQueue<>();
			String[] line = in.nextLine().split(" ");
			for (int i=0; i<nump; i++) {
				int pi = Integer.parseInt(line[i]);
				q.add(new Pair(i,pi));
				total += pi;
			}
			System.out.printf("Case #%d:",a+1);
			StringBuilder build = new StringBuilder();
			while (!q.isEmpty()) {
				Pair out1 = q.poll();
				if (total!=3) {
					Pair out2 = q.poll();
					build.append(String.format(" %s%s",(char)(out1.pn+'A'),(char)(out2.pn+'A')));
					if (out1.num>1) {
						q.add(new Pair(out1.pn,out1.num-1));
					}
					if (out2.num>1) {
						q.add(new Pair(out2.pn,out2.num-1));
					}
					total -= 2;
				}
				else {
					build.append(String.format(" %s",(char)(out1.pn+'A')));
					if (out1.num>1) {
						q.add(new Pair(out1.pn,out1.num-1));
					}
					total -= 1;
				}
			}
			System.out.printf("%s\n",build.toString());
		}
	}
}