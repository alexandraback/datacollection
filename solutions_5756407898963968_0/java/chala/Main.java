/*
	read data

	guest1 map1
	guest2 map2

	compare 2 maps

	output
*/

import java.io.*;
import java.util.*;

public class Main {

	static class Q {
		int index;
		Input no1 = new Input();
		Input no2 = new Input();
		String answer() {
			List<Integer> ans = new ArrayList<Integer>();
			List<Integer> ls1 = no1.ls.get(no1.row - 1);
			List<Integer> ls2 = no2.ls.get(no2.row - 1);
			for (Integer i : ls1) {
				if (ls2.contains(i)) {
					ans.add(i);
				}
			}
			String result = "";
			if (ans.size() == 1) {
				result = "Case #" + index + ": " + ans.get(0);
			} else if (ans.size() == 0) {
				result = "Case #" + index + ": " + "Volunteer cheated!";
			} else if (ans.size() > 1) {
				result = "Case #" + index + ": " +	"Bad magician!";
			}
			return result;
		}
	}

	static class Input {
		int row;
		List<List<Integer>> ls = new ArrayList<List<Integer>>();
		{
			for (int i = 0; i < 4; i++) {
				ls.add(new ArrayList<Integer>());
			}
		}

	}

	public static void main(String[] args) throws Exception {

		Scanner scan = new Scanner(System.in);
		int i0 = scan.nextInt();

		PrintStream out = new PrintStream("01out.txt");

		for (int i = 0; i < i0; i++) {
			Q q = new Q();
			q.index = i + 1;
			q.no1.row = scan.nextInt();
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					q.no1.ls.get(j).add(scan.nextInt());
				}
			}
			q.no2.row = scan.nextInt();
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					q.no2.ls.get(j).add(scan.nextInt());
				}
			}
			//System.out.println(q.answer());
			out.println(q.answer());

		}
		out.close();



	}

}