import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class A {
	static String file = "A-small-attempt0";	
	
	static String solve(String[] d) {		
		int moves = 0;		
		List<List<Integer>> counts = new ArrayList<List<Integer>>();
		List<List<Character>> chars = new ArrayList<List<Character>>();
		
		for (int i = 0; i < d.length; i++) {
			counts.add(new ArrayList<Integer>());
			chars.add(new ArrayList<Character>());			
			int counter = 1;
			char lastC = d[i].charAt(0);
			for(int j = 1; j < d[i].length(); j++) {
				if (d[i].charAt(j) == lastC) {
					counter++;
				} else {
					chars.get(i).add(lastC);
					counts.get(i).add(counter);
					lastC = d[i].charAt(j);
					counter=1;
				}			
			}
			
			chars.get(i).add(lastC);
			counts.get(i).add(counter);
		}
		
		// check if possible
		List<Character> first = chars.get(0);
		for (int i = 1; i < chars.size(); i++) {
			List<Character> current = chars.get(i);
			
			if (current.size() != first.size())
				return "Fegla Won";
			
			for(int j = 0; j < current.size(); j++)
				if (current.get(j) != first.get(j))
					return "Fegla Won";
		}
		
		// possible		
		for (int i = 0; i < chars.get(0).size(); i++) {
			int[] t = new int[d.length];
			for(int j = 0; j < counts.size(); j++) {
				t[j] = counts.get(j).get(i);
			}
			Arrays.sort(t);
			
			int med = t[t.length/2];
			for(int j = 0; j < t.length; j++)
				moves += Math.abs(t[j] - med);
		}
				
		return "" + moves;		
	}
	
	public static void main(String[] args) throws IOException {	
				
		FileInputStream fis = new FileInputStream(file+ ".in");
		InputStreamReader isr = new InputStreamReader(fis);
		BufferedReader br = new BufferedReader(isr);

		FileOutputStream fos = new FileOutputStream(file + ".out");
		OutputStreamWriter isw = new OutputStreamWriter(fos);
		BufferedWriter bw = new BufferedWriter(isw);

		String line = null;
		List<String> lines = new ArrayList<String>();
		while ((line = br.readLine()) != null) {
			lines.add(line);
		}

		int problemCount = Integer.parseInt(lines.get(0));
		int currentIndex = 1;
		for (int i = 0; i < problemCount; i++) {
			int n = Integer.parseInt(lines.get(currentIndex++));			
			String[] d = new String[n]; 
			for (int j = 0; j < d.length; j++) {
				d[j] = lines.get(currentIndex++);
			}
			
			String r = "Case #" + (i+1) +": " + solve(d);
							
			bw.write(r);
			bw.newLine();
		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();			
	}
}