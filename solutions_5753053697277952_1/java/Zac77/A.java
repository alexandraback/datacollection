/**
 * Source code for Google Code Jam 2016 - Online Round 1: Sub-Round C - Problem A
 * Author: Zac ZHANG (zac771989@gmail.com)
 * Date: 05/08/2016
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	public static final String FILE_NAME = "A-large";
	
	private BufferedReader in;
	
	public static void main(String[] args) throws IOException {
		A main = new A();
		main.start();
	}
	
	private void start() throws IOException {
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(FILE_NAME + ".out")));
		in = new BufferedReader(new FileReader(FILE_NAME + ".in"));
		
		int numCases = Integer.parseInt(in.readLine());
		for (int iCase = 1; iCase <= numCases; iCase++)
			out.println("Case #" + iCase + ":" + solve());
		
		in.close();
		out.close();
	}
	
	private String solve() throws IOException {
		int N = Integer.parseInt(in.readLine());
		StringTokenizer st = new StringTokenizer(in.readLine());
		int[] p = new int[N];
		for (int i = 0; i < N; i++)
			p[i] = Integer.parseInt(st.nextToken());
		StringBuilder ans = new StringBuilder();
		
		int sum = 0;
		for (int i : p)
			sum += i;
		
		int[] current = new int[N];
		
		while (sum > 0) {
			int index1 = 0, index2 = 0;
			while (index1 < N && current[index1] == p[index1])
				index1++;
			while (index2 < N && (index2 == index1 || current[index2] == p[index2]))
				index2++;
			int nTotal = 0;
			if (index1 < N) {
				nTotal++;
				current[index1]++;
				ans.insert(0, (char) (index1 + 'A'));
			}
			if (index2 < N) {
				nTotal++;
				current[index2]++;
				ans.insert(0, (char) (index2 + 'A'));
			}
			ans.insert(0, ' ');
			sum -= nTotal;
		}
		
		return ans.toString();
	}
	
}
