import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class prob2 {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileReader("input"));
		PrintWriter out = new PrintWriter(new FileWriter("output"));
		
		int cases = in.nextInt();
		for (int a=0; a<cases; a++) {
			int barbers = in.nextInt();
			int place = in.nextInt();
			
			int rates[] = new int[barbers];
			int highest = -1;
			for (int b=0; b<barbers; b++) {
				rates[b] = in.nextInt();
				if (rates[b] > highest) {
					highest = rates[b];
				}
			}
			
			int reset = highest;
			while (true) {
				int val = 1;
				for (int b=0; b<barbers; b++) {
					if (reset % rates[b] != 0) {
						val = 0;
					}
				}
				
				if (val == 1) {
					break;
				} else {
					reset = reset + highest;
				}
			}
			
			int resetJump=0;
			for (int b=0; b<barbers; b++) {
				resetJump = resetJump + (reset / rates[b]);
			}
						
			while (place > resetJump) {
				place = place - resetJump;
			}
			
			//System.out.println(place);
			
			int timeLeft[] = new int[barbers];
			for (int b=0; b<barbers; b++) {
				timeLeft[b] = 0;
			}
			
			while(place > 0) {
				int min = timeLeft[0];
				for (int b=0; b<barbers; b++) {
					if (timeLeft[b] < min) {
						min = timeLeft[b];
					}
				}
				
				for (int b=0; b<barbers; b++) {
					timeLeft[b] = timeLeft[b] - min;
					
					if (timeLeft[b] == 0) {
						timeLeft[b] = rates[b];
						place--;
						
						if (place == 0) {
							//System.out.println((b+1));
							out.print("Case #" + (a+1) + ": " + (b+1) + "\n");
							break;
						}
					}
				}
			}

			
		}
		
		// template output:
		// out.print("Case #" + (a+1) + ": " + time + "\n");
		
		out.close();
	}
}