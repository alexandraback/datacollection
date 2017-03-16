package Round1A;

import java.util.Scanner;

public class MushroomMonster {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int testCases = in.nextInt();
		int testCaseNumber = 1;
		while(testCaseNumber <= testCases){
			int N = in.nextInt();
			int[] array = new int[N];
			for(int i=0; i<N; i++){
				array[i] = in.nextInt();
			}
			int donuts1 = solveCase1(array, N);
			int donuts2 = solveCase2(array, N);
			System.out.println("Case #"+testCaseNumber+": "+donuts1+" "+donuts2);
			testCaseNumber++;
		}
		in.close();
	}

	private static int solveCase2(int[] array, int N) {
		int maxDifference = -1;
		for(int i=1; i<N; i++){
			if(array[i] <= array[i-1]){
				if(array[i-1]-array[i] > maxDifference){
					maxDifference = array[i-1]-array[i];					
				}
			}
		}
		int donutRate = maxDifference;
		int minDonutsEaten = 0;
		for(int i=0; i<N-1; i++){
			if(array[i] < donutRate){
				minDonutsEaten = minDonutsEaten + array[i];
			}else{
				minDonutsEaten = minDonutsEaten + donutRate;
			}
		}
		return minDonutsEaten;
	}

	private static int solveCase1(int[] array, int N) {
		int minDonuts = 0;
		for(int i=1; i<N; i++){
			if(array[i] < array[i-1]){
				minDonuts = minDonuts + array[i-1] - array[i];
			}
		}
		return minDonuts;
	}
}
