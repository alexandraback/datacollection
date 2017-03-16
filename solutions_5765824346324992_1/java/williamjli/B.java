import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class B {

	public static void main(String[] args) throws IOException {
		
		BufferedReader input = new BufferedReader(new FileReader("C:\\Users\\William Li\\Desktop\\input.txt"));
		PrintWriter output = new PrintWriter(new FileWriter("C:\\Users\\William Li\\Desktop\\output.txt"));
		
		int T = Integer.parseInt(input.readLine());
		
		for (int t = 1; t <= T; t++){
			System.out.println("working on test" + t);
			String[] firstLine = input.readLine().split(" ");
			
			int B = Integer.parseInt(firstLine[0]);
			int N = Integer.parseInt(firstLine[1]);
			
			double[] rates = new double[B];
			double total = 0;
			
			String[] nextLine = input.readLine().split(" ");
			int[] barbers = new int[B];
			
			for (int i = 0; i < nextLine.length; i++){
				
				barbers[i] = Integer.parseInt(nextLine[i]);
				total += 1.0 / barbers[i];
				
			}
			
			for (int i = 0; i < barbers.length; i++){
				
				rates[i] = (1.0 / barbers[i]) / total;
				
			}
			
			Barber[] times = new Barber[B];
			int place = N;
			
			for (int i = 0; i < barbers.length; i++){
				
				place -= Math.floor(rates[i] * Math.max(N - 1000000, 0));
				times[i] = new Barber(Math.round(Math.floor(rates[i] * Math.max(N - 1000000, 0))) * barbers[i], barbers[i], i + 1);
				
			}
			
			while (place > 0){
				
				Arrays.sort(times);
				place--;
				times[0].backlog += times[0].rate;
				
			}
			
			output.println("Case #" + t + ": " + times[0].id);
			
		}
		
		input.close();
		output.close();
		
		System.exit(0);
		
	}
	
	public static class Barber implements Comparable<Barber> {
		
		long backlog;
		int rate;
		int id;
		
		public Barber(long backlog, int rate, int id) {
			
			this.backlog = backlog;
			this.rate = rate;
			this.id = id;
			
		}
		
		@Override
		public int compareTo(Barber arg0) {
			
			if (backlog > arg0.backlog){
				
				return 1;
				
			}else if (backlog == arg0.backlog){
				
				if (id > arg0.id){
					
					return 1;
					
				}else{
					
					return -1;
					
				}
				
			}else{
				
				return -1;
				
			}
			
		}
		
	}

}