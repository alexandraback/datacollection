import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

/**
 * @author Mark Devine
 * 
 */
public class B {
	static final boolean DEBUG = false;
	static Scanner in;
	static List<PrintStream> out;

	public static void main(String[] args) throws FileNotFoundException {
		out = new ArrayList<PrintStream>();
		out.add(System.out);
		if (DEBUG) {
			in = new Scanner(new File("t"));
		} else {
			in = new Scanner(new File(B.class.getName() + ".in"));
			out.add(new PrintStream(B.class.getName() + ".out"));
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
    int numBarbers = i();
    int place = i();
    int maxBarberTime = 0;
    int[] barbers = new int[numBarbers];
    int badGCD = 1;
    Set<Integer> ints = new HashSet<Integer>();
    for (int i = 0; i < numBarbers; i++) {
      int time = i();
      if (!ints.contains(time) && badGCD % time != 0) {
        badGCD *= time;
        ints.add(time);
      }
      barbers[i] = time;
      maxBarberTime = Math.max(maxBarberTime, time);
    }
    System.out.println(Arrays.toString(barbers));
    System.out.println("GCD: " + badGCD);
    int cycle = badGCD * numBarbers;
    System.out.println("cycle: " + cycle);
    int[] barberOrder = new int[cycle];
    int count = 0;
    int modBy = 0;
    for (int i = 0; i < badGCD; i++) {
      for (int j = 0; j < numBarbers; j++) {
//        if (count == place - 1) {
//          return "" + (j + 1);
//        }
        if (i % barbers[j] == 0) {
          barberOrder[count++] = j + 1;
          modBy++;
        }
      }
    }
    System.out.println("mod by: " + modBy);
//    System.out.println(Arrays.toString(barberOrder));
    
		return "" + barberOrder[(place - 1) % modBy];
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