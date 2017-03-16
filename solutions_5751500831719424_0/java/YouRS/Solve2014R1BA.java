
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;


public class Solve2014R1BA {
	private static String filePath = "A-small-attempt0.in";

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		long startDatetime = System.currentTimeMillis();

		StringBuffer answer = new StringBuffer();
		try {
			BufferedReader br = null;
			String line = null;
			if (filePath == null) br = new BufferedReader(new InputStreamReader(System.in));
			else br = new BufferedReader(new InputStreamReader(new FileInputStream(filePath)));

			int T = Integer.parseInt(br.readLine());
			//System.out.println(T);

			for (int x = 1; x <= T; x++) {
				if ( (line = br.readLine()) == null) { throw new Exception("wrong! Case #" + x); }
				System.out.println("Case #" + x + ": ");
				answer.append("Case #" + x + ": ");

				int N = Integer.parseInt(line);
				String[] Si = new String[N];
				for (int i = 0; i < N; i++) {
					if ( (Si[i] = br.readLine()) == null) { throw new Exception("wrong! Case #" + x); }
				}

				int y = 0;
				List<Character> cs = new ArrayList<Character>();
				int[][] cnts = new int[N][100];
				char c = ' ';
				int idx = -1;
				for (int p = 0; p < Si[0].length(); p++) {
					char curr = Si[0].charAt(p);
					if (curr != c) {
						cs.add(curr);
						c = curr;
						cnts[0][++idx] = 1;
					} else {
						cnts[0][idx]++;
					}
				}
				int size = cs.size();
				boolean FeglaWon = false;
				for (int i = 1; i < N; i++) {
					idx = 0;
					if (Si[i].charAt(0) != cs.get(idx)) {
						FeglaWon = true;
						break;
					}
					for (int p = 0; p < Si[i].length(); p++) {
						char curr = Si[i].charAt(p);
						if (curr == cs.get(idx)) {
							cnts[i][idx]++;
						} else {
							idx++;
							if (idx >= size) {
								FeglaWon = true;
								break;
							}
							if (curr == cs.get(idx)) {
								cnts[i][idx]++;
							} else {
								FeglaWon = true;
								break;
							}
						}
					}
					if (FeglaWon) break;
					if (idx != size - 1) {
						FeglaWon = true;
						break;
					}
				}

				if (FeglaWon) answer.append("Fegla Won\n");
				else {
					for (int i = 0; i < size; i++) {
						int ymin = 999999999;
						for (int j = 0; j < N; j++) {
							int ycurr = 0;
							for (int k = 0; k < N; k++) {
								if (cnts[j][i] > cnts[k][i])
									ycurr += cnts[j][i] - cnts[k][i];
								else
									ycurr += cnts[k][i] - cnts[j][i];
							}
							if (ycurr < ymin) ymin = ycurr;
						}
						y += ymin;
					}
					answer.append(y).append("\n");
				}
			}
			br.close();
			br = null;
			output(answer);
		} catch (Exception e) {
			e.printStackTrace();
		}
		long tm = System.currentTimeMillis() - startDatetime;
		long tms = tm / 1000;
		System.out.println("The process time: " + tms + "s " + (tm%1000) + "ms");
	}

	private static void output(StringBuffer answer) throws Exception {
		String outPath = "answer.out";
		if (filePath != null) outPath = filePath.substring(0, filePath.length()-2) + "out";
		FileOutputStream fos = new FileOutputStream(outPath, false);
		fos.write(answer.toString().getBytes());
		fos.close();
		fos = null;
	}
}
