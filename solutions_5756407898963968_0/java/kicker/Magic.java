import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;

public class Magic {

	Scanner sc = new Scanner(getClass().getResourceAsStream(IN));
	static final String FILENAME = "A-small-attempt0";
	static final String IN = FILENAME + ".in";
	static final String OUT = FILENAME + ".out";
	PrintStream out ;

	private void solve() {
		int firstChoice = sc.nextInt();
		int count = 0;

		sc.nextLine();
		HashSet<Integer> solution = new HashSet<>(4);
		String result = "";
		for (int i = 0; i < 4; i++) {
			if (i == (firstChoice - 1)) {
				for (int j = 0; j < 4; j++) {
					solution.add(sc.nextInt());
				}
			}
			sc.nextLine();
		}
		int secondChoice = sc.nextInt();
		sc.nextLine();
		for (int i = 0; i < 4; i++) {
			if (i == (secondChoice - 1)) {
				for (int j = 0; j < 4; j++) {
					int nextInt = sc.nextInt();
					if (solution.contains(nextInt)) {
						count++;
						result = nextInt + "";
					}

				}
			}
			sc.nextLine();
		}

		if(count>1){
			result = "Bad magician!";
		}else if(count ==0){
			result = "Volunteer cheated!";
		}
		out.print(result);
	
	}

	private void run() throws Exception {
		out = new PrintStream(new FileOutputStream(OUT));
		int t = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= t; i++) {
			out.print("Case #" + i + ": ");
			solve();
			out.println();
		}
		sc.close();
		out.close();
	}

	public static void main(String args[]) throws Exception {
		new Magic().run();
	}

}