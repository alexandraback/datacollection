package R1C;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
		
	private static Scanner reader;
	private static PrintWriter writer;
	
	static String alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	public static void main(String[] args) throws IOException {
		reader = new Scanner(new FileReader("input.in"));
		writer = new PrintWriter(new FileWriter("output.out"));
		int nt = reader.nextInt();
		for(int tc = 1; tc <= nt; tc++) {
			writer.printf("Case #%d:", tc);
			int n = reader.nextInt();
			Party[] a = new Party[n];
			int sum = 0;
			for(int i = 0; i < n; i++) {
				a[i] = new Party(reader.nextInt(), alpha.charAt(i));
				sum += a[i].n;
			}
			Arrays.sort(a);
			while(a[0].n > 0) {
				if(a[0].n == a[1].n) {
					if(sum % 2 == 1 && a[0].n == 1) {
						a[0].n--;
						writer.print(" " + a[0].c);
						sum--;
					} else {
						a[0].n--;
						a[1].n--;
						writer.print(" " + a[0].c + "" + a[1].c);
						sum -= 2;
					}
				} else if(a[0].n >= 2) {
					a[0].n -= 2;
					writer.print(" " + a[0].c + "" + a[0].c);
					sum -=2;
				} else {
					a[0].n--;
					writer.print(" " + a[0].c);
					sum--;
				}
				Arrays.sort(a);
			}
			writer.println();
		}
		reader.close();
		writer.close();
	}
	
	static class Party implements Comparable<Party> {
		
		int n; char c;
		
		public Party(int n, char c) {
			this.n = n;
			this.c = c;
		}

		public int compareTo(Party o) {
			return o.n - n;
		}
		
		public String toString() {
			return c + " " + n;
		}
		
	}

}
