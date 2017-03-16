/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package round1a2015;

/**
 *
 * @author Andrii
 */
import qr2015.*;
import java.util.NavigableSet;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.util.Collections;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.io.FileInputStream;
import java.util.TreeSet;
import java.io.InputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.io.FileOutputStream;
import java.util.SortedSet;
import java.io.File;
import java.util.Set;

public class ProblemC {

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "C-(small|large).*[.]in";
            File directory = new File(".");
            File[] candidates = directory.listFiles(new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return name.matches(regex);
                }
            });
            File toRun = null;
            for (File candidate : candidates) {
                if (toRun == null || candidate.lastModified() > toRun.lastModified()) {
                    toRun = candidate;
                }
            }
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("c.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++) {
            solver.solve(i, in, out);
        }
        out.close();
    }
}

class TaskC {

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int N = in.readInt();
        int[] X = new int[N];
        int[] Y = new int[N];
        for (int i = 0; i < N; i++) {
            X[i] = in.readInt();
            Y[i] = in.readInt();
        }
        float[] dx1 = {0, 0.5f, 0, -0.5f, 0};
        float[] dy1 = {0, 0f, 0.5f, 0, -0.5f};
        int[][][] d = new int[N][N][5];

        for (int x = 0; x < N - 1; x++) {
            for (int y = x + 1; y < N; y++) {
                int dx = (X[y] - X[x]);
                int dy = (Y[y] - Y[x]);
                for (int j = 0; j < 5; j++) {
                    for (int i = 0; i < N; i++) {
                        float r = dx * (Y[i] - Y[x] + dy1[j]) - dy * (X[i] - X[x] + dx1[j]);
                        if (r > 0) {
                            d[x][y][j]++;
                        } else if (r < 0) {
                            d[y][x][j]++;
                        }
                    }
                }
            }
        }
        out.printLine("Case #" + testNumber + ":");
        if (N == 1) {
            out.printLine(0);
            return;
        }
        for (int i = 0; i < N; i++) {
            int min = Integer.MAX_VALUE;
            for (int j = 0; j < N; j++) {
                if (j == i) {
                    continue;
                }
                for (int k = 0; k < 5; k++) {
                    min = Math.min(Math.min(min, d[i][j][k]), d[j][i][k]);
                }
            }
            out.printLine(min);
        }
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1) {
            throw new InputMismatchException();
        }
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0) {
                return -1;
            }
        }
        return buf[curChar++];
    }

    public int readInt() {
        int c = read();
        while (isSpaceChar(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public long readLong() {
        int c = read();
        while (isSpaceChar(c)) {
            c = read();
        }
        long sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public String readString() {
        int c = read();
        while (isSpaceChar(c)) {
            c = read();
        }
        StringBuilder res = new StringBuilder();
        do {
            if (Character.isValidCodePoint(c)) {
                res.appendCodePoint(c);
            }
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public boolean isSpaceChar(int c) {
        if (filter != null) {
            return filter.isSpaceChar(c);
        }
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public char readCharacter() {
        int c = read();
        while (isSpaceChar(c)) {
            c = read();
        }
        return (char) c;
    }

    public String next() {
        return readString();
    }

    public interface SpaceCharFilter {

        public boolean isSpaceChar(int ch);
    }
}

class OutputWriter {

    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0) {
                writer.print(' ');
            }
            writer.print(objects[i]);
        }
    }

    public void printLine(Object... objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

}

class IntPair implements Comparable<IntPair> {

    public final int first, second;

    public IntPair(int first, int second) {
        this.first = first;
        this.second = second;
    }

    public String toString() {
        return "(" + first + "," + second + ")";
    }

    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }

        IntPair intPair = (IntPair) o;

        return first == intPair.first && second == intPair.second;

    }

    public int hashCode() {
        int result = first;
        result = 31 * result + second;
        return result;
    }

    public int compareTo(IntPair o) {
        if (first < o.first) {
            return -1;
        }
        if (first > o.first) {
            return 1;
        }
        if (second < o.second) {
            return -1;
        }
        if (second > o.second) {
            return 1;
        }
        return 0;
    }
}

class ReverseComparator<T extends Comparable<T>> implements Comparator<T> {

    public int compare(T o1, T o2) {
        return o2.compareTo(o1);
    }
}
