import java.io.*;
import java.util.*;

public class A {
	public static boolean DEBUG = true;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		
		int cases = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= cases; t++){
			pw.print("Case #" + t + ": ");
			
			int n = nextInt(br);
			
			StringTokenizer st = getst(br);
			int[] m = new int[n];
			
			for(int i = 0; i < n; i++){
				m[i] = nextInt(st);
			}
			
			int a = 0;
			int b = 0;
			
			for(int i = 1; i < n; i++){
				a += Math.max(0, m[i-1]-m[i]);
				b = Math.max(b, m[i-1]-m[i]);
			}
			
			int c = 0;
			
			for(int i = 0; i < n-1; i++){
				c += Math.min(b, m[i]);
			}
			
			pw.println(a + " " + c);
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