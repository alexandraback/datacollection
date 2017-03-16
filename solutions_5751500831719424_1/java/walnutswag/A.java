package round1b;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {


	public static void main(String[] args) throws IOException {

//		String test = "ssssssssss";
//		System.out.println(contract(test));
//		System.out.println(Arrays.toString(hist(test)));
//		System.exit(0);
		
		String path = "A-large";
		BufferedReader in = new BufferedReader(new FileReader(Main.DIR + path + ".in"));
		PrintWriter out = new PrintWriter(Main.DIR + path + ".out");

		int inputs = Integer.parseInt(in.readLine());

		iterations: for (int idx = 0; idx < inputs; idx++) {
			System.out.print("Case #"+(idx+1)+": ");
			out.print("Case #"+(idx+1)+": ");
			
			int N = Integer.parseInt(in.readLine());
			
			String[] words = new String[N];
			for (int i = 0; i < N; i++)
				words[i] = in.readLine();
			
			String contract = contract(words[0]);
			for (int i = 1; i < N; i++) {
				if (!contract(words[i]).equals(contract)) {
					System.out.println("Fegla Won");
					out.println("Fegla Won");
					continue iterations;
				}
					
			}
			
			int[][] hists = new int[N][];
			for (int i = 0; i < N; i++)
				hists[i] = hist(words[i]);
			
			int[][] flipped = new int[contract.length()][N];
			for (int i = 0; i < contract.length(); i++) {
				for (int j = 0; j < N; j++) {
					flipped[i][j] = hists[j][i];
				}
			}
			for (int i = 0; i < contract.length(); i++)
				Arrays.sort(flipped[i]);
			
			int cost = 0;
			for (int i = 0; i < contract.length(); i++) {
				int mid = flipped[i][N/2];
				for (int j = 0; j < N; j++) {
					cost += Math.abs(flipped[i][j] - mid);
				}
			}
			
			System.out.println(cost);
			out.println(cost);
			
		}

		in.close();
		out.close();

	}
	
	
	public static String contract(String s) {
		StringBuilder builder = new StringBuilder();
		builder.append(s.charAt(0));
		char prev = s.charAt(0);
		
		for (int i = 1; i < s.length(); i++) {
			char cur = s.charAt(i);
			if (cur == prev) 
				continue;
			builder.append(cur);
			prev = cur;
		}
		
		return builder.toString();
	}
	
	public static int[] hist(String s) {
		String contract = contract(s);
		int[] hist = new int[contract.length()];
		int j = 0;
		char prev = s.charAt(0);
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == prev)
				hist[j]++;
			else {
				prev = s.charAt(i);
				j++;
				i--;
			}
				
		}
		
		return hist;
	}

}
