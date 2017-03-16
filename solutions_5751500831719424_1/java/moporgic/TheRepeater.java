import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class TheRepeater {

	static {
		try {
			String input = "A-large.in";
			String output = input.substring(0, input.lastIndexOf('.')) + ".out";
			System.setIn(new FileInputStream(input));
			System.setOut(new PrintStream(new FileOutputStream(output), true));
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(0);
		}
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		Set<Integer> set = new HashSet<>();
		int[][] data = new int[101][101];
		int[] buf = new int[101];
		int segNum;
		Integer sign;
		for (int C = input.nextInt(), c = 1; c <= C; c++) {
			int N = input.nextInt();
			segNum = 0;
			sign = null;
			for (int i = 0; i < N; i++) {
				char[] line = input.next().toCharArray();
				if (segNum == -1)
					continue;
				Arrays.fill(buf, 0);
				int idx = 0;
				buf[idx] = 1;
				StringBuilder bd = new StringBuilder();
				bd.append(line[0]);
				for (int j = 1; j < line.length; j++) {
					if (line[j] != line[j - 1]) {
						bd.append(line[j]);
						idx++;
					}
					buf[idx]++;
				}
				System.arraycopy(buf, 0, data[i], 0, idx + 1);
				if (segNum == 0)
					segNum = idx + 1;
				else if (idx + 1 != segNum)
					segNum = -1;
				if (sign == null)
					sign = bd.toString().hashCode();
				else if (bd.toString().hashCode() != sign)
					segNum = -1;
			}
			if (segNum != -1) {
				int op = 0;
				for (int s = 0; s < segNum; s++) {
					int sop = Integer.MAX_VALUE;
					for (int i = 0; i < N; i++) {
						set.add(data[i][s]);
					}
					for (int v : set) {
						int sopTmp = 0;
						for (int i = 0; i < N; i++) {
							sopTmp += Math.abs(data[i][s] - v);
						}
						sop = Math.min(sop, sopTmp);
					}
					set.clear();
					op += sop;
				}
				System.out.printf("Case #%d: %d\n", c, op);
			} else {
				System.out.printf("Case #%d: Fegla Won\n", c);
			}
		}
		input.close();
	}
}
