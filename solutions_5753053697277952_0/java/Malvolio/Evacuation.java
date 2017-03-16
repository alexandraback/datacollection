package round1c;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class Evacuation {
	private static Writer writer;
	private static BufferedReader reader;

	public static void main(String[] args) throws IOException {
		File file = new File("round1c/A-small-attempt2.in");
		reader = new BufferedReader(new FileReader(file));
		
		File outputFile = new File("round1c/outputA-small.out");
		writer = new FileWriter(outputFile);
		
		int numberOfExercises = Integer.parseInt(reader.readLine());
		for (int exercise = 1; exercise <= numberOfExercises; exercise++) {
			int numberOfParties = Integer.parseInt(reader.readLine());
			String[] strings = reader.readLine().split(" ");
			int[] partysizes = new int[numberOfParties];
			for (int party = 0; party < numberOfParties; party++){
				partysizes[party] = Integer.parseInt(strings[party]);
			}
			generateOutput("Case #" + exercise + ": " + doExercise(partysizes));
		}
		reader.close();
		writer.close();
	}
	
	private static void generateOutput(String line) throws IOException {
		System.out.println(line);
		writer.write(line + "\n");
	}
	
	private static String doExercise(int[] partysizes) throws IOException {
		StringBuilder answer = new StringBuilder();
		
		int sum = 0;
		for (int p : partysizes) {
			sum+=p;
		}
		
		for (int i = 0; i < sum; i++) {
			int max = 0;
			int nextparty = 0;
			char evacuate = 0;
			for (int party = 0; party < partysizes.length; party++) {
				if (partysizes[party] > max) {
					max = partysizes[party];
					evacuate = (char) ('A' + party);
					nextparty = party;
				}
			}
			answer.append(evacuate);
			if ((sum - i) %2 == 1) {
				answer.append(" ");
			}
			partysizes[nextparty]--;
		}
		answer.deleteCharAt(answer.length()-1);
		return answer.toString();
	}
}
