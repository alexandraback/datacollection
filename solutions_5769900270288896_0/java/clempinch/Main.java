package jam.round1.b;

import java.io.IOException;

import file.input.InputProcessor;
import file.output.OutputGenerator;

public class Main {

	public static void main(String[] args) throws IOException {
		String file = "B-small-attempt0";
		ProblemInputProcessor pip = new ProblemInputProcessor(file + ".in");
		pip.startProcess();
		OutputGenerator og = new OutputGenerator(file + ".out",
				pip.getNumberOfTestCases());
		for (ProblemInput problemInput : pip) {
			og.printOneLineTestResult(problemInput.solve());
		}
		pip.endProcess();
		og.end();
		System.out.println("Done");
	}

}

class ProblemInputProcessor extends InputProcessor<ProblemInput> {

	public ProblemInputProcessor(String inputFile) {
		super(inputFile);
	}

	@Override
	protected ProblemInput getNextTestCase() {
		String[] inputs = getNextLine().split(" ");
		return new ProblemInput(Integer.parseInt(inputs[0]), Integer.parseInt(inputs[1]), Integer.parseInt(inputs[2]));
	}

}

class ProblemInput {
	
	int r;
	int c;
	int n;

	public ProblemInput(int r, int c, int n) {
		this.r = r;
		this.c = c;
		this.n = n;
	}

	public String solve() {
		return Integer.toString(solveProblem());
	}
	
	public int solveProblem() {
		if(n == 0) {
			return 0;
		}
		if(r *c == 1) {
			return 0;
		}
		if(r == 1 || c == 1) {
			int res = (n-(r*c+1)/2)*2;
			return res >= 0 ? res : 0;
		}
		if(r*c == n) {
			return r*(c-1)+(r-1)*c;
		}
		if(n <= r*c/2) {
			return 0;
		}
		if(r*c == 4 && n == 3) {
			return 2;
		}
		// tricky cases
		if(r == 2 || c == 2) {
			if(n == r*c/2 +1) {
				return 2;
			}
			if(n == r*c/2 +2) {
				return 4;
			}
			else {
				return 4+3*(n-(r*c/2+2));
			}
		}
		if(r*c == 9) { // 3x3
			if(n == 5) {
				return 0;
			}
			if(n == 6) {
				return 3;
			}
			if(n == 7) {
				return 6;
			}
			if(n == 8) {
				return 8;
			}
		}
		if(r*c == 12) { // 3x4
			if(n == 7) {
				return 3;
			}
			if(n == 8) {
				return 5;
			}
			if(n == 9) {
				return 8;
			}
			if(n == 10) {
				return 10;
			}
			if(n == 11) {
				return 13;
			}
		}
		if(r*c == 15) { // 3x5
			if(n == 8) {
				return 0;
			}
			if(n == 9) {
				return 3;
			}
			if(n == 10) {
				return 6;
			}
			if(n == 11) {
				return 9;
			}
			if(n == 12) {
				return 12;
			}
			if(n == 13) {
				return 14;
			}
			if(n == 14) {
				return 18;
			}
		}
		if(r*c == 16) {
			if(n == 9) {
				return 2;
			}
			if(n == 10) {
				return 4;
			}
			if(n == 11) {
				return 7;
			}
			if(n == 12) {
				return 10;
			}
			if(n == 13) {
				return 13;
			}
			if(n == 14) {
				return 16;
			}
			if(n == 15) {
				return 20;
			}
		}		
		return 0;
	}

}
