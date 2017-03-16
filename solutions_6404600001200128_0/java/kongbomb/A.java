package running;

import org.psjava.util.ZeroTo;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.util.Scanner;

public class A implements Runnable {

	@Override
	public void run() {
		Scanner in = new Scanner(System.in);
		int casen = in.nextInt();
		for (int casei : ZeroTo.get(casen)) {
			System.out.print("Case #" + (casei + 1) + ": ");

			int n = in.nextInt();
			int[] m = new int[n];
			for (int i : ZeroTo.get(n))
				m[i] = in.nextInt();

			int r1 = 0;
			for (int i : ZeroTo.get(n - 1))
				if (m[i] > m[i + 1])
					r1 += m[i] - m[i + 1];

			int maxEat = 0;
			for(int i : ZeroTo.get(n-1))
				maxEat = Math.max(maxEat, m[i] - m[i+1]);

			int r2 = 0;
			for(int i : ZeroTo.get(n-1))
				r2 += Math.min(maxEat, m[i]);

			System.out.println(r1 + " " + r2);
		}
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new BufferedInputStream(new FileInputStream("solutions/running-io/A-small-attempt0.in")));
		new A().run();
	}

}
