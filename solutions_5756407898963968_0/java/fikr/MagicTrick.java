//Google Code Jam Qualification Round 2014
//Problem A. Magic Trick

import java.util.*;
import java.io.*;

class MagicTrick{
	static String inname = "A-small-attempt0.in";    // input file name here
	static String outname = "A-small-attempt0.out";  // output file name here
	static int n;
	public static void main(String[] args){
		try{
			Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
			//Scanner in = new Scanner(System.in);
			BufferedWriter out = new BufferedWriter(new FileWriter(outname));
			int t = in.nextInt();
			in.nextLine();
			for (int cas = 1; cas <= t; cas++){
				String ans = "";
				int a1 = in.nextInt();
				int card1[][] = new int[4][4];
				for (int i = 0; i < 4; i++){
					for (int j = 0; j < 4; j++){
						card1[i][j] = in.nextInt();
					}
				}
				int a2 = in.nextInt();
				int card2[][] = new int[4][4];
				for (int i = 0; i < 4; i++){
					for (int j = 0; j < 4; j++){
						card2[i][j] = in.nextInt();
					}
				}
				ans = solve(a1, card1, a2, card2);
				//System.out.print("Case #" + cas + ": " + ans + "\n");
				out.write("Case #" + cas + ": " + ans + "\n");
			}
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static String solve(int a1, int[][] card1, int a2, int[][] card2){
		int[] row1 = new int[4];
		int[] row2 = new int[4];
		for (int i = 0; i < 4; i++){
			row1[i] = card1[a1-1][i];
			row2[i] = card2[a2-1][i];
		}
		int count = 0;
		int lastMatch = -1;
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				if (row1[i] == row2[j]){ 
					count++;
					lastMatch = row1[i];
				}
			}
		}
		if (count == 1) return "" + lastMatch;
		else if (count < 1) return "Volunteer cheated!";
		else return "Bad magician!";
	}
}