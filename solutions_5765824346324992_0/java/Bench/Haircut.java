import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Haircut{

	public static void main(String[] args) {
		Scanner scanner = null;
		try {
			scanner = new Scanner(new File("input.txt"));
		} catch (FileNotFoundException e) {
			System.out.println("Couldn't open input file.\n" + e.getMessage());
			e.printStackTrace();
		}
		FileWriter writer = null;
		try {
			writer = new FileWriter(new File("output.txt"));
		} catch (IOException e) {
			System.out.println("Couldn't open/make output file." + e.getMessage());
			e.printStackTrace();
		}
		
		int numTrials = scanner.nextInt();
		for (int trial = 1; trial <= numTrials; trial++) {
			try {
				System.out.println("Trial #" + trial);
				writer.write("Case #" + trial + ": ");
				solveTrial(scanner, writer);
				writer.write("\n");
			}catch (IOException e) {
				System.out.println("Error on trial #" + trial + "\n" + e.getMessage());
				e.printStackTrace();
			}
		}
		try {
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		scanner.close();
		System.out.println("Completed Trials!");
	}
	static void solveTrial(Scanner scanner, FileWriter writer)
			throws IOException {
		int B = scanner.nextInt();
		long N = scanner.nextLong();
		int[] M = new int[B];
		int max = 0;
		int min = Integer.MAX_VALUE;
		for (int i =0; i< B; i++){
			M[i] = scanner.nextInt();
			max = Math.max(M[i],max);
			min = Math.min(M[i], min);
		}
		if (N <= B)
			writer.write("" + N);
		else{
			long maxSearch = (N/B)*max + max;
			long minSearch = Math.max((N/B)*min - (2 * min),0);
			long search = (maxSearch + minSearch)/2;
			for (;;){
				long currNumHair = numHaircut(search, M);
				//System.out.println("search = " + search + " min = " + minSearch + " max = " + maxSearch + "\ncurr num = " + currNumHair);
				if (currNumHair < N){
					minSearch = search;
				}else if (currNumHair >= N){
					maxSearch = search;
				}
				if (maxSearch <= minSearch + 1){
					long numRemaining = N - numHaircut(minSearch,M);
					for (int i = 0; i < B; i++){
						if (maxSearch % M[i] == 0){
							numRemaining--;
							//System.out.println("num rem" + numRemaining);
							if (numRemaining == 0){
								writer.write("" + (i+1));
								return;
							}
						}
					}
					return;
				}else{
					search = (minSearch + maxSearch)/2;
				}
			}
		}
	}
	
	static long numHaircut(long minute, int[] M){
		long returnValue = 0;
		for (int i = 0; i < M.length; i++){
			returnValue += (minute/M[i]) + 1;
		}
		return returnValue;
	}
}
