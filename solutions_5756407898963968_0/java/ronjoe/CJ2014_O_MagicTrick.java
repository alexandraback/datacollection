package org.rtc.codeJam;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class CJ2014_O_MagicTrick {

	public CJ2014_O_MagicTrick(String fileName) {
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
			BufferedReader br = new BufferedReader(new FileReader(fileName));
			int numCases = getNum(br);
			for (int i = 0; i < numCases; i++) {
				int a1 = getNum(br);
				int[] set1 = getSet(br, a1);
				int a2 = getNum(br);
				int[] set2 = getSet(br, a2);

				List<Integer> answers = new ArrayList<>();
				for (int x = 0; x < 4; x++) {
					for (int y = 0; y < 4; y++) {
						if (set1[x] == set2[y]) {
							answers.add(set1[x]);
						}
					}
				}

				String outStr = "Case #" + (i + 1) + ": ";
				if (answers.size() == 1) {
					outStr += answers.get(0);
				} else if (answers.isEmpty()) {
					outStr += "Volunteer cheated!";
				} else {
					outStr += "Bad magician!";
				}
				System.out.println(outStr);
				bw.write(outStr, 0, outStr.length());
				bw.newLine();
			}
			br.close();
			bw.close();

		} catch (Exception e) {
			System.err.println(e);
		}
	}

	public static void main(String[] args) {
		// String fileName = args[0];
		String fileName = "A-small-attempt0.in";
		CJ2014_O_MagicTrick se = new CJ2014_O_MagicTrick(fileName);
	}

	private int getNum(BufferedReader br) throws IOException {
		String line = br.readLine();
		return Integer.parseInt(line);
	}

	private int[] getSet(BufferedReader br, int row) throws IOException {
		String[] set1 = null;
		for (int i = 0; i < 4; i++) {
			String nums = br.readLine();
			if (i == row - 1) {
				set1 = nums.split(" ");
			}
		}
		int[] set = new int[4];
		for (int i = 0; i < 4; i++) {
			set[i] = Integer.parseInt(set1[i]);
		}
		return set;
	}

//	private void test(int n) {
//		int result = getNumber(n);
//		System.out.println("n=" + n + ", result=" + result);
//	}
}
