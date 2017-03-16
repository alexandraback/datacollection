package spikemf.googlecodejam.rounds;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.FileWriter;
import java.io.BufferedWriter;

/* Magic Trick*/


public class QA {
	static String infilename = "A-small-attempt0.in";
	static String outfilename = "qa.out";
	static BufferedWriter out;
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new FileReader(infilename));
		int cases = Integer.parseInt(br.readLine());
		int[][] array1 = new int[4][4];
		int[][] array2 = new int[4][4];
		for (int i=1;i<=cases;i++) {
			int l1 = Integer.parseInt(br.readLine()) - 1;
			for (int j =0; j<4;j++) {
				array1[j] = parseIntArray(br.readLine());
			}
			int l2 = Integer.parseInt(br.readLine()) - 1;
			for(int j=0;j<4;j++) {
				array2[j] = parseIntArray(br.readLine());
			}

			int[] line1 = array1[l1];
			int[] line2 = array2[l2];
			
			handleLines(line1,line2);
		}
		br.close();
		if (out != null) out.close();
	}
	private static int[] parseIntArray(String line) {
		String[] s = line.split(" ");
		int[] array = new int[4];
		for (int i=0;i<4;i++) {
			array[i] = Integer.parseInt(s[i]);
		}
		return array;
	}
	static int caseNumber = 1;
	public static void writeLine(String line) throws IOException {
		if (out == null) {
			out = new BufferedWriter(new FileWriter(outfilename));
		}
		if (line == null) return;
		line = line.trim();
		if (line == "") return;
		out.write("Case #" + (caseNumber++) + ": ");
		out.write(line);
		out.write("\n");
	}
	public static void handleLines(int[] line1, int[] line2) throws IOException {
		
		/** if line1 intersect line2 == 1 number, ok
		 * if >1 bad magician
		 * if 0 cheated
		 */
		int overlap = 0;
		int lastmatch = 0;
		for (int i=0;i<4;i++) {
			int candidate = line1[i];
			for (int k: line2) {
				if (candidate == k) {
					overlap++;
					lastmatch = candidate;
				}
			}
		}
		String output;
		if (overlap == 0) {
			output = "Volunteer cheated!";
		} else if (overlap == 1) {
			output = "" + lastmatch;
		} else {
			output = "Bad magician!";
		}
		
		writeLine(output);
	}
}

