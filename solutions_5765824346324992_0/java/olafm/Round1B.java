import java.io.*;
import java.util.*; 

public class Round1B {

	int cases;
	
	void process(Scanner scanner, PrintStream out) throws IOException {
		cases = scanner.nextInt();
		scanner.nextLine();
		
		for (int n = 0; n < cases; n++) {
			int B = scanner.nextInt();
			long N = scanner.nextLong();
			int[] M = new int[B];
			long[] free = new long[B];
			long max = 1;
			boolean maxOk = true;
			for (int i = 0; i < B; i++) {
				M[i] = scanner.nextInt();
				free[i] = 0;
				if (/*max % M[i] != 0 && */maxOk)
					if (max < Long.MAX_VALUE / M[i])
						max *= M[i];
					else
						maxOk = false;
			}
			if (maxOk) {
				long b = 0;
				for (int i = 0; i < B; i++) {
					b += max / M[i];
				}
				N = N % b;
				if (N == 0)
					N = b;
			}
			
			int which = 0;
			for (int p = 0; p < N; p++) {
				long minTime = Long.MAX_VALUE;
				int barber = -1;
				for (int i = 0; i < B; i++) 
					if (free[i] < minTime) {
						barber = i;
						minTime = free[i];
					}
				free[barber] += M[barber];
				which = barber + 1;
				//System.err.println(which + " ");
			}
			//System.err.println();
			System.out.println("Case #" + (n + 1) + ": " + which + " " + N + " " + B);
			out.println("Case #" + (n + 1) + ": " + which);
		}
	}
	
	Round1B() throws IOException {
		/*String sampleText = "3\r\n" + 
				"2 4\r\n" + 
				"10 5\r\n" + 
				"3 12\r\n" + 
				"7 7 7\r\n" + 
				"3 8\r\n" + 
				"4 2 1"; 
		Scanner in = new Scanner(sampleText);
		PrintStream out = System.out;*/
		
		
		Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\B-small-attempt2.in"));
		PrintStream out = new PrintStream("out-B-small.txt");
		
		/*
		Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\B-large.in"));
		PrintStream out = new PrintStream("out-B-large.txt");
		*/

		
		process(in, out);
		
		in.close();
		out.close();
	}	
	
	public static void main(String[] args) throws IOException {
		new Round1B();
	}	
	
}
