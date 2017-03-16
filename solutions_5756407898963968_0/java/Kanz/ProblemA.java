package googleJam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemA {
	public static void main(String[] args){
		String filename = "src/input.txt";
		String output = "src/output.txt";
		String answer = "";
		
		try {
			Scanner scan = new Scanner(new File(filename));
			int a = scan.nextInt();
			for(int i = 0; i < a; i++){
				int row1 = scan.nextInt()-1;
				scan.nextLine();
				String[][] arr1 = new String[4][];
				for(int j = 0; j < 4; j++){
					arr1[j] = scan.nextLine().split(" ");
					System.out.println(Arrays.toString(arr1[j]));
				}
				int row2 = scan.nextInt()-1;
				scan.nextLine();
				String[][] arr2 = new String[4][];
				for(int j = 0; j < 4; j++){
					arr2[j] = scan.nextLine().split(" ");
				}
				for(int j = 0; j < 4; j++){
					for(int k = 0; k < 4; k++){
						System.out.print(arr1[j][k] + "-" + arr2[j][k] + " ");
					}
					System.out.print("\n");
				}
				int count = 0;
				String numb = "";
				for(int j = 0; j < 4; j++){
					for(int k = 0; k < 4; k++){
						if (arr1[row1][j].equals(arr2[row2][k])){
							count++;
							numb = arr1[row1][j];
						}
					}
				}
				answer += "Case #" + (i+1) + ": ";
				if(count == 1){
					answer += numb + "\n"; 
				}else if (count > 1){
					answer += "Bad magician!\n";
				}else{
					answer += "Volunteer cheated!\n";
				}
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		try {
			PrintWriter writer = new PrintWriter(new File(output));
			writer.print(answer);
			writer.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
	}
}
