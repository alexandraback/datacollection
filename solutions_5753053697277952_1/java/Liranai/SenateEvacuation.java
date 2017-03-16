package Round1C;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class SenateEvacuation {
	public static void main(String[] args) {

		try {
			BufferedReader reader = new BufferedReader(new FileReader("Round1C/A-large.in"));

			Scanner in = new Scanner(reader);
			int T = in.nextInt();

			try {
				BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("Round1C/A-large.out")));
				for (int i = 0; i < T; i++) {
					int N = in.nextInt();
					int[] sizes = new int[N];
					for (int j = 0; j < N; j++) {
						sizes[j] = in.nextInt();
					}
					writer.write("Case #" + (i + 1) + ": " + getInstructions(N, sizes) + "\n");
				}

				reader.close();
				in.close();
				writer.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		}
	}

	public static String getInstructions(int N, int[] sizes) {
		StringBuilder bldr = new StringBuilder();

		int senateMembers = 0;
		for (int i = 0; i < sizes.length; i++) {
			senateMembers += sizes[i];
		}

		while (senateMembers > 0) {
			int selector = -1, value = 0;
			for (int i = 0; i < sizes.length; i++) {
				if (sizes[i] > value) {
					selector = i;
					value = sizes[i];
				}
			}

			bldr.append((char) (65 + selector));
			sizes[selector]--;
			senateMembers--;

			boolean majority = false;
			for (int i = 0; i < sizes.length; i++) {
				if (sizes[i] > (senateMembers / 2)) {
					majority = true;
				}
			}

			if (majority) {
				selector = -1;
				value = 0;
				for (int i = 0; i < sizes.length; i++) {
					if (sizes[i] > value) {
						selector = i;
						value = sizes[i];
					}
				}
				bldr.append((char) (65 + selector));
				sizes[selector]--;
				senateMembers--;
			}

			bldr.append(" ");
			// System.out.println(bldr.toString());
		}
		return bldr.toString();
	}
}
