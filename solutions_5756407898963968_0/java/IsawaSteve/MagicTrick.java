import java.io.File;
import java.io.FileNotFoundException;
import java.lang.reflect.Array;
import java.util.Scanner;

/**
 * For Google Code Jam Qualification Round.
 * @author Jay
 *
 */
public class MagicTrick {


	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc;
		try {
			sc = new Scanner(new File(args[0]));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return;
		}
		String totalProblems = sc.nextLine();
		int total = Integer.parseInt(totalProblems);
		int pos = 1;
		for (;pos <= total;pos++) {
			String[][] box1 = new String[4][4];
			String guess1 = sc.nextLine();
			String line1a = sc.nextLine();
			box1[0] = line1a.split(" ");
			String line2a = sc.nextLine();
			box1[1] = line2a.split(" ");
			String line3a = sc.nextLine();
			box1[2] = line3a.split(" ");
			String line4a = sc.nextLine();
			box1[3] = line4a.split(" ");
			
			String[][] box2 = new String[4][4];
			String guess2 = sc.nextLine();
			String line1b = sc.nextLine();
			box2[0] = line1b.split(" ");
			String line2b = sc.nextLine();
			box2[1] = line2b.split(" ");
			String line3b = sc.nextLine();
			box2[2] = line3b.split(" ");
			String line4b = sc.nextLine();
			box2[3] = line4b.split(" ");
			
			String choice = determineSelection(guess1, box1, guess2, box2);

			
			System.out.println("Case #"+pos+": "+choice);
		}
	}
	
	private static String determineSelection(String guess1, String[][] box1,
			String guess2, String[][] box2) {
		String[] row1 = box1[Integer.parseInt(guess1) - 1];
		String[] row2 = box2[Integer.parseInt(guess2) - 1];
		String selection = "Volunteer cheated!";
		for (String item: row1) {
			for (String item2: row2) {
				if (item.equals(item2)) {
					if (!selection.equals("Volunteer cheated!")) {
						return "Bad magician!";
					}
					selection = item;
				}
			}
		}
		
		return selection;
	}
}
