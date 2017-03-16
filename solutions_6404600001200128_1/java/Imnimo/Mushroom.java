import java.io.File;
import java.util.Scanner;


public class Mushroom {
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("A-large.in"));
		int numCases = Integer.parseInt(s.nextLine());
		for(int currentCase = 1;currentCase<=numCases;currentCase++) {
			int numSteps = Integer.parseInt(s.nextLine());
			int[] mushrooms = new int[numSteps];
			String m = s.nextLine();
			String[] mArr = m.split("\\s+");
			for(int i = 0;i<numSteps;i++) {
				mushrooms[i] = Integer.parseInt(mArr[i]);
			}
			System.out.println("Case #" + currentCase + ": " + minA(mushrooms) + " " + minB(mushrooms));
		}
		
	}
	public static int minA(int[] mushrooms) {
		int sum = 0;
		for(int i = 1;i<mushrooms.length;i++) {
			if(mushrooms[i]<mushrooms[i-1]) {
				sum+=(mushrooms[i-1]-mushrooms[i]);
			}
		}
		return sum;
	}
	public static int minB(int[] mushrooms) {
		int biggestDrop = 0;
		for(int i = 1;i<mushrooms.length;i++) {
			if(mushrooms[i]<mushrooms[i-1] && (mushrooms[i-1] - mushrooms[i])>biggestDrop) {
				biggestDrop = (mushrooms[i-1] - mushrooms[i]);
			}
		}
		int sum = 0;
		for(int i = 1;i<mushrooms.length;i++) {
			
			if(mushrooms[i-1] < biggestDrop) {
				sum+=mushrooms[i-1]; //she only eats what was there
			} else {
				sum+=biggestDrop;
			}
			
		}
		return sum;
		
	}
}
