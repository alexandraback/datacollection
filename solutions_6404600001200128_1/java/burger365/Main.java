import java.io.FileInputStream;
import java.io.InputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.util.Scanner;
import java.io.OutputStream;
import java.io.PrintWriter;
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
			final String regex = "A-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("a.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        final int N = in.nextInt();

        int[] m = new int[N];
        for (int i = 0; i < N; i++)
            m[i] = in.nextInt();

        // Method 1
        int res1 = 0;
        for (int i = 1; i < N; i++)
            res1 += Math.max(m[i - 1] - m[i], 0);

        // Method 2
        int eat = 0;
        for (int i = 1; i < N; i++)
            eat = Math.max(eat, m[i - 1] - m[i]);
        int res2 = 0;
        for (int i = 1; i < N; i++)
            res2 += Math.min(m[i - 1], eat);

        out.println("Case #" + testNumber + ": " + res1 + " " + res2);
    }
}

