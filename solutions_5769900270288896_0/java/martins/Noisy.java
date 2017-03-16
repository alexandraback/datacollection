import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
public class Noisy {
	
	static final String filename = "B-small-attempt1.in";
	
	static Scanner seer;
	static int T;
	static int i;
	static int R;
	static int C;
	static int N;
	static ArrayList<Integer> numlist;

	public static void main(String[] args) throws FileNotFoundException {
		//seer = new Scanner(System.in);
		seer = new Scanner(new File(filename));
		T = seer.nextInt();
		for(i = 0; i < T; i++){
			R = seer.nextInt();
			C = seer.nextInt();
			N = seer.nextInt();
			System.out.printf("Case #%d: %d\n",i+1,solve());
		}
		
	}
	
	public static int solve(){
		int min = Integer.MAX_VALUE;
		for(int dis = 0; dis < Math.pow(2,R*C); dis++){
			if(countones(dis) == N){
				int val = hunhappy(dis) + vunhappy(dis);
				if(val < min)
					min = val;
			}
		}
		
		return min;
	}
	
	public static int hunhappy(int n){
		int res = 0;
		int iter = 1;
		while(iter <= R*C){
			if(iter % C != 0){
				if(n%2 == 1 && (n/2)%2 == 1){
					res++;
				}
			}
			n = n/2;
			iter++;
		}
		return res;
		
	}
	public static int vunhappy(int n){
		int res = 0;
		int iter = 1;
		while(iter <= R*C-C){
			int neigh = (int) Math.pow(2,C);
			if(n%2 == 1 && (n/neigh)%2 == 1){
				res++;
			}
			n = n/2;
			iter++;
		}
		return res;
		
		
	}
	
	public static int countones(int n){
		int res = 0;
		while(n > 0){
			if(n%2 == 1)
				res++;
			n = n/2;
		}
		return res;
	}


}
