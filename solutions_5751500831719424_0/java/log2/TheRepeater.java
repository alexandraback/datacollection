import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class TheRepeater {

	private File from;
	private File to;

	public TheRepeater(String in, String out) {
		from = new File(in);
		to = new File(out);
	}

	public static void main(String[] args) throws IOException {
		 String filename = "A-small-attempt0.in";
//		String filename = "A-large-practice.in";
//		String filename = "A-my.in";
		new TheRepeater(filename, replaceExtension(filename, "out")).go();
	}

	private static String replaceExtension(String fileName,
			String desiredExtension) {
		int lastIndexOf = fileName.lastIndexOf(".");
		String fileNameWithReplacedExtension = fileName.substring(0,
				lastIndexOf) + "." + desiredExtension;
		return fileNameWithReplacedExtension;
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
		int[] ns = readIntVector(bufferedReader);
		int n = ns[0];
		String seq = null;
		boolean mismatch = false;
		int maxLength = 100;
		int[][] columnCounters = new int[maxLength][n];
		int actualMaxLength = 0;
		for (int i = 0; i < n && !mismatch; i++) {
			String line = bufferedReader.readLine();
			StringBuilder sb = new StringBuilder();
			char lastChar = '\0';
			int lastCounter = 0;
			for (int j = 0; j < line.length(); j++) {
				char curChar = line.charAt(j);
				if (j == 0 || curChar != lastChar) {
					if (j > 0)
						columnCounters[sb.length()][i] = lastCounter;
					lastCounter = 0;
					sb.append(curChar);
					lastChar = curChar;
				}
				lastCounter++;
			}
			columnCounters[sb.length()][i] = lastCounter;
			actualMaxLength = Math.max(actualMaxLength, sb.length());
			String simplified = sb.toString();
			if (i == 0)
				seq = simplified;
			else if (!seq.equals(simplified)) {
				mismatch = true;
			}
		}
		int differences = 0;
		if (!mismatch) {
			for (int i = 1; i <= actualMaxLength; i++) {
				Arrays.sort(columnCounters[i]);
				int median = columnCounters[i][n / 2];
				int mismatches = 0;
				for (int j = 0; j < n; j++) {
					mismatches += Math.abs(columnCounters[i][j] - median);
				}
				differences += mismatches;
			}
		}
		writer.print("Case #" + caseIndex + ": ");
		if (mismatch)
			writer.print("Fegla Won");
		else
			writer.print(differences);
		writer.println();
	}

	private boolean swapIfPossible(long[] speeds) {
		for (int i = speeds.length - 2; i >= 0; i--) {
			int firstIndex = i;
			int secondIndex = i + 1;
			long current = speeds[firstIndex];
			long next = speeds[secondIndex];
			if (current > next) {
				speeds[firstIndex] = next;
				speeds[secondIndex] = current;
				return true;
			}
		}
		return false;
	}

	private boolean canReach(long[] positions, long[] speeds, long spaceGoal,
			long timeGoal, long minWinningGroupSize) {
		int reachedCount = 0;
		for (int index = positions.length - 1; index >= 0; index--) {
			long positionAtEnd = positions[index] + speeds[index] * timeGoal;
			long boundedPosition = Math.min(positionAtEnd, spaceGoal);
			if (boundedPosition >= spaceGoal) {
				if (++reachedCount == minWinningGroupSize)
					return true;
				else {
					continue;
				}
			}
			return false;
		}
		return false;
	}

	private String[] readStrings(BufferedReader bufferedReader)
			throws IOException {
		String line = bufferedReader.readLine();
		return line.split(" ");
	}

	private int[] readIntVector(BufferedReader bufferedReader)
			throws IOException {
		String[] parts = readStrings(bufferedReader);
		int[] values = new int[parts.length];
		for (int i = 0; i < parts.length; i++) {
			values[i] = Integer.valueOf(parts[i]);
		}
		return values;
	}
}
