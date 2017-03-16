package magicTrick;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class MagicTrick {

	public static void main(String[] args) {
		try{
		String fileName = "C:\\Users\\Beez\\CodeJam2014\\A-small-attempt1.in";
		String outName = "C:\\Users\\Beez\\CodeJam2014\\A-Small-out.txt";
		BufferedReader in = new BufferedReader(new FileReader(fileName));
		int t = Integer.parseInt(in.readLine());
		String answer[] = new String[t];
		for(int i = 0; i < t; i++){
			int answer1 = Integer.parseInt(in.readLine());
			int row1[][] = new int[4][4];
			for(int j = 0; j < 4; j++){
				String line = in.readLine();
				for(int k = 0; k < 4; k++){
					row1[j][k] = Integer.parseInt(line.split(" ")[k]);
				}
			}
			int answer2 = Integer.parseInt(in.readLine());
			int row2[][] = new int[4][4];
			for(int j = 0; j < 4; j++){
				String line = in.readLine();
				for(int k = 0; k < 4; k++){
					row2[j][k] = Integer.parseInt(line.split(" ")[k]);
				}
			}
			int count = 0;
			int card = 0;
			int check = 0;
			for(int j = 0; j < 4; j++){
				check = row1[answer1 - 1][j];
				for(int k = 0; k < 4; k++){
					if(check == row2[answer2 - 1][k]){
						count++;
						card = check;
					}
				}
			}
			if(count == 1){
				answer[i] = "Case #" + (i + 1) + ": " + card;
			}else if(count > 1){
				answer[i] = "Case #" + (i + 1) + ": Bad Magician!";
			}else if(count < 1){
				answer[i] = "Case #" + (i + 1) + ": Volunteer Cheated!";
			}
		}
		in.close();
		PrintWriter out = new PrintWriter(new FileWriter(outName));
		for(int i = 0; i < t; i++){
			out.println(answer[i]);
		}
		out.close();
		}catch(Exception e){
			System.out.println("Error running program");
			e.printStackTrace();
		}

	}

}
