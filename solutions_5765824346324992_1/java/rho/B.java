import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;

class barber implements Comparable<barber>
{
	int pos=0;
	long speed=0, work=0;

	public barber(int S, int P)
	{
		speed=S;
		pos=P;
	}
	
	public void add()
	{
		work+=speed;
	}
	
	public long set(long T)
	{
		work=T-T%speed;
		return T/speed;
	}
	
	public int compareTo(barber arg0) {
		if(work-arg0.work<0)
			return -1;
		else if(work-arg0.work==0)
			return pos-arg0.pos;
		else
			return 1;
	}
	
	@Override
	public String toString() {
		return "#"+pos+"|"+speed+"@"+work;
	}
}

public class B {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("B-large.in"));
		int T = sc.nextInt();
		for(int testC = 1; testC<=T; ++testC)
		{
			int B = sc.nextInt();
			long N=sc.nextLong();
			ArrayList<barber> arrL = new ArrayList<barber>();

			
			
			for(int i=0; i<B; ++i)
				arrL.add(new barber(sc.nextInt(), i));
			//System.out.println(arrL);
			long time = 0, first = 1000;
			long served = calc(arrL, first);
			//System.out.println(first+","+served+" |1 "+arrL);
			while(served<N)
			{
				time=first;
				first*=2;
				served = calc(arrL, first);
		//		System.out.println(first+","+served+" |2 "+arrL);
			}
			served = calc(arrL, time);
			first/=2;
			long inc=first;
			while(inc>1000)
			{
				inc/=2;
				served = calc(arrL, time+inc);
				//System.out.println((time+inc)+","+served+" |3 "+arrL);
				if(served<N)
					time+=inc;
			}
			served = calc(arrL, time);
			//System.out.println(time+","+served+" |4 "+arrL);
			
			PriorityQueue<barber> Q = new PriorityQueue<barber>(arrL);
			int last=-1;
			while(served<N)
			{
				barber b = Q.poll();
				last=b.pos+1;
				b.add();
				Q.add(b);
				served++;
			//	System.out.println(Q);
			}
			
			System.out.printf("Case #%d: %d\n", testC, last);	
		}
		
		
		
	}
	
	static long calc(ArrayList<barber> Q, long T)
	{
		long tot=0;
		for(barber B:Q)
			tot+=B.set(T);
		return tot;
	}
	
}
