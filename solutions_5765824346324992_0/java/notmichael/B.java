import java.util.*;

public class B {

	public static void main(String[] args) {
		B b = new B();
		b.run();
	}

	public void run() {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		for (int a=0; a<cases; a++) {
			int numB = in.nextInt();
			long line = in.nextLong();
			in.nextLine();
			String[] split = in.nextLine().split(" ");
			long[] barbers = new long[numB];
			for (int i=0; i<numB; i++) {
				barbers[i] = Long.parseLong(split[i]);
			}
			long lcm = barbers[0];
			for (int i=1; i<numB; i++) {
				lcm = lcm(lcm,barbers[i]);
			}
			long inc = 0;
			for (int i=0; i<numB; i++) {
				inc += lcm / barbers[i];
			}
			long lineAct = line % inc;
			if (lineAct==0) {
				lineAct = inc;
			}
			if (lineAct <= numB) {
				System.out.println("Case #" + (a+1) + ": " + lineAct);
			}
			else {
				long[] time = new long[numB];
				long min = 100001;
				for (int i=0; i<numB; i++) {
					time[i] = barbers[i];
					min = Math.min(barbers[i],min);
				}
				long i = lineAct-((long)numB);
				int ans = -1;
				while (i>0) {
					long minNext = 100001;
					for (int j=0; j<numB; j++) {
						time[j] -= min;
						if (time[j]==0) {
							i--;
							time[j] = barbers[j];
							if (i==0) {
								ans = j;
								break;
							}
						}
						minNext = Math.min(minNext,time[j]);
					}
					min = minNext;
				}
				System.out.println("Case #" + (a+1) + ": " + (ans+1));
			}
		}
	}

	private long gcd(long a, long b) {
		while (b>0) {
			long t = b;
			b = a%b;
			a = t;
		}
		return a;
	}

	private long lcm(long a, long b) {
		return a * b / gcd(a,b);
	}

}