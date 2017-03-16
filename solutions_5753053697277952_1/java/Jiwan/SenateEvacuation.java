package seattle.algostar.ps.acmicpc.codejam2016.round1c;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class SenateEvacuation {
	public static void main(String[] args) throws FileNotFoundException {
		new SenateEvacuation().solve();
	}

	private void solve() throws FileNotFoundException {
		Scanner sc = new Scanner(new FileInputStream(new File("/home/mosaick/A-large.in")));
		PrintWriter out = new PrintWriter(new FileOutputStream("/home/mosaick/A-large.out"));
		
//		Scanner sc = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		
		int tt = sc.nextInt();
		for (int t = 1; t <= tt; t++) {

			int nn = sc.nextInt();
			
			Person[] A = new Person[nn];
			int total = 0;
			for (int i = 0; i < nn; i++) {
				String s = String.valueOf((char)((char)'A' + i));
				A[i] = new Person(s, sc.nextInt());
				total += A[i].cnt;
			}

			Arrays.sort(A);
			
			StringBuilder plan = new StringBuilder();
			while (true) {
				
				if (A[0].cnt == 0) break;
				
				String pick = A[0].alpha;
				A[0].cnt--;
				total--;
				
				Arrays.sort(A);
				
				if (A[0].cnt * 2 > total) {
					pick += A[0].alpha;
					A[0].cnt--;
					total--;
				}
				
				plan.append(pick + " ");
				
				Arrays.sort(A);
			}
			
			plan.deleteCharAt(plan.length()-1);
			out.println("Case #" + t + ": " + plan.toString());
			out.flush();
		}
		out.close();
		System.out.println("==END==");
	}
	
	class Person implements Comparable<Person> {
		String alpha;
		int cnt;
		public Person(String a, int cnt) {
			this.alpha = a;
			this.cnt = cnt;
		}
		@Override
		public int compareTo(Person o) {
			return -(this.cnt - o.cnt);
		}
	}
}
