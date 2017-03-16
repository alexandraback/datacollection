import java.util.*;


public class Program {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int nCases = in.nextInt();
		in.nextLine();
		for (int caseNumber = 1; caseNumber <= nCases; caseNumber++) {
			ArrayList<Integer> cards1 = new ArrayList<>();
			int nMatches = 0;
			int match = 0;
			
			int row1 = in.nextInt();
			in.nextLine();
			for (int i = 1; i <= 4; i++) {
				String line = in.nextLine();
				if (i == row1) {
					String[] s = line.split(" ");
					for (String si : s) {
						cards1.add(Integer.parseInt(si));
					}
				}
			}
			
			int row2 = in.nextInt();
			in.nextLine();
			for (int i = 1; i <= 4; i++) {
				String line = in.nextLine();
				if (i == row2) {
					String[] s = line.split(" ");
					for (String si : s) {
						int c = Integer.parseInt(si);
						if (cards1.contains(c)) {
							match = c;
							nMatches++;
						}
					}
				}
			}			

			System.out.print("Case #");
			System.out.print(caseNumber);
			System.out.print(": ");
			if (nMatches == 0) {
				System.out.println("Volunteer cheated!");
			} else {
				if (nMatches > 1) {
					System.out.println("Bad magician!");
				} else {
					System.out.println(match);
				}
			}
		}


	}

}
