import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

public class Main {

	static FileReader fr;
	static Scanner sc;
	static FileWriter fw;

	public static void openFiles(String inFile, String outFile) throws IOException {	
		fr = new FileReader(inFile);
		fw = new FileWriter(outFile);
		sc = new Scanner(fr);
		sc.useLocale(Locale.US);
	}
	public static void closeFiles() throws IOException {
		sc.close();
		fw.close();
		fr.close();
	}
	public static void writeLine(String line) throws IOException {
		write(line + "\n");
	}
	public static void write(String str) throws IOException {
		System.out.print(str);
		fw.write(str);
	}


	public static void main(String[] args) throws Exception {
		openFiles("A-large.in", "output.txt");

		int t = sc.nextInt();
		sc.nextLine();

		// launch processCase(i) for every test case
		for (int i=1; i<=t; i++) {
			write("Case #"+i+":");
			processCase(i);
			writeLine("");
		}

		closeFiles();
	}

	public static void processCase(int caseNumber) throws Exception { 
		int n = sc.nextInt();
		int parties[] = new int[n];
		
		for (int i=0; i<n; i++) {
			parties[i] = sc.nextInt();
		}
		
		while(true) {
			int party1 = getBiggestParty(parties);
			char char1 = (char) ('A' + party1);
			if (party1 == -1) break;
			
			parties[party1] -= 1;
			int party2 = getBiggestParty(parties);
			char char2 = (char) ('A' + party2);
			parties[party2] -= 1;
			
			if (wouldHaveMajority(parties)) {
				parties[party2]++;
				write(" " + char1);
			} else {
				write(" " + char1 + "" + char2);
			}
		}
	}
	
	public static int getBiggestParty(int parties[]) {
		int best = -1;
		int bestSize = 0;
		for (int i=0; i<parties.length; i++) {
			if (parties[i] > bestSize) {
				best = i;
				bestSize = parties[i];
			}
		}
		return best;
	}
	
	public static boolean wouldHaveMajority(int parties[]) {
		int bestSize = 0;
		int total = 0;
		
		for (int i=0; i<parties.length; i++) {
			if (parties[i] > bestSize) {
				bestSize = parties[i];
			}
			total += parties[i];
		}
		
		return bestSize > total/2;		
	}
	
}
