import java.io.FileInputStream;
import java.io.InputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;

public class R1AC {

    private static InputReader in;
    private static PrintWriter out;

    public static void main(String[] args) throws IOException {
        // -------------------------------------------------------------------------
        // Initializing...
        new R1AC();
        // -------------------------------------------------------------------------
        // put your code here... :)
        int tests = in.readInt();
        for (int te = 1; te <= tests; te++) {
        	int n = in.readInt();
        	 Point [] p = new Point[n];
        	 for (int i = 0; i < p.length; i++) {
				p[i] = new Point(in.readInt(), in.readInt());
			}
        	 int [] res = new int[n];
        	 Arrays.fill(res, Integer.MAX_VALUE);
        	 for (int mask = 1; mask < (1<<p.length); mask++) {
				Point[] ne = get(p,mask);
				Point [] ch = convexHull(ne);
				int cut = n;
				for (int i = 0; i < p.length; i++) {
					if ((mask & (1<<i)) !=0)cut--;
				}
				for (int i = 0; i < p.length; i++) {
					for (int j = 0; j < ch.length; j++) {
						if (p[i] == ch[j]) res[i] = Math.min(res[i], cut);
					}
				}
			}
        	out.println("Case #"+te+":");
        	for (int i = 0; i < res.length; i++) {
				out.println(res[i]);
			}
		}
        // -------------------------------------------------------------------------
        // closing up
        end();
        // --------------------------------------------------------------------------

    }

    


	private static Point[] get(Point[] p, int mask) {
		int size = 0;
		for (int i = 0; i < p.length; i++) {
			if ((mask & (1<<i)) !=0)size++;
		}
		Point [] ret = new Point[size];int index = 0;
		for (int i = 0; i < p.length; i++) {
			if ((mask & (1<<i)) !=0)ret[index++] = p[i];
		}
		return ret;
	}




	static class Point implements Comparable<Point> {
		long x, y;

		public Point(long x, long y) {
			this.x = x;
			this.y = y;
		}

		public int compareTo(Point o) {
			return Long.compare(x, o.x) != 0 ? Long.compare(x, o.x) : Long.compare(y, o.y);
		}
	}

	static boolean cw(Point a, Point b, Point c) {
		return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) <= 0;
	}

	public static Point[] convexHull(Point[] p) {
		int n = p.length;
		if (n <= 1)
			return p;
		Arrays.sort(p);
		Point[] q = new Point[n * 2];
		int cnt = 0;
		for (int i = 0; i < n; q[cnt++] = p[i++])
			for (; cnt > 1 && !cw(q[cnt - 2], q[cnt - 1], p[i]); --cnt)
				;
		for (int i = n - 2, t = cnt; i >= 0; q[cnt++] = p[i--])
			for (; cnt > t && !cw(q[cnt - 2], q[cnt - 1], p[i]); --cnt)
				;
		return Arrays.copyOf(q, cnt - 1 - (q[0].compareTo(q[1]) == 0 ? 1 : 0));
	}
    
    public R1AC() throws IOException {
        // Input Output for Console to be used for trying the test samples of
        // the problem
        in = new InputReader(System.in);
        out = new PrintWriter(System.out);
//      in = new InputReader(new FileInputStream("grant.in"));
      out = new PrintWriter("R1AC.out");
    }

    private static void end() throws IOException {
        out.flush();
        out.close();
        System.exit(0);
    }

    class InputReader {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int peek() {
            if (numChars == -1)
                return -1;
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    return -1;
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar];
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private String readLine0() {
            StringBuilder buf = new StringBuilder();
            int c = read();
            while (c != '\n' && c != -1) {
                if (c != '\r')
                    buf.appendCodePoint(c);
                c = read();
            }
            return buf.toString();
        }

        public String readLine() {
            String s = readLine0();
            while (s.trim().length() == 0)
                s = readLine0();
            return s;
        }

        public String readLine(boolean ignoreEmptyLines) {
            if (ignoreEmptyLines)
                return readLine();
            else
                return readLine0();
        }

        public BigInteger readBigInteger() {
            try {
                return new BigInteger(readString());
            } catch (NumberFormatException e) {
                throw new InputMismatchException();
            }
        }

        public char readCharacter() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            return (char) c;
        }

        public double readDouble() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, readInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, readInt());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }

        public boolean isExhausted() {
            int value;
            while (isSpaceChar(value = peek()) && value != -1)
                read();
            return value == -1;
        }

        public String next() {
            return readString();
        }

        public SpaceCharFilter getFilter() {
            return filter;
        }

        public void setFilter(SpaceCharFilter filter) {
            this.filter = filter;
        }

    }

    private interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }
}