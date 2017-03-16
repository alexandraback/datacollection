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
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    long lcm(long a,long b){
        long g = gcd(a,b);
        return (a/g)*b;
    }
    long gcd(long a,long b){
        if ( a % b == 0 ){
            return b;
        }
        return gcd(b,a%b);
    }
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int B = in.nextInt();
        long N = in.nextLong();
        int[] M = new int[B];
        for(int i = 0 ; i < B ; ++i){
            M[i] = in.nextInt();
        }
        long circle = M[0];
        for(int i = 1 ; i < B ; ++i){
            circle = lcm(circle,M[i]);
        }
        int customerCount = 0;
        for(int i = 0 ; i < B ; ++i ){
            customerCount += circle / M[i];
        }
        N = N % customerCount + customerCount;
        int barberForN = 0;
        int[] times = new int[B];
        for(int i = 0 ; i < N ; ++i){
            int free = 0;
            for(int j = 0 ; j < B ; ++j){
                if ( times[free] > times[j] ){
                    free = j;
                }
            }
            barberForN = free+1;
            times[free] += M[free];
        }
        out.println("Case #"+testNumber+": "+barberForN);
    }
}

