package world2015.round1a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.PriorityQueue;

public class HairCut {

	public int solve(int B, int N, long[] M) {
		int minIdx = 0;
		for (int i=1; i<B; i++)
			if (M[i]<M[minIdx])
				minIdx = i;
		int[] lower = lower(N, M, minIdx);
		long[] finishTime = new long[B];
		if (lower[0]>0) {
			long t = M[minIdx]*lower[0];
			for (int i=0; i<B; i++)
				finishTime[i] = M[i]-(t-1)%M[i]+1;
		}
		return solve2(B, N-lower[1], M, finishTime);
	}
	
	private int[] lower(int N, long[] M, int minIdx) {
		int left = 0, right = N;
		long leftNumFinished = 0;
		while (left<right) {
			int mid = (left+right+1)/2;
			long numFinished = numFinished(M, minIdx, mid);
			if (numFinished<N) {
				left = mid;
				leftNumFinished = numFinished;
			} else
				right = mid-1;
		}
		return new int[]{left, (int)leftNumFinished};
	}
	
	private long numFinished(long[] M, int minIdx, int n) {
		long time = M[minIdx]*n;
		if (time==0)
			return 0;
		long res = 0;
		for (int i=0; i<M.length; i++)
			res += (time-1)/M[i] + 1;
		return res;
	}
	
	private int solve2(int B, int N, long[] M, long[] finishTime) {
		PriorityQueue<Barber> que = new PriorityQueue<>();
		for (int i=0; i<B; i++)
			que.add(new Barber(i+1, M[i], finishTime[i]));
		for (int i=0; i<N-1; i++) {
			Barber barber = que.poll();
			barber.finishTime += barber.time;
			que.add(barber);
		}
		return que.peek().id;
	}
	
	private class Barber implements Comparable<Barber> {
		private int id;
		private long time;
		private long finishTime;
		private Barber(int id, long time, long finishTime) {
			this.id = id;
			this.time = time;
			this.finishTime = finishTime;
		}
		@Override
		public int compareTo(Barber barber) {
			if (finishTime<barber.finishTime)
				return -1;
			else if (finishTime>barber.finishTime)
				return 1;
			else
				return id-barber.id;
		}
	}
	
	public static void main(String args[]) throws IOException {
		String inputPath = "file/world2015/round1a/B-Large.in";
		String outputPath = inputPath.substring(0, inputPath.lastIndexOf('.')) + ".out";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));
		PrintWriter pw = new PrintWriter(outputPath);
		String line = br.readLine();
		int numProblems = Integer.parseInt(line);
		for (int i=0; i<numProblems; i++) {
			line = br.readLine().trim();
			String[] tokens = line.split(" ");
			int B = Integer.parseInt(tokens[0]);
			int N = Integer.parseInt(tokens[1]);
			long[] M = new long[B];
			tokens = br.readLine().trim().split(" ");
			for (int j=0; j<B; j++)
				M[j] = Long.parseLong(tokens[j]);
			int res = new HairCut().solve(B, N, M);
			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + (i+1) + ": " + res);
			System.out.println(sb);
			pw.println(sb);
		}
		br.close();
		pw.close();
	}
}
