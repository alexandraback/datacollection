import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;


public class Haircut {

	class Entry{
		int index;
		long time;
		public Entry(int i, long t){
			index = i;
			time = t;
		}
	}
	
	public void work() throws IOException{
		Scanner sc = new Scanner(new FileReader("jam.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("jam.out"));
		int cases;
		cases = sc.nextInt();
		for ( int z = 1 ; z <= cases ; z++ ){
			int b = sc.nextInt();
			int n = sc.nextInt();
			int[] m = new int[b];
			PriorityQueue<Entry> queue = new PriorityQueue(new Comparator<Entry>(){
				@Override
				public int compare(Entry o1, Entry o2) {
					if ( o1.time > o2.time || o1.time == o2.time && o1.index > o2.index )
						return 1;
					if ( o1.time < o2.time || o1.time == o2.time && o1.index < o2.index )
						return -1;
					return 0;
				}
				
			});
			
			double rateSum = 0;
			for ( int i = 0 ; i < b ; i++ ){
				m[i] = sc.nextInt();
				rateSum += 1.0/m[i];
			}
			double totalTime = (n-1)/rateSum;
			int count = 0;
			long minTime = Long.MAX_VALUE;
			for ( int i = 0 ; i < b ; i++ ){
				minTime = Math.min(minTime, ((long)(totalTime/m[i]))*m[i]);
			}
			
			for ( int i = 0 ; i < b ; i++ ){
				long pep = ((long)(minTime/m[i]));
				long time = pep*m[i];
				count += pep;
				queue.offer(new Entry(i,time));
			}
			
			for ( int i = count ; i < n-1 ; i++ ){
				Entry e = queue.poll();
				e.time += m[e.index];
				queue.offer(e);
			}
		
			bw.write("Case #" + z + ": ");
			bw.write(""+(queue.peek().index+1));
			bw.write("\n");
		}
		bw.close();
		sc.close();
	}

}
