import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.lang.reflect.Array;


public class B {
	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("outputB.txt"));
		int nrTests = Integer.parseInt(br.readLine());
		for(int tNr = 1; tNr <= nrTests; tNr++) {
			String[] vals = br.readLine().split(" ");
			int r = Integer.parseInt(vals[0]);
			int c = Integer.parseInt(vals[1]);
			int n = Integer.parseInt(vals[2]);
			
			if((r * c + 1) / 2 >= n) {
				pw.println("Case #" + tNr + ": 0");
				continue;
			}
			cRes = 100000;
			cn = 0;
			func(r, c, n, 0);
			pw.println("Case #" + tNr + ": " + cRes);
		}
		
		pw.close();
		br.close();
		System.out.println("done!");
	}
	
	static boolean[][] map = new boolean[16][16];
	static int cRes = 0, cn = 0;
	static void func(int r, int c, int n, int bitNr) {
		if(bitNr == r * c) {
			if(cn != n) {
				return;
			}
			int res = 0;
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					if(j + 1 < c && map[i][j] && map[i][j + 1]) {
						res++;
					}
					if(i + 1 < r && map[i][j] && map[i + 1][j]) {
						res++;
					}
				}
			}
			
			cRes = Math.min(cRes, res);
			return;
		}
		
		int cr = bitNr / c, cc = bitNr % c;
		map[cr][cc] = false;
		func(r, c, n, bitNr + 1);
		
		if(cn < n) {
			cn++;
			map[cr][cc] = true;
			func(r, c, n, bitNr + 1);
			cn--;
		}
	}
}
