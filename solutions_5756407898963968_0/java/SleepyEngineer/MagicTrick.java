package magicTrick;

import java.util.*;
import java.io.*;

public class MagicTrick {
	String res;
	int solution;
	String[] row1 = {"","","",""};
	String[] row2 = {"","","",""};
	int rowNum;
	
	String[] getArray(int row, Scanner fr){
		String[] rowTemp = {"","","",""};
		for(int i=1;i<5;i++){
			if(i==row){
				rowTemp = fr.nextLine().split(" ");
			} else {
				fr.nextLine();
			}
		}
		return rowTemp;
	}

	String solve(Scanner fr){
		solution = 0;
	
		rowNum = fr.nextInt();
		fr.nextLine();
		row1 = getArray(rowNum,fr);
		
		rowNum = fr.nextInt();
		fr.nextLine();
		row2 = getArray(rowNum,fr);
		
		for(String number:row1){
			for (String number2:row2){
				if (number.equals(number2)){
					solution += 1;
					res = number;
				}
			}
		}
		
		if (solution == 0){
			return "Volunteer cheated!";
		} else if (solution == 1){
			return res;
		} else{
			return "Bad magician!";
		}
	}

	public void doMain() throws Exception {
		Scanner fr = new Scanner(new FileReader("src/magicTrick/A-small.in"));
		PrintWriter fw = new PrintWriter(new FileWriter("src/magicTrick/A-small.out"));
		
		int caseCnt = fr.nextInt();
		
		long time = System.currentTimeMillis();
		
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {

			res = solve(fr);

			fw.println("Case #" + caseNum + ": " + res);
			
			System.out.println("Finished " + caseNum + " in " + (System.currentTimeMillis() - time) + "ms.");
		}
		
		fw.flush();
		fw.close();
		fr.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new MagicTrick()).doMain();
	}
}
