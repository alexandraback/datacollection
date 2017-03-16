import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.stream.Collectors;

public class Barbers {
	
	static String	inputFile	= "B-small-attempt6";
	// static String inputFile = "test";
	static String	problemName	= "Barber";
	
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
		
		List<String> results = preprocessed.parallelStream().map(Barbers::process).collect(Collectors.toList());
		
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
		
		// StringBuilder result = new StringBuilder();
		
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

		int[] params = Arrays.stream(lines.remove(0).split(" ")).mapToInt(Integer::parseInt).toArray();
		int[] barbertimes = Arrays.stream(lines.remove(0).split(" ")).mapToInt(Integer::parseInt).toArray();
		
		int barbers = params[0];
		int customers = params[1];

		// --------------------------------------------------------------
		/*
		 * The processing code:
		 */
		// Temporary variable used at various places
		int remain;
		if (Arrays.stream(barbertimes).allMatch(i -> i == barbertimes[0])) { return Integer.toString((remain = customers % barbers) == 0 ? barbers : remain); }
		
		int lcm = Arrays.stream(barbertimes).distinct().reduce(Barbers::lcm).getAsInt();
		int cycleAmount = 0;
		for (int j : barbertimes) {
			cycleAmount += lcm / j;
		}

		customers %= cycleAmount;

		// If two barbers idle, the one with the lower id comes first
		Comparator<Barber> comp = (o1, o2) -> {
			return o1.remaining == o2.remaining ? o1.id - o2.id : o1.remaining - o2.remaining;
		};
		PriorityQueue<Barber> queue = new PriorityQueue<>(barbers, comp);
		for (int i = 0; i < barbers; i++) {
			queue.add(new Barber(i));
		}
		
		for (int i = 0; i < customers - 1; i++) {
			int tmp;
			if ((tmp = queue.peek().remaining) > 0) {
				queue.stream().forEach(b -> b.remaining -= tmp);
			}
			
			Barber b = queue.poll();
			b.remaining = barbertimes[b.id];
			queue.add(b);
		}

		// --------------------------------------------------------------

		/*
		 * Luckily String also has a toString()-Method.
		 */
		return Integer.toString(queue.peek().id + 1);
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

	public static int gcd(int a, int b) {
		while (b > 0) {
			int temp = b;
			b = a % b; // % is remainder
			a = temp;
		}
		return a;
	}

	public static int lcm(int a, int b) {
		return a * (b / gcd(a, b));
	}
}

class Barber {
	public int	id;
	public int	remaining	= 0;
	
	public Barber(int id) {
		this.id = id;
	}

	@Override
	public String toString() {
		return "Barber #" + this.id + ", remaining: " + this.remaining;
	}
}
