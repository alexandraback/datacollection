import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;


public class Mashroom {
	public static void main(String[] args) throws IOException {
		Path fFilePath = Paths.get(args[0]);
		try (Scanner scanner = new Scanner(fFilePath,
				StandardCharsets.UTF_8.name())) {
			int count = 0;
			int platesCount;
			while (scanner.hasNextLine()) {
				if (count == 0) {
					scanner.nextLine();
				} else {
					platesCount = Integer.valueOf(scanner.nextLine());
					String plateLine = scanner.nextLine();
					int[] mashrooms = parsePlate(platesCount, plateLine);
					solveMashroomProblem(count, mashrooms);
				}
				count++;
			}
		}
	}
	
	private static void solveMashroomProblem(int caseNumber, int[] mashrooms) {
		// TODO Auto-generated method stub
		int any = anyCount(mashrooms);
		int constant = constantTime(mashrooms);
		System.out.println("Case #" + caseNumber + ": " + any + " " + constant);
	}
	
	private static int anyCount(int[] mashrooms) {
		int count = 0;
		for(int i = 0; i < mashrooms.length - 1; i++) {
			if(mashrooms[i] > mashrooms[i+1]) {
				count += mashrooms[i] - mashrooms[i+1];
			}
		}
		return count;
	}
	
	private static int constantTime(int[] mashrooms) {
		int count = 0;
//		double time = mashrooms[0] / 10;
		int max = 0;
		for(int i = 0; i < mashrooms.length - 1; i++) {
			max = Math.max(max, mashrooms[i] - mashrooms[i+1]);
		}
//		double time = max / 10;
		for(int i = 0; i < mashrooms.length - 1; i++) {
//			int d =
			if(max < mashrooms[i]) {
				count += max;
			} else {
				count += mashrooms[i];
			}
		}
		return count;
	}

	private static int[] parsePlate(int plateCount, String plateLine) {
		int[] cakes = new int[plateCount];
		Scanner scanner = new Scanner(plateLine);
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
