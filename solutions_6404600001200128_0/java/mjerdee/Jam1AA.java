import java.io.*;
import java.util.*;
public class Jam1AA{
	public static void main(String[] args) throws IOException{
		BufferedReader f = new BufferedReader( new FileReader("g.in"));
		PrintWriter out = new PrintWriter( new BufferedWriter( new FileWriter("gJamout.txt")));
		//Scanner f = new Scanner(System.in);	
		int t = i(f.readLine());
		for(int iii = 1; iii <= t; iii++){
			int num = i(f.readLine());
			String[] cur = f.readLine().split(" ");	
			int[] te = new int[num];
			for(int i = 0; i < num; i++){
				te[i] = i(cur[i]);
			}
			int res1 = 0;
			for(int i = 1; i < num; i++){
				if(te[i] < te[i - 1]){
					res1 += te[i - 1] - te[i];
				}
			}
			int res2 = 0; int md = 0;
			for(int i = 1; i < num; i++){
				md = Math.max(md, te[i - 1] - te[i]);
			}
			for(int i = 0; i < num - 1; i++){
				res2 += Math.min(md, te[i]);
			}
			out.println("Case #" + iii + ": " + res1 + " " + res2);
		}
		out.close();
		System.exit(0);
	}
	public static int i(String s){ return Integer.parseInt(s); }
	public static int[][] fill(int[][] input, int val){
		int[][] res = new int[input.length][input[0].length];
		for(int i = 0; i < input.length; i++){
			for(int j = 0; j < input[0].length; j++){
				res[i][j] = val;
			}
		}
		return res;
	}
}