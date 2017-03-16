import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;



public class problemA {

	private class Node {
		int num;
		
	}
	public static void main(String[]args) throws IOException {
		Scanner input = new Scanner(new File("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter("smallAOut0.txt")); 
		int testCases = input.nextInt();
		for (int i=1; i<=testCases; i++) {
			int word = input.nextInt();
			String [] words = new String[word];
			int[] indexes = new int[word];
			int[] repeats = new int[word];
			int count = 0;
			boolean impossible = false;
			for (int x=0; x<word; x++) {
				words[x] = input.next();
			}
			boolean done = false;
			
			
			do {
				char last = words[0].charAt(indexes[0]);
				for (int x=1; x<word; x++) {
					if (last != words[x].charAt(indexes[x])) {
						impossible = true;
					}
				}
				
				if (!impossible) {
					
					for (int x=0; x<word; x++) {
						repeats[x] = 0;
						while (indexes[x]<words[x].length() && words[x].charAt(indexes[x])==last) {
							indexes[x]++;
							repeats[x]++;
						}
					}
					
					Arrays.sort(repeats);
					int median = repeats[word/2];
					for (int x=0; x<word; x++) {
						count += Math.abs(repeats[x] - median);
					}
				}
				
				done = false;
				for (int x=0; x<word; x++) {
					if (indexes[x]>=words[x].length()) {
						done = true;
					}
				}
				
			} while(!impossible && !done);

			for (int x=0; x<word; x++) {
				if (indexes[x]<words[x].length()) {
					impossible = true;
				}
			}

			out.print("Case #" + i + ": ");
			if (!impossible) {
				out.println(count);
			} else {
				out.println("Fegla Won");
			}
			
			
			
			
		}
		out.close();
	}
	
}
