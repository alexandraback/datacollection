package round1a;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.concurrent.Semaphore;

public class ProblemB {
	
	public void run(File in, File out) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(in));
		FileWriter fw = new FileWriter(out);
		
		int t = Integer.parseInt(br.readLine());
		final int[] results = new int[t];
		
		final Semaphore sem = new Semaphore(4);
		
		for (int i = 1; i <= t; i++) {
			String[] string = br.readLine().split(" ");
			int b = Integer.parseInt(string[0]);
			final int n = Integer.parseInt(string[1]);
			
			final int[] m = new int[b];
			string = br.readLine().split(" ");
			
			for (int j = 0; j < b; j++) {
				m[j] = Integer.parseInt(string[j]);
			}
			
			sem.acquire();
			
			final int num = i;
			Thread solver = new Thread() {
				@Override
				public void run() { 
					results[num - 1] = solve(n, m);
					System.out.println("Case #" + num + "... DONE!");
					sem.release();
				}
			};
			solver.start();
		}
		
		sem.acquire(4);
		
		for (int i = 1; i <= t; i++) {
			fw.write("Case #" + i + ": " + results[i - 1] + "\n");
		}
		
		fw.close();
		br.close();
	}
	
	private int solve(int n, int[] m) {
		if (n <= m.length) {
			return n;
		}
		
		int person = m.length;
		int[] time = Arrays.copyOf(m, m.length);
		
		while (true) {
			int min = min(time);
			
			for (int i = 0; i < m.length; i++) {
				time[i] -= min;
				if (time[i] == 0) {
					time[i] = m[i];
					person++;
					
					if (person == n) {
						return i + 1;
					}
				}
			}
		}
	}
	
	private int min(int[] m) {
		int min = m[0];
		
		for (int i : m) {
			if (i < min) {
				min = i;
			}
		}
		
		return min;
	}
	
	public static void main(String[] args) throws Exception {
//		String name = "B-sample";
		String name = "B-small-attempt2";
//		String name = "B-large";
		new ProblemB().run(new File(name + ".in"), new File(name + ".out"));
		
		System.out.println("DONE!");
	}

}
