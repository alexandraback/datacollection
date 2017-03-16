import java.util.*;

public class pA {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt();
		for(int t=0; t<T; ++t) {
			int n = in.nextInt();
			String[] arr = new String[n];
			for(int i=0; i<n; ++i) arr[i] = in.next();
			int[] ptrs = new int[n];
			int[] count = new int[n];

			boolean changed = true;
			boolean poss = true;
			int numMoves = 0;

			while(changed) {
				changed = false;

				char c = '\n';

				if(ptrs[0] < arr[0].length())
					c = arr[0].charAt(ptrs[0]);
				else {
					boolean allPast = true;
					for(int i=0; i<n; ++i) if(ptrs[i] < arr[i].length()) allPast = false;
					if(allPast) c = '\0';
				}

				for(int i=0; i<n; ++i) {
					if(ptrs[i] < arr[i].length() && arr[i].charAt(ptrs[i]) == c) {
						while(ptrs[i] < arr[i].length() && arr[i].charAt(ptrs[i]) == c) {
							++ptrs[i];
							++count[i];
						}
						changed = true;
					}
					else if(c != '\0') poss = false;
				}

				if(!poss) break;

				int max = 0;
				for(int i=0; i<n; ++i) if(count[i] > max) max = count[i];
				// for(int i=0; i<n; ++i) numMoves += (max-count[i]);
				int minCost = 987654321;
				for(int i=0; i<=max; ++i) {
					int tmp = 0;
					for(int j=0; j<n; ++j) tmp += Math.abs(i-count[j]);

					if(tmp < minCost) minCost = tmp;
				}

				numMoves += minCost;

				Arrays.fill(count, 0);
				// System.out.println(Arrays.toString(ptrs) + " " + numMoves);
			}

			System.out.print("Case #" + (t+1) + ": ");
			if(poss == true)
				System.out.println(numMoves);
			else System.out.println("Fegla Won");

		}
	}
}