import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;


public class New {
	
	private String[] ss;
		
	public void d() {
		File f = new File("kod.txt");
		try (Scanner s = new Scanner(f)) {
			
		int T = s.nextInt();
		ss = new String[T];
		for (int i = 0; i < T; i++) {
			int N = s.nextInt();
			String[] p = new String[N];
			for (int j = 0; j < N; j++) {
				p[j] = s.next();
			}
			compute(p, i);
		}
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		f = new File("out.txt");
		try (PrintWriter pw = new PrintWriter(f)) {
			for (int i = 1; i < ss.length + 1; i++) {
				pw.println("Case #" + i + ": " + ss[i-1]);
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	private void compute (String[] f, int i) {
		String s = toBegin(f[0], 0);
		for (int j = 0; j < f.length; j++) {
			if (!s.equals(toBegin(f[j], j))) {
				ss[i] = "Fegla Won";
				return;
			}
		}
		int[][] f2 = new int[s.length()][f.length];
		int c = 0;
		for (int j = 0; j < f.length; j++) {
			char last = f[j].charAt(0);
			c = 0;
			for (int k = 0; k < f[j].length(); k++) {
				if (last != f[j].charAt(k)) {
					last = f[j].charAt(k);
					c++;
					f2[c][j] = 1;
				} else {
					f2[c][j]++;
				}
			}
		}
		
		int[] min = new int[s.length()];
		Arrays.fill(min, Integer.MAX_VALUE);
		int[] sum = new int[s.length()];
		for (int j = 0; j < 101; j++) {
			for (int k = 0; k < sum.length; k++) {
				sum[k] = 0;
				for (int l = 0; l < f.length; l++) {
					sum[k] = sum[k] + Math.abs(f2[k][l]);
					f2[k][l]--;
				}
				if (sum[k] < min[k]) {
					min[k] = sum[k];
				}
			}
		}
		c = 0;
		for (int j = 0; j < min.length; j++) {
			c = c + min[j];
		}
		ss[i] = "" + c;
	}
	
	private String toBegin(String s, int i) {
		StringBuilder sb = new StringBuilder();
		char last = s.charAt(0);
		sb.append(last);
		for (int j = 1; j < s.length(); j++) {
			if (last != s.charAt(j)) {
				last = s.charAt(j);
				sb.append(last);
			}
		}
		return sb.toString();
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		New n = new New();
		n.d();
	}

}
