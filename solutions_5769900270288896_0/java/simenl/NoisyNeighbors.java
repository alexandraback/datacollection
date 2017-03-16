import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class NoisyNeighbors {
	static String filename = "B-small-attempt0";
	static Scanner sc;
	static int best;
	
	public static void main(String[] args) throws FileNotFoundException{
		System.setIn(new FileInputStream(filename + ".in"));
		System.setOut(new PrintStream(filename + ".out"));
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int casee = 1 ; casee<=t ; casee++){
			System.out.print("Case #" + casee + ": ");
			solve();
			System.out.println(best);
		}
	}
	public static void solve(){
		best = Integer.MAX_VALUE;
		int r = sc.nextInt();
		int c = sc.nextInt();
		int n = sc.nextInt();
		boolean[][] board = new boolean[r][c];
		rec(0, n, 0, board, r,c);
		
	}
	
	public static void rec(int pos, int left, int cost, boolean[][] board, int r, int c){
		if(left == 0){
			best = Math.min(best, cost);
		}
		if(pos >= r*c){
			return;
		}
		int x = pos%r;
		int y = pos/r;
		
		rec(pos+1, left, cost, board, r, c);
		int add = 0;
		if(x > 0 && board[x-1][y]){
			add++;
		}
		if(y > 0 && board[x][y-1]){
			add++;
		}
		board[x][y] = true;
		rec(pos+1, left-1, cost+add, board, r, c);
		board[x][y] = false;
	}
}
