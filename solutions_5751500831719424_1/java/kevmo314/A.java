import java.util.Arrays;
import java.util.Scanner;


public class A {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		testCase:
		for(int t = 0; t < T; t++) {
			int N = in.nextInt();
			String[] lines = new String[N];
			for(int i =0 ; i < N; i++) {
				lines[i] = in.next();
			}
			// use any
			int min = 0;
			String sig = signature(lines[0]);
			for(int i = 0; i < N; i++) {
				if(!sig.equals(signature(lines[i]))) {
					System.out.println("Case #" + (t + 1) + ": Fegla Won");
					continue testCase;
				}
			}
			
			int[][] count = new int[N][sig.length()];
			for(int i = 0; i < N; i++) {
				String line = lines[i];
				int sIndex = 0;
				for(int j = 0; j < line.length(); j++) {
					if(sig.charAt(sIndex) == line.charAt(j)) {
						count[i][sIndex]++;
					} else {
						sIndex++;
						j--;
					}
				}
			}
			for(int i = 0; i < sig.length(); i++) {
				// choose d
				int best = Integer.MAX_VALUE;
				for(int d = 1; d <= 100; d++) {
					int local = 0;
					for(int j = 0; j < N; j++) {
						local += Math.abs(count[j][i] - d);
					}
					best = Math.min(local, best);
				}
				min += best;
			}
			System.out.println("Case #" + (t + 1) + ": " + min);
		}
	}
	public static String signature(String s) {

		String target = "";
		for(int i = 0 ;i  <s.length(); i++) {
			if(target.length() == 0 || s.charAt(i) != target.charAt(target.length() - 1)) {
				target += s.charAt(i);
			}
		}
		return target;
	}
}
