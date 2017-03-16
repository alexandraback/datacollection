import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class GoogleCodeJam2015Round1AProblemA{
	public static void main(String[] args) throws IOException{
		//Scanner input = new Scanner(System.in);
		
		Scanner input = new Scanner(new File("A-small-attempt0.in"));
		int n = input.nextInt();
		String[][] answer = new String[n][2];
		for(int i = 0; i < n; i++){
			int numOfPlates = input.nextInt();
			int[] plates = new int[numOfPlates];
			for(int m = 0; m < numOfPlates; m++){
				plates[m] = input.nextInt();
			}
			answer[i][0] = "" + firstMethod(plates);
			answer[i][1] = "" + secondMethod(plates);
		}
		input.close();
		
		PrintWriter out = new PrintWriter(new FileWriter("Round1AProblemASmall0.out"));
		for(int i = 0; i < answer.length; i++){
			out.println("Case #" + (i + 1) + ": " + answer[i][0] + " " + answer[i][1]); 
		}
		out.close();
		System.out.println(Arrays.deepToString(answer));
	}
	
	public static int firstMethod(int[] plates){
		//System.out.println(Arrays.toString(plates));
		int sum = 0;
		for(int i = 0; i < plates.length - 1; i++){
			if(plates[i] > plates[i + 1]){
				sum += plates[i] - plates[i + 1];
				
			}
		}
		//System.out.println(sum);
		return sum;
	}
	
	public static int secondMethod(int[] plates){
		int sum = 0;
		if(notEating(plates)){
			return 0;
		}
		else{
			int minSpeed = findMinSpeed(plates);
			for(int i = 0; i < plates.length - 1; i++){
				if(plates[i] >= minSpeed){
					sum += minSpeed;
				}
				else if (plates[i] < minSpeed){
					sum += plates[i];
				}
			}
			return sum;
		}
	}
	
	public static boolean notEating(int[] plates){
		for(int i = 0; i < plates.length - 1; i++){
			if (plates[i] != plates[i + 1]){
				return false;
			}
		}
		return true;
	}
	
	public static int findMinSpeed(int[] plates){
		int minSpeed = -1;
		for(int i = 0; i < plates.length - 1; i++){
			if(plates[i] > plates[i + 1]){
				int diff = plates[i] - plates[i + 1];
				int speed = diff;
				if(minSpeed == -1 || speed > minSpeed){
					minSpeed = speed;
				}
			}
		}
		return minSpeed;
	}
	
	
}
