import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;

public class repeater {
	public static void main(String args[]) {
		try {
			File file = new File("output.out");
			if (!file.exists()) {
				file.createNewFile();
			}
			String content = "";
			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);

			FileInputStream fstream = new FileInputStream("A-small-attempt0.in");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;
			int T, R = 0;

			T = Integer.parseInt(br.readLine());

			for (int i = 1; i <= T; i++) {

				int N = Integer.parseInt(br.readLine());
				int total = 0;
				String st[] = new String[N];

				for (int j = 0; j < N; j++) {
					st[j] = br.readLine();
				}
				String reduced[] = new String[N];
				int l = 0;
				for (int j = 0; j < N; j++) {
					char t = st[j].charAt(0);
					reduced[j] = Character.toString(t);
					for (int k = 1; k < st[j].length(); k++) {
						if (st[j].charAt(k) != t) {
							reduced[j] = reduced[j].concat(Character
									.toString(st[j].charAt(k)));
							t = st[j].charAt(k);

						} else
							total++;
					}
				}
				Integer pow[][] = new Integer[N][reduced[0].length()];

				boolean fail = true;
				if (total == 0) {
					String prev = reduced[0];
					for (int j = 1; j < N; j++) {
						if (prev.compareToIgnoreCase(reduced[j]) != 0) {
							content = "Case #" + i + ": " + "Fegla Won" + "\n";
							fail = false;
							break;
						}
					}

					if (!fail) {
						content = "Case #" + i + ": " + "Fegla Won" + "\n";
					} else
						content = "Case #" + i + ": " + "0" + "\n";

				} else {
					/*
					 * int ans = 0; for (int j = 0; j < N; j++) { int m = 0; int
					 * temppower = 0; for (int k = 0; k < st[j].length(); k++) {
					 * if (st[j].charAt(k) == reduced[j].charAt(m)) {
					 * temppower++;
					 * 
					 * } else {
					 * 
					 * pow[j][m] = temppower; m++; temppower = 1; } } }
					 */
					content = "Case #" + i + ": " + total + "\n";
				}
				/*
				 * for (int j = 0; j < N; j++) { System.out.println(st[j] + "="
				 * + reduced[j]); System.out.println(pow[j]); }
				 */
				bw.write(content);
				System.out.print(content);

			}

			// }
			in.close();
			bw.close();
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
	}
}
