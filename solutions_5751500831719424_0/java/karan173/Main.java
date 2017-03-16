import java.io.*;
import java.util.InputMismatchException;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author karan173
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("a.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("a.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		FastReader in = new FastReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		solver.solve(1, in, out);
		out.close();
	}
}

class Task {
    public void solve(int testNumber, FastReader in, PrintWriter out) 
    {
        int t = in.ni ();
        int z = 1;
        while (t-- > 0)
        {
            int n = in.ni ();
            char a[] = in.ns ().toCharArray ();
            char b[] = in.ns ().toCharArray ();
            out.print ("Case #" + z++ + ": ");
            int ctr1 = 0;
            int ctr2 = 0;
            int moves = 0;
            boolean done = false;
            while (!done)
            {
//                out.println ("==" + ctr1 + " " + ctr2);
                if (ctr1 == a.length && ctr2 == b.length)
                {
                    out.println (moves);
                    done = true;
                    continue;
                }
                if (ctr1 == a.length || ctr2 == b.length)
                {
                    out.println ("Fegla Won");
                    done = true;
                    continue;
                }
                if (a[ctr1] != b[ctr2])
                {
                    out.println ("Fegla Won");
                    done = true;
                    continue;
                }
                int ct1 = 0;
                int ct2 = 0;
                char c = a[ctr1];
                while (ctr1 < a.length && a[ctr1] == c)
                {
                    ct1++;
                    ctr1++;
                }
                while (ctr2 < b.length && b[ctr2] == c)
                {
                    ct2++;
                    ctr2++;
                }

                moves += Math.abs (ct1 - ct2);
            }
        }
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

    public interface SpaceCharFilter
    {
        public boolean isSpaceChar(int ch);
    }
}

