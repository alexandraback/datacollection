import java.io.FileInputStream;
import java.util.Scanner;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Quy Doan
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		ProblemA solver = new ProblemA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class ProblemA {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int N = in.nextInt();
        int[] M = new int[N];
        int maxDist = 0;
        for(int i = 0 ; i < N ; ++i){
            M[i] = in.nextInt();
            if ( i > 0 ){
                maxDist = Math.max(maxDist,M[i-1]-M[i]);
            }
        }
        int first = 0;
        int second = 0;
        for(int i = 0 ; i < N ; ++i){
            if ( i > 0 && M[i-1] > M[i] ){
                first += M[i-1]-M[i];

            }
            if ( i < N - 1) {
                second += Math.min(maxDist, M[i]);
            }
        }
        out.println("Case #"+testNumber+": "+first+" "+second);
    }
}

