package shb.test.codejam.k14;

import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import shb.test.codejam.JamInputReader;

public class MagicTrick {
	private JamInputReader jam;
	private StringBuffer out;

	public static void main(String[] args) throws IOException {
//		MagicTrick problem = new MagicTrick("magic-sample.in");
		MagicTrick problem = new MagicTrick("A-small-attempt0.in");
		

		int tests = problem.jam.readInt();
		assert (1 <= tests) && (tests <= 100);
		for (int t = 1; t <= tests; t++) {
			problem.doTrick(t);
		}
		problem.jam.close();
		problem.printResults();
	}

	private void doTrick(int t) throws NumberFormatException, IOException {
		List<Integer> first = new ArrayList<Integer>();
		int[] row1 = readRow();
		for (int i = 0; i < 4; i++) {
			first.add(row1[i]);
		}

		int[] row2 = readRow();

		int card = 0;
		int count = 0;
		for (int i = 0; i < 4; i++) {
			if (first.contains(row2[i])) {
				count++;
				card = row2[i];
			}
		}

		String result;
		switch (count) {
		case 0:
			result = "Volunteer cheated!";
			break;
		case 1:
			result = card + "";
			break;
		default:
			result = "Bad magician!";
		}
		if (t>1)out.append("\n");
		out.append("Case #"+t+": " + result);
	}

	private int[] readRow() throws NumberFormatException, IOException {
		int row = jam.readInt();
		assert 1 <= row && row <= 4;
		int[] cards = new int[4];
		// read first row
		for (int i = 1; i <= row; i++) {
			cards = jam.readIntArray(4);
		}
		// advance to end of matrix
		for (int i = row + 1; i <= 4; i++) {
			jam.readIntArray(4);
		}
		return cards;
	}
	
	private void printResults() throws IOException {
		BufferedWriter writer = new BufferedWriter(new FileWriter("magicTrick.out"));
		writer.append(out.toString());
		writer.close();
	}

	public MagicTrick(String filename) throws FileNotFoundException {
		jam = new JamInputReader(filename);
		out = new StringBuffer();
	}
}
