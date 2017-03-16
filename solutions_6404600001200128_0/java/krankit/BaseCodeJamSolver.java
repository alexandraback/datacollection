package personal.codejam.infra;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public abstract class BaseCodeJamSolver implements ICodeJamSolver {

	protected BufferedReader br;
	protected BufferedWriter bw;

	@Override
	public void solve() throws Exception {
		bw = new BufferedWriter(new FileWriter(getOutputPath()));

		br = new BufferedReader(new FileReader(getInputPath()));
		Integer numTests = Integer.valueOf(br.readLine());
		preprocess();
		for (int test = 1; test <= numTests; test++) {
			String output = solveTestCase(test, br);
			writeOutput(caseString(test, output));
		}
	}

	private String caseString(int test, String output) {
		return String.format("%s%d: %s", getOutputText(), test, output);
	}

	protected String getOutputText() {
		return "Case #";
	}

	protected void preprocess() {
		// TODO Auto-generated method stub

	}

	protected void writeOutput(String output) throws IOException {
		bw.write(output);
		bw.newLine();
	}

	protected abstract String solveTestCase(int test, BufferedReader inputReader)
			throws IOException;

	@Override
	public void cleanUp() throws IOException {
		bw.close();
		br.close();
	}

}
