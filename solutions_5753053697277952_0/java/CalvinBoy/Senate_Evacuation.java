import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

import javafx.util.Pair;


public class Senate_Evacuation {
	private static String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	private static Character pop(PriorityQueue<Pair<Integer, Integer>> q, boolean isSecond) {

		Pair<Integer, Integer> first = q.poll();
		if(first == null) return null;
		Pair<Integer, Integer> second = q.peek();
		if(isSecond && first.getValue()==1 && q.size()==1 && second.getValue()==1) {
			q.add(first);
			return null;
		}
		
		int firstKey = first.getKey();
		int firstValue = first.getValue();
		firstValue--;
		if(firstValue > 0 ) {
			q.add(new Pair<Integer, Integer>(firstKey, firstValue));
		}
		return alphabet.charAt(firstKey);
		
	}
	
	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		int t = scanner.nextInt();
		for(int cas=1; cas<=t; ++cas) {
			int n = scanner.nextInt();
			PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>(n, new Comparator<Pair<Integer, Integer>>() {

				@Override
				public int compare(Pair<Integer, Integer> o1,
						Pair<Integer, Integer> o2) {
					return o2.getValue().compareTo(o1.getValue());
				}
			});
			for(int i=0; i<n; ++i) {
				int pi = scanner.nextInt();
				Pair<Integer, Integer> pairI = new Pair<Integer, Integer>(i, pi);
				pq.add(pairI);
			}
			System.out.printf("Case #%d:", cas);
			while(pq.size()!=0) {
				Character c1 = pop(pq, false);
				Character c2 = pop(pq, true);
				if(c2 != null) System.out.printf(" " + c1 + c2);
				else System.out.printf(" " + c1);
			}
			System.out.println();
		}
	}
}
