package round1a;

import googleJam.Pair;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.TreeMap;

public class hairs {

	
	
	public static void main(String...args) {
		
		
		Scanner reader = new Scanner(System.in);
		int caseCount = Integer.parseInt(reader.nextLine());
		
	
		//for each use case
		for(int caseId = 0; caseId < caseCount; caseId++) {
			
			int spot = 1;
			
			int barberCount = reader.nextInt();
			int peopleCount = reader.nextInt();
			reader.nextLine();
			
			ArrayList<Integer> barbers = new ArrayList<Integer>();
			
			int factor = 1;
			int sum = 0;
			for(int i = 0; i < barberCount; i++) {
				int time = reader.nextInt();
				barbers.add(time);
				
//				if( (factor % time) != 0) {
//					factor = factor * time;
//				}
//				else {
//					
//				}
				
				factor = factor * time;
			}
			
			for(Integer time : barbers) {
				
				sum += Math.floorDiv(factor, time);
				
			}
			
			
			//speed cycles
			if(peopleCount > sum) {
				peopleCount = peopleCount % sum;
				
				peopleCount += sum;
			}
			
	
			
			ArrayList<Pair> times = new ArrayList<Pair>();
			
			

			while(peopleCount > 0) {
				
				ArrayList<Pair> timesNew = new ArrayList<Pair>();
				
				//decrement and remove finished barbers
				for(int i = 0; i < times.size(); i++) {
					
					int timeLeft = times.get(i).x;
					int barberId = times.get(i).y;
					
					timeLeft -= 1;
					
					if(timeLeft > 0) {
						timesNew.add(new Pair(timeLeft, barberId));
					}
				}
				times = timesNew;
				
				
				if(times.size() < barbers.size()) {
					
					for(int barberId = 0; barberId < barberCount && peopleCount > 0; barberId++) {
						
						boolean found = false;
						for(Pair cur : times) {
							
							if(cur.y == barberId) {
								found = true;
							}
							
						}
						
						if(found == false) {
							times.add(new Pair(barbers.get(barberId), barberId));
							
							peopleCount -= 1;
						}
					}
					
				}
				
			}
			
			if(times.size() > 0) {
				spot = times.get(times.size() - 1).y + 1;
			}
			else {
				spot = 1;
			}

		
			
			
			System.out.println("Case #"+ (caseId + 1) + ": "+ spot);
			reader.nextLine();
		}
	}
}
