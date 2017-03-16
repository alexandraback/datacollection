package round1a;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class ProblemA {
	
	public void run(File in, File out) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(in));
		FileWriter fw = new FileWriter(out);
		
		int t = Integer.parseInt(br.readLine());
		
		for (int i = 1; i <= t; i++) {
			int n = Integer.parseInt(br.readLine());
			int[] nums = new int[n];
			
			String[] line = br.readLine().split(" ");
			
			for (int j = 0; j < n; j++) {
				nums[j] = Integer.parseInt(line[j]);
			}
			
			int min = solve1(nums);
			
			fw.write("Case #" + i + ": " + min + " " + solve2(nums, min) + "\n");
		}
		
		fw.close();
		br.close();
	}
	
	private int solve1(int[] n) {
		int eaten = 0;
		for (int i = 1; i < n.length; i++) {
			if (n[i] < n[i - 1]) {
				eaten += n[i - 1] - n[i];
			}
		}
		
		return eaten;
	}
	
	private int solve2(int[] n, int min) {
		double min_rate = 0;
		for (int i = 1; i < n.length; i++) {
			double rate = (n[i - 1] - n[i]) / 10.0;
			if (rate > min_rate) {
				min_rate = rate;
			}
		}
		
		int eaten = 0;
		for (int i = 1; i < n.length; i++) {
			if (n[i - 1] > 10 * min_rate) {
				eaten += 10 * min_rate;
			} else {
				eaten += n[i - 1];
			}
			
		}
		
		return eaten ;
	}
	
	public static void main(String[] args) throws Exception {
//		String name = "A-sample";
		String name = "A-small-attempt0";
//		String name = "A-large";
		new ProblemA().run(new File(name + ".in"), new File(name + ".out"));
		
		System.out.println("DONE!");
	}

}
