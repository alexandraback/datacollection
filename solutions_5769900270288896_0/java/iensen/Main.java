import java.io.IOException;
import java.util.Locale;
import java.util.InputMismatchException;
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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int R = in.nextInt();
        int C = in.nextInt();
        int N = in.nextInt();
        int minU = Integer.MAX_VALUE;
        for(int i = 0; i < (1<<R*C);i++) {
            if(Integer.bitCount(i)!=N)
                continue;
            int [][] aps = new int[R][C];
            for(int r = 0; r< R; r++) {
                for(int c  = 0; c< C; c++) {
                    int id = (r*C + c);
                    if(BitUtils.getBit(i,id)) {
                        aps[r][c]=1;
                    }
                }
            }
            //
            int u =0;
            for(int r = 0; r< R;r++) {
                for(int c= 0; c < C; c++) {
                    for(int dr = -1; dr<=1;dr++) {
                        for(int dc = -1; dc<=1;dc++) {
                            if(Math.abs(dr) + Math.abs(dc)!=1)
                                continue;
                            if(r + dr < 0 || r+ dr>=R || c + dc <0 || c+ dc >=C)
                                continue;;
                            if(aps[r][c]==1 && aps[r+dr][c+dc]==1)
                                ++u;

                        }
                    }
                }
            }
            minU = Math.min(u,minU);
        }
        out.println("Case #"+testNumber+": "+minU/2);
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

class BitUtils
{

    public static boolean getBit(long number,int bitIdx) {
        return (number & (1l << bitIdx))>0;
    }

}

