package world2015.round1a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class MashroomMonster {

	public int[] solve(int[] mashrooms) {
		return new int[]{first(mashrooms), second(mashrooms)};
	}
	
	private int first(int[] mashrooms) {
		int res = 0;
		int plate = 0;
		for (int i=0; i<mashrooms.length; i++) {
			if (mashrooms[i]<plate)
				res += plate-mashrooms[i];
			plate = mashrooms[i];
		}
		return res;
	}
	
	private int second(int[] mashrooms) {
		int maxDiff = 0;
		for (int i=0; i<mashrooms.length-1; i++)
			maxDiff = Math.max(maxDiff, mashrooms[i]-mashrooms[i+1]);
		int res = 0;
		int plate = 0;
		for (int i=0; i<mashrooms.length; i++) {
			int eaten = Math.min(plate, maxDiff);
			res += eaten;
			plate -= eaten;
			plate = mashrooms[i];
		}
		return res;
	}
	
	public static void main(String args[]) throws IOException {
		String inputPath = "file/world2015/round1a/A-small-attempt0.in";
		String outputPath = inputPath.substring(0, inputPath.lastIndexOf('.')) + ".out";
		BufferedReader br = new BufferedReader(new FileReader(inputPath));
		PrintWriter pw = new PrintWriter(outputPath);
		String line = br.readLine();
		int numProblems = Integer.parseInt(line);
		for (int i=0; i<numProblems; i++) {
			line = br.readLine().trim();
			int N = Integer.parseInt(line);
			String[] tokens = br.readLine().trim().split(" ");
			int[] m = new int[N];
			for (int j=0; j<N; j++)
				m[j] = Integer.parseInt(tokens[j]);
			int[] res = new MashroomMonster().solve(m);
			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + (i+1) + ": " + res[0] + " " + res[1]);
			System.out.println(sb);
			pw.println(sb);
		}
		br.close();
		pw.close();
	}
}
