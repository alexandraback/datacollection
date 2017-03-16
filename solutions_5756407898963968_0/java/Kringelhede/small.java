package qual.a;

import java.io.BufferedWriter;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class small {
	private void solve(long case_T, Scanner reader, BufferedWriter writer) throws Exception {
		//First deck
		Set<Integer> deck1 = new HashSet<Integer>();
		int row = reader.nextInt();
		for (int i=1;i<=4;i++) {
			for (int j=1;j<=4;j++) {
				int card = reader.nextInt();
				if (row==i) {
					deck1.add(card);
				}
			}
		}

		//Second deck
		Set<Integer> deck2 = new HashSet<Integer>();
		row = reader.nextInt();
		for (int i=1;i<=4;i++) {
			for (int j=1;j<=4;j++) {
				int card = reader.nextInt();
				if (row==i) {
					deck2.add(card);
				}
			}
		}

		//Find the numbers in both sets
		deck1.retainAll(deck2);

		if (deck1.isEmpty()) {
			writeOutput(writer, case_T, "Volunteer cheated!");
		}
		else if (deck1.size()==1) {
			writeOutput(writer, case_T, deck1.iterator().next().toString());
		}
		else {
			writeOutput(writer, case_T, "Bad magician!");
		}
	}

	private void writeOutput(BufferedWriter writer, long case_T, String output) throws Exception {
		String result = String.format("Case #%d: %s",  case_T, output);

		System.out.println(result);
		writer.write(result+"\n");
	}

	private void run() throws Exception {
		Path inputFile = Paths.get(getClass().getSimpleName()+".in");
		Path outputFile = Paths.get(getClass().getSimpleName()+".out");

		Charset charset = Charset.forName("US-ASCII");
		try (
				Scanner reader = new Scanner(Files.newBufferedReader(inputFile, charset));
				BufferedWriter writer = Files.newBufferedWriter(outputFile, charset)) {
			long cases_T = new Long(reader.nextLine());

			for (long case_T = 1; case_T<=cases_T; case_T++) {
				solve(case_T, reader, writer);
			}
		}
	}

	public static void main(String... args) throws Exception {
		new small().run();
	}
}
