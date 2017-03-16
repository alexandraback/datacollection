import java.io.IOException;
import java.util.PriorityQueue;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
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

    public long gcd(long a, long b) {
        return b == 0? a: gcd(b, a % b);
    }

    public long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }

    public long lcm(int[] arr) {
        long num = arr[0];
        for(int i = 1; i < arr.length; i++) {
            num = lcm(num, arr[i]);
        }
        return num;
    }

    public void solve(int testNumber, InputReader jin, PrintWriter jout) {
        int b = jin.int32();
        int n = jin.int32();
        final int[] mk = IOUtils.read1DIntArray(jin, b);

        int cnt = 0;
        int g = (int) lcm(mk);
        for(int x: mk) {
            cnt += g / x;
        }
        if(cnt > 0)
            n = ((n - 1) % cnt);

        PriorityQueue<Pair> que = new PriorityQueue<Pair>(b + 1, new Comparator<Pair>() {
            @Override
            public int compare(Pair p1, Pair p2) {
                BigInteger t1 = BigInteger.valueOf(p1.count).multiply(BigInteger.valueOf(mk[p1.id]));
                BigInteger t2 = BigInteger.valueOf(p2.count).multiply(BigInteger.valueOf(mk[p2.id]));

                int val = t1.compareTo(t2);
                if(val == 0) {
                    return p1.id - p2.id;
                }
                return val;
            }
        });
        for(int i = 0; i < b; i++) {
            que.add(new Pair(0, i));
        }
        for(int i = 0; i < n; i++) {
            Pair p = que.poll();
            que.add(new Pair(p.count + 1, p.id));
        }
        Pair p = que.poll();
        jout.printf("Case #%d: %d\n", testNumber, p.id + 1);
    }
}

class Pair {
    int count;
    int id;

    Pair(int a, int b) {
        count = a;
        id = b;
    }
}

class InputReader {
    private static final int bufferMaxLength = 1024;
    private InputStream in;
    private byte[] buffer;
    private int currentBufferSize;
    private int currentBufferTop;
    private static final String tokenizers = " \t\r\f\n";

    public InputReader(InputStream stream) {
        this.in = stream;
        buffer = new byte[bufferMaxLength];
        currentBufferSize = 0;
        currentBufferTop = 0;
    }

    private boolean refill() {
        try {
            this.currentBufferSize = this.in.read(this.buffer);
            this.currentBufferTop = 0;
        } catch(Exception e) {}
        return this.currentBufferSize > 0;
    }


    public Byte readChar() {
        if(currentBufferTop < currentBufferSize) {
            return this.buffer[this.currentBufferTop++];
        } else {
            if(!this.refill()) {
                return null;
            } else {
                return readChar();
            }
        }
    }

    public String token()  {
        StringBuffer tok = new StringBuffer();
        Byte first;
        while((first = readChar()) != null && (tokenizers.indexOf((char) first.byteValue()) != -1));
        if(first == null) return null;
        tok.append((char)first.byteValue());
        while((first = readChar()) != null && (tokenizers.indexOf((char) first.byteValue()) == -1)) {
            tok.append((char)first.byteValue());
        }
        return tok.toString();
    }


    public String next() {
        return token();
    }

    public Integer int32() throws NumberFormatException {
        String tok = token();
        return tok == null? null : Integer.parseInt(tok);
    }

    public Long int64() throws NumberFormatException {
        String tok = token();
        return tok == null? null : Long.parseLong(tok);
    }
}

class IOUtils {
    public static int[] read1DIntArray(InputReader in, int size) {
        int[] arr = new int[size];
        for(int i = 0; i < size; i++) {
            arr[i] = in.int32();
        }
        return arr;
    }

    public static int[][] read2DIntArray(InputReader in, int rowSize, int colSize) {
        int[][] arr = new int[rowSize][];
        for(int i = 0; i < rowSize; i++) {
            arr[i] = IOUtils.read1DIntArray(in, colSize);
        }
        return arr;
    }
}

