import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.stream.Collectors;

public class Mushrooms {
	
	static String	inputFile	= "A-large";
	static String	problemName	= "Mushrooms";
	
	static Path		in			= Paths.get("./" + inputFile + ".in");
	// Path in = Paths.get("./test.in");
	static Path		out			= Paths.get("./" + problemName + ".out");
	
	public static void main(String[] args) throws IOException {
		List<String> lines = Files.lines(in).skip(1).collect(Collectors.toList());
		
		List<List<String>> preprocessed;
		
		/*
		 * The following block is just a preparation because I don't know beforehand how many lines I will have to join for the problem.
		 */
		
		// int group = 1;
		// preprocessed = preprocessLinesEvenSpaced(lines, group);
		
		// preprocessed = preprocess1(lines);
		preprocessed = preprocess2(lines);
		// preprocessed = preprocess3(lines);
		// preprocessed = preprocess4(lines);
		// preprocessed = preprocess5(lines);

		// preprocessed = new LinkedList<>();
		// while (!lines.isEmpty()) {
		// int[] params = Arrays.stream(lines.get(0).split(" ")).mapToInt(Integer::parseInt).toArray();
		// preprocessLinesUnevenSpaced(preprocessed, lines, Arrays.stream(params).sum() + 1); //The +1 makes the params list a part of the processed list.
		// }
		
		List<String> results = preprocessed.parallelStream().map(Mushrooms::process).collect(Collectors.toList());
		
		StringBuilder output = new StringBuilder();
		String prefix = "";
		{
			int i = 1;
			for (Object element : results) {
				String string = (String) element;
				output.append(prefix).append("Case #").append(i++).append(": ").append(string);
				prefix = "\n";
			}
		}
		Files.write(out, output.toString().getBytes());
	}
	
	public static String process(List<String> lines) {
		
		/*
		 * Preparation for the result. Either something to assemble or a static result.
		 */
		
		StringBuilder result = new StringBuilder();
		
		// String constant1 = "";
		// String constant2 = "";
		// String constant3 = "";
		// String result = constant0;
		
		// -------------------------------------------------------------

		/*
		 * If necessary, the first line contains an arbitray of int-Parameters. This is singled out by the following code.
		 */

		// int[] params = Arrays.stream(lines.get(0).split(" ")).mapToInt(Integer::parseInt).toArray();
		// lines.remove(0);

		int N = Arrays.stream(lines.remove(0).split(" ")).mapToInt(Integer::parseInt).toArray()[0];
		int[] m = Arrays.stream(lines.remove(0).split(" ")).mapToInt(Integer::parseInt).toArray();

		// --------------------------------------------------------------
		/*
		 * The processing code:
		 */
		int firstMethod = 0;
		int secondMethod = 0;
		int maxDist = 0;
		for (int i = 1; i < m.length; i++) {
			if (m[i] < m[i - 1]) {
				int dist = m[i - 1] - m[i];
				
				firstMethod += dist;
				maxDist = dist > maxDist ? dist : maxDist;
			}
		}
		
		for (int i = 0; i < m.length - 1; i++) {
			secondMethod += maxDist < m[i] ? maxDist : m[i];
		}
		
		result.append(firstMethod).append(" ").append(secondMethod);
		// --------------------------------------------------------------

		/*
		 * Luckily String also has a toString()-Method.
		 */
		return result.toString();
	}
	
	/**
	 * Groups multiple lines into a single list to ease processing later on.
	 *
	 * @param lines
	 *            The single lines to group
	 * @param group
	 *            How many lines to group
	 * @return a list of grouped lines.
	 */
	@SuppressWarnings("null")
	public static List<List<String>> preprocessLinesEvenSpaced(List<String> lines, int group) {
		List<List<String>> preprocessedLines = new LinkedList<>();
		
		int tmp = 0;
		List<String> tmpList = null;
		for (Object element : lines) {
			if (tmp == 0) {
				if (tmpList != null) {
					preprocessedLines.add(tmpList);
				}
				tmpList = new LinkedList<>();
			}
			String s = (String) element;
			tmpList.add(s);
			tmp = (tmp + 1) % group;
		}
		
		preprocessedLines.add(tmpList);
		
		return preprocessedLines;
	}

	/**
	 * Does magic referencing to remove processed lines from the input-lines and add it to the processed lines. It is almost 03:00 AM here so forgive me.
	 *
	 * @param toAddTo
	 *            Where to
	 * @param lines
	 *            Where from
	 * @param group
	 *            How many
	 */
	public static void preprocessLinesUnevenSpaced(List<List<String>> toAddTo, List<String> lines, int group) {
		List<String> tmpList = new LinkedList<>();
		for (int i = 0; i < group; i++) {
			tmpList.add(lines.remove(0));
		}
		toAddTo.add(tmpList);
	}

	/*
	 * The following methods are just quick ways to preprocess a given set of lines. I use it to just uncomment a line without further thinking.
	 */
	
	public static List<List<String>> preprocess1(List<String> lines) {
		return preprocessLinesEvenSpaced(lines, 1);
	}
	
	public static List<List<String>> preprocess2(List<String> lines) {
		return preprocessLinesEvenSpaced(lines, 2);
	}
	
	public static List<List<String>> preprocess3(List<String> lines) {
		return preprocessLinesEvenSpaced(lines, 3);
	}
	
	public static List<List<String>> preprocess4(List<String> lines) {
		return preprocessLinesEvenSpaced(lines, 4);
	}
	
	public static List<List<String>> preprocess5(List<String> lines) {
		return preprocessLinesEvenSpaced(lines, 5);
	}
}
