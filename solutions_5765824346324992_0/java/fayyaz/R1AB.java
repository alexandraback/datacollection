import java.io.FileInputStream;
import java.io.InputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.PriorityQueue;

public class R1AB {

    private static InputReader in;
    private static PrintWriter out;

    public static void main(String[] args) throws IOException {
        // -------------------------------------------------------------------------
        // Initializing...
        new R1AB();
        // -------------------------------------------------------------------------
        // put your code here... :)
        int tests = in.readInt();
        for (int te = 1; te <= tests; te++) {
//        	System.out.println(te);
        	int b = in.readInt();
        	int n = in.readInt();
        	int [] wait = new int[b];
        	for (int i = 0; i < wait.length; i++) {
				wait[i] = in.readInt();
			}
//        	System.out.println(clacturn(0,196317120,wait));
//        	System.out.println(clacturn(0,6,new int[]{1,2}));

        	int ans = 0;
        	loop:for (int B = 0; B < wait.length; B++) {
				long low = 0;
				long hig = n*1l +1;
				int itr = 100;
				while (itr-->0){
					long mid = (hig+low)/2;
					long calc = clacturn(B, mid, wait);
					if (calc == n) {
						ans = B+1;
						break loop;
					}else if(calc > n){
						hig = mid;
					}else {
						low = mid;
					}
 				}
			}
//        	PriorityQueue<event> e = new PriorityQueue<>();
//        	for (int i = 0; i < wait.length; i++) {
//				e.add(new event(i, 0));
//			}
//        	int last = -1;
//        	long time = 0;
//        	while(n-->0){
//        		event c = e.poll();
//        		e.add(new event(c.bid, c.time+wait[c.bid]));
//        		last = c.bid+1;
//        		time = c.time;
//        	}
        	out.println("Case #"+te+": "+ans);
		}
        // -------------------------------------------------------------------------
        // closing up
        end();
        // --------------------------------------------------------------------------

    }

    static long clacturn(int b,long t,int [] wait){
    	long time = (t-1)*wait[b];
    	long ret = 0;
    	for (int i = 0; i < wait.length; i++) {
			long val = time/wait[i] ;
			if (val*wait[i] == time && i > b) val--;
			ret += val+1;
		}
    	return ret;
    }
    
    public R1AB() throws IOException {
        // Input Output for Console to be used for trying the test samples of
        // the problem
        in = new InputReader(System.in);
        out = new PrintWriter(System.out);
//      in = new InputReader(new FileInputStream("grant.in"));
      out = new PrintWriter("R1AB.out");
    }

    private static void end() throws IOException {
        out.flush();
        out.close();
        System.exit(0);
    }

    static class event implements Comparable<event> {
    	int bid;
    	long time;
    	public event(int bid,long time) {
    		this.bid = bid;
    		this.time = time;
		}
		public int compareTo(event o) {
			if (this.time == o.time)
				return Integer.compare(this.bid, o.bid);
			return Long.compare(this.time, o.time);
		}
    	
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