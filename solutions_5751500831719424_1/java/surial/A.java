import java.util.Arrays;
import java.util.Scanner;


public class A {
	private static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) {
			try {
				System.out.printf("Case #%d: %d\n", i + 1, exec());
			} catch (FeglaEx e) {
				System.out.printf("Case #%d: %s\n", i + 1, "Fegla Won");
			}
		}
	}
	
	// Observation: If you can't get there with deletion only, you can't get there at all;
	// the 'you can also dupe a number' thing is only going to make it faster sometimes.
	
	private static class FeglaEx extends Throwable {}
	
	public static int exec() throws FeglaEx {
		int n = sc.nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; i++) s[i] = sc.next();
		
		char[] m;
		{
			StringBuilder mb = new StringBuilder();
			for (int i = 0; i < s[0].length(); i++) {
				if (i == 0 || s[0].charAt(i - 1) != s[0].charAt(i)) mb.append(s[0].charAt(i));
			}
			m = mb.toString().toCharArray();
		}
		
		int[][] counts = new int[n][m.length];
		
		for (int i = 0; i < n; i++) {
			char[] x = s[i].toCharArray();
			int p = 0;
			for (int j = 0; j < m.length; j++) {
				if (p >= x.length || x[p] != m[j]) throw new FeglaEx();
				int y = 0;
				while (p < x.length && x[p] == m[j]) {
					y++;
					p++;
				}
				counts[i][j] = y;
				if (j == m.length - 1 && p != x.length) throw new FeglaEx();
			}
		}
		
		int totalSolve = 0;
		int[] steps = new int[101];
		
		for (int i = 0; i < m.length; i++) {
			for (int j = 0; j < 101; j++) steps[j] = 0;
			for (int j = 0; j < 101; j++) {
				for (int k = 0; k < n; k++) {
					steps[j] += Math.abs(counts[k][i] - j);
				}
			}
			int sm = Integer.MAX_VALUE;
			for (int j = 0; j < 101; j++) sm = Math.min(sm, steps[j]);
			totalSolve += sm;
		}
		
		return totalSolve;
	}
}
