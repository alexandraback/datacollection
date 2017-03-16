import java.util.*;

public class A {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int total = s.nextInt();
		int current = 1;
		while (current <= total) {
			HashSet set1 = getRowSet(s);
			HashSet set2 = getRowSet(s);
			set1.retainAll(set2);
			
			System.out.print("Case #" + (current++) +": ");
			String msg;
			if (set1.size() == 0) {
				msg = "Volunteer cheated!";
			} else if (set1.size() > 1) {
				msg = "Bad magician!";
			} else {
				msg = set1.iterator().next().toString();
			}
			System.out.println(msg);
		}
	}
	
	public static HashSet getRowSet(Scanner s) {
		int row = s.nextInt();
		int grid[][] = new int[4][4];
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[i].length; j++) {
				grid[i][j] = s.nextInt();
			}
		}
		HashSet set = new HashSet();
		for (int j = 0; j < grid[row-1].length; j++) {
			set.add(grid[row-1][j]);
		}
		return set;
	}
}
