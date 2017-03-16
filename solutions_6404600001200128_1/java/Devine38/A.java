import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @author Mark Devine
 * 
 */
public class A {
	static final boolean DEBUG = false;
	static Scanner in;
	static List<PrintStream> out;

	public static void main(String[] args) throws FileNotFoundException {
		out = new ArrayList<PrintStream>();
		out.add(System.out);
		if (DEBUG) {
			in = new Scanner(new File("t"));
		} else {
			in = new Scanner(new File(A.class.getName() + ".in"));
			out.add(new PrintStream(A.class.getName() + ".out"));
		}
		int T = i();
		for (int i = 0; i < T; i++) {
			pf("Case #%d: %s\n", i + 1, solve());
		}
		System.out.println("Done");
		in.close();
		for (PrintStream ps : out) {
			ps.close();
		}
	}

	static String solve() {
		int intervals = i();
		int[] mushrooms = new int[intervals];
		int eatenFirst = 0;
		int last = -1;
		int maxRate = 0;
		for (int i = 0; i < intervals; i++) {
		  int plate = i();
		  if (last == -1) {
		  } else if (plate < last) {
		    eatenFirst += last - plate;
		    maxRate = Math.max(maxRate, last - plate);
		  }
      last = plate;
		  mushrooms[i] = plate;
		}
		// second way
		int eatenSecond = 0;
		for (int i = 0; i < intervals - 1; i++) {
		  int plate = mushrooms[i];
		  eatenSecond += Math.min(plate, maxRate);
		}

		return eatenFirst + " " + eatenSecond;
	}

	static void p(String x) {
		for (PrintStream ps : out) {
			ps.print(x);
		}
	}

	static void pl(String x) {
		for (PrintStream ps : out) {
			ps.println(x);
		}
	}

	static void pf(String format, Object... args) {
		for (PrintStream ps : out) {
			ps.printf(format, args);
		}
	}

	static String f(String format, Object... args) {
		return String.format(format, args);
	}

	static int i() {
		return in.nextInt();
	}

	static long l() {
		return in.nextLong();
	}

	static String s(String pattern) {
		return in.next(pattern);
	}

	static String li() {
		return in.nextLine();
	}
}