import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintWriter;
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
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader jin, PrintWriter jout) {
        int n = jin.int32();
        int[] arr = IOUtils.read1DIntArray(jin, n);

        int min = 0;
        int max = 0;
        int diff = 0;
        for(int i = 1; i < n; i++) {
            int tdiff = arr[i] - arr[i - 1];
            if(tdiff < 0) {
                min += -tdiff;
                diff = Math.max(diff, -tdiff);
            }
        }

        if(diff != 0) {
            for(int i = 0; i < n - 1; i++) {
                max += Math.min((double)arr[i], diff);
            }
        }

        jout.print("Case #" + testNumber + ": ");
        jout.println(min + " " + max);
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

