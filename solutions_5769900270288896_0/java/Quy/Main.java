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
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int R = in.nextInt();
        int C = in.nextInt();
        int total = R * C;
        int N = in.nextInt();
        int result = Integer.MAX_VALUE;
        for(int mask = 0 ; mask < (1<<total) ; ++mask){
            int rentCount = 0;
            for(int i = 0 ; i < total ; ++i){
                if ( (mask & (1<<i )) != 0 ){
                    ++rentCount;
                }
            }
            if ( rentCount != N){
                continue;
            }
            int unhappiness = 0;
            for( int i = 0 ; i < R ; ++i){
                for(int j = 0; j < C ; ++j){
                    int current = i*C + j;
                    if ( (mask & (1<<current)) == 0 ){
                        continue;
                    }
                    if ( i + 1 < R ){
                        int below = (i+1)*C + j;
                        if ( (mask & (1<<below)) != 0 ){
                            ++unhappiness;
                        }
                    }
                    if ( j + 1 < C ){
                        int right = i*C + j + 1;
                        if ( (mask & (1<<right)) != 0 ){
                            ++unhappiness;
                        }
                    }
                }
            }

            result = Math.min(result,unhappiness);
        }
        out.println("Case #"+testNumber+": "+result);

    }
}

