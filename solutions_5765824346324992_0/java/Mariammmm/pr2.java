import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class pr2 {
	public static void main(String args[]) throws IOException{
//		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//		PrintWriter out = new PrintWriter(System.out);
		BufferedReader in = new BufferedReader(new FileReader("p2.in"));
		PrintWriter out = new PrintWriter(new FileWriter("p2.out"));
		int t = Integer.parseInt(in.readLine());
		for(int i=1; i<=t; i++){
			out.print("Case #"+i+": ");
			out.println(oneTest(in)+1);			
			out.flush();
		}
		out.flush();
	}
	
	private static long oneTest(BufferedReader in) throws IOException{
		StringTokenizer tok = new StringTokenizer(in.readLine());
		int b = Integer.parseInt(tok.nextToken());
		int n = Integer.parseInt(tok.nextToken());
		int [] arr = new int [b];
		
		tok = new StringTokenizer(in.readLine());
		for(int i=0; i<b; i++){
			arr[i] = Integer.parseInt(tok.nextToken());
		}
		
		if(n<=b){
			return n-1;
		}
		
		long time = binarySearch(arr, n - 1);
		
		long c = n - 1- inProcess(time, arr) ; 
		//System.out.println(c);
		for(int i=0; i<arr.length; i++){
			if(time%arr[i]==0) {
				if(c==0) return i;
			}	{
				c--;
			}
		}
		
		return 0;
	}
	
	private static int basic(int [] arr, int n){
		return arr[n - 1];
	}
	private static long binarySearch(int [] arr, int target){
		long a = 0;
		long b = 1000000001;
		b*=1000000;
		//long b = 1000;
		while(b-a>1){
			long mid = (a+b)/2;
			long inProc = inProcess(mid, arr);
			if(inProc>target){
				b = mid;
			}	else {
				a = mid;
			}
		}
		System.out.println("A: " +a);
		return a;
	}
	private static long inProcess(long time, int [] arr){
		long res = 0;
		for(int i=0; i<arr.length; i++){
			long a = time/arr[i];
			if(time%arr[i]!=0){
				a++;
			}
			
			res+=a;
		}
		
		return res;
	}
}
