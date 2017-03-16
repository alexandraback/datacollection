import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

public class Magician {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("A-small-attempt0.in.txt"));
		PrintWriter out = new PrintWriter(new File("a.out"));
		int T = in.nextInt();

		for (int i = 0; i < T; i++) {
			String s = "Case #" + (i + 1) + ": " + new Magician().solve(in);
			out.println(s);
			//System.out.println(s);
		}
		out.close();
	}

	private String solve(Scanner in) {
		HashMap<Integer, Boolean> cards = new HashMap<>();
		int first = in.nextInt();

		for (int i = 0; i < first; i++)
			in.nextLine();
		for (int i = 0; i < 4; i++) {
			cards.put(in.nextInt(), true);
		}
		for (int i=first; i<=4; i++)
			in.nextLine();

		int second = in.nextInt();
		int value = -1;
		for (int i = 0; i < second; i++)
			in.nextLine();
		for (int i = 0; i < 4; i++) {
			int x = in.nextInt();
			if (cards.containsKey(x)) {
				if (value != -1)
					return bad(second, in);
				else
					value = x;
			}

		}
		for (int i=second; i<=4; i++)
			in.nextLine();
		if (value==-1)
			return"Volunteer cheated!";
		return ""+value;

	}
	private String bad(int first, Scanner in){
		for (int i=first; i<=4; i++)
			in.nextLine();
		return "Bad magician!";
	}
}
