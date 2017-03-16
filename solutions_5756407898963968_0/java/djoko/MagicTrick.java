import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class MagicTrick {
	
	public Set<Integer> readSet(Scanner sc) {
		HashSet<Integer> set = new HashSet<Integer>();
		
		int selectedRow = sc.nextInt();
		for (int row = 1; row <= 4; row++) {
			for (int col = 1; col <= 4; col++) {
				int n = sc.nextInt();
				if (selectedRow == row) {
					set.add(n);
				}
			}
		}
		
		return set;
	}
	
	public void process() {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++) {
			Set<Integer> firstSet = readSet(sc);
			Set<Integer> secondSet = readSet(sc);
			firstSet.retainAll(secondSet);
			
			System.out.print("Case #" + (i + 1) + ": ");
			switch(firstSet.size()) {
			case 0:
				System.out.println("Volunteer cheated!");
				break;
			case 1:
				System.out.println(firstSet.toArray()[0]);
				break;
			default:
				System.out.println("Bad magician!");
			}
		}
	}
	
	public static void main(String args[]) {
		MagicTrick mt = new MagicTrick();
		mt.process();
	}
}
