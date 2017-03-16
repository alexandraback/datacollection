package barbers;

import java.util.LinkedList;

public class TestBarbers {
	
	private int B;
	private int N;
	private int[] s;

	public TestBarbers(int b, int n, int[] s) {
		B = b;
		N = n;
		this.s = s;
	}

	public int getResult () {
		int i,j,k;
		int res = -1;
		long time = 0;
		long cptAtTime = 0;
		for (i=15; i>=0; i--) {
			long tmp = time;
			long cpt = 0;
			for (j=0; j<11 && cpt<N; j++) {
				cpt = 0;
				for (k=0; k<B; k++) {
					cpt += (tmp/s[k])+1;
				}
				tmp += Math.pow(10, i);
//				System.out.println(cpt);
			}
			j -= 2;
			time += j*Math.pow(10, i);
//			System.out.println("Number: "+i+" "+j);
		}
		time++;
		cptAtTime = 0;
		for (k=0; k<B; k++) {
			cptAtTime += (time/s[k])+1;
		}
		
//		System.out.println(time+" "+cptAtTime+" "+N);
		LinkedList<Integer> freeAtTime = new LinkedList<Integer>();
		for (k=0; k<B; k++) {
			if ((time%s[k]) == 0) {
				freeAtTime.addLast(k);
//				System.out.println("YEAH");
			}
		}
		for (long cpt=cptAtTime; cpt>=N; cpt--)
			res = freeAtTime.pollLast();
		
		return res;
	}
	
}