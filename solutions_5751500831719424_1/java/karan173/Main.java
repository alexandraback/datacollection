import java.io.*;
import java.util.Arrays;
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
            char s[][] = new char[n][];
            for (int i = 0; i < n; i++)
            {
                s[i] = in.ns ().toCharArray ();
            }
            out.print ("Case #" + z++ + ": ");
            int ctr[] = new int[n];
            Arrays.fill (ctr, 0);
            long moves = 0;
            boolean done = false;
            int mov[] = new int[n];
            while (!done)
            {
                int x = 0;
                for (x = 0; x < n; x++)
                {
                    if (ctr[x] != s[x].length)
                    {
                        break;
                    }
                }
                if (x == n)
                {
                    out.println (moves);
                    done = true;
                    continue;
                }
                x = 0;
                for (x = 0; x < n; x++)
                {
                    if (ctr[x] == s[x].length)
                    {
                        break;
                    }
                }
                //x==n => none equal to length
                if (x != n)
                {
                    out.println ("Fegla Won");
                    done = true;
                    continue;
                }
                char c = s[0][ctr[0]];
                x = 0;
                for (x = 0; x < n; x++)
                {
                    if (c != s[x][ctr[x]])
                    {
                        break;
                    }
                }
                if (x != n)
                {
                    out.println ("Fegla Won");
                    done = true;
                    continue;
                }
                x = 0;
                Arrays.fill (mov, 0);
                for (x = 0; x < n; x++)
                {
                    while (ctr[x] < s[x].length && s[x][ctr[x]] == c)
                    {
                        ctr[x]++;
                        mov[x]++;
                    }
                }
                Arrays.sort (mov);
                int med1 = mov[mov.length / 2];
                int med2 = med1;
                if ((mov.length / 2 - 1) < n)
                {
                    med2 = mov[(mov.length / 2) - 1];
                }
                long mov1 = 0;
                long mov2 = 0;
                for (int i = 0; i < n; i++)
                {
                    mov1 += Math.abs (med1 - mov[i]);
                    mov2 += Math.abs (med2 - mov[i]);
                }
                moves += Math.min (mov1, mov2);
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

