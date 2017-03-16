package Jam2014.Round1B;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Stack;


public class Problem1 {

	public static void main(String[] args) {
		try {
			//String file = "problem_a_test";
			//String file = "A-small-attempt0";
			String file = "A-large";
			FileReader fr = new FileReader(file + ".in");
			BufferedReader br = new BufferedReader(fr);
			FileWriter fw = new FileWriter(file + ".out");
			BufferedWriter bw = new BufferedWriter(fw);
			String line;
			line = br.readLine();
			int cases = Integer.parseInt(line);
			String words[];
			for(int i=0; i<cases; i++) {
				line = br.readLine();
				int N = Integer.parseInt(line);
				words = new String[N];
				for(int j=0; j<N; j++) {
					words[j] = br.readLine();
				}
				boolean notPossible = false;
				int blocks = getBlocks(words[0]);
				int diffs[][][] = new int[N][N][blocks];
				for(int k=0; k<N; k++) {
					if(getBlocks(words[k]) != blocks)
						notPossible = true;
				}
				if(!notPossible) {
					for(int k=0; k<N; k++) {
						for(int l=0; l<N; l++) {
							//System.out.println(words[k] + " " + words[l]);
							int dist[] = dist(words[k], words[l], blocks);
							if(dist == null) {
								notPossible = true;
								break;
							}
							diffs[k][l] = dist;
							//for(int p=0; p<blocks; p++) System.out.println(dist[p]);
						}
						if(notPossible) break;
					}
				}
				int sum = 0;
				
				if(!notPossible) {
					for(int q = 0; q<blocks; q++) {
						int min = -1;
						for(int p = 0; p<N; p++) {
							int test = 0;
							for(int o = 0; o<N; o++) {
								test += diffs[o][p][q];
							}
							if(min == -1) min = test;
							else if(test < min) min = test;
						}
						sum += min;
					}
				}
				
				if(notPossible)
					bw.write("Case #" + (i+1)+": Fegla Won");
				else
					bw.write("Case #" + (i+1)+": " + sum);
				bw.write("\n");
			}
			br.close();
			bw.close();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static int getBlocks(String w) {
		StringBuilder sb1 = new StringBuilder(w);
		char c1,r1;
		int i1 = -1, i2 = -1;
		int l1 = 0, l2 = 0;
		boolean finished = false;
		int index = 0;
		while(!finished) {
			c1 = sb1.charAt(++i1);
			while(i1 < w.length()-1 && c1 == sb1.charAt(i1+1)) {
				i1++;
			}
			if(i1 == w.length()-1) {
				finished = true;
			}
			index++;
		}
		return index;
	}
	
	public static int[] dist(String w1, String w2, int blocks) {
		StringBuilder sb1 = new StringBuilder(w1);
		StringBuilder sb2 = new StringBuilder(w2);
		char c1,r1,c2,r2;
		int i1 = -1, i2 = -1;
		int l1 = 0, l2 = 0;
		int diff[] = new int[blocks];
		boolean finished = false;
		int index = 0;
		while(!finished) {
			if(sb1.charAt(i1+1) != sb2.charAt(i2+1)) {
				diff = null;
				finished = true;
			} else {
				c1 = sb1.charAt(++i1);
				r1 = c1;
				l1 = 1;
				while(i1 < w1.length()-1 && c1 == sb1.charAt(i1+1)) {
					i1++;
					l1++;
				}
				c2 = sb2.charAt(++i2);
				r2 = c2;
				l2 = 1;
				while(i2 < w2.length()-1 && c2 == sb2.charAt(i2+1)) {
					i2++;
					l2++;
				}
				if(i1 == w1.length()-1 && i2 == w2.length()-1) {
					finished = true;
				}
				diff[index++] = Math.abs(l1-l2);
				//System.out.println("i1: " + i1);
				//System.out.println("i2: " + i2);
				//System.out.println("l1: " + l1);
				//System.out.println("l2: " + l2);
			}
			
		}
		return diff;
	}
}
