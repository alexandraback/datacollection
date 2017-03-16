import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemA {
    private static final String FILENAME = "A-large";

	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader(FILENAME + ".in"));
        PrintWriter output = new PrintWriter(new FileWriter(FILENAME + ".out"));

        long start = System.currentTimeMillis();
        int testCase = input.nextInt();
        for (int t=1; t<=testCase; t++) {
        	int N = input.nextInt();
        	int[] P = new int[N];
        	int sum = 0;
        	for (int i=0; i<N; i++) {
        		P[i] = input.nextInt();
        		sum += P[i];
        	}
        	
        	String result = "";
        	while (sum > 0) {
        		boolean found = false;
        		for (int i=0; i<N && !found; i++) {
        			for (int j=0; j<N && !found; j++) {
        				int[] nP = Arrays.copyOf(P, P.length);
        				nP[i]--; nP[j]--;
        				if (nP[i] >= 0 && nP[j] >= 0 && isValid(nP)) {
        					result = result + " " + (char)('A' + i) + (char)('A' + j);
        					sum -= 2;
        					found = true;
        					P = nP;
        				}
        			}
        		}
        		if (!found) {
        			for (int i=0; i<N; i++) {
        				int[] nP = Arrays.copyOf(P, P.length);
        				nP[i]--;
        				if (nP[i] >= 0 && isValid(nP)) {
        					result = result + " " + (char)('A' + i);
        					sum--;
        					P = nP;
        				}
        			}
        		}
        	}
        	output.print("Case #"+t+":"+result+"\n");
        }
        System.out.printf("Total duration: %dms\n", System.currentTimeMillis() - start);

        input.close();
        output.close();
	}
	
	public static boolean isValid(int[] P) {
		int sum = 0;
		int max = 0;
		for (int i=0; i<P.length; i++) {
			sum += P[i];
			if (max < P[i]) max = P[i];
		}
		return (max <= (sum / 2));
	}
}
