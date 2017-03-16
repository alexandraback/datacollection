import java.util.*;

public class A {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	
	for (int nc = 1; nc <= nCase; nc++) {
		int N = scanner.nextInt();
		String[] str = new String[N];
		for (int i = 0; i < N; i++)
			str[i] = scanner.next();
		
		char[][][] ch = new char[N][100][2];
		int[] chCnt = new int[N];
		for (int i = 0; i < N; i++) {
			char c = 0;
			int cnt = 0;
			for (int j = 0; j < str[i].length(); j++) {
				if (c == 0) {
					c = str[i].charAt(j);					
				} else {
					if (str[i].charAt(j) != c) {
							ch[i][chCnt[i]][0] = c;
							ch[i][chCnt[i]++][1] = (char)cnt;
							cnt = 0;
							c = str[i].charAt(j);
					}
				}
				cnt++;
			}
			ch[i][chCnt[i]][0] = c;
			ch[i][chCnt[i]++][1] = (char)cnt;
		}
		/*
		for (int n = 0; n < N; n++) {
			for (int i = 0; i < 100; i++)
				if (ch[n][i][0] != 0) {
					System.out.print(""+ch[n][i][0] +" " + (int)ch[n][i][1]);
				}
			System.out.println();
		}
		*/
		boolean ok = true;
		for (int i = 0; i < N; i++)
			ok &= (chCnt[0] == chCnt[i]);
		if (!ok) {
			System.out.println("Case #" + nc + ": Fegla Won");
			continue;
		}
		
		ok = true;
		for (int i = 0; i < chCnt[0] && ok; i++) {
			for (int n = 0; n < N; n++) {
				ok &= (ch[0][i][0] == ch[n][i][0]);
			}
		}
		if (!ok) {
			System.out.println("Case #" + nc + ": Fegla Won");
			continue;
		}
		
		int ans = 0;
		for (int i = 0; i < chCnt[0]; i++) {
			int maxC = 0;
			for (int n = 0; n < N; n++)
				maxC = Math.max(maxC, ch[n][i][1]);
			
			int best = 10000;
			for (int k = 1; k <= maxC; k++) {
				int need = 0;
				for (int n = 0; n < N; n++) {
					if (k < ch[n][i][1])
						need += (ch[n][i][1]-k);
					else if (k > ch[n][i][1])
						need += (k - ch[n][i][1]);
				}
				best = Math.min(best, need);
			}
			ans += best;
		}
		
		System.out.println("Case #" + nc + ": " + ans);
	}
}
}