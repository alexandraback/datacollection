package gcj.Qual2014A;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;
import java.io.*;

public class GCJ {

	public static void tr(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}

	public static void main(String[] args) throws Throwable {
		String pkg = new Object(){}.getClass().getEnclosingClass().getPackage().getName().replace('.', '/');
		String dir = "src/" + pkg;

		String filename = "";

//		if (true) { filename = "sample.in"; }
		if (true) { filename = "A-small-attempt0.in"; }
//		if (true) { filename = "A-large-practice.in"; }

		Scanner sc = null;
		try {
			sc = new Scanner(new File(dir + "/" + filename));
		} catch (FileNotFoundException e) {
			tr(e.getMessage());
			return;
		}
		PrintWriter fout = new PrintWriter(new File(dir + "/" + filename + ".res"));

		GCJ obj = new GCJ();
		int TNO = sc.nextInt();
		for (int tno = 0; tno < TNO; tno++) {
			fout.write(String.format("Case #%d: ", (tno + 1)));
			obj.solve(sc, fout);
			fout.flush();
		}
		fout.flush();
		fout.close();
	}

	void solve(Scanner sc, PrintWriter fout) {
		boolean[] ng = new boolean[16];
		for (int it = 0; it < 2; it++) {
			int a = sc.nextInt();
			for (int i = 1; i <= 4; i++) {
				for (int j = 0; j < 4; j++) {
					int x = sc.nextInt();
					if (a != i) {
						ng[x-1] = true;
					}
				}
			}
		}

		int ans = -1;
		for (int i = 0; i < 16; i++) if (!ng[i]) {
			if (ans == -1)
				ans = i+1;
			else {
				ans = 99;
			}
		}

		if (ans == 99) {
			fout.write("Bad magician!\n");
		} else if (ans == -1) {
			fout.write("Volunteer cheated!\n");
		} else {
			fout.write(ans+"\n");
		}
	}
}
