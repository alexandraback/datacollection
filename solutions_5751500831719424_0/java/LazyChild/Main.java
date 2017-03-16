import java.util.Scanner;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			final String regex = "A.*.in";
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
			outputStream = new FileOutputStream("output.txt");
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
        int n = in.nextInt();
        String[] strings = new String[n];
        String[] shorts = new String[n];
        List<Integer>[] counts = new List[n];
        for (int i = 0; i < n; ++i) {
            strings[i] = in.next();
            shorten(i, strings, shorts, counts);
        }

        out.printf("Case #%d: ", testNumber);
        if (!valid(shorts)) {
            out.println("Fegla Won");
        } else {
            int m = shorts[0].length();
            int ans = 0;
            for (int i = 0; i < m; ++i) {
                ans += calculateCost(i, counts);
            }
            out.println(ans);
        }
    }

    private int calculateCost(int colNo, List<Integer>[] counts) {
        int n = counts.length;
        int[] numbers = new int[n];
        for (int i = 0; i < n; ++i) {
            numbers[i] = counts[i].get(colNo);
        }
        Arrays.sort(numbers);
        int pri = numbers[n / 2];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += Math.abs(numbers[i] - pri);
        }
        return ans;
    }

    private boolean valid(String[] shorts) {
        int n = shorts.length;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (!shorts[i].equals(shorts[j])) {
                    return false;
                }
            }
        }
        return true;
    }

    private void shorten(int pos, String[] strings, String[] shorts, List<Integer>[] counts) {
        String s = strings[pos];
        List<Integer> co = new ArrayList<Integer>();
        StringBuilder sb = new StringBuilder();
        int count = 0;
        int length = s.length();
        for (int i = 0; i < length; ++i) {
            if (i == 0 || s.charAt(i - 1) != s.charAt(i)) {
                if (i != 0) {
                    co.add(count);
                }
                sb.append(s.charAt(i));
                count = 1;
            } else {
                ++count;
            }
        }
        co.add(count);
        shorts[pos] = sb.toString();
        counts[pos] = co;
    }
}

