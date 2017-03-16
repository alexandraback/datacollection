import java.io.*;
import java.util.*;
public class Jam1AB{
	public static void main(String[] args) throws IOException{
		BufferedReader f = new BufferedReader( new FileReader("g.in"));
		PrintWriter out = new PrintWriter( new BufferedWriter( new FileWriter("gJamout.txt")));
		//Scanner f = new Scanner(System.in);	
		int t = i(f.readLine());
		for(int iii = 1; iii <= t; iii++){
			String[] cur = f.readLine().split(" ");	
			int b = i(cur[0]);
			int n = i(cur[1]);
			cur = f.readLine().split(" ");	
			int[] bar = new int[b]; double d = 0;
			for(int i = 0; i < b; i++){
				bar[i] = i(cur[i]);
				d += 1/(double) bar[i];
			}
			int start = (int) (((n - 1)/d) + 0.000000001);
			int amount = 0;
			for(int i = 0; i < b; i++){
				amount += start/bar[i];
			}
			int res = 1000000;
			while(amount < n){
				int c = 0; int md = 100000000;
				for(int i = 0; i < b; i++){
					md = Math.min(md, start % bar[i]);
				}
				for(int i = 0; i < b; i++){
					if(start % bar[i] == md){
						c++;
					}
				}
				if(amount + c >= n){
					int g = n - amount;
					for(int i = 0; i < b; i++){
						if(start % bar[i] == md){
							g--;
							if(g == 0){
								res = i + 1;
							}
						}
					}
					amount += c;
				}else{
					amount += c;
					start += md;
				}
			}
			out.print("Case #" + iii + ": " + res + " " + b + " " + n + " ");
			for(int i = 0; i < b; i++){
				out.print(bar[i] + " ");
			}
			out.println();
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