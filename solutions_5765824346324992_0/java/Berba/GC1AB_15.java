import java.util.*;

public class GC1AB_15{
	static int gcd(int a, int b){
		if(b==0) return a;
		return gcd(b,a%b);
	}

	static class State implements Comparable<State>{
		int time, bar;
		public State(int time, int bar){
			this.time = time;
			this.bar = bar;
		}

		public int compareTo(State s){
			if(time != s.time)
				return time - s.time;
			return bar - s.bar;
		}
	}
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int ca = 1; ca <= T; ca++){
			int B = sc.nextInt();
			int N = sc.nextInt();

			int arr[] = new int[B];
			int LCM = 1;
			for(int i = 0; i < B; i++){
				arr[i] = sc.nextInt();
				LCM = LCM*arr[i]/gcd(LCM,arr[i]);
			}

			int per = 0;
			for(int i = 0; i < B; i++)
				per += LCM/arr[i];


			N %= per;
			if(N==0) 
				N += per;
			PriorityQueue<State> pq = new PriorityQueue<State>();
			for(int i = 0; i < B; i++)
				pq.offer(new State(0,i));

			for(int i = 0; i < N-1; i++){
				State s = pq.poll();
				pq.offer(new State(s.time + arr[s.bar],s.bar));
			}

			System.out.printf("Case #%d: %d\n",ca,pq.peek().bar+1);
		}		
	}
}