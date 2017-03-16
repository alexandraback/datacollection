import static java.lang.System.*;
import java.util.*;

public class Main {
	static int MAX = 102;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(in);

		int setnum = sc.nextInt();
		for(int seti=1; seti<=setnum; seti++) {
			int n = sc.nextInt();

			boolean f = true;
			int length = 0;
			int[][] str = new int[n][MAX];
			char[] chr = new char[MAX];
			for(int i=0; i<n; i++) {
				char[] tmp = sc.next().toCharArray();
				 
				int idx = -1;
				for(int j=0; j<tmp.length; j++) {
					if(j==0 || tmp[j-1]!=tmp[j]) {
						idx++;
						if(i==0) chr[idx] = tmp[j];
					}
					if(chr[idx] != tmp[j]) f = false;
					
					str[i][idx]++;
				}
				if(i==0) length = idx;
				if(idx != length) f = false;
			}
			if(!f) {
				out.println("Case #" + seti + ": Fegla Won");
				continue;
			}
			length++;
//			out.println(length);
//			for(int j=0; j<length; j++) out.print(chr[j]+ " ");
//			out.println();
//			for(int i=0; i<n; i++) {
//				for(int j=0; j<length; j++) out.print(str[i][j] + " ");
//				out.println();
//			}
			
			int[][] count = new int[length][MAX];
			for(int i=0; i<length; i++) {
				for(int j=0; j<n; j++) {
					count[i][str[j][i]]++;
				}
			}
//			for(int i=0; i<length; i++) {
//				for(int j=0; j<10; j++) out.print(count[i][j] + " ");
//				out.println();
//			}
			
			int ans = 0;
			for(int i=0; i<length; i++) {
				int score = Integer.MAX_VALUE;
				int nscore = 0;
				int right = n;
				int left = 0;
				for(int j=1; j<MAX; j++) nscore += j*count[i][j];
				for(int j=1; j<MAX; j++) {
					nscore -= right;
					right -= count[i][j];
					left += count[i][j-1];
					nscore += left;
					
					score = Math.min(score, nscore);
				}
				ans += score;
			}

			out.println("Case #" + seti + ": " + ans);
		}
	}

}
