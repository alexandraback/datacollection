import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;


public class MagicTrick {
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("A-small-attempt0.in"));
		String first = s.nextLine();
		int numCases = Integer.parseInt(first);
		for(int i = 1;i<=numCases;i++) {
			ArrayList<String> secondOpts = new ArrayList<String>();
			ArrayList<String> firstOpts = new ArrayList<String>();
			
			String line = s.nextLine();
			int firstRow = Integer.parseInt(line);
			for(int row = 1;row<=4;row++) {
				line = s.nextLine();
				if(row!=firstRow) {
					continue;
				}
				
				String[] opts = line.split(" ");
				for(String o : opts) {
					firstOpts.add(o);
				}
			}
			line = s.nextLine();
			int secondRow = Integer.parseInt(line);
			for(int row = 1;row<=4;row++) {
				line = s.nextLine();
				if(row!=secondRow) {
					continue;
				}
				
				String[] opts = line.split(" ");
				for(String o : opts) {
					secondOpts.add(o);
				}
			}
			String ans = "";
			int matches = 0;
			for(String o : firstOpts) {
				if(secondOpts.contains(o)) {
					ans = o;
					matches++;
				}
			}
			if(matches == 0) {
				System.out.println("Case #" + i + ": " + "Volunteer cheated!");
			}
			if(matches == 1) {
				System.out.println("Case #" + i + ": " + ans);
			}
			if(matches > 1) {
				System.out.println("Case #" + i + ": " + "Bad magician!");
			}
		}
	}
}
