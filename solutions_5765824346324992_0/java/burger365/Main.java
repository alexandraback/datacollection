import java.io.FileInputStream;
import java.io.InputStream;
import java.io.FilenameFilter;
import java.util.AbstractQueue;
import java.util.Locale;
import java.util.Scanner;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "B-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("b.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    class Data implements Comparable<Data> {
        int index;
        long value;

        public Data(int index, long value) {
            this.index = index;
            this.value = value;
        }
        public int compareTo(Data o) {
            if (value == o.value) {
                return index - o.index;
            } else {
                return value - o.value < 0 ? -1 : 1;
            }
        }
    }
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int B = in.nextInt(), N = in.nextInt() - 1;

        int[] M = new int[B];
        for (int i = 0; i < B; i++)
            M[i] = in.nextInt();

        BigInteger lcm = BigInteger.valueOf(M[0]);
        for (int i = 1; i < B; i++) {
            lcm = lcm.multiply(BigInteger.valueOf(M[i]).divide(lcm.gcd(BigInteger.valueOf(M[i]))));
        }

        int cycle = 0;
        for (int m : M) cycle += (lcm.divide(BigInteger.valueOf(m))).intValue();
        N %= cycle;

        PriorityQueue<Data> pq = new PriorityQueue<>();
        for (int i = 0; i < B; i++)
            pq.add(new Data(i, 0));

        while (true) {
            Data data = pq.remove();
            if (N-- == 0) {
                out.println("Case #" + testNumber + ": " + (data.index + 1));
                return;
            }
            pq.add(new Data(data.index, data.value + M[data.index]));
        }
    }
}

