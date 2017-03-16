import java.io.FileInputStream;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Kartik Singal (ka4tik)
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
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        long b = in.nextLong();
        long n = in.nextLong();
        long times[] = new long[(int)b];
        for (int i = 0; i < b; i++) {
            times[i] = in.nextLong();
        }

        long hi = 10000000000000000L;
        long lo = 0;
        while (lo < hi) {
            long mid = (lo + hi) / 2;
            long sum = 0;
            for (long i = 0; i < b; i++)
                sum += (mid / times[(int)i]) + 1;
//            System.out.println(mid + " " +sum);
            if (sum < n)
                lo = mid + 1;
            else
                hi = mid;
        }
        for (int i = 0; i < b; i++) {
            n -= ((lo - 1) / times[i]) + 1;
        }
//        System.out.println(lo);
        ArrayList<Long> a = new ArrayList<Long>();
        for (long i = 0; i < b; i++)
            if (lo % times[(int)i] == 0)
                a.add((long)i);


        n--;

        n%=a.size();
        out.println("Case #" + testNumber + ": " + (a.get((int) n) + 1));


    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) try {
            tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return tokenizer.nextToken();
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

}

