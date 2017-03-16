import java.util.*;

public class A {
	public static int sol(int n, int[] b){
		for (int i=1; i<n; i++)
			for (int j=i+1; j<=n; j++)
				if (b[i]<b[j]){
					int t = b[i];
					b[i] = b[j];
					b[j] = t;
				}
		int ans = 0;
		for (int i=1; i<=n; i++)
			ans += Math.abs(b[i] - b[(n+1)/2]);
		return ans;
	}
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		int z = input.nextInt();
		for (int y=1; y<=z; y++){
			System.out.print("Case #"+y+": ");
			int n = input.nextInt();
			String[] s = new String[200];
			for (int i=1; i<=n; i++)
				s[i] = input.next();
			int[][] t = new int[200][200];
			int[][] a = new int[200][200];
			for (int i=1; i<=n; i++){
				t[i][1] = s[i].charAt(0);
				a[i][1] = 1;
				int k = 1;
				for (int j=1; j<=s[i].length()-1; j++)
					if (s[i].charAt(j) == s[i].charAt(j-1)) a[i][k]++;
					else{
						k++;
						t[i][k] = s[i].charAt(j);
						a[i][k] = 1;
					}
				a[i][0] = k;
			}
			boolean f = true;
			int ans = 0;
			int k = a[1][0];
			for (int i=1; i<=n; i++)
				if (a[i][0] != k) f = false;
			if (f){
				for (int j=1; j<=k; j++){
					int x = t[1][j];
					for (int i=1; i<=n; i++)
						if (t[i][j] != x) f = false;
					int[] b = new int[200];
					for (int i=1; i<=n; i++)
						b[i] = a[i][j];
					ans += sol(n, b);
				}
			}
			if (f) System.out.println(ans);
			else System.out.println("Fegla Won");
		}
	}
}
