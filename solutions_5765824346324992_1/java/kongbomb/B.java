package running;

import org.psjava.algo.sequence.search.BinarySearchFirstTrue;
import org.psjava.ds.math.Function;
import org.psjava.ds.numbersystrem.LongNumberSystem;
import org.psjava.util.ZeroTo;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.util.Scanner;

public class B implements Runnable {

	private int b;
	private int n;
	private int[] m;

	@Override
	public void run() {
		Scanner in = new Scanner(System.in);
		int casen = in.nextInt();
		for(int casei : ZeroTo.get(casen)) {
			System.out.print("Case #" + (casei + 1) + ": ");

			b = in.nextInt();
			n = in.nextInt();
			m = new int[b];
			for(int i : ZeroTo.get(b))
				m[i] = in.nextInt();

			long waitTime = BinarySearchFirstTrue.search(LongNumberSystem.getInstance(), new Function<Long, Boolean>() {
				@Override
				public Boolean get(Long time) {
					return n <= calcFinishedCustomer(time) + b;
				}
			}, 0L, 123456789123456789L, -1L);

			int cutting = 0;
			for(int i : ZeroTo.get(b))
				if(waitTime % m[i] != 0)
					cutting++;

			int waiting = n - calcFinishedCustomer(waitTime) - cutting;

			int freeBarberCount = 0;
			for(int i : ZeroTo.get(b)) {
				if(waitTime % m[i] == 0) {
					freeBarberCount++;
					if(waiting == freeBarberCount) {
						System.out.println(i+1);
						break;
					}
				}
			}
		}
	}

	private int calcFinishedCustomer(long time) {
		int total = 0;
		for(int mk : m)
			total = (int) Math.min(n, total + time / mk);
		return total;
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new BufferedInputStream(new FileInputStream("solutions/running-io/B-large.in")));
		new B().run();
	}

}
