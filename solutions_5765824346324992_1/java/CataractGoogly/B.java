
import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class B {

	int solve(int[] m, int N)
	{
		int numBarbers = m.length;

		// don't have to wait!
		if (N <= numBarbers) {
			return N;
		}

		long lo = 0;
		long hi = 10000000000000000L;
		while (lo + 1 < hi) {
			long mid = lo + (hi-lo)/2;
			long numCuts = 0;
			for (int x:m) numCuts += (1 + mid/x);
			if (numCuts < N) lo = mid;
			else hi = mid;
		}
		long ncLo = 0;
		for (int x: m) ncLo += (1 + lo/x);
		for (int b=0; b<numBarbers; b++) {
			if (hi%m[b] == 0) {
				ncLo++;
				if (ncLo == N) return b+1;
			}
		}
		return -1;
	}

	public static void main(String[] args) {
		try {
			File fin = new File("B-large.in");
			Scanner sc = new Scanner(fin);
			File fout = new File("bout.txt");
			PrintWriter pw = new PrintWriter(fout);
			//PrintWriter pw = new PrintWriter(System.out);
			int T = sc.nextInt();
			for (int cn=1; cn<=T; cn++) {
				int B = sc.nextInt();
				int N = sc.nextInt();
				int[] m = new int[B];
				for (int i=0; i<B; i++) {
					m[i] = sc.nextInt();
				}
				B b = new B();
				pw.write("Case #" + cn + ": " + b.solve(m, N) + "\n");
			}
			pw.flush();
			pw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
