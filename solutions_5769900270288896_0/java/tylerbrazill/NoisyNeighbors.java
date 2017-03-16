import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class NoisyNeighbors {
	NoisyNeighbors(Scanner in, PrintWriter out){
		int tests = in.nextInt();
		for(int t = 1; t<=tests; t++){
			int R = in.nextInt();
			int C = in.nextInt();
			int N = in.nextInt();
			int full = 1<<(R*C);
			int min = Integer.MAX_VALUE;
			for(int m = 0; m<full; m++)
				if(Integer.bitCount(m) == N){
					int res = 0;
					for(int r = 0; r<R; r++)
						for(int c = 0; c<C; c++){
							if((((m>>(r*C))>>c)&1) == 0)
								continue;
							if(r < R-1 && (((m>>(r*C+C))>>c)&1) != 0)
								res++;
							if(c < C-1 && (((m>>(r*C))>>(c+1))&1) != 0)
								res++;
						}
					min = Math.min(res, min);
				}
			out.printf("Case #%d: %d\n", t, min);
		}
		out.close();
	}
	public static void main(String[] args) throws FileNotFoundException {
		String name = "B-small-attempt0";
//		new NoisyNeighbors(new Scanner(System.in), new PrintWriter(System.out));
		new NoisyNeighbors(new Scanner(new File(name+".in")), new PrintWriter(new File(name+".out")));
	}
}
