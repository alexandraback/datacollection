import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Scanner;


public class Neighbours {
	
	public static long minUnhappy(int R, int C, int N) {
		
		long happy = (R*C+1)/2;
		
		long unhappy1 = 0;
		long unhappy2 = 0;
		long unhappy3 = 0;
		long unhappy4 = 0;
		if (R == 1 || C == 1) {
			unhappy1 = (R*C+1)%2;
			unhappy2 = R*C-happy-unhappy1;
		} else {
			if (R%2==0 || C%2==0) {
				unhappy2 = 2;
			}
			unhappy3 = R+C-2-unhappy2;
			unhappy4 = (R-2)*(C-2)-((R-2)*(C-2)+1)/2;
		}
		
		if (happy + unhappy1 + unhappy2 + unhappy3 + unhappy4 != R*C) {
			System.err.println("problem: " + Integer.toString(R) + " " + Integer.toString(C));
			System.err.println("problem: 0:" + Long.toString(happy) + " 1:" + Long.toString(unhappy1) + " 2:" + Long.toString(unhappy2));
			System.err.println("problem: 3:" + Long.toString(unhappy3) + " 4:" + Long.toString(unhappy4));
		}
		
		if (N <= happy) {
			return 0;
		}
		N -= happy;
		long unhappiness = 0;
		
		if (N <= unhappy1) {
			return N;
		}
		N -= unhappy1;
		unhappiness += unhappy1;
		
		if (N <= unhappy2) {
			return unhappiness + N*2;
		}
		N -= unhappy2;
		unhappiness += unhappy2*2;
		
		if (N <= unhappy3) {
			if (R%2==1 && C%2==1) {
				return unhappiness + N*3 - 1;
			}
			return unhappiness + N*3;
		}
		N -= unhappy3;
		unhappiness += unhappy3*3;
		
		if (R%2==1 && C%2==1) {
			return unhappiness + N*4 - 1;
		}
		
		return unhappiness + N*4;
	}
	
	public static void test() {
		for (int i=1; i<10; ++i) {
			for (int j=1; j<10; ++j) {
				minUnhappy(i, j, 0);
			}	
		}
	}
	

	public static void main(String[] args) throws IOException {
		
		test();
				
		Scanner sc = new Scanner(new File(args[0]));
        File outFile = new File(args[1]);
        FileOutputStream os = new FileOutputStream(outFile);
        OutputStreamWriter osw = new OutputStreamWriter(os);
        Writer w = new BufferedWriter(osw);
		        
		int cases = sc.nextInt();

		for (int i=0; i<cases; ++i) {
			
			int R = sc.nextInt();
			int C = sc.nextInt();
			int N = sc.nextInt();
			
			w.write("Case #" + Integer.toString(i+1) + ": " + Long.toString(minUnhappy(R, C, N)) + "\n");
		}

		w.close();
		sc.close();
	}

}
