import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;




public class MagicTrick {
	
	public static void main(String[] args) throws IOException{
		
		String fileIn = "C:/Users/Valentin/workspace/GoogleCodeJamQualif/src/A-small-attempt0.in";
		String fileOut = "C:/Users/Valentin/workspace/GoogleCodeJamQualif/src/test-A.out";
		System.setIn(new FileInputStream(fileIn));
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		System.setOut(new PrintStream(fileOut));
		
		String line;
		int i = 1;
		int testCase = 1;
		
		int rowFirst = 0;
		int rowSecond = 0;
		List<String[]> tabFirst = new ArrayList<>();
		List<String[]> tabSecond = new ArrayList<>();
		
		boolean firstLine = true;
		while ((line = stdin.readLine()) != null && line.length() != 0) {
			String[] input = line.split(" ");
			if (firstLine) {
				firstLine = false;
				continue; 
			}
			if (i == 1) {
				tabFirst = new ArrayList<>();
				tabSecond = new ArrayList<>();
			}
			switch (i) {
				case 1: rowFirst = Integer.parseInt(input[0]);
						break;
				case 2: tabFirst.add(input);
						break;
				case 3: tabFirst.add(input);
						break;
				case 4: tabFirst.add(input);
						break;
				case 5: tabFirst.add(input);
						break;
				case 6: rowSecond = Integer.parseInt(input[0]);
						break;
				case 7: tabSecond.add(input);
						break;
				case 8: tabSecond.add(input);
						break;
				case 9: tabSecond.add(input);
						break;
				case 10: tabSecond.add(input);
						break;
			}
			if (i == 10) {
				i = 1;
				calculate(rowFirst, tabFirst, rowSecond, tabSecond, testCase);
				testCase++;
				continue;
			}
			i++;
		}
		
		
	}

	private static void calculate(int rowFirst, List<String[]> tabFirst,
			int rowSecond, List<String[]> tabSecond, int testCase) {
		String cardNumber = "0";
		boolean cheat = false;
		for (String i : tabFirst.get(rowFirst - 1)) {
			if (cheat) {
				break;
			}
			for (String j : tabSecond.get(rowSecond - 1)) {
				if (i.equals(j)) {
					if (!cardNumber.equals("0")) {
						cheat = true;
						break;
					}
					else {
						cardNumber = i;
					}
				}
			}
		}
		
		
		if (cheat) System.out.println("Case #" + testCase + ": Bad magician!");
		else if (cardNumber.equals("0")) System.out.println("Case #" + testCase + ": Volunteer cheated!");
		else System.out.println("Case #" + testCase + ": " + cardNumber);
		
	}

}
