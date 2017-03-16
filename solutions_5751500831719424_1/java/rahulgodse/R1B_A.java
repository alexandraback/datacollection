package gcj.contest.y2014;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class R1B_A {

	public static void main(String[] args) {
		
		InputReader ir = new InputReader();
		
		int T = ir.nextInt();
		for (int i=0; i<T; i++) {
		
			int N = ir.nextInt();
			String[] words = new String[N];
			for (int j=0; j<N; j++) words[j] = ir.nextString() + '0';
			
			char[][] wordChar = new char[N][100];
			int[][] charCount = new int[N][100];
			int[] maxCount = new int[100];
			
			int uniqueChars = -1;
			
			boolean possible = true;
			
			for (int j=0; j<N && possible; j++) {
				String temp = words[j];
				int k=0;
				int iter = 0;
				char currChar = '0';
				int currCount = 0;
				while (k<temp.length()) {
					if (currChar == temp.charAt(k)) {
						currCount++;
					} else {
						if (currChar != '0') {
							wordChar[j][iter] = currChar;
							charCount[j][iter] = currCount;
							maxCount[iter] = Math.max(maxCount[iter], currCount);
							
							if (j>0 && wordChar[j][iter] != wordChar[0][iter]) {
								possible=false;
								break;
							}
							iter++;
						}
						currChar = temp.charAt(k);
						currCount = 1;
					}
					k++;
				}
				
				if (possible) {
					if (j==0) { 
						uniqueChars = iter;
					} else if (uniqueChars != iter) {
						possible = false;
					}
				}
			}
			
			int moves = 0;
			for (int x=0; possible && x<uniqueChars; x++) {
				int m1=10000;
				for (int y=0; y<=maxCount[x]; y++) {
					int m2 = 0; 
					for (int z=0; z<N; z++) {
						m2 += Math.abs(charCount[z][x] - y);
					}
					m1 = Math.min(m1, m2);
				}
				moves += m1;
			}
			
			System.out.print("Case #" + (i+1) + ": ");
			System.out.print((possible ? moves : "Fegla Won"));
			System.out.println();
		}
	}
	
	static class InputReader {
		
		BufferedReader bf = null;
		StringTokenizer buff = null;
	
		public InputReader() {
			bf = new BufferedReader(new InputStreamReader(System.in));
			readLine();
		}
		
		private void readLine() {
			try {
				buff = new StringTokenizer(bf.readLine());
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		
		private String nextToken() {
			if (buff.hasMoreTokens()) {
				return buff.nextToken();
			} else {
				readLine();
				return nextToken();
			}
		}
		
		public String nextString() {
			return nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(nextToken());
		}
		
		public long nextLong() {
			return Long.parseLong(nextToken());
		}
		
		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}
	
}
