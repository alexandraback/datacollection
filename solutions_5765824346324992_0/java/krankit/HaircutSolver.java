package personal.codejam15.round1a;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

import personal.codejam.infra.BaseCodeJamSolver;
import personal.codejam.infra.ICodeJamSolver;

public class HaircutSolver extends BaseCodeJamSolver {
	private static final String SMALL_OUTPUT = "/Users/ankkumar/Documents/Personal/workspace/Codejam2015/src/personal/codejam15/round1a/B-small-attempt3.out";
	private static final String LARGE_OUTPUT = "/Users/ankkumar/Documents/Personal/workspace/Codejam2015/src/personal/codejam15/round1a/B-large.out";

	private static final String SMALL_INPUT_PRACTICE = "/Users/ankkumar/Downloads/Codejam2015/Round1A/B-small-practice.in";
	private static final String SMALL_INPUT = "/Users/ankkumar/Downloads/Codejam2015/Round1A/B-small-attempt3.in";
	private static final String LARGE_INPUT = "/Users/ankkumar/Downloads/Codejam2015/Round1A/B-large.in";

	@Override
	public String getInputPath() {
		return SMALL_INPUT;
	}

	@Override
	public String getOutputPath() {
		return SMALL_OUTPUT;
	}

	public static void main(String[] args) throws Exception {
		ICodeJamSolver solver = new HaircutSolver();
		solver.solve();
		solver.cleanUp();
	}

	@Override
	protected String solveTestCase(int test, BufferedReader inputReader)
			throws IOException {
		String input = inputReader.readLine();
		String[] parts = input.split("\\s+");
		Integer B = Integer.valueOf(parts[0]);
		Integer N = Integer.valueOf(parts[1]);

		input = inputReader.readLine();
		parts = input.split("\\s+");

		Integer[] barbAr = new Integer[B];
		List<Integer> serviceQ = new LinkedList<Integer>();
		for (int i = 0; i < B; i++) {
			Integer val = Integer.valueOf(parts[i]);
			barbAr[i] = val;
			serviceQ.add(val);
		}

		Integer lcm = 1;
		Integer gcd = 1;

		for (int i = 0; i < B; i++) {
			gcd = gcd(lcm, barbAr[i]);
			lcm = (lcm * barbAr[i]) / gcd;
		}

		Integer lcmSlot = 0;

		for (int i = 0; i < B; i++) {
			lcmSlot = lcmSlot + lcm / barbAr[i];
		}

		N = N % lcmSlot;

		if (N == 0) {
			N = lcmSlot;
		}

		if (B >= N) {
			return String.valueOf(N);
		}

		Integer nextCust = B;
		Integer emptySlot = -1;
		while (nextCust < N) {
			emptySlot = findEmpty(serviceQ);
			while (emptySlot == -1) {
				Integer min = Collections.min(serviceQ);
				updateServiceQ(serviceQ, min);
				emptySlot = findEmpty(serviceQ);
			}
			serviceQ.set(emptySlot, barbAr[emptySlot]);
			nextCust++;
		}

		return String.valueOf(emptySlot + 1);
	}

	private Integer gcd(Integer lcm, Integer integer) {
		if (lcm == 1 || integer == 1) {
			return 1;
		}
		Integer dividend = lcm > integer ? lcm : integer;
		Integer divisor = lcm < integer ? lcm : integer;
		Integer rem = dividend % divisor;
		if (rem == 0) {
			return divisor;
		}
		return gcd(divisor, rem);
	}

	private void updateServiceQ(List<Integer> serviceQ, Integer min) {
		for (int i = 0; i < serviceQ.size(); i++) {
			Integer newVal = serviceQ.get(i);
			newVal = newVal - min < 0 ? 0 : newVal - min;
			serviceQ.set(i, newVal);
		}

	}

	private Integer findEmpty(List<Integer> serviceQ) {
		for (int i = 0; i < serviceQ.size(); i++) {
			if (serviceQ.get(i) == 0) {
				return i;
			}
		}
		return -1;
	}
}
