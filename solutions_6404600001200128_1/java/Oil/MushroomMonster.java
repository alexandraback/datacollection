import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;


public class MushroomMonster {

	public static void main(String[] args) {
		InputData input = new InputData(2);
		List<String> inputLines = input.getLines();
		List<String> outputCases = new ArrayList<String>();
		
		Iterator<String> iterator = inputLines.iterator();
		while(iterator.hasNext()) {
			int times = Integer.parseInt(iterator.next());
			String mushroomString = iterator.next();
			int[] mushroomCounts = new int[times];
			Scanner mushroomScanner = new Scanner(mushroomString);
			for (int i = 0; i < times; i++) {
				mushroomCounts[i] = mushroomScanner.nextInt();
			}
			mushroomScanner.close();
			int method1 = 0, method2 = 0; //running results for each method.
			
			int prevMushrooms = mushroomCounts[0]; //running store of previous mushroom count.
			int maxDifference = 0; //for method 2
			for (int mushroomCount : mushroomCounts) {
				int difference = prevMushrooms - mushroomCount;
				if (difference > 0) {
					method1 += difference;
					if (difference > maxDifference) {
						maxDifference = difference;
					}
				}
				prevMushrooms = mushroomCount;
			}
			for (int i = 0; i < times - 1; i++) { //ignore last one.
				int mushroomCount = mushroomCounts[i];
				if (mushroomCount > maxDifference) method2 += maxDifference;
				else method2 += mushroomCount;
			}
			
			outputCases.add(method1 + " " + method2);
		}
		
		for (int i = 0; i < outputCases.size(); i++) {
			System.out.println("Case #" + (i+1) + ": " + outputCases.get(i));
		}
	}

}
