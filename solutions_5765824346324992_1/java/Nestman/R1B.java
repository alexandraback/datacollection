package gcj2015;

import java.io.*;
import java.util.*;

public class R1B {
	
	static int[] m = new int[1001];
	
	public static void main(String[] args) throws IOException, FileNotFoundException {
		// TODO Auto-generated method stub
	//	Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("other/gcj2015/B-large.in"))));
		PrintWriter ou = new PrintWriter("other/gcj2015/R1B.txt");
		
		int res,rep,i,j,b,sl,ans;
		long per;
		int n;

		
		res = sc.nextInt();
		for(rep=1;rep<=res;rep++){
			
			b = sc.nextInt();
			n = sc.nextInt();
			//System.out.println(gcj(b,n));
			sl = -1;
			for(i=0;i<b;i++) {
				m[i] = sc.nextInt();
				sl = Math.max(sl,m[i]);
			}
			
			per = 1;
			
			long l = 0,r;
			
			while (check(sl,per*sl,b)<n) {
				l = per;
				per *= 2;
			}
			
			r = per; long mid;
		while (r-l>1) {
				mid = (r+l) / 2;
				if (check(sl,mid*sl,b)<n) l = mid;
				else r = mid;
			} 
			
	//		System.out.println(l+" "+r);
			l = l*sl; r = r*sl;
			while (r-l>1){
				mid = (r+l)/2;
				if (check(sl,mid,b)<n) l = mid;
				else r = mid;
			}
			
//			System.out.println(l+" "+r);
			ans = -1;
			
			int num = 0;
			for(i=0;i<b;i++){
				//num += Math.ceil(((double) l / (double) m[i]));
				num += l / m[i] +1;
				if (l % m[i] == 0) num--;
			}
			
			
			for(i=0;i<b;i++)
				if (l % m[i] == 0) {
					num++;
	//				System.out.println(n-num);
					if (num==n) {ans = i+1;
					break;
					}
				}
			
			System.out.printf("Case #%d: %d\n", rep, ans);
			ou.printf("Case #%d: %d\n", rep, ans);
		}
		
		ou.close();
	}
	
	public static long check(long sl, long per, int b){
		int num = 0;
		long t = per;
		
		for(int i=0;i<b;i++) {
			//num += Math.ceil(((double) t / (double) m[i]));
			num += t / m[i] +1;
			if (t % m[i] == 0) num--;
		}
		return num;
	}
	public static long gcj(long a, long b){
		
		if (a==0) return b;
		if (b==0) return a;
		if (a==b) return a;
		if (a>b) return gcj(b, a % b);
		return gcj(a,b % a);
	}
	
	public static long lcm(long a, long b){
		return (a/gcj(a,b))*b;
	}
}
