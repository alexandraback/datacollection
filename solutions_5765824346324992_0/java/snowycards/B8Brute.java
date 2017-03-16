import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class B8Brute {
	
	public static long peopleCutAtTime(long time, int[] barbers) {
		long peopleCut = 0;
		for(int i = 0; i < barbers.length; i++) {
			long thisBarberCut = time / barbers[i];
			peopleCut += thisBarberCut;
		}
		return peopleCut;
	}
	
	public static long findTime(long start, long end, long betweenStart, long betweenEnd, int[] barbers) {
		if(start > end)
			return -1;
		long mid = (end-start)/2+start;
		long peopleCutAtTime = peopleCutAtTime(mid, barbers);
		
		if(peopleCutAtTime < betweenStart) {
			return findTime(mid+1, end, betweenStart, betweenEnd, barbers);
		} else if(peopleCutAtTime > betweenEnd) {
			return findTime(start, mid-1, betweenStart, betweenEnd, barbers);
		} else {
			return mid;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(
				"B-small-attempt4.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("B_out1.txt"));
		
		int cases = Integer.parseInt(br.readLine());
		
		for(int n = 1; n <= cases; n++) {
			
			StringTokenizer stinput = new StringTokenizer(br.readLine(), " ");
			int numBarbers = Integer.parseInt(stinput.nextToken());
			int place = Integer.parseInt(stinput.nextToken());
			
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int[] barbers = new int[numBarbers];
			for(int i = 0; i < numBarbers; i++)
				barbers[i] = Integer.parseInt(st.nextToken());
			
			
			int solution = -1;
			if(numBarbers >= place)
				solution = place;
			else {
				long timeAt = findTime(1, Long.MAX_VALUE, place - 2*numBarbers - 1, place-numBarbers-1, barbers);
				long peopleCutAlready = peopleCutAtTime(timeAt, barbers);
				
				for(int i = 0; i < barbers.length; i++)
					if(timeAt % barbers[i] != 0)
						peopleCutAlready++;
				
				System.out.println(timeAt);
				
				loop: for(int i = 0; i < 200000; i++) {
					
					for(int j = 0; j < barbers.length; j++) {
						if(timeAt % barbers[j] == 0) {
							if(peopleCutAlready == place-1) {
								solution = j + 1;
								break loop;
							}
							peopleCutAlready++;
						}
					}
					timeAt++;
				}
			}
			pw.printf("Case #%d: %d\n", n, solution);
		}
		
		pw.close();
	}
}
