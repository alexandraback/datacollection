import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class MagicTrick {

	private void work() throws Exception {
		Scanner sc = new Scanner(new BufferedReader(new FileReader(
				"A-small-attempt0.in")));
		PrintWriter pw = new PrintWriter(new FileWriter("A-small-attempt0.out"));

		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			pw.printf("Case #%d: ", tc);
			int fst = sc.nextInt();
			Set<Integer> s1 = new HashSet<Integer>();
			for (int i = 1; i <= 4; i++) {
				for (int j = 0; j < 4; j++) {
					int t = sc.nextInt();
					if (i == fst)
						s1.add(t);
				}
			}
			int snd = sc.nextInt();
			Set<Integer> s2 = new HashSet<Integer>();
			for (int i = 1; i <= 4; i++) {
				for (int j = 0; j < 4; j++) {
					int t = sc.nextInt();
					if (i == snd)
						s2.add(t);
				}
			}
			s1.retainAll(s2);
			if (s1.isEmpty()) {
				pw.println("Volunteer cheated!");
			} else if (s1.size() > 1) {
				pw.println("Bad magician!");
			} else {
				pw.println(s1.toArray(new Integer[1])[0]);
			}
		}
		sc.close();
		pw.close();
	}

	public static void main(String[] args) throws Exception {
		new MagicTrick().work();
	}

}
