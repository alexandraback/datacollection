import java.io.*;
import java.math.*;
import java.util.*;
public class BSecondRound {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int cases = 1; cases <= T; cases++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int B = Integer.parseInt(st.nextToken());
			int[] barbers = new int[N];
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < barbers.length; i++) 
				barbers[i] = Integer.parseInt(st.nextToken());
			if(N >= B) {
				System.out.println("Case #" + cases + ": " + B);
				continue;
			}
			B -= N;
			int cnt = 1;
			int ans = 0;
			int a = 0;
			while(ans != barbers.length) {
				ans = 0;
				for (int i = 0; i < barbers.length; i++) {
					if(cnt % barbers[i] == 0) {
						a++;
						ans++;
						
					}
				}
				cnt++;
			}
			B %= a;
			cnt = 1;
			a = 0;
			while(a < B) {
				for (int i = 0; i < barbers.length; i++) {
					if(cnt % barbers[i] == 0) {
						a++;
						if(a == B) ans = i+1;
						
					}
				}
				cnt++;
			}
			//System.out.println(cnt);
			System.out.println("Case #" + cases + ": " + ans);
		}
	}
}
