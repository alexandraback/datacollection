import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;

public class MagicTrick {

	private File from;
	private File to;

	public MagicTrick(String in, String out) {
		from = new File(in);
		to = new File(out);
	}

	public static void main(String[] args) throws IOException {
		new MagicTrick(args[0], args[1]).go();
	}

	private void go() throws IOException {
		try (FileReader fileReader = new FileReader(from)) {
			try (BufferedReader bufferedReader = new BufferedReader(fileReader)) {
				int cases = getNextInt(bufferedReader);
				translateAll(cases, bufferedReader);
			}
		}

	}

	private int getNextInt(BufferedReader bufferedReader) throws IOException {
		String readLine = bufferedReader.readLine();
		return Integer.valueOf(readLine);
	}

	private void translateAll(int count, BufferedReader bufferedReader)
			throws IOException {
		try (PrintWriter writer = new PrintWriter(new FileWriter(to))) {
			for (int i = 1; i <= count; i++) {
				translateNext(i, bufferedReader, writer);
			}
		}
	}

	private void translateNext(int caseIndex, BufferedReader bufferedReader,
			PrintWriter writer) throws IOException {
		int row1 = getNextInt(bufferedReader);
		int[][] arrangement1 = readMatrix(bufferedReader);
		int row2 = getNextInt(bufferedReader);
		int[][] arrangement2 = readMatrix(bufferedReader);

		Set<Integer> firstSet = getSet(row1, arrangement1);
		Set<Integer> secondSet = getSet(row2, arrangement2);

		firstSet.retainAll(secondSet);

		writer.print("Case #" + caseIndex + ": ");
		switch (firstSet.size()) {
		case 1: {
			writer.print(firstSet.iterator().next());
			break;
		}

		case 0: {
			writer.print("Volunteer cheated!");
			break;
		}

		default: {
			writer.print("Bad magician!");
			break;
		}
		}
		writer.println();
	}

	private Set<Integer> getSet(int row, int[][] arrangement) {
		Set<Integer> values = new HashSet<>();
		for (int i : arrangement[row - 1]) {
			values.add(i);
		}
		return values;
	}

	private int[][] readMatrix(BufferedReader bufferedReader)
			throws IOException {
		int[][] matrix = new int[4][];
		for (int i = 0; i < 4; i++) {
			matrix[i] = readVector(bufferedReader);
		}
		return matrix;
	}

	private int[] readVector(BufferedReader bufferedReader) throws IOException {
		String line = bufferedReader.readLine();
		String[] parts = line.split(" ");
		int[] values = new int[parts.length];
		for (int i = 0; i < parts.length; i++) {
			values[i] = Integer.valueOf(parts[i]);
		}
		return values;
	}
}
