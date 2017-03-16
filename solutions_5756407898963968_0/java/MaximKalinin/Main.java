import java.io.StreamTokenizer;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Set;
import java.util.Iterator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.Collection;
import java.util.HashSet;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		TokenizerReader in = new TokenizerReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, TokenizerReader in, PrintWriter out) {
        Set<Integer> firstRow = read(in);
        Set<Integer> secondRow = read(in);
        firstRow.retainAll(secondRow);
        out.print("Case #" + testNumber + ": ");
        if (firstRow.isEmpty())
            out.println("Volunteer cheated!");
        else if (firstRow.size() > 1)
            out.println("Bad magician!");
        else
            out.println(firstRow.iterator().next());
    }

    private Set<Integer> read(TokenizerReader in) {
        Set<Integer> result = new HashSet<>();
        int rowNum = in.nextInt() - 1;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                int n = in.nextInt();
                if (i == rowNum)
                    result.add(n);
            }
        }
        return result;
    }
}

class TokenizerReader extends StreamTokenizer {
    public TokenizerReader(InputStream in) {
        super(new BufferedReader(new InputStreamReader(in)));
        defaultConfig();
    }

    public String nextString() {
        try {
            nextToken();
        } catch (IOException e) {
            throw new RuntimeException("nextString: exception in line " + lineno(), e);
        }
        return sval;
    }

    public String next() {
        return nextString();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public void defaultConfig() {
        resetSyntax();
        wordChars(33, 126);
        whitespaceChars(0, ' ');
    }

}

