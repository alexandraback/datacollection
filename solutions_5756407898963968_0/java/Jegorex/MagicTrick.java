import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

/**
 * @author Jelle Prins
 */
public class MagicTrick {

	public static void main(String[] args) {
		String input = "input.txt";
		String output = "output.txt";
		if (args.length >= 1) {
			input = args[0];
			if (args.length >= 2) {
				output = args[1];
			}
		}
		new MagicTrick(input, output);
	}

	private class Case {
		private String line1;
		private String line2;
	}

	public MagicTrick(String inputString, String outputString) {
		File input = new File(inputString);
		File output = new File(outputString);
		if (!input.isFile()) {
			System.err.println("input file not found");
			System.exit(1);
		}
		if (output.exists()) {
			output.delete();
		}

		try {
			Case[] cases = readInput(input);
			String[] results = executeCases(cases);
			writeOutput(output, results);
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	private Case[] readInput(File file) throws Exception {
		Scanner scanner = new Scanner(file);
		int caseCount = scanner.nextInt();
		scanner.nextLine();
		Case[] cases = new Case[caseCount];
		for (int i = 0; i < caseCount; i++) {
			cases[i] = new Case();
			int line = scanner.nextInt();
			for (int j = 0; j < line; j++) {
				scanner.nextLine();
			}
			cases[i].line1 = scanner.nextLine();
			for (int j = 0; j < 4 - line; j++) {
				scanner.nextLine();
			}
			line = scanner.nextInt();
			for (int j = 0; j < line; j++) {
				scanner.nextLine();
			}
			cases[i].line2 = scanner.nextLine();
			for (int j = 0; j < 4 - line; j++) {
				scanner.nextLine();
			}
		}
		scanner.close();
		return cases;
	}

	private String[] executeCases(Case[] cases) {
		String[] output = new String[cases.length];
		for (int i = 0; i < cases.length; i++) {
			output[i] = executeCase(i + 1, cases[i]);
		}
		return output;
	}

	private void writeOutput(File output, String[] results) throws Exception {
		PrintWriter pw = new PrintWriter(new FileWriter(output));
		for (int i = 0; i < results.length; i++) {
			if (i != results.length - 1) {
				pw.println(results[i]);
			} else {
				pw.print(results[i]);
			}
		}
		pw.close();
	}

	private String executeCase(int caseID, Case input) {
		List<Integer> found = new ArrayList<Integer>();
		Set<Integer> set = new HashSet<Integer>();
		String[] s1 = input.line1.split(" ");
		String[] s2 = input.line2.split(" ");

		for (int i = 0; i < 4; i++) {
			set.add(Integer.parseInt(s1[i]));
		}
		for (int i = 0; i < 4; i++) {
			int number = Integer.parseInt(s2[i]);
			if (!set.add(number)) {
				found.add(number);
			}
		}

		if (found.size() == 1) {
			return parseOutput(caseID, found.get(0).toString());
		} else if (found.size() == 0) {
			return parseOutput(caseID, "Volunteer cheated!");
		} else {
			return parseOutput(caseID, "Bad magician!");
		}
	}

	private String parseOutput(int caseID, String answer) {
		String output = "Case #" + caseID + ": " + answer;
		System.out.println(output);
		return output;
	}
}
