package R1B_2014;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;

public class Asmall {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner reader = new Scanner(new FileReader("in"));
		int nt = reader.nextInt();
		for (int t = 1; t <= nt; t++) {
			System.out.print("Case #" + t + ": ");
			int n = reader.nextInt();
			String x = reader.next();
			String y = reader.next();
			ArrayList<P> xp = new ArrayList<P>();
			ArrayList<P> yp = new ArrayList<P>();
			for(int i = 0; i < x.length(); i++) {
				if(i == 0) {
					xp.add(new P(x.charAt(i), 1));
				} else {
					if(x.charAt(i) == x.charAt(i - 1)) {
						xp.get(xp.size() - 1).cnt++;
					} else {
						xp.add(new P(x.charAt(i), 1));
					}
				}
			}
			for(int i = 0; i < y.length(); i++) {
				if(i == 0) {
					yp.add(new P(y.charAt(i), 1));
				} else {
					if(y.charAt(i) == y.charAt(i - 1)) {
						yp.get(yp.size() - 1).cnt++;
					} else {
						yp.add(new P(y.charAt(i), 1));
					}
				}
			}
			int count = 0;
			boolean ok = xp.size() == yp.size();
			for(int i = 0; ok && i < xp.size(); i++) {
				if(xp.get(i).c != yp.get(i).c) {
					ok = false;
				} else {
					count += Math.abs(xp.get(i).cnt - yp.get(i).cnt);
				}
			}
			if(!ok) {
				System.out.println("Fegla Won");
			} else {
				System.out.println(count);
			}
		}
	}
	
	static class P {
		char c;
		int cnt;
		public P(char c, int cnt) {
			this.c = c;
			this.cnt = cnt;
		}
		public String toString() {
			return "[" + c + ", " + cnt + "]";
		}
	}
	
	
}
