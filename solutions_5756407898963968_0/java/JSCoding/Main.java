import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 * Main Class
 * Solves all Google Code Jam Tasks.
 * @author Jones
 */
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		// read input file and prepare buffered writer
		Scanner sc = new Scanner(new File("A-small-attempt0.in"));
		BufferedWriter wr = new BufferedWriter(new FileWriter("A-small-attempt0.out"));
		// get the number of test cases
		int noCases = sc.nextInt();

		for(int i=0; i<noCases; i++) {
			String line = "";
			int cRowA = 0;
			int cRowB = 0;
			int[] inputA = new int[4];
			int[] inputB = new int[4];
			
			// chosen row
			
			for(int row = 0; row < 2; row++){
				int[] inRef = null;
				// chosen row
				if(row == 0){
					cRowA = sc.nextInt();
					inRef = inputA;
				} else { 
					cRowB = sc.nextInt();
					inRef = inputB;
				}
				sc.nextLine();
				
				for(int t = 1; t <= 4; t++){
					line = sc.nextLine();
					
					if((row == 0 && cRowA == t)|| (row == 1 && cRowB == t)){
						String[] helper = new String[4];
						helper = line.split(" ");
						// convert to int
						for(int x = 0; x < inRef.length; x++){
							inRef[x] = Integer.parseInt(helper[x]);
						}
					}
				}
			}
			
			// calculate result
			int hits = 0;
			int lastHit = 0;
			for(int m = 0; m < inputA.length; m++){
				for(int n = 0; n < inputB.length; n++){
					if(inputA[m] == inputB[n]){
						hits++;
						lastHit = inputA[m];
					}
				}
			}
			
			if(hits == 1){
				wr.write("Case #" + (i+1) + ": " + lastHit);
			}else if(hits == 0){
				wr.write("Case #" + (i+1) + ": Volunteer cheated!");
			}else{
				wr.write("Case #" + (i+1) + ": Bad magician!");
			}
			wr.newLine();
		}
		wr.close();
	}

}
