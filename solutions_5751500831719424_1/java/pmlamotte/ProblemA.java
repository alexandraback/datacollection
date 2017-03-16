import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;


/**
 * @author Paul LaMotte
 *
 */
public class ProblemA {

	public static void main(String[] args) {
		try {
			System.setOut(new PrintStream(new FileOutputStream("ProblemA.out")));
			Scanner scan = new Scanner(new FileInputStream("ProblemA.in"));
			int cases = new Scanner(scan.nextLine()).nextInt();
			for (int l = 0; l < cases; l++) {
				int numStrings = scan.nextInt();
				String[] arr = new String[numStrings];
				for (int i = 0; i < numStrings; i++) {
					arr[i] = scan.next();
				}
				
				HashSet<String> res = new HashSet<String>();
				int count = 0;
				for (int j = 0; j < arr.length; j++) {
					String flatStr = arr[j].charAt(0) + "";
					if (j == 0) { count = 1; }
					for (int i = 1; i < arr[j].length(); i++) {
						char c = arr[j].charAt(i);
						if (c != flatStr.charAt(flatStr.length()-1)) {
							if (j == 0) { count++; }
							flatStr += c + "";
						}
					}
					res.add(flatStr);
				}
				String str = "";

				if (res.size() > 1) {
					str = "Fegla Won";
				} else {
					String[][] strs = new String[numStrings][count];
					for (int i = 0; i < arr.length; i++) {
						String out = "";
						char prev = arr[i].charAt(0);
						out += "" + prev;
						int pos = 0;
						for (int j = 1; j < arr[i].length(); j++) {
							char next = arr[i].charAt(j);
							if (next == prev) {
								out += next;
							} else if (next != prev) {
								strs[i][pos] = out;
								out = "" + next;
								prev = next;
								pos++;
							}
						}
						strs[i][pos] = out;
					}
					
					int best = Integer.MAX_VALUE;
					int ops = 0;
					for (int i = 0; i < count; i++) {
						int maxSize = 0;
						for (int j = 0; j < strs.length; j++) {
							maxSize = Math.max(maxSize, strs[j][i].length());
						}
						int min = Integer.MAX_VALUE;
						for (int k = 1; k <= maxSize; k++) {
							int totops = 0;
							for (int j = 0; j < strs.length; j++) {
								totops += Math.abs(strs[j][i].length() - k); 
							}
							min = Math.min(min, totops);
						}
						ops += min;
					}
					str = ops + "";
				}
				
				System.out.printf("Case #%d: %s%n", l+1, str);
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
