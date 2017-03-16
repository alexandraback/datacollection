package TicTacToeTomek;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class TicTacToeTomek {
	

	
	public static void main(String[] argv) throws IOException {

		System.out.println(System.getProperty("user.dir"));

		File file = new File("./src/TicTacToeTomek/A-small-attempt0.in");
		FileInputStream fis = new FileInputStream(file);
		BufferedReader br = new BufferedReader(new InputStreamReader(fis));
		
		ArrayList<String> resultList = new ArrayList<String>();
		
		int num = Integer.parseInt(br.readLine());
		
		String[][] board1 = new String[4][];
		String[][] board2 = new String[4][];
		
		for (int i = 0; i < 4; i++) {
			board1[i] = new String[4];
			board2[i] = new String[4];
		}
		
		for (int i = 0; i < num; i++) {
			int line1 = Integer.parseInt(br.readLine());
			for (int j = 0; j < 4; j++) {
				board1[j] = br.readLine().split(" ");
			}
			int line2 = Integer.parseInt(br.readLine());
			for (int j = 0; j < 4; j++) {
				board2[j] = br.readLine().split(" ");
			}
			
			resultList.add(getResult(board1[line1 - 1], board2[line2 - 1]));
		}
		
		for (int i = 0; i < resultList.size(); i++) {
			System.out.println("Case #" + i + ": " + resultList.get(i));
		}
		
	}
	
	public static String getResult(String[] row1, String[] row2) {
		int count = 0;
		int posX = 0;		
		
		for (int i = 0; i < row1.length; i++) {
			for (int j = 0; j < row2.length; j++) {
				if (row1[i].equalsIgnoreCase(row2[j])) {
					posX = i;
					count++;
				}
			}
		}
		
		if (count > 1) 
			return "Bad magician!";
		if (count == 1)
			return row1[posX];
		else return "Volunteer cheated!";
	}
	
}