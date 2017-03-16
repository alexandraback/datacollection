import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class BarberBinary {
	public static void main(String[] args){
		BarberBinary t = new BarberBinary();
		t.readInput();
	}
	
	public void readInput(){
		Scanner scan;
		try {
			scan = new Scanner(new File("input.txt"));
			PrintStream p = new PrintStream("output.txt");
			int num = scan.nextInt();
			for(int i = 1; i <= num; i++){
				scan.nextLine();
				int barbers = scan.nextInt();
				long placeN = scan.nextLong();
				
				long[] barberTimes = new long[barbers];
				long max = Long.MIN_VALUE;
				for (int j = 0; j < barbers; j++) {
					barberTimes[j] = scan.nextLong();
					if (barberTimes[j] > max) {
						max = barberTimes[j];
					}
				}
				
				long left = 0;
				long right = max * placeN + 1;
				
				// Binary search
				
				long toFind = placeN;
				while (left < right) {
					long mid = (left + right) / 2;
					long served = barbers;
					for (int k = 0; k < barbers; k++) {
						served += mid / barberTimes[k];
					}
					if (served < toFind) {
						left = mid + 1;
					} else {
						right = mid;
					}
					
				}
				
				long timeBefore = left - 1;
				long served = barbers;
				if (timeBefore >= 0) {
					for (int k = 0; k < barbers; k++) {
						served += timeBefore / barberTimes[k];
					}
					List<Integer> ok = new ArrayList<Integer>();
					for (int k = 0; k < barbers; k++) {
						if ((left / barberTimes[k]) * barberTimes[k] == left) {
							ok.add(k);
						}
					}
					
					int offset = (int)(placeN - served - 1);
					p.println("Case #" + i + ": " + (ok.get(offset) + 1));
					System.out.println("Case #" + i + ": " + (ok.get(offset) + 1));
				} else {
					p.println("Case #" + i + ": " + (placeN));
					System.out.println("Case #" + i + ": " + (placeN));
				}
				
				
			}
			p.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
	}
	
	public static class BarberTime implements Comparable<BarberTime>{
		public long time;
		public int index;
		
		@Override
		public int compareTo(BarberTime b) {
			if (b.time == this.time) {
				return Integer.compare(this.index, b.index);
			} else {
				return Long.compare(this.time, b.time);
			}
		}
	}
}

