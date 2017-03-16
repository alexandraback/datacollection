package codejam1A;

import java.util.PriorityQueue;
import java.util.Scanner;

public class BCopy {

	public static void main(String args[]){

		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		for(int i = 0; i < n; i++){

			int result =-1;
			int nb = scan.nextInt();
			int nc = scan.nextInt();
			int time[] = new int[nb];
			for(int j = 0; j < nb; j++){
				time[j] = scan.nextInt();
			}
			int lcm = 1;
			int nCos = 0;
			PriorityQueue<Triple> queue = new PriorityQueue<Triple>();

			if(nb >= nc){
				result = nc;
			}
			else{
				for(int j = 0; j < nb; j++){
					lcm = lcm(lcm, time[j]);
				}

				for(int j = 0; j < nb; j++){
					nCos += lcm/time[j];
				}

				nc = nc - nCos*(nc/nCos) + nCos;
				//
				//				System.out.println(lcm);
				//				System.out.println(nCos);
				//				System.out.println("nb: "+nb);
				//				System.out.println("nc: "+nc);

				boolean flag = false;
				if(nc == 0){
					flag = true;
				}
				if(nb >= nc && nc != 0){
					result = nc;
				}
				else{
					for(int j = 0; j < nb; j++){
						//Triple myTriple = new Triple(time[j], time[j], j+1);
						queue.add(new Triple(time[j], time[j], (j+1)));
					}

					if(flag){
						result = queue.peek().getBID();
						//System.out.println(result);
					}
					else{
						for(int c = nb; c < nc-1; c++){
//
//							System.out.println(queue.peek().getBID());
//							System.out.println(queue.peek().getWTime());
							Triple peek = queue.poll();
							//peek.update();
							queue.add(new Triple(peek.getWTime()+peek.getUTime(), peek.getUTime(), peek.getBID()));
						}
						result = queue.peek().getBID();
					}

				}

			}
			System.out.println("Case #"+ (i+1) +": " + result);
		}

	}

	static int gcd(int x, int y)
	{
		int r=0, a, b;
		a = (x > y) ? x : y;
		b = (x < y) ? x : y;

		r = b;
		while(a % b != 0)
		{
			r = a % b;
			a = b;
			b = r;
		}
		return r;
	}

	static int lcm(int x, int y)
	{
		int a;
		a = (x > y) ? x : y;
		while(true)
		{
			if(a % x == 0 && a % y == 0)
				return a;
			++a;
		}
	}
}

