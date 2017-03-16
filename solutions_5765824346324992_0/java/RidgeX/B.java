import java.util.*;

public class B {
	static class Barber implements Comparable<Barber> {
		int index;
		int timer;

		public Barber(int i) {
			index = i;
			timer = 0;
		}

		public int compareTo(Barber other) {
			return index - other.index;
		}
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int cases = input.nextInt();
		for (int c = 0; c < cases; c++) {
			int b = input.nextInt();
			int n = input.nextInt();
			int[] m = new int[b];
			for (int i = 0; i < b; i++) {
				m[i] = input.nextInt();
			}
			PriorityQueue<Barber> available = new PriorityQueue<Barber>();
			List<Barber> inUse = new ArrayList<Barber>();
			for (int i = 0; i < b; i++) {
				available.add(new Barber(i));
			}
			List<Integer> list = new ArrayList<Integer>();
			while (true) {
				if (list.size() >= 4) {
					int x = list.size() / 4;
					boolean valid = true;
					for (int i = 0; i < x; i++) {
						if (list.get(i) != list.get(x+i) || list.get(i) != list.get(2*x+i) || list.get(i) != list.get(3*x+i)) {
							valid = false;
							break;
						}
					}
					if (valid) break;
				}
				while (!available.isEmpty()) {
					Barber bb = available.remove();
					bb.timer = m[bb.index];
					inUse.add(bb);
					list.add(bb.index);
				}
				for (int i = inUse.size() - 1; i >= 0; i--) {
					Barber bb = inUse.get(i);
					bb.timer--;
					if (bb.timer == 0) {
						inUse.remove(i);
						available.add(bb);
					}
				}
			}
			int answer = list.get((n-1) % list.size()) + 1;
			System.out.println(String.format("Case #%d: %d", c+1, answer));
		}
	}
}
