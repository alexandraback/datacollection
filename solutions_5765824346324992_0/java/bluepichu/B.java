import java.io.*;
import java.util.*;

public class B {
	public static boolean DEBUG = true;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		
		int cases = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= cases; t++){
			pw.print("Case #" + t + ": ");
			
			StringTokenizer st = getst(br);
			
			long b = nextInt(st);
			long n = nextInt(st);
			
			long[] m = new long[(int)b];
			
			st = getst(br);
			
			for(int i = 0; i < b; i++){
				m[i] = nextInt(st);
			}
			
			long hi = (long)1e15;
			long lo = 0;
			
			while(lo < hi){
				//debug(lo + " " + hi);
				long mid = (lo+hi)/2;
				long proc = 0;
				for(int i = 0; i < b; i++){
					proc += mid / m[i] + 1;
				}
				
				if(proc > n-1){
					hi = mid;
				} else {
					lo = mid+1;
				}
			}
			
			//debug(lo);
			
			long p = 0;
			
			for(int i = 0; i < b; i++){
				p += (lo-1)/m[i] + 1;
			}
			
			int ans = -1;
			
			for(int i = 0; i < b; i++){
				if(lo/m[i] > (lo-1)/m[i]){
					p++;
					if(p == n){
						ans = i+1;
						break;
					}
				}
			}
			
			pw.println(ans);
		}
		
		br.close();
		pw.close();
	}
	
	public static void debug(Object o){
		if(DEBUG){
			System.out.println("~" + o);
		}
	}
	
	public static StringTokenizer getst(BufferedReader br) throws Exception{
		return new StringTokenizer(br.readLine(), " ");
	}
	
	public static int nextInt(BufferedReader br) throws Exception{
		return Integer.parseInt(br.readLine());
	}
	
	public static int nextInt(StringTokenizer st) throws Exception{
		return Integer.parseInt(st.nextToken());
	}
}