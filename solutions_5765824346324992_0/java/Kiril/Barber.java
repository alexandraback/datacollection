import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Scanner;


public class Barber {
	public static void main(String[] args) throws IOException {
		Path fFilePath = Paths.get(args[0]);
		try (Scanner scanner = new Scanner(fFilePath,
				StandardCharsets.UTF_8.name())) {
			int count = 0;
			int barbersCount;
			int customer;
			while (scanner.hasNextLine()) {
				if (count == 0) {
					scanner.nextLine();
				} else {
					Scanner bar = new Scanner(scanner.nextLine());
					bar.useDelimiter(" ");
					
					barbersCount = Integer.valueOf(bar.next());
					customer = Integer.valueOf(bar.next());
					
					String barberLine = scanner.nextLine();
					int[] barbers = parseBarberTime(barbersCount, barberLine);
					solveBarbersProblem(count, customer, barbers);
				}
				count++;
			}
		}
	}
	
	
	 static int lcm(int x, int y)
	    {
	        int a;
	        a = (x > y) ? x : y; // a is greater number
	        while(true)
	        {
	            if(a % x == 0 && a % y == 0)
	                return a;
	            ++a;
	        }	
	    }
	
	 private static int lcm_a(int[] numbers){
			int result = numbers[0];
			for(int i = 1; i < numbers.length; i++){
			    result = lcm(result, numbers[i]);
			}
			return result;
		}
	 
	private static void solveBarbersProblem(int caseNumber, int customer, int[] barbersTime) {
		int[] barbers = new int[barbersTime.length];
		Arrays.fill(barbers, 0);
		
		int max = lcm_a(barbersTime);
		
		int customerCount = 0;
		boolean no = false;
		for(int i = 0; i < barbersTime.length; i++) {
			customerCount += Math.floor(max / barbersTime[i]); 
//			if(max % barbersTime[i] != 0) {
//				//barbers[i] += max % barbersTime[i];
//				no =true;
//			}
		}
		int minBar = -1;
		int start = 0;
//		if(customer % customerCount == 0) {
//			start = customer;
//			minBar = available(barbers);
//		} else {
//		if(no) {
//			start = 0;
//		} else {
			start = customer - customer % customerCount - customerCount;
//		}
//		}
		for(int i = start; i < customer; i++) {
			minBar = available(barbers);
			barbers[minBar] += barbersTime[minBar];
		}
		System.out.println("Case #" + caseNumber + ": " + (minBar + 1));
	}
	
	private static int available(int[] barbers) {
		int minBar = -1;
		int minVal = Integer.MAX_VALUE;
		for(int k = 0; k < barbers.length; k++) {
			if(minVal > barbers[k]) {
				minVal = barbers[k];
				minBar = k;
			}
		}
		return minBar;
	}

	private static int[] parseBarberTime(int barbersCount, String barberLine) {
		int[] cakes = new int[barbersCount];
		Scanner scanner = new Scanner(barberLine);
	    scanner.useDelimiter(" ");
	    int index = 0;
	    while(scanner.hasNext()){
	    	String count = scanner.next();
	    	cakes[index] = Integer.valueOf(count);
	    	index++;
		}
	    
		return cakes;
	}
}
