package codeJam2015;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;

public abstract class Cases {

	public static Case[] readAllCases(String file, int caseSize) throws IOException {
		if(file == null || file.length() == 0)
			throw new IllegalArgumentException();
		Path path = Paths.get(file);
		BufferedReader br = Files.newBufferedReader(path, StandardCharsets.UTF_8);
		int caseNum = Integer.parseInt(br.readLine());
		Case[] cases = new Case[caseNum];
		int i = 0;
		while(br.ready()) {
			cases[i] = new Case(i + 1);
			for(int j = 0; j < caseSize; j++)
				cases[i].input.add(br.readLine());
			i++;
		}
		br.close();
		return cases;
	}
	
	public static void writeOutput(String outputFile, Case[] cases) throws IOException {
		String data = "";
		for(Case ca : cases) {
			data += ca.toString() + "\n";
		}
		BufferedWriter bw = Files.newBufferedWriter(Paths.get(outputFile), StandardCharsets.UTF_8);
		bw.write(data);
		bw.close();
	}
	
	public static class Case {
		static final String title = "Case #";
		int id;
		ArrayList<String> input;
		String output;
		
		protected Case(int id) {
			this.id = id;
			this.input = new ArrayList<String>();
			this.output = "";
		}
		
		@Override
		public String toString() {
			return title + id + ": " + (output == null ? "" : output);
		}
	}
}