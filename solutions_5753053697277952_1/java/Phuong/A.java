package gg.codejam._2016._1c;

import java.util.Arrays;
import java.util.Scanner;

public class A {

	static class Ele implements Comparable<Ele> {
		public int value;
		public char c;
		@Override
		public int compareTo(Ele o) {
			// TODO Auto-generated method stub
			if (value == o.value) return c- o.c;
			return -(value - o.value);
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int ti = 1; ti <= t; ti++) {
			int n = sc.nextInt();
			int[] a = new int[n];
			Ele[] b = new Ele[n];
			int sum = 0;
			for (int i = 0; i < n; i++) {
				a[i] = sc.nextInt();
				b[i] = new Ele();
				b[i].value = a[i];
				b[i].c = (char) (i + 'A');
				sum += a[i];
			}
			int co = sum;
			System.out.print("Case #" + ti + ":");
			while (co > 0) {
				Arrays.sort(b);
				System.out.print(" " + b[0].c);
				b[0].value--;
				co--;
				if (b[0].value > b[1].value) {
					System.out.print(b[0].c);
					b[0].value--;
					co--;
				} else if (b[0].value < b[1].value && b[1].value * 2 > co) {
					System.out.print(b[1].c);
					b[1].value--;
					co--;
				}
			}
			System.out.println();
		}
		sc.close();
	}

}
