package gcj;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;

public class A {

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		PrintStream out = new PrintStream(args[0] + ".out");
		
		int T = Integer.parseInt(in.readLine());
		for (int t = 0; t < T; t++) {
			// For each test case
			int N = Integer.parseInt(in.readLine());
			
			List<Character> seq = new ArrayList<Character>();
			
			String firstStr = in.readLine();
			char current = '!';
			
			for (int i = 0; i < firstStr.length(); i++) {
				if (firstStr.charAt(i) != current) {
					current = firstStr.charAt(i);
					seq.add(current);
				}
			}
			
			int[][] counts = new int[N][seq.size()];
			
			current = firstStr.charAt(0);
			int currentCount = 1;
			int currentIndex = 0;
			
			for (int i = 1; i < firstStr.length(); i++) {
				if (firstStr.charAt(i) == current) { 
					currentCount ++;
				} else {
					// add total and move on
					counts[0][currentIndex] = currentCount;
					current = firstStr.charAt(i);
					currentCount = 1;
					currentIndex ++;
				}
			}
			counts[0][currentIndex] = currentCount;
			
			boolean error = false;
			
			for (int n = 1; n < N; n++) {
				// For all other strings
				String str = in.readLine();
				
				if (str.charAt(0) != seq.get(0)) {
					error = true;
					break;
				}
				
				current = str.charAt(0);
				currentCount = 1;
				currentIndex = 0;
				
				for (int i = 1; i < str.length(); i++) {
					if (str.charAt(i) == current) {
						currentCount ++;
					} else {
						// add total and move on
						counts[n][currentIndex] = currentCount;
						current = str.charAt(i);
						currentCount = 1;
						currentIndex ++;
						if (seq.size() <= currentIndex) {
							// too many elements
							error = true;
							break;
						}
						if (str.charAt(i) != seq.get(currentIndex)) { // mismatch next char
							error = true;
							break;
						}
					}
				}
				
				if (currentIndex != seq.size() - 1) {
					// too few elements
					error = true;
					break;
				}
				
				if (error)
					break;
				
				counts[n][currentIndex] = currentCount;
			}
			System.out.println("case" + (t+1));
			if (error) {
				out.println("Case #" + (t+1) + ": Fegla Won");
			} else {
				int total = 0;
				for (int i = 0; i < seq.size(); i++) {
					// for each letter in the sequence
					int[] freqs = new int[101];
					
					int minIndex = 100;
					int maxIndex = -1;
					
					for (int k = 0; k < N; k++) {
						int next = counts[k][i];
						minIndex = Math.min(minIndex, next);
						maxIndex = Math.max(maxIndex,  next);
						freqs[next] ++;
					}
					
					while (maxIndex != minIndex) {
						if (freqs[minIndex] < freqs[maxIndex]) {
							total += freqs[minIndex];
							freqs[minIndex + 1] += freqs[minIndex];
							minIndex ++;
						} else {
							total +=  freqs[maxIndex];
							freqs[maxIndex - 1] += freqs[maxIndex];
							maxIndex --;
						}
					}
				}
				out.println("Case #" + (t+1) + ": " + total);
			}
		}
		
		in.close();
		out.close();
	}
	
}
