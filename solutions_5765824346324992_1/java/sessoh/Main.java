import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("B.in")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("B.out"))));
		
		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			String[] str = br.readLine().split(" ");
			int B = Integer.parseInt(str[0]);
			long N = Integer.parseInt(str[1]);
			long[] M = new long[B];
			str = br.readLine().split(" ");
			for (int i = 0; i < B; i++) M[i] = Integer.parseInt(str[i]);
			
			if (N <= B) {
				pw.println("Case #"+(t+1)+": "+N);
				continue;
			}
			
			double cutperminute = 0.0;
			for (int i = 0; i < B; i++) cutperminute += 1.0 / M[i];
			
			double rate = 0.00001;
			long hage = N;
			long[] rank = new long[B];
			while (hage >= N) {
				hage = B;
				long estimated = (long)(N / (cutperminute*(1.0+rate)));
				rate *= 10;
				for (int i = 0; i < B; i++) {
					hage += estimated / M[i];
					rank[i] = ((M[i]-(estimated % M[i]))<<10)|i;
				}
//				System.out.println(estimated);
			}
//			System.out.println(hage);
//			for (int i = 0; i < B; i++) System.out.println((rank[i]>>10)+" "+(rank[i]&0x3ffL));

			int answer = 0;
			loop:while (true) {
				Arrays.sort(rank);
				long p = rank[0]>>10;
				for (int i = 0; i < B; i++) {
					long c = rank[i]>>10;
					int b = (int)(rank[i]&0x3ffL);
					if (c == p) {
						if (++hage == N) {
							answer = b;
							break loop;
						}
						rank[i] = (M[b]<<10)|b;
					} else {
						rank[i] = ((c-p)<<10)|b;
					}
				}
			}
			
			pw.println("Case #"+(t+1)+": "+(answer+1));
			pw.flush();
		}

		pw.close();
		br.close();
	}
}
