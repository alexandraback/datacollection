

import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Double.parseDouble;
import static java.lang.Float.parseFloat;

public class HaircutFast {
	public static Scanner s = new Scanner(System.in);
	
	public static void main(String[] args) {
		PriorityQueue<Barber> x = new PriorityQueue<Barber>();
		x.add(new Barber(3, 0));
		x.add(new Barber(2, 0));
		x.add(new Barber(1, 0));
		
		int n = parseInt(s.nextLine());
		
		for (int i=1 ; i<=n ; i++) {
			System.out.print("Case #" + i + ": ");
			System.err.println(i+"/"+n);
			
			run();
		}
	}
	
	public static void run() {
		int B, N;
		
		B = s.nextInt();
		N = s.nextInt();
		
		long cycletime = 1;
		
		PriorityQueue<Barber> cuting = new PriorityQueue<Barber>();
		Barber[] barbers = new Barber[B];
		for (int i=0 ; i<B ; i++) {
			int M = s.nextInt();
			
			cycletime = kgV(cycletime, M);
			
			Barber b = new Barber(i, M);
			
			barbers[i] = b;
			cuting.add(b);
		}
		
		long cyclesize = 0;
		for (int i=0 ; i<B ; i++) {
			cyclesize += cycletime / barbers[i].M;
		}
		
		if (N >= cyclesize) N = (int) ((N - 1) % cyclesize) + 1;
		
		Barber cur=null;
		
		System.err.println("BLUB " + N + " " + cycletime + " " + cyclesize);
		for (int i=0 ; i<N ; i++) {
			cur = cuting.poll();
			cur.servesUntil += cur.M;
			cuting.add(cur);
		}
		
		System.out.println(cur.id + 1);
	}
	
	public static long kgV(long a, long b) {
		long x = ggt(a, b);
		
		return (a / x) * b;
	}
	
	public static long ggt(long a, long b) {
		while (b != 0) {
			long t = b;
			b = a % b;
			a = t;
		}
		
		return a;
	}
	
	public static class Barber implements Comparable<Barber> {
		public final int id;
		public final long M;
		
		public long servesUntil;
		
		public Barber(int id, long M) {
			this.id = id;
			this.M = M;
			this.servesUntil = 0;
		}
		
		@Override
		public boolean equals(Object obj) {
			return obj == this;
		}
		
		@Override
		public int compareTo(Barber o) {
			long dif = servesUntil - o.servesUntil;
			if (dif > 0) return 1;
			else if (dif < 0) return -1;
			
			return id - o.id;
		}
	}
	
}
