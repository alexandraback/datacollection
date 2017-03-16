package codejam15;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Vector;

public class CopyOfSolution2 {
	public static void main(String[] args) throws IOException {
		// BufferedReader br = new BufferedReader(
		// new FileReader(
		// "/Users/vladimir/Documents/workspaceg/GGL/src/codejam15/B-small-attempt2.in"));
		BufferedReader br = new BufferedReader(new FileReader("/Users/vladimir/Documents/workspaceg/GGL/src/codejam15/B-large.in"));
		int T = Integer.valueOf(br.readLine());		
		PrintWriter writer = new PrintWriter("/Users/vladimir/Documents/workspaceg/GGL/src/codejam15/output.txt", "UTF-8");

		for (int i = 0; i < T; i++) {
			String[] RCN = br.readLine().split(" ");
			int R = Integer.valueOf(RCN[0]);
			int C = Integer.valueOf(RCN[1]);
			int N = Integer.valueOf(RCN[2]);			
			
			if(R == C && R == 1) {
				writer.println("Case #" + (i + 1) + ": " + 0);
			} else {	
				int counter = 0;
				int un = 0;	
				int min = 0;
				boolean[][] grid = new boolean[R][C];
				
				for(int j = 0; j < R; j++) {
					int start = (j % 2 == 0)? 0 : 1; 
					for(int k = start; k < C; k += 2) {
						counter++;
						grid[j][k] = true;
					}
				}
				
				if(counter < N) {
					PriorityQueue<Integer> heap = new PriorityQueue<Integer>();
					
					for(int j = 0; j < R; j++) {
						for(int k = 0; k < C; k++) {
							if(!grid[j][k]) {
								int cur = 0;
								if(j > 0) {
									cur++;
								}
								if(k > 0) {
									cur++;
								}
								if(j < R - 1) {
									cur++;
								}
								if(k < C - 1) {
									cur++;
								}
								heap.add(cur);
							}
						}
					}
					
					while(counter < N) {
						Integer cur = heap.remove();						
						un += cur;
						counter++;
					}
				}
				
				min = un;
				un = 0;
				counter = 0;
				grid = new boolean[R][C];

				for(int j = 0; j < R; j++) {
					int start = (j % 2 == 0)? 1 : 0; 
					for(int k = start; k < C; k += 2) {
						counter++;
						grid[j][k] = true;
					}
				}
				
				if(counter < N) {
					PriorityQueue<Integer> heap = new PriorityQueue<Integer>();
					
					for(int j = 0; j < R; j++) {
						for(int k = 0; k < C; k++) {
							if(!grid[j][k]) {
								int cur = 0;
								if(j > 0) {
									cur++;
								}
								if(k > 0) {
									cur++;
								}
								if(j < R - 1) {
									cur++;
								}
								if(k < C - 1) {
									cur++;
								}
								heap.add(cur);
							}
						}
					}
					
					while(counter < N) {
						Integer cur = heap.remove();						
						un += cur;
						counter++;
					}
				}
								
				
				writer.println("Case #" + (i + 1) + ": " + Math.min(min, un));
			}					
		}
		writer.close();
	}
}