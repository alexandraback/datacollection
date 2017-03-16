import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Mahmoud Aladdin <aladdin3>
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader jin, OutputWriter jout) {
        int n = jin.int32();
        char[] first = new char[5000];
        Arrays.fill(first, 'A');
        int[][] count = new int[5000][n];
        for(int[] row : count) Arrays.fill(row, 0);
        String token = jin.token();
        first[0] = token.charAt(0); int ci = 1;
        count[0][0] = 1;
        for(int j = 1; j < token.length(); j++) {
            if(token.charAt(j) == first[ci - 1]) {
                count[ci - 1][0]++;
            } else {
                count[ci][0]++;
                first[ci++] = token.charAt(j);

            }
        }
        boolean valid = true;
        for(int i = 1; i < n; i++) {
            token = jin.token();
            int ti = 1;
            valid &= first[0] == token.charAt(0);
            count[0][i] = 1;
            for(int j = 1; valid && j < token.length(); j++) {
                if(token.charAt(j) == first[ti - 1]) {
                    count[ti - 1][i]++;
                } else {
                    count[ti][i]++;
                    valid &= first[ti] == token.charAt(j);
                    ti++;
                }
                valid &= ti <= ci;
            }
            valid &= ti == ci;
        }
        jout.print("Case #" + testNumber + ":", "");
        if(!valid) {
            jout.println("Fegla Won");
        } else {
            int minMoves = 0;
            for(int i = 0; i < ci; i++) {
                minMoves += makeEqual(count[i]);
            }
            jout.println(minMoves);
        }
    }

    int makeEqual(int[] arr) {
        int moves = Integer.MAX_VALUE;
        for(int i = 0; i < arr.length; i++) {
            int cnt = 0;
            for(int j = 0; j < arr.length; j++) {
                cnt += Math.abs(arr[j] - arr[i]);
            }
            moves = Math.min(cnt, moves);
        }
        return moves;
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
    
    
    private Byte readChar() {
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

    public String next() {
        return token();
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
    
    public Integer int32() throws NumberFormatException {
        String tok = token();
        return tok == null? null : Integer.parseInt(tok);
    }

    }

class OutputWriter {
    private final int bufferMaxOut = 1024;
    private PrintWriter out;
    private StringBuilder output;
    private boolean forceFlush = false;

    public OutputWriter(OutputStream outStream) {
        out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outStream)));
        output = new StringBuilder(2 * bufferMaxOut);
    }

    public OutputWriter(Writer writer) {
        forceFlush = true;
        out = new PrintWriter(writer);
        output = new StringBuilder(2 * bufferMaxOut);
    }

    private void autoFlush() {
        if(forceFlush || output.length() >= bufferMaxOut) {
            flush();
        }
    }

    public void print(Object... tokens) {
        for(int i = 0; i < tokens.length; i++) {
            if(i != 0) output.append(' ');
            output.append(tokens[i]);
        }
        autoFlush();
    }

    public void println(Object... tokens) {
        print(tokens);
        output.append('\n');
        autoFlush();
    }

    public void flush() {
        out.print(output);
        output.setLength(0);
    }

    public void close() {
        flush();
        out.close();
    }
}

