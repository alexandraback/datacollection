package magictrick;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class MagicTrick {

	static Scanner in=null;
	static PrintWriter out=null;
	
	public static void main(String[] args) {
		
		try {
		File file = new File("magictrickin.txt");
		File file2=new File("magictrickout.txt");
		in = new Scanner(file);
		out = new PrintWriter(file2);
		int testCases = in.nextInt();
		for (int i=0;i<testCases;i++) {
			solveCase(i+1);
		}
		out.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void solveCase(int caseNum) throws Exception {
		int row1=in.nextInt()-1;
		int[][] arrangement1=new int[4][4];
		for (int i=0;i<4;i++) {
			for (int j=0;j<4;j++) {
				arrangement1[i][j]=in.nextInt();
			}
		}
		int row2=in.nextInt()-1;
		int[][] arrangement2=new int[4][4];
		for (int i=0;i<4;i++) {
			for (int j=0;j<4;j++) {
				arrangement2[i][j]=in.nextInt();
			}
		}
		int solution = 0;
		for (int i=0;i<4;i++) {
			int possibleSolution=arrangement1[row1][i];
			System.out.println(possibleSolution);
			for (int j=0;j<4;j++) {
				if (arrangement2[row2][j]==possibleSolution) {
					if (solution!=0) {
						out.println("Case #"+caseNum+": Bad Magician!");
						return;
					} else {
						solution=possibleSolution;
					}
				}
			}
		}
		if (solution==0) {
			out.println("Case #"+caseNum+": Volunteer cheated!");
			return;
		} else {
			out.println("Case #"+caseNum+": "+solution);
			return;
		}
	}
}