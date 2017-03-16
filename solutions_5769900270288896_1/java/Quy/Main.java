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
		TaskBB solver = new TaskBB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskBB {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int R = in.nextInt();
        int C = in.nextInt();
        int total = R * C;
        int N = in.nextInt();
        int result = 0;
        if ( N > total / 2 + total % 2){
            boolean[][] board = new boolean[R][C];
            for(int i = N + 1 ; i <= total ; ++i){
                int del_r=0,del_c=0, mx = 0;
                for(int r = 0 ; r < R ; ++r ){
                    for(int c = 0 ; c < C ; ++c){
                        if ( board[r][c] ) continue;
                        int conn = 0;
                        if ( r > 0 && !board[r-1][c] ){
                            ++conn;
                        }
                        if ( r + 1 < R && !board[r+1][c]){
                            ++conn;
                        }
                        if ( c > 0 && !board[r][c-1] ){
                            ++conn;
                        }
                        if( c + 1 < C && !board[r][c+1]){
                            ++conn;
                        }
                        if ( conn > mx ){
                            mx = conn;
                            del_r = r;
                            del_c = c;
                        }
                    }
                }
                board[del_r][del_c] = true;
            }
            for(int r = 0 ; r < R ; ++r){
                for(int c = 0 ; c < C ; ++c){
                    if ( board[r][c] ) continue;
                    if ( r + 1 < R && !board[r+1][c] ){
                        ++result;
                    }
                    if ( c + 1 < C && !board[r][c+1] ){
                        ++result;
                    }
                }
            }
        }
        out.println("Case #"+testNumber+": "+result);
    }
}

