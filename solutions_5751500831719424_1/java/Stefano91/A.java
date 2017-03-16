package googlejamcode2014.round1A;


import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class A {
	static final String INPUT_FILE = "1A/A/sample.in";
	static final String OUTPUT_FILE = "1A/A/sample-output.txt";
	
	public static void main(String args[]) throws Exception {
		Locale.setDefault(Locale.US);
		Scanner in = new Scanner(new File(INPUT_FILE));
		BufferedWriter out = new BufferedWriter(new FileWriter(new File(OUTPUT_FILE)));
		

		int T = in.nextInt();
		
		for (int t = 1; t <= T; t++) {
			String result = "";

			
			int N = in.nextInt();
			int L = in.nextInt();

			char[][] outlets = new char[N][L], devices = new char[N][L];

			String line;
			String[] split;
			
			
			do {
				line = in.nextLine();
			}
			while (line.equals(""));
			split = line.split(" ");
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < L; j++) {
					outlets[i][j] = split[i].charAt(j);
				}
			}

	
			do {
				line = in.nextLine();
			}
			while (line.equals(""));
			split = line.split(" ");
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < L; j++) {
					outlets[i][j] = split[i].charAt(j);
				}
			}
			
			

			
			
			

			//result = String.valueOf(count);

			out.append("Case #" + t + ": " + result);
			out.newLine();
		}


		in.close();
		out.close();
	}


	

}
