/* Filename: B.java
 * Author: Mushiyo
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;
import java.util.*;

public class B {

	public static void main(String[] args) throws FileNotFoundException {
		//Scanner input = new Scanner(System.in);
		Scanner input = new Scanner(new File("B-small-attempt1.in"));
		PrintWriter out = new PrintWriter(new File("B.out"));
		PriorityQueue<Barber> pq = new PriorityQueue();

		while (input.hasNext()) {
			int T = input.nextInt();

			for (int caseNum = 1; caseNum <= T; ++caseNum) {
				int B = input.nextInt();
				int N = input.nextInt();
				int[] M = new int[B];

				for (int i = 0; i < M.length; ++i) {
					M[i] = input.nextInt();
				}

				int LCM = lcm(M[0], M[1]);
				for (int i = 2; i < M.length; ++i) {
					LCM = lcm(LCM, M[i]);
				}

				int sum = 0;
				for (int i = 0; i < M.length; ++i) {
					sum += LCM / M[i];
				}
				
				int tmp = (N - 1) % sum + 1;
				int y = 0;
				
				if(tmp <= B){
					y = tmp;
				} else{
					pq.clear();
					
					for(int i = 0; i < B; ++i){
						pq.add(new Barber(i, 0));
					}
					
//					while(pq.size() > 1){
//						out.print(pq.poll() + " ");
//					}

					while(tmp > 1){
						Barber b = pq.poll();
						//out.print(b + " ");
						
						b.time += M[b.id];
						pq.add(b);
						
						--tmp;
					}
					
					y = pq.peek().id + 1;
				}

				out.printf("Case #%d: %d\n", caseNum, y);
			}
		}
		
		input.close();
		out.close();
	}

	public static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	public static int lcm(int a, int b) {
		// gcd(a, b) * lcm(a, b) = a * b
		// lcm(a, b) = (a * b) / gcd(a, b)
		// since a * b might overflow
		// so use a / gcd(a, b) * b
		return a / gcd(a, b) * b;
	}

	static class Barber implements Comparable<Barber> {
		int id;
		int time;

		Barber(int id, int time) {
			this.id = id;
			this.time = time;
		}

		@Override
		public int compareTo(Barber b) {
			if (this.time == b.time) {
				if (this.id < b.id) {
					return -1;
				} else if (this.id > b.id) {
					return 1;
				} else {
					return 0;
				}
			} else if (this.time < b.time) {
				return -1;
			} else {
				return 1;
			}
		}
		
		public String toString(){
			return String.format("Id %d, time %d.", id, time);
		}
	}
}
