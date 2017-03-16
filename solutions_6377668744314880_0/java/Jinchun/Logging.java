import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class Logging {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("C-small-attempt1.in"));//
		PrintWriter out = new PrintWriter("out.txt");
		int T = in.nextInt();
		for(int i=1;i<=T;i++){
			int N = in.nextInt();
			int[][] pos = new int[N][2];
			for(int j=0;j<N;j++){
				pos[j][0]=in.nextInt();
				pos[j][1]=in.nextInt();
			}
			int[] res = count(pos);
			out.println("Case #"+i+":");
			for(int j=0;j<N;j++){
				out.println(res[j]);
			}
		}
		out.close();
		in.close();

	}
	
	private static int[] count(int[][]pos){
		int N=pos.length;
		int[] res = new int[N];
		Arrays.fill(res,N);
		for(int i=0;i<N;i++){
			for(int j=i+1;j<N;j++){
				int min = helper(pos,i,j);
				res[i]=Math.min(min, res[i]);
				res[j]=Math.min(min,res[j]);
			}
		}
		return res;
	}
	
	private static int helper(int[][]pos, int i, int j){
		int p = 0, n=0;
		for(int k=0;k<pos.length;k++){
			long res = ((long)pos[j][1]-(long)pos[i][1])*((long)pos[k][0]-(long)pos[i][0])-((long)pos[k][1]-(long)pos[i][1])*((long)pos[j][0]-(long)pos[i][0]);
			if(res>0){
				p++;
			}
			else if(res<0){
				n++;
			}
		}
		return Math.min(p, n);
	}

}
