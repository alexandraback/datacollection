import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;
import java.util.StringTokenizer;

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
    private int n;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int r = in.nextInt();
        int c = in.nextInt();
        n = in.nextInt();

       // int sol = solve(r, c);
        int solB = brute(r, c);

        out.println(String.format("Case #%d: %d", testNumber, solB));
    }

    private int brute(int r, int c) {
        int min = Integer.MAX_VALUE;

        for (int i=0; i< (1L << (r*c)); i++){
            int nr = count(i);

            if (nr == n){
                min = Math.min(min, create2(r, c, i));
            }
        }

        return min;
    }

    private int count(int x) {
        int sol = 0;

        while (x != 0){
            sol++;
            x = x- (x & (-x));
        }

        return sol;
    }

    private int create2(int r, int c, int conf){
        boolean[][] a = new boolean[r][c];

        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                if (((1 << (i*c + j)) & conf) != 0){
                    a[i][j] = true;
                }
            }
        }
        int[] dx = {-1, 0, 0, 1};
        int[] dy = {0, -1, 1, 0};

        int cnt = 0;

        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){

                for (int k=0; k<4; k++){
                    int newI = i + dx[k];
                    int newJ = j + dy[k];

                    if (newI >= 0 && newI < r && newJ >= 0 && newJ < c && a[i][j] && a[newI][newJ]){
                        cnt++;
                    }
                }

            }
        }

        return cnt/2;
    }

}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;


    public InputReader(InputStream stream){
        reader = new BufferedReader(new InputStreamReader(stream));
    }

    public String next(){
        while (tokenizer == null || !tokenizer.hasMoreTokens()){
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException("FATAL ERROR", e);
            }
        }

        return tokenizer.nextToken();
    }

    public int nextInt(){
        return Integer.valueOf(next());
    }

}

