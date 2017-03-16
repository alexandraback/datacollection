import java.io.*;
import java.util.InputMismatchException;
import java.util.Locale;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author karan173
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
		FastReader in = new FastReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB
{
    boolean filled[][];
    int minAns = Integer.MAX_VALUE;
    int r, c, n;
    public void solve(int testNumber, FastReader in, PrintWriter out)
    {
        minAns = Integer.MAX_VALUE;
        r = in.ni ();
        c = in.ni ();
        n = in.ni ();
        filled = new boolean[r][c];
        findAns (0, 0);
        out.print("Case #"+testNumber+": ");
        out.println (minAns);
    }

    private void findAns(int i, int j)
    {
//        System.out.println (i + " " + );
        if (i == r)
        {
            checkAns ();
            return;
        }
        if (j == c)
        {
            findAns (i + 1, 0);
            return;
        }
        filled[i][j] = false;
        findAns (i, j + 1);
        filled[i][j] = true;
        findAns (i, j + 1);
    }

    private void checkAns()
    {
        int cntFilled = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (filled[i][j])
                {
                    cntFilled++;
                }
            }
        }
        if (cntFilled != n)
        {
            return;
        }
        int sharedWalls = 0;
        for (int i = 0; i < r - 1; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (filled[i][j] && filled[i + 1][j])
                {
                    sharedWalls++;
                }
            }
        }
        for (int i = 0; i < r ; i++)
        {
            for (int j = 0; j < c - 1; j++)
            {
                if (filled[i][j] && filled[i][j + 1])
                {
                    sharedWalls++;
                }
            }
        }
        minAns = Math.min (minAns, sharedWalls);
    }
}

class FastReader
{

    public InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;

    public FastReader(InputStream stream)
    {
        this.stream = stream;
    }

    public int read()
    {
        if (numChars == -1)
        {
            throw new InputMismatchException ();
        }
        if (curChar >= numChars)
        {
            curChar = 0;
            try
            {
                numChars = stream.read (buf);
            } catch (IOException e)
            {
                throw new InputMismatchException ();
            }
            if (numChars <= 0)
            {
                return -1;
            }
        }
        return buf[curChar++];
    }

    public int ni()
    {
        int c = read ();
        while (isSpaceChar (c))
            c = read ();
        int sgn = 1;
        if (c == '-')
        {
            sgn = -1;
            c = read ();
        }
        int res = 0;
        do
        {
            if (c < '0' || c > '9')
            {
                throw new InputMismatchException ();
            }
            res *= 10;
            res += c - '0';
            c = read ();
        } while (!isSpaceChar (c));
        return res * sgn;
    }

    public String ns()
    {
        int c = read ();
        while (isSpaceChar (c))
            c = read ();
        StringBuilder res = new StringBuilder ();
        do
        {
            res.appendCodePoint (c);
            c = read ();
        } while (!isSpaceChar (c));
        return res.toString ();
    }

    public boolean isSpaceChar(int c)
    {
        if (filter != null)
        {
            return filter.isSpaceChar (c);
        }
        return isWhitespace (c);
    }

    public static boolean isWhitespace(int c)
    {
        return c==' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public String next()
    {
        return ns ();
    }

    public interface SpaceCharFilter
    {
        public boolean isSpaceChar(int ch);
    }
}

