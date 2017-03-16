import java.io.*;
import java.util.*;


public class MagicTrick {
	public static Scanner sc;
	public static int x[];
	public static int y[];
	public static int temp;

	public static void main(String[] args) throws Exception {
//		sc = new Scanner(System.in);
		sc = new Scanner(new File("E:\\GitHub\\HHH\\CodeJam\\MagicTrick\\A-small-attempt0.in"));
		String sol = "";
		int c = sc.nextInt();
		
		
		for (int i = 1; i <= c; i++) {
			sol += "Case #" + i + ": " + solve() + "\n";
		}
		
		
		
		
		
		
		System.out.print(sol);
		PrintWriter pw = new PrintWriter(new File("E:\\GitHub\\HHH\\CodeJam\\MagicTrick\\A-small-attempt0.out"));
		pw.print(sol);
		pw.close();
	}
	
	public static String solve() {
		int row = sc.nextInt();
		x = new int[4];
		
		for (int i = 1; i < row; i++) {
			sc.nextInt();
			sc.nextInt();
			sc.nextInt();
			sc.nextInt();
		}
		
		for (int i = 0; i < 4; i++) {
			x[i] = sc.nextInt();
//			System.out.print(x[i] + " ");
		}
		
		for (int i = row + 1; i <= 4; i++) {
			sc.nextInt();
			sc.nextInt();
			sc.nextInt();
			sc.nextInt();
		}
		
		y = new int[4];
		row = sc.nextInt();
		
		for (int i = 1; i < row; i++) {
			sc.nextInt();
			sc.nextInt();
			sc.nextInt();
			sc.nextInt();
		}
		
		for (int i = 0; i < 4; i++) {
			y[i] = sc.nextInt();
//			System.out.print(y[i] + " ");
		}
		
		for (int i = row + 1; i <= 4; i++) {
			sc.nextInt();
			sc.nextInt();
			sc.nextInt();
			sc.nextInt();
		}
		
		int ans = 0;
		for (int i = 0; i < 4; i++) {
			ans += isIn(y[i]);
		}
		
		
		if (ans == 0)
			return "Volunteer cheated!";
		if (ans == 1)
			return "" + temp;
		if (ans > 1)
			return "Bad magician!";
		return null;
	}

	public static int isIn(int b) {
		for (int i = 0; i < 4; i++) {
			if (x[i] == b) {
				temp = b;
				return 1;
			}
		}
		
		return 0;
	}
}
