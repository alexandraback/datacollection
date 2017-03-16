import java.io.FileNotFoundException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collection;
import java.util.HashSet;
import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileReader;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Set;
import java.util.StringTokenizer;
import java.io.ByteArrayOutputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author abra
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		MagicTrick solver = new MagicTrick();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class MagicTrick extends SavingChelperSolution {

  public void solve() {
    int firstLine = in.nextInt() - 1;

    Integer[][] a = new Integer[4][4];
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        a[i][j] = in.nextInt();
      }
    }

    int secondLine = in.nextInt() - 1;

    Integer[][] b = new Integer[4][4];
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        b[i][j] = in.nextInt();
      }
    }

    Set<Integer> set = new HashSet<>();
    set.addAll(Arrays.asList(a[firstLine]));
    set.retainAll(Arrays.asList(b[secondLine]));

    if (set.size() == 0) {
      out.println("Volunteer cheated!");
    }

    if (set.size() == 1) {
      out.println(set.iterator().next());
    }

    if (set.size() > 1) {
      out.println("Bad magician!");
    }
  }
}

abstract class SavingChelperSolution {

  public InputReader in;
  public OutputWriter out;

  private OutputWriter toFile;

  public SavingChelperSolution() {
    try {
      toFile = new OutputWriter("gcj-output.txt");
    } catch (FileNotFoundException e) {
      throw new RuntimeException(e);
    }
  }

  public abstract void solve();

  public void solve(int testNumber, InputReader in, OutputWriter out) {

    ByteArrayOutputStream saved = new ByteArrayOutputStream();

    OutputWriter savingOut = new OutputWriter(saved);

    this.in = in;
    this.out = savingOut;

    solve();
    savingOut.flush();

    String result = "Case #" + testNumber + ": " + saved.toString();
    if (!result.endsWith("\n")) {
      result += "\n";
    }

    out.write(result);
    out.flush();
    toFile.write(result);
    toFile.flush();
  }

}

class InputReader {

  BufferedReader br;
  StringTokenizer in;

  public InputReader(String fileName) {
    try {
      br = new BufferedReader(new FileReader(fileName));
    } catch (IOException e) {
      throw new RuntimeException(e);
    }
  }

  public InputReader(InputStream inputStream) {
    br = new BufferedReader(new InputStreamReader(inputStream));
  }

  boolean hasMoreTokens() {
    while (in == null || !in.hasMoreTokens()) {
      String s = nextLine();
      if (s == null) {
        return false;
      }
      in = new StringTokenizer(s);
    }
    return true;
  }

  public String nextString() {
    return hasMoreTokens() ? in.nextToken() : null;
  }

  public String nextLine() {
    try {
      in = null; // riad legacy
      return br.readLine();
    } catch (Exception e) {
      e.printStackTrace();
      return null;
    }
  }

  public int nextInt() {
    return Integer.parseInt(nextString());
  }

  public String next() {
    return nextString();
  }
}

class OutputWriter extends PrintWriter {

  public OutputWriter(String fileName) throws FileNotFoundException {
    super(fileName);
  }

  public OutputWriter(OutputStream outputStream) {
    super(outputStream);
  }

  public OutputWriter(Writer writer) {
    super(writer);
  }

}

