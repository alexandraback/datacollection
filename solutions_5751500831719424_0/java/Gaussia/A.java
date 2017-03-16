import java.util.Arrays;
import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		run();
	}
	
	public static void run() {		
		Scanner scn = new Scanner(System.in);
		int T = scn.nextInt();
		
		for (int t = 1; t<=T; t++) {
			int N = scn.nextInt();
			String strs[] = new String[N];
			for (int i=0; i<N; i++){
				strs[i] = scn.next();
			}
			
			int moves = 0;
			int pos[] = new int[N];
			for (int i=0; i<N; i++) {
				pos[i] = 0;
			}
			int nbr[] = new int[N];
			
			boolean ok = true;
			int operations = 0;
			while (true) {
				char c = strs[0].charAt(pos[0]);
				//System.out.print(c);
				for (int i=0; i<N; i++) {
					char c2 = strs[i].charAt(pos[i]);
					if (c != c2){
						ok = false;
						break;
					}				
					int count = 0;
					while (strs[i].charAt(pos[i]+count) == c) {
						count++;
						if ((pos[i]+count)==strs[i].length()){
							break;
						}
					}
					pos[i] = pos[i] + count;
					nbr[i] = count;

				}
				Arrays.sort(nbr);
				int mean = nbr[(int) Math.floor(N/2)];
				for (int i = 0; i<N; i++) {

					operations = operations + Math.abs(mean - nbr[i]);

				}
				if (!ok) {
					break;
				}
				int tmp = 0;
				for (int i = 0; i<N; i++) {
					//System.out.println(i + ":" + pos[i]);
					//System.out.println(i + ":" + strs[i].length());
					if (pos[i]==(strs[i].length())) {
						tmp++;
					}
				}
				
				if (tmp>0){
					if (tmp!=N) {
						ok = false;
					}
					break;
				}
			}

			if (ok) {
				System.out.println("Case #" + t + ": " + operations);
			} else{
				System.out.println("Case #" + t + ": Fegla Won");				
			}
			
		}
	}
    
}


