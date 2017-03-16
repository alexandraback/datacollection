package world2015.round1a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Logging {

	public int[] solve(int N, long[] X, long[] Y) {
		int[] res = new int[N];
		for (int i=0; i<N; i++)
			res[i] = solve(N, X, Y, i);
		return res;
	}
	
	private int solve(int N, long[] X, long[] Y, int idx) {
		int min = N-1;
		for (int i=0; i<N; i++) {
			if (i==idx)
				continue;
			Line line = new Line(new long[]{X[idx], Y[idx]}, new long[]{X[i], Y[i]});
			int[] cnt = new int[3];
			for (int j=0; j<N; j++) {
				if (j==i || j==idx)
					continue;
				int where = line.where(new long[]{X[j], Y[j]});
				cnt[where+1]++;
			}
			min = Math.min(min, cnt[0]);
			min = Math.min(min, cnt[2]);
		}
		return min;
	}
	
	private class Line {
		private long[] p1;
		private long dx, dy;
		private Line(long[] p1, long[] p2) {
			this.p1 = p1;
			dx = p2[0]-p1[0];
			dy = p2[1]-p1[1];
		}
		private int where(long[] p) {
			long where = (p[0]-p1[0])*dy-(p[1]-p1[1])*dx;
			if (where>0)
				return 1;
			else if (where<0)
				return -1;
			else
				return 0;
		}
	}
	
	public static void main(String args[]) throws IOException {
		String inputPath = "file/world2015/round1a/C-small-attempt1.in";
		String outputPath = inputPath.substring(0, inputPath.lastIndexOf('.')) + ".out";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));
		PrintWriter pw = new PrintWriter(outputPath);
		String line = br.readLine();
		int numProblems = Integer.parseInt(line);
		for (int i=0; i<numProblems; i++) {
			line = br.readLine().trim();
			int N = Integer.parseInt(line);
			long[] X = new long[N];
			long[] Y = new long[N];
			for (int j=0; j<N; j++) {
				String[] tokens = br.readLine().trim().split(" ");
				X[j] = Long.parseLong(tokens[0]);
				Y[j] = Long.parseLong(tokens[1]);
			}
			int[] res = new Logging().solve(N, X, Y);
			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + (i+1) + ":");
			for (int j=0; j<N; j++)
				sb.append("\n" + res[j]);
			System.out.println(sb);
			pw.println(sb);
		}
		br.close();
		pw.close();
	}
}
