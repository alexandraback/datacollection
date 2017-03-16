import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class R1Q1 {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner input = new Scanner(new File("in.txt"));
		PrintWriter output = new PrintWriter(new File("out.txt"));
		int count = input.nextInt();
		int round;
		int[] mushrooms;
		int minMethodOne;
		int minMethodTwo;
		for(int i = 0; i<count; i++)
		{
			round = input.nextInt();
			mushrooms = new int[round];
			for(int x = 0; x<round; x++)
				mushrooms[x] = input.nextInt();
			
			minMethodOne = solveOne(mushrooms);
			minMethodTwo = solveTwo(mushrooms);
			output.write("Case #" + (i+1) + ": " + minMethodOne + " " + minMethodTwo + "\n");
		}
		output.close();
	}

	private static int solveTwo(int arr[]) {
		int max = 0;
		int min = 0;
		for(int a = 0; a<arr.length-1; a++)
		{
			if(arr[a] - arr[a+1] > max)
				max = arr[a] - arr[a+1];
		}
		for(int b = 0; b<arr.length-1; b++)
		{
			if(arr[b] < max)
				min+= arr[b];
			else
				min+=max;
		}
		return min;
	}

	private static int solveOne(int arr[]) {
		int min = 0;
		for(int a = 0; a<arr.length-1; a++)
		{
			if(arr[a] > arr[a+1])
				min+= arr[a] - arr[a+1];
		}
		return min;
	}

}
