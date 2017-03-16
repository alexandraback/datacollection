import java.io.*;
import java.util.*; 

public class Round1A {

	int cases;
	
	void process(Scanner scanner, PrintStream out) throws IOException {
		cases = scanner.nextInt();
		scanner.nextLine();
		
		for (int n = 0; n < cases; n++) {
			int N = scanner.nextInt();
			int[] arr = new int[N];
			for (int i = 0; i < N; i++) {
				arr[i] = scanner.nextInt();
			}
			
			int met1 = 0, minSpeed = 0;
			for (int i = 1; i < N; i++) {
				if (arr[i] < arr[i-1]) {
					int diff = arr[i-1] - arr[i];
					met1 += diff;
					if (diff > minSpeed)
						minSpeed = diff;
				}
			}

			int met2 = 0;
			for (int i = 1; i < N; i++) {
				int diff = arr[i-1] - arr[i];
				if (diff < minSpeed)
					diff = minSpeed;
				if (diff > arr[i-1])
					diff = arr[i-1];
				met2 += diff;
			}
			
			out.println("Case #" + (n + 1) + ": " + met1 + " " + met2);
		}
	}
	
	Round1A() throws IOException {
		/*String sampleText = "4\r\n" + 
				"4\r\n" + 
				"10 5 15 5\r\n" + 
				"2\r\n" + 
				"100 100\r\n" + 
				"8\r\n" + 
				"81 81 81 81 81 81 81 0\r\n" + 
				"6\r\n" + 
				"23 90 40 0 100 9"; 
		Scanner in = new Scanner(sampleText);
		PrintStream out = System.out;
		*/
		/*
		Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\A-small-attempt0.in"));
		PrintStream out = new PrintStream("out-A-small.txt");
		*/
		
		Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\A-large.in"));
		PrintStream out = new PrintStream("out-A-large.txt");
		

		
		process(in, out);
		
		in.close();
		out.close();
	}	
	
	public static void main(String[] args) throws IOException {
		new Round1A();
	}	
	
}
