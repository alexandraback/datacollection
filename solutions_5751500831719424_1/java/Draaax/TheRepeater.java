import java.util.ArrayList;
import java.util.Scanner;


public class TheRepeater {
	public static void main(String[] args) {
Scanner kb = new Scanner(System.in);
		
		int cases = kb.nextInt();
		
		for(int c = 1; c <= cases; c++) {
			int strings = kb.nextInt();
			
			String[] stringList = new String[strings];
			for(int i = 0; i < strings; i++) {
				stringList[i] = kb.next();
			}
					
			String[] minimum = getMinimum(stringList);
			int[][] lengths = getNumber(stringList);
			
			boolean doesWork = true;
			String previous = minimum[0];
			for(int i = 1; i < minimum.length; i++) {
				String current = minimum[i];
				if(!current.equals(previous)) doesWork = false;
			}
			
			System.out.print("Case #" + c  + ": ");
			
			if(doesWork) {
				System.out.println(solve(minimum, lengths));
			} else {
				System.out.println("Fegla Won");
			}
			
			
		}	
	}
	
	
	private static int solve(String[] minimum, int[][] lengths) {
		int cost = 0;
		
		for(int i = 0; i < minimum[0].length(); i++) {
			ArrayList<Integer> numberList = new ArrayList<>(minimum.length);
			
			for(int j = 0; j < minimum.length; j++) {
				numberList.add(lengths[j][i]);
			}
			int minNumber = Integer.MAX_VALUE;
			for(int j = 1; j <= 100; j++) {
				int tempSum = 0;
				for(int k = 0; k < numberList.size(); k++) {
					tempSum += (int) Math.abs(numberList.get(k) - j);
				}
				minNumber = Math.min(minNumber, tempSum);
			}
			cost += minNumber;
		}
		
		return cost;
	}


	private static String[] getMinimum(String[] strings) {
		String[] output = new String[strings.length];
		
		for(int i = 0; i < strings.length; i++) {
			String s = strings[i];
			String current = "" + s.charAt(0);
			
			for(int j = 1; j < s.length(); j++) {
				char c = s.charAt(j);
				if(c != current.charAt(current.length() - 1)) {
					current += c + "";
				}
			}
			
			output[i] = current;
		}
		return output;
	}
	
	private static int[][] getNumber(String[] strings) {
		int[][] output = new int[strings.length][];
		
		for(int i = 0; i < strings.length; i++) {
			String s = strings[i];
			
			int[] lengths = new int[s.length()];
			
			char previous = s.charAt(0);
			int index = 0;
			int length = 1;
			for(int j = 1; j < s.length(); j++) {
				char current = s.charAt(j);
				if(current != previous) {
					previous = current;
					lengths[index] = length;
					length = 0;
					index++;
				}
				length++;
			}
			lengths[index] = length;
			
			output[i] = lengths;
		}
		return output;
	}
}
