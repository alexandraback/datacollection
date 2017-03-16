package round1b_14;

import java.util.*;
import java.io.*;


public class A {
	BufferedReader in;
	StringTokenizer st;
	FileWriter out;
	
	int getint() {
		return Integer.parseInt(st.nextToken());
	}
	
	void run() throws Exception {
		in = new BufferedReader(new FileReader("src/round1b_14/A.in"));
		st = new StringTokenizer(in.readLine());
		out = new FileWriter("src/round1b_14/A.out");
		
		int T = getint();
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(in.readLine());
			int N = getint();
			
			String[] words = new String[N];
			for (int i = 0; i < N; i++) {
				words[i] = in.readLine().trim();
			}
			int[] indices = new int[N];
			
			boolean possible = false;
			int totalsum = 0;
			while (true) {
				boolean done = true;
				for (int i = 0; i < N; i++) {
					if (indices[i] < words[i].length()) {
						done = false;
					}
				}
				if (done) {
					possible = true;
					break;
				}
				
				ArrayList<Integer> nums = new ArrayList<Integer>();
				char[] c = new char[N];
				boolean oops = false;
				for (int i = 0; i < N; i++) {
					if (indices[i] >= words[i].length()) {
						oops = true;
						break;
					} else {
						c[i] = words[i].charAt(indices[i]);
						if (i != 0 && c[i] != c[0]) {
							oops = true;
							break; 
						}
					}
				}
				if (oops) break;
				
				for (int i = 0; i < N; i++) {
					int count = 0;
					while (indices[i] < words[i].length() && words[i].charAt(indices[i]) == c[i]) {
						count++;
						indices[i]++;
					}
					nums.add(count);
				}
				Collections.sort(nums);
				int med = nums.get(N/2);
				int total = 0;
				for (Integer num : nums) {
					total += Math.abs(med-num);
				}
				totalsum += total;
			}
			
			out.write(String.format("Case #%d: %s\n", t, possible ? Integer.toString(totalsum) : "Fegla Won"));
		}
		
		in.close();
		out.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new A()).run();
	}
}
