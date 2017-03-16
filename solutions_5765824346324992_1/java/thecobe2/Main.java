import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	static int answ;
	
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		int z, N, i, j, k;
		long M;
		int B;
		int barber[] = new int[1000];
		boolean serve[] = new boolean[1000];
		long lo, hi, mid;
		int x;
		for(z = 1; z <= T; z++){
			B = in.nextInt();
			M = in.nextLong();
			
			for(i = 0; i < B; i++)
				barber[i] = in.nextInt();
			
			if(M <= B){
				System.out.println("Case #" + z + ": " + M);
				continue;
			}
			
			lo = 1;
			hi = 223372036854775807l;
			answ = 0;
			while(lo <= hi){
				mid = lo + ((hi - lo) / 2l);
				//System.out.println(lo + " " + mid + " "+ hi);
				x = check(mid, barber, M, serve, B);
				if(x == 0)
					break;
				if(x < 0){
					//System.out.println("REDUCE");
					hi = mid - 1;
				}
				if(x > 0)
					lo = mid + 1;
			}              
			
			System.out.println("Case #" + z + ": " + answ);
		}
	}
	
	static int check(long T, int[] barber, long M, boolean serve[], int B){
		Arrays.fill(serve, 0, B, false);
		long sum = 0;
		int willServe = 0;
		for(int i = 0; i < B; i++){
			sum += (T + barber[i] - 1) / barber[i];
			if(T % barber[i] == 0){
				serve[i] = true;
				willServe++;
			}
		}
		//System.out.println(sum);
		if(sum < M && M <= sum + willServe){
			for(int i = 0; i < B; i++){
				if(serve[i])
					sum++;
				if(sum == M){
					answ = i + 1;
					break;
				}
			}
			return 0;
		}
		if(sum >= M)
			return -1;
		return 1;
	}
}
