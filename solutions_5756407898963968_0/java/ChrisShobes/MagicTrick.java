package codejam2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class MagicTrick {

	public void solve(String file) {
		try {
			Scanner reader = new Scanner(new File(file));
			reader.nextLine(); // skip first line
			int i = 1;
			int firstGuess;
			int secondGuess;
			String[][] square4x4First = new String[4][4];
			String[][] square4x4Second = new String[4][4];
			while(reader.hasNextLine()) {
				
				firstGuess = Integer.parseInt(reader.nextLine()) - 1;
				square4x4First[0] = reader.nextLine().split(" ");
				square4x4First[1] = reader.nextLine().split(" ");
				square4x4First[2] = reader.nextLine().split(" ");
				square4x4First[3] = reader.nextLine().split(" ");
				
				secondGuess = Integer.parseInt(reader.nextLine()) - 1;
				square4x4Second[0] = reader.nextLine().split(" ");
				square4x4Second[1] = reader.nextLine().split(" ");
				square4x4Second[2] = reader.nextLine().split(" ");
				square4x4Second[3] = reader.nextLine().split(" ");
				String result = solve(square4x4First[firstGuess], square4x4Second[secondGuess]);
				System.out.println("Case #" + i + ": " + result); 
				i++;
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	private String solve(String[] first, String[] second) {
		String result = "";
		int c = 0;
		for(String a : first) {
			for(String b: second) {
				if(a.equals(b)) {
					result += a;
					c++;
				}
			}
		}
		if(c > 1) {
			return "Bad magician!";
		}
		else if(c == 1) {
			return result;
		}
		else {
			return "Volunteer cheated!";
		}
	}

	public static void main(String[] args) {
		MagicTrick test = new MagicTrick();
		/*
		String[] a = {"5","6","7","8"};
		String[] b = {"9", "10", "7", "12"};
		System.out.println(test.solve(a, b));
		String[] c = {"5","6","7","8"};
		String[] d = {"5","6","7","8"};
		System.out.println(test.solve(c, d));
		String[] e = {"5","6","7","8"};
		String[] f = {"9", "10", "11", "12"};
		System.out.println(test.solve(e, f));
		*/
		test.solve("A-small-attempt0.in");
	}

}
