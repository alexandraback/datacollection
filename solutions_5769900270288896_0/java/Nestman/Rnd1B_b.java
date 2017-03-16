package gcj2015;

import java.io.*;
import java.util.*;

public class Rnd1B_b {

	static int r,c,n,ans;
	static boolean[][] h = new boolean[20][20];
	
	public static void main(String[] args) throws IOException, FileNotFoundException {
		// TODO Auto-generated method stub
	//	Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("other/gcj2015/B-small-attempt0.in"))));
		PrintWriter ou = new PrintWriter("other/gcj2015/RnBb.txt");
		
		int res,rep,i,j;
		

		res = sc.nextInt();
		
		for(rep=1;rep<=res;rep++){
			
			r = sc.nextInt();
			c = sc.nextInt();
			n = sc.nextInt();
			
			for(i=0;i<=r;i++) Arrays.fill(h[i],false);
			ans = 10000;
			search(0,1,0);
			System.out.println(ans);
			ou.printf("Case #%d: ", rep);
			ou.println(ans);
			
		}
		ou.close();
	}
	
	public static void search(int depth, int x, int y) {
		int i,j;
		
		if (depth == n) {
			int num = 0;
			for(i=1;i<=r;i++)
				for(j=1;j<=c;j++)
					if (h[i][j]) {
						if (h[i-1][j]) num++;
						if (h[i+1][j]) num++;
						if (h[i][j+1]) num++;
						if (h[i][j-1]) num++;
					}
			num = num / 2;
			
			if (num<ans) ans = num;
		}
		
		else {
			
			for(j=y+1;j<=c;j++) {
				h[x][j] = true;
				search(depth+1,x,j);
				h[x][j] = false;
			}
			
			for (i=x+1;i<=r;i++)
				for(j=1;j<=c;j++) {
					h[i][j] = true;
					search(depth+1,i,j);
					h[i][j] = false;
				}
		}
	}
}
