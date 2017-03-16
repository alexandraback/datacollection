package eu.grzegorzjankowski;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class MagicTrick {

	public static void main(String[] args) {
		BufferedReader br = null;
		File file;
		
		try {
 
			String sCurrentLine;
			file = new File("c:\\CodeJam\\MagicTrick\\result.txt");
			if (file.exists()) file.delete();
			file.createNewFile();
			

			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);
			
			br = new BufferedReader(new FileReader("c:\\CodeJam\\MagicTrick\\A-small-attempt0.in"));
 
			int t = Integer.parseInt(br.readLine());
			for (int i = 0; i < t ; i++) {
				int row = Integer.parseInt(br.readLine());
				assert (row <= 4);
				
				String[] first = new String[4];
				for (int j = 0; j < 4; j++) {
					first[j] = br.readLine();
				}
				
				int row2 = Integer.parseInt(br.readLine());
				assert (row2 <= 4);
				
				String[] second = new String[4];
				for (int j = 0; j < 4; j++) {
					second[j] = br.readLine();
				}
				
				bw.write("Case #"+ (i+1) +": " + solveIt(first[row-1], second[row2-1]));
				bw.newLine();
				System.out.println(i+1);
				
			}
			bw.close();
			System.out.println("done"); 
 
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
 
	}
	
	public static String solveIt(String first, String second) {
		String[] firstDecition = first.split(" ");
		String[] secondDecition = second.split(" ");
		
		int counter = 0;
		String number = null;
		for (String a : firstDecition) {
			for (String b : secondDecition) {
				if (a.equals(b)) {counter++;
					number = a;
				}
			}
		}
		
		switch (counter) {
		case 1:
			return number;
		case 0: 
			return "Volunteer cheated!";
		default:
			return "Bad magician!";
		}
		
		
	}

	

}
