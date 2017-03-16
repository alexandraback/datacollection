import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("A.in")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("A.out"))));
		
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			int ans1 = Integer.parseInt(br.readLine())-1;
			int[][] grid1 = new int[4][4];
			for (int j = 0; j < 4; j++) {
				String[] str = br.readLine().split(" ");
				for (int k = 0; k < 4; k++) grid1[j][k] = Integer.parseInt(str[k])-1;
			}
			int ans2 = Integer.parseInt(br.readLine())-1;
			int[][] grid2 = new int[4][4];
			for (int j = 0; j < 4; j++) {
				String[] str = br.readLine().split(" ");
				for (int k = 0; k < 4; k++) grid2[j][k] = Integer.parseInt(str[k])-1;
			}
			pw.println("Case #"+(i+1)+": "+analyze(ans1, grid1, ans2, grid2));
		}

		pw.close();
		br.close();
	}
	
	private static String analyze(int ans1, int[][] grid1, int ans2, int[][] grid2) {
		int[] suggest = new int[16];
		for (int i = 0; i < 4; i++) { suggest[grid1[ans1][i]]++; suggest[grid2[ans2][i]]++; }
		int answer = -1;
		for (int i = 0; i < 16; i++) {
//			if (suggest[i] > 2) return "Bad magician!";
			if (suggest[i] == 2) {
				if (answer < 0) answer = i;
				else return "Bad magician!";
			}
		}
		if (answer < 0) return "Volunteer cheated!";
		return ""+(answer+1);
	}
}
