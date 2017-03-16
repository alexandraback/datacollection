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
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {

    int[] dx = new int[]{1, 0, 0, -1};
    int[] dy = new int[]{0, 1, -1, 0};

    boolean[][] grid;

    public void solve(int testNumber, InputReader jin, PrintWriter jout) {
        int tr = jin.int32();
        int tc = jin.int32();

        int r = Math.min(tr, tc);
        int c = Math.max(tr, tc);
        int n = jin.int32();

        grid = new boolean[r][c];
        jout.println("Case #" + testNumber + ": " + bt(0, 0, 0, n));

    }

    private int bt(int x, int y, int score, int n) {
        int extra = add(x, y);
        int ox = x;
        int oy = y;
        x = (x + 1) % grid.length;
        if(x == 0) y = (y + 1) % grid[x].length;
        if((x | y) == 0) return n == 0? score : (n == 1? score + extra : Integer.MAX_VALUE >> 1);
        grid[ox][oy] = true;
        int v2 = bt(x, y, score + extra, n - 1);
        grid[ox][oy] = false;
        int v1 = bt(x, y, score, n);
        return Math.min(v1, v2);
    }

    private int add(int x, int y) {
        int n = 0;
        for(int k = 0; k < dx.length; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= grid.length) continue;
            if(ny < 0 || ny >= grid[nx].length) continue;
            if(grid[nx][ny]) n++;
        }
        return n;
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

