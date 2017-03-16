import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class R2A {

	public static void main(String[] args) {
		try {
			Scanner in = new Scanner(new File("D:\\Downloads\\A-large.in"));
			FileWriter out = new FileWriter("D:\\Downloads\\A.out");

			int t = in.nextInt();

			for (int i = 0; i < t; i++) {
				int n = in.nextInt();

				int[][] counts = new int[100][n];
				ArrayList<Character> list = new ArrayList<Character>();
				boolean impossible = false;
				for (int j = 0; j < n; j++) {
					String s = in.next();

					if (impossible) {
						continue;
					}

					if (j == 0) {
						int index = -1;
						for (int k = 0; k < s.length(); k++) {
							if (index == -1 || s.charAt(k) != list.get(index)) {
								index++;
								list.add(s.charAt(k));
								counts[index][j]++;
							} else {
								counts[index][j]++;
							}
						}
					} else {
						int index = 0;
						int k = 0;
						while (index < list.size() && k < s.length()) {
							if (s.charAt(k) == list.get(index)) {
								counts[index][j]++;
								k++;
							} else {
								if (counts[index][j] == 0) {
									break;
								}
								index++;
							}
						}
						if (index != list.size() - 1 || k < s.length()) {
							impossible = true;
						}
					}
				}

				String resultString = "Case #" + (i + 1) + ": ";
				if (impossible) {
					resultString += "Fegla Won";
				} else {
					int sum = 0;
					for (int k = 0; k < list.size(); k++) {
						Arrays.sort(counts[k]);
						int middle = counts[k][n / 2];
						for (int j = 0; j < n; j++) {
							sum += Math.abs(middle - counts[k][j]);
						}
					}
					resultString += sum;
				}
				out.write(resultString + "\n");
			}
			out.close();
			in.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

}
