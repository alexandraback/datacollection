import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class A {

	public static void main(String[] args) {
		try {
			setInputFile("input.in");
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		}
		try {
			setOutputFile("output.out");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		Scanner sc = new Scanner(System.in);
		int testCase = sc.nextInt();
		
		for (int i = 0; i < testCase; i++) {
			String str[] = new String[sc.nextInt()];
			for (int j = 0; j < str.length; j++) {
				str[j] = sc.next();
			}
			
			boolean lose = false;
			int number = 0;
			label : while(true) {
				for (int j = 0; j < str.length; j++) {
					if(str[j].length() == 0) {
						for (int k = 0; k < str.length; k++) {
							if(str[k].length() != 0) {
								lose = true;
								break label;
							}
						}
						break label;
					}
				}
				char letter = str[0].charAt(0);
				for (int j = 1; j < str.length; j++) {
					if(str[j].charAt(0) != letter) {
						lose = true;
						break label;
					}		
				}
				int counters[] = new int[str.length];
				for (int j = 0; j < str.length; j++) {
					counters[j] = countLenght(str[j]);
					str[j] = str[j].substring(counters[j]);
				}
				int minMove = numberOfMinMoves(counters);
				number += minMove;
					
			}
			if(lose)
				System.out.println("Case #"+(i+1)+": Fegla Won");
			else
				System.out.println("Case #"+(i+1)+": "+number);
			
		}
		
		sc.close();
	}
	
	private static int countLenght(String str) {
		if(str.length() == 0)
			return 0;
		int counter = 1;
		char letter = str.charAt(0);
		for (int j = 1; j < str.length(); j++) {
			if(str.charAt(j) == letter)
				counter++;
			else break;
		}
		return counter;
	}
	
	private static int numberOfMinMoves(int counters[]) {
		int min = counters[0];
		int max = counters[0];
		for (int i = 1; i < counters.length; i++) {
			if(counters[i] < min)
				min = counters[i];
			else if(counters[i] > max)
				max = counters[i];
		}
		
		return numberOfMoves(counters, min, max);
	}

	private static int numberOfMoves(int counters[], int current, int until) {
		int counter = 0;
		for (int i = 0; i < counters.length; i++) {
			counter += Math.abs(counters[i]-current);
		}
		if(current == until)
			return counter;
		return Math.min(counter, numberOfMoves(counters, current+1, until));
	}

	private static void setInputFile(String path) throws FileNotFoundException {
		System.setIn(new FileInputStream(new File(path)));
	}

	private static void setOutputFile(String path) throws FileNotFoundException {
		System.setOut(new PrintStream(new File(path)));
	}
}
