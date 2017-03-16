import java.io.File;
import java.util.ArrayList;
import java.util.Formatter;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class A {
	private static final String ANS = "Case #%s: %s\n";

	public static void main(String[] args) throws Exception {
		try (Scanner in = new Scanner(new File("io/A/A.in.txt")); Formatter out = new Formatter("io/A/A.out.txt")) {
			int tests = in.nextInt();
			for (int i = 1; i <= tests; ++i) {
				new A().solve(i, in, out);
			}
		}
	}

	private void solve(int testNo, Scanner in, Formatter out) {
		Set<Integer> ans = rowAns(in);
		ans.retainAll(rowAns(in));
		if (ans.isEmpty()) {
			out.format(ANS, testNo, "Volunteer cheated!");
		} else if (ans.size() == 1) {
			out.format(ANS, testNo, ans.iterator().next());
		} else {
			out.format(ANS, testNo, "Bad magician!");
		}
	}

	private Set<Integer> rowAns(Scanner in) {
		List<Integer> ans = new ArrayList<>();
		int toIndex = 4 * in.nextInt();
		for (int i = 0; i < 16; ++i) {
			ans.add(in.nextInt());
		}
		return new HashSet<>(ans.subList(toIndex - 4, toIndex));
	}
}
