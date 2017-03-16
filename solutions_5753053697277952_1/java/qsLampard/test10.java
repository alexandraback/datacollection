import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Scanner;


public class test10 {
	class Party {
		char symbol;
		Integer count;
		public Party(char symbol, int count) {
			this.symbol = symbol;
			this.count = count;
		}
	}
	public String evacuate(int[] people) {
		int size = 0;
		PriorityQueue<Party> pq = new PriorityQueue<Party>((p1, p2) -> p2.count.compareTo(p1.count));
		for (int i = 0; i < people.length; i++) {
			Party p = new Party((char)('A' + i), people[i]);
			pq.add(p);
			size += people[i];
		}
		StringBuilder sb = new StringBuilder();
		while (pq.size() > 0) {
			if (size == 3 && pq.size() == 3) {
				Party p1 = pq.poll();
				sb.append(" ").append(p1.symbol);
				size--;
			} else {
				Party p1 = pq.poll();
				Party p2 = pq.poll();
				sb.append(" ").append(p1.symbol).append(p2.symbol);
				if (p1.count > 1) {
					p1.count--;
					pq.add(p1);
				}
				if (p2.count > 1) {
					p2.count--;
					pq.add(p2);
				}
				size -= 2;
			}
		}
		return sb.toString();
	}
	public static void main(String[] args) {
		
		test10 test = new test10();
	    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	    Long t = in.nextLong();  // Scanner has functions to read ints, longs, strings, chars, etc.
	    for (int i = 1; i <= t; ++i) {
	    	int parties = in.nextInt();
	    	int[] people = new int[parties];
	    	for (int j = 0; j < parties; ++j) {
	    		people[j] = in.nextInt();
	    	}
    		System.out.println("Case #" + i + ":" + test.evacuate(people));
	    }
	}
}
