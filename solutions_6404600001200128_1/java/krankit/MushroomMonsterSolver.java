package personal.codejam15.round1a;

import java.io.BufferedReader;
import java.io.IOException;

import personal.codejam.infra.BaseCodeJamSolver;
import personal.codejam.infra.ICodeJamSolver;

public class MushroomMonsterSolver extends BaseCodeJamSolver {
	private static final String SMALL_OUTPUT = "/Users/ankkumar/Downloads/Codejam2015/Round1A/A-small-attempt0-out.txt";
	private static final String LARGE_OUTPUT = "/Users/ankkumar/Downloads/Codejam2015/Round1A/A-large.out";

	private static final String SMALL_INPUT_PRACTICE = "/Users/ankkumar/Downloads/Codejam2015/Round1A/A-small-practice.in";
	private static final String SMALL_INPUT = "/Users/ankkumar/Downloads/Codejam2015/Round1A/A-small-attempt0.in";
	private static final String LARGE_INPUT = "/Users/ankkumar/Downloads/Codejam2015/Round1A/A-large.in";

	public static void main(String[] args) throws Exception {
		ICodeJamSolver solver = new MushroomMonsterSolver();
		solver.solve();
		solver.cleanUp();
	}

	@Override
	public String getInputPath() {
		return LARGE_INPUT;
	}

	@Override
	public String getOutputPath() {
		return LARGE_OUTPUT;
	}

	@Override
	protected String solveTestCase(int test, BufferedReader inputReader)
			throws IOException {
		String input = inputReader.readLine();
		Integer N = Integer.valueOf(input);
		input = inputReader.readLine();
		String[] parts = input.split("\\s+");
		Integer[] mushAr = new Integer[N];
		for (int i = 0; i < N; i++) {
			mushAr[i] = Integer.valueOf(parts[i]);
		}
		Integer Y = 0;
		Integer maxDiff = Integer.MIN_VALUE;
		for (int i = 0; i < N - 1; i++) {
			Integer diff = mushAr[i] - mushAr[i + 1];
			if (maxDiff < diff) {
				maxDiff = diff;
			}
			Y += diff > 0 ? diff : 0;
		}
		Integer Z = 0;
		for (int i = 0; i < N - 1; i++) {
			if (mushAr[i] > maxDiff) {
				Z += maxDiff;
			} else {
				Z += mushAr[i];
			}
		}

		return String.format("%d %d", Y, Z);
	}

}
