import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class mush {
	public static void main(String args[]) throws IOException{
		BufferedReader in = new BufferedReader(new FileReader("p1.in"));
		PrintWriter out = new PrintWriter(new FileWriter("p1.out"));
		int t = Integer.parseInt(in.readLine());
		for(int i=1; i<=t; i++){
			out.print("Case #"+i+": ");
			oneTest(in, out);
			out.flush();
		}
	}
	
	private static void oneTest(BufferedReader in, PrintWriter out) throws IOException{
		int n = Integer.parseInt(in.readLine());
		int [] arr = new int [n];
		
		StringTokenizer tok = new StringTokenizer(in.readLine());
		for(int i=0; i<n; i++){
			arr[i] = Integer.parseInt(tok.nextToken());
		}
		
		out.println(solve1(arr)+" "+solve2(arr));
	}
	
	private static long solve1(int [] arr){
		long res = 0;
		for(int i = 1; i<arr.length; i++){
			if(arr[i]>=arr[i-1]) continue;
			res= res + (arr[i-1] - arr[i]);
		}
		return res;
	}
	
	private static long solve2(int [] arr){
		int rate = 0;
		long res = 0;
		
		for(int i=1; i<arr.length; i++){
			rate = Math.max(rate, arr[i - 1]- arr[i]);
		}
		
		for(int i=0; i<arr.length - 1; i++){
			res = res+Math.min(rate, arr[i]); 
		}
		return res;
		
	}
}
