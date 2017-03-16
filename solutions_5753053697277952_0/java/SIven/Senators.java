import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Senators {

	static List<Integer> senators = new ArrayList<Integer>();

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int t = in.nextInt(); // Scanner has functions to
								// read ints, longs,
								// strings, chars, etc.
		for (int i = 1; i <= t; ++i) {
			senators = new ArrayList<Integer>();
			int u = in.nextInt();
			for (int j = 1; j <= u; j++) {
				senators.add(in.nextInt());
			}
			String plans = "";
			while(sum(senators) > 0){
				plans = plans + " " + generatePlan();
			}
			System.out.println("Case #" + i + ":" + plans);
		}
	}

	private static String generatePlan() {
		String plan = "";

		int index = getMaxIndex(senators);
		senators.set(index, senators.get(index) - 1); // Send one out
		plan = plan + getCharForNumber(index+1);
		if (sum(senators) > 0) {
			List<Integer> newSenators = new ArrayList<Integer>(senators);
			index = getMaxIndex(senators);
			newSenators.set(index, newSenators.get(index) - 1); // Test to send
																// another one
																// out
			int newMax = newSenators.get(getMaxIndex(newSenators));
			if (newMax*2 > sum(newSenators)) {
				// Do not apply anything
			} else {
				senators = new ArrayList<Integer>(newSenators);
				plan = plan + getCharForNumber(index+1);
			}
		}
		return plan;
	}

	private static int getMaxIndex(List<Integer> senators2) {
		int index = 0;
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < senators2.size(); i++) {
			if (senators2.get(i) > max) {
				index = i;
				max = senators2.get(i);
			}
		}
		return index;
	}

	private static int sum(List<Integer> senators) {
		int amount = 0;
		for (Integer i : senators) {
			amount += i;
		}
		return amount;
	}

	private static String getCharForNumber(int i) {
		return i > 0 && i < 27 ? String.valueOf((char) (i + 64)) : null;
	}
}
