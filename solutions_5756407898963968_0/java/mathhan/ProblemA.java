package codejam.y2014.qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;

public class ProblemA {
	
	static final String BAD_MAICIAN = "Bad magician!";
	static final String VOLUNTEER_CHEATED = "Volunteer cheated!";
	

	
	public ProblemA() {
	}
	
	
	
	void readLine(HashSet<Integer> values, String line) {
		String[] sp = line.split(" ");
		for (int i=0; i<sp.length; i++) {
			values.add(Integer.parseInt(sp[i]));
		}
	}
	
	
	
	HashSet<Integer> readRow(BufferedReader br) throws NumberFormatException, IOException {
		
		HashSet<Integer> values = new HashSet<Integer>();
		int row = Integer.parseInt(br.readLine());
		String[] lines = new String[4];
		for (int i=0; i<4; i++) {
			lines[i] = br.readLine();
		}
		this.readLine(values, lines[row-1]);
		return values;
	}
	
	
	String readBlock(BufferedReader br) throws IOException {
	
		HashSet<Integer> row_1 = this.readRow(br);
		HashSet<Integer> row_2 = this.readRow(br);
		
		int count = 0;
		int lastMatch = -1;
		for (Integer row2Element : row_2) {
			if (row_1.contains(row2Element)) {
				count ++;
				lastMatch = row2Element;
			}
		}
		
		if (count == 0) {
			return VOLUNTEER_CHEATED;
		} else if (count == 1) {
			return lastMatch + "";
		} else {
			return BAD_MAICIAN;
		}
		
	}
	
	
	public ArrayList<String> read(BufferedReader br) throws NumberFormatException, IOException {
		ProblemA problemA = new ProblemA();
		 ArrayList<String> results = new  ArrayList<String>();
		int cases = Integer.parseInt(br.readLine());
		for (int i=1; i<=cases; i++) {
			String result = problemA.readBlock(br);
			results.add("Case #" + i + ": " + result);
		}
		return results;
	}
	
	
	public ArrayList<String> read(String file) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new FileReader(file));
		ArrayList<String> results = this.read(br);
		br.close();
		return results;
	}
	
	
	
	public void writeResult(ArrayList<String> results, String output) throws IOException {
		BufferedWriter bw = new BufferedWriter(new FileWriter(output));
		for (int i=0; i<results.size(); i++) {
			
			bw.write(results.get(i));
			bw.newLine();
		}
		bw.close();
	}
	
	
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
	
		
		String file_name = "A-small-attempt0.in";
		///String file_name = "A-large-practice.in";
		///String file_name = "A-test";
		String test = "src/input/" + file_name;
			
		String output = "/Users/chunhan/Desktop/output/" + file_name;
		System.out.println(output);
		ProblemA problemA = new ProblemA();
		ArrayList<String> results = problemA.read(test);
		for (String result : results) {
			System.out.println(result);
		}
		problemA.writeResult(results, output);
	}
	

}
