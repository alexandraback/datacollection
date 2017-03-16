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
		String [] tokens = input.get(0).split(" ");
		int numB = Integer.parseInt(tokens[0]);
		long index = Long.parseLong(tokens[1]);
		tokens = input.get(1).split(" ");

		int[] time = new int[numB];
		for (int i = 0; i < numB; i++) time[i]=Integer.parseInt(tokens[i]);

		int total = 1;
		for (int i = 0; i < numB; i++) total = lcm(total, time[i]);

		int roundC = 0;
		for (int i = 0; i < numB; i++) roundC = roundC + (total/time[i]);

		int indexC = (int)(index % (long)roundC);
		if (indexC==0) indexC = roundC;
		if (indexC <= numB) return Integer.toString(indexC);

		int step = total;
		for (int i = 0; i < numB; i++) step = gcd(step, time[i]);

		int[] current = new int[numB];
		for (int i = 0; i < numB; i++) current[i] = time[i];

		int cm = numB+1;
		while(true) {
			for (int j = 0; j < numB; j++) {
				if (current[j] == 0) {
					if (cm==indexC) return Integer.toString(j+1);
					current[j] += time[j];
					cm++;
				}
				else {
					current[j] = current[j]-step;
					if (current[j] == 0) {
						if (cm==indexC) return Integer.toString(j+1);
						current[j] += time[j];
						cm++;
					}
				}
			}
		}
	}

	private static int lcm(int a, int b) {
		for(int i = 1; i <= b; i++) {
    		if(i*a % b == 0)
        		return i*a;
        }
        return a*b;
	}

	private static int gcd(int a, int b) {
		if(b == 0){
			return a;
		}
		return gcd(b, a%b);
	}	
/*
	private static int gcd(int a, int b) {
		while (b > 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}*/
}