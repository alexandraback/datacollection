import java.io.*;
import java.util.*;
public class Jam1BA{
	public static void main(String[] args) throws IOException{
		BufferedReader f = new BufferedReader( new FileReader("g.in"));
		PrintWriter out = new PrintWriter( new BufferedWriter( new FileWriter("gJamout.txt")));
		//Scanner f = new Scanner(System.in);	
		int t = i(f.readLine());
		for(int iii = 1; iii <= t; iii++){
			int r; int c; int n; int temp;
			String[] cur = f.readLine().split(" ");	
			temp = r = i(cur[0]);
			c = i(cur[1]);
			n = i(cur[2]);
			r = Math.max(r, c);
			c = Math.min(temp, c);
			int num1 = 0;
			int num2 = 0;
			int num3 = 0;
			int num4 = 0;
			int left = 0;
			if(c != 1){
				if(r % 2 == 1 && c % 2 == 1){
					if(n > (r*c + 3)/2){
						left = n - (r*c - 1)/2;
						num2 = 4;
						num3 = r + c - 6;
						num4 = r*c - (r*c - 1)/2 - 4 - (r + c - 6);
					}else{
						left = n - (r*c + 1)/2;
						num2 = 0;
						num3 = r + c - 2;
						num4 = r*c - num2 - num3;
					}
				}else{
					left = n - r*c/2;
					num2 = 2;
					num3 = r + c - 4;
					num4 = r*c/2 - 2 - (r + c - 4);
				}
			}else{
				if(n > (r + 1)/2){
					left = n - (r)/2;
					num2 = (r - 2)/2;
					num1 = 1 + (r % 2);
				}else{
					left = 0;
				}
			}
			int res = 0;
			if(left > 0){
				if(left <= num1){
					res += left;
				}else{
					res += num1;
				}
				left -= num1;
			}
			if(left > 0){
				if(left <= num2){
					res += left*2;
				}else{
					res += num2*2;
				}
				left -= num2;
			}
			if(left > 0){
				if(left <= num3){
					res += left*3;
				}else{
					res += num3*3;
				}
				left -= num3;
			}
			if(left > 0){
				if(left <= num4){
					res += left*4;
				}else{
					res += num4*4;
				}
				left -= num4;
			}
			out.println("Case #" + iii + ": " + res);
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