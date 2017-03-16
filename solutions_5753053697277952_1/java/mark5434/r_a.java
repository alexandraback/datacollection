package codejam2016r1c;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

class x {
	char c;
	int n;
}

class comp implements Comparator<x> {
	public int compare(x arg0, x arg1) {
		return arg1.n-arg0.n;
	}
	
}
public class r_a {
	static String doit(int n, x[] arr) {
		StringBuilder sb = new StringBuilder();
		PriorityQueue<x> pq = new PriorityQueue<>(new comp());
		for (x xi : arr) pq.add(xi);
		while (!pq.isEmpty()) {
			if (pq.size()==2) break;
			sb.append(' ');
			x xi = pq.poll();
			sb.append(xi.c);
			if (xi.n>1) {
				x xin = new x();
				xin.c = xi.c;
				xin.n = xi.n-1;
				pq.add(xin);
			}
			if (pq.size()==2) break;
			x xi2 = pq.poll();
			if (xi2==null) break;
			sb.append(xi2.c);
			if (xi2.n>1) {
				x xin = new x();
				xin.c = xi2.c;
				xin.n = xi2.n-1;
				pq.add(xin);
			}
		}
		x xi1 = pq.poll();
		x xi2 = pq.poll();
		if (xi1.n!=xi2.n) {
			System.err.println("err");
		}
		int x = xi1.n;
		while (x!=0) {
			sb.append(' ');
			sb.append(xi1.c);
			sb.append(xi2.c);
			x--;
		}
		return sb.toString();
	}
	static public void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("d:/A-small-attempt1.in"));
		PrintWriter pw = new PrintWriter("d:/out");
		int cn = sc.nextInt();
		for (int casei=0;casei<cn;casei++) {
			int n = sc.nextInt();
			x arr[] = new x[n];
			for (int i=0;i<n;i++) {
				arr[i] = new x();
				arr[i].c = (char) ('A'+i);
				arr[i].n = sc.nextInt();
			}
			pw.printf("Case #%d:%s\n", casei+1, doit(n, arr));
		}
		sc.close();
		pw.close();
	}
}
