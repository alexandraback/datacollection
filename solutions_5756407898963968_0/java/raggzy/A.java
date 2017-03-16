package y2014.qualification;

import template.Runner;
import template.Solver;

import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by raggzy on 4/12/14.
 */
public class A extends Solver {
	public A(Scanner in, PrintStream out, int TC) {
		super(in, out, TC);
	}

	public static final int MAX_ROW = 4;
	public static final int MAX_COL = 4;

	private Set<Integer> readAndGetPossibleCards() {
		int rowNum = in.nextInt();
		Set<Integer> result = new HashSet<Integer>();
		for (int r = 1; r <= MAX_ROW; r++) {
			for (int c = 1; c <= MAX_COL; c++) {
				int card = in.nextInt();
				if (r == rowNum) {
					result.add(card);
				}
			}
		}
		return result;
	}

	@Override
	public void solve() {
		Set<Integer> cards1 = readAndGetPossibleCards();
		Set<Integer> cards2 = readAndGetPossibleCards();
		cards1.retainAll(cards2);
		String answer;
		if (cards1.size() == 0) {
			answer = "Volunteer cheated!";
		} else if (cards1.size() == 1) {
			answer = String.valueOf(cards1.iterator().next());
		} else {
			answer = "Bad magician!";
		}
		out.println(String.format("Case #%d: %s", TC, answer));
	}

	public static void main(String[] args) throws Exception {
		Runner.main(A.class);
	}
}
