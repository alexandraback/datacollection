import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String args[]) throws Exception {
		ArrayList<String> lines = readFile();
		FileWriter fw = new FileWriter("result.out");

		int cases = Integer.parseInt(lines.get(0));

		for (int i=1; i<=cases; i++) {
			fw.write("Case #" + i + ": ");
			fw.write(solveProblem(lines.subList((i-1)*2+1,i*2+1)));
			fw.write("\n");
		}
/*
		int curr = 1;
		for (int i=1; i<=cases; i++) {
			int line = Integer.parseInt(lines.get(curr));
			curr++;
			fw.write("Case #" + i + ": ");
			fw.write(solveProblem(lines.subList(curr, curr+line)));
			fw.write("\n");			
			curr = curr + line;
		}
*/
		fw.close();
	}

	private static ArrayList<String> readFile() throws Exception {
		FileReader fr = new FileReader("input.in");
		BufferedReader br = new BufferedReader(fr);

		ArrayList<String> res = new ArrayList<String>();

		String line = br.readLine();
		while (line != null) {
			res.add(line);
			line = br.readLine();
		}
		res.add(line);

		fr.close();
		br.close();
		return res;
	}	

	private static String solveProblem(List<String> input) throws Exception {
		int num = Integer.parseInt(input.get(0));
		String [] tokens = input.get(1).split(" ");

		int res1 = 0;
		int pre = 0;
		int max = 0;
		for (int i = 0; i < num; i++) {
			int curr = Integer.parseInt(tokens[i]);
			if (curr < pre) {
				res1 = res1 + pre - curr;
				if (pre - curr > max) max = pre - curr;
			}
			pre = curr;
		}

		int res2 = 0;
		for (int i = 0; i < num-1; i++) {
			res2 = res2 + Math.min(max, Integer.parseInt(tokens[i]));
		}

		return Integer.toString(res1) + " " + Integer.toString(res2);
	}
}