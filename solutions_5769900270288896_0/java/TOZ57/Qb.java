package q1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Qb{
	public static void main(String args[]) throws FileNotFoundException{
		File fi = new File("B-small-attempt1.in.txt");
		File fo = new File("B.txt");
		Scanner s = new Scanner(fi);
		PrintWriter p = new PrintWriter(fo);
		int T = s.nextInt();
		for(int i=1;i<=T;i++){
			int R = s.nextInt();
			int C = s.nextInt();
			int N = s.nextInt();
			p.write("Case #" + i + ": " + ans(R,C,N) + "\n");
		}
		p.flush();
	}
	public static int ans(int R, int C, int N){
		if(N == 0){ return 0; }
		int[] crd = new int[N];
		int S = R*C;
		for(int i=0;i<N;i++){
			crd[i] = i;
		}
		int min = 999999;
		while(crd[0] < S-N+1){
			int cf = 0;
			for(int i=1;i<N;i++){
				for(int j=0;j<i;j++){
					if(crd[i] - crd[j] == R ||
							(crd[i] - crd[j] == 1) && (crd[i] % R != 0)){
						cf++;
					}
				}
			}
			min = Math.min(min, cf);
			// Next array
			crd[N-1]++;
			for(int i=N-1;i>0;i--){
				if(crd[i] > S-N+i){
					crd[i-1]++;
					for(int j=i;j<N;j++){
						crd[j] = crd[j-1]+1;
					}
				}
			}
		}
		return min;
	}
}
