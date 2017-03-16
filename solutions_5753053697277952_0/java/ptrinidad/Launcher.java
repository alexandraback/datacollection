package commons;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Launcher {

	public static void main(String[] args) throws IOException {
		File inFile = new File("A-small-attempt0.in");
	    File outFile = new File("A-small-attempt0.out");
	    Scanner in = new Scanner(inFile);
	    BufferedWriter out = new BufferedWriter(new FileWriter(outFile));
	    int testCases = in.nextInt();
	    for(int t=1;t<=testCases;t++){
	    	Problem problem = processLine(in);
	    	Result result = problem.execute();

	        out.write("Case #" + t + ":" + result + "\n");
	    }
	    in.close();
	    out.close();

	}

	private static Problem processLine(Scanner in) {
		int nParties = in.nextInt();
		int totalMembers = 0;
		int partyMembers[] = new int[nParties];
		for (int i = 0; i < nParties; i++) {
			partyMembers[i] = in.nextInt();
			totalMembers += partyMembers[i];
		}
				
		return new Problem(partyMembers,totalMembers);
	}



}
