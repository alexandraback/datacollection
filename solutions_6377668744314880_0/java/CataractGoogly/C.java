
import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class C {

	int[] solve(long[] x, long[] y)
	{
		int n = x.length;
		int[] res = new int[n];
		if (n < 3) return res;

		for (int i=0; i<n; i++) {
			res[i] = Integer.MAX_VALUE;
			for (int j=0; j<n; j++) {
				if (i==j) continue;
				int positive = 0;
				int negative = 0;
				for (int k=0; k<n; k++) {
					long x1 = x[k]-x[i];
					long y2 = y[j]-y[i];
					long y1 = y[k]-y[i];
					long x2 = x[j]-x[i];
					long prod = x1*y2 - y1*x2;
					if (prod < 0 ) negative++;
					if( prod > 0) positive++;
				}
				res[i] = Math.min(res[i], negative);
				res[i] = Math.min(res[i], positive);
			}
		}
		return res;
	}

	public static void main(String[] args) {
		try {
			File fin = new File("C-small-attempt0.in");
			Scanner sc = new Scanner(fin);
			File fout = new File("cout.txt");
			PrintWriter pw = new PrintWriter(fout);
			//PrintWriter pw = new PrintWriter(System.out);
			int T = sc.nextInt();
			for (int cn=1; cn<=T; cn++) {
				int N = sc.nextInt();
				long[] x = new long[N];
				long[] y = new long[N];
				for (int i=0; i<N; i++) {
					x[i] = sc.nextLong();
					y[i] = sc.nextLong();
				}
				C c = new C();
				int[] res = c.solve(x, y);
				pw.printf("Case #%d:\n", cn);
				for (int r: res) pw.printf("%d\n", r);
			}
			pw.flush();
			pw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
