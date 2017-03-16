import java.io.IOException;
import java.util.Locale;
import java.util.InputMismatchException;
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
    long howMany(int[] M, long t) {
        if (t <= 0)
            return 0;
        long ct = 0;
        for (int i = 0; i < M.length; i++) {
            ct += t / M[i] + 1;
        }
        return ct;
    }

    long checkL(int[] M, long t, int N) {

        return N - howMany(M, t);
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int B = in.nextInt();
        int n = in.nextInt();

        int M[] = new int[B];

        for (int i = 0; i < B; i++) {
            M[i] = in.nextInt();
        }
        if (n <= B) {
            out.println("Case #" + testNumber + ": " + n);
        } else {
            long l = 0;
            long r = 1000000000000000l;
            // find the smallest time when exactly N-1 finished the job
            while (l != r - 1) {
                long c = (l + r) / 2;
                if (checkL(M, c, n) <= 0) {
                    r = c;
                } else {
                    l = c;
                }
            }
            if (checkL(M, 0, n) <= 0)
                r = 0;

            long hm = howMany(M, r);
            long left = hm - n;

            ArrayList<Integer> barbers = new ArrayList<Integer>();
            for (int i = 0; i < B; i++) {
                if (r % M[i] == 0)
                    barbers.add(i);
            }

            int bidx = -1;
            for (int i = barbers.size() - 1; i >= 0; i--) {
                if (left > 0)
                    --left;
                else {
                    bidx = barbers.get(i) + 1;
                    break;
                }


            }
            out.println("Case #" + testNumber + ": " + bidx);


        }
    }
}

class InputReader {

    private InputStream stream;
    int curCharIndex = 0;
    int charsInBuf = 0;
     byte buf[] = new byte[16*1024];

    public InputReader(InputStream stream) {
        this.stream = stream;
    }


    public int readChar() {

        if (curCharIndex >= charsInBuf) {
            curCharIndex = 0;
            try {
                charsInBuf = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (charsInBuf <= 0)
                return -1;
        }
        return buf[curCharIndex++];
    }

    public void putCharBack(int c) {
        buf[--curCharIndex] = (byte) c;
    }


    public int nextInt() {

        int c;
        do {
            c = readChar();
        }while(isWhitespace(c));

        int sign = 1;
        if (c == '-') {
            c = readChar();
            sign = -1;

        }
        int res = 0;
        do {
            res *= 10;
            res += c - '0';
            c = readChar();
        } while (!isWhitespace(c) && c!=-1);
        if( c != -1) putCharBack(c);
        return sign * res;
    }


    public String nextToken() {
        int c;
        do {
            c = readChar();
        }while(isWhitespace(c));

        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = readChar();
        } while (!isWhitespace(c) && c!=-1);
        if( c != -1) putCharBack(c);
        return res.toString();
    }

    /*
    * For the purpose of compatibilty with Chelper Chrome extension
     */

    public String next() {
        return nextToken();
    }


    private boolean isWhitespace(int c) {
        return  c==' ' || c=='\n'|| c=='\r' || c=='\t';
    }
}

