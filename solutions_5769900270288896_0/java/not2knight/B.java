import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class B implements Runnable {

    private static final String DIR = "/home/igoradmin/work/develop/competitions/codejam/2015/src/";

    String problemName = B.class.getName();

    static final int inf = (int)1e9;

//  String fileName = String.format(DIR + "%s-statement", problemName);
  String fileName = String.format(DIR + "%s-small-attempt0", problemName);
//	String fileName = String.format(DIR + "%s-large", problemName);

	public void run() {
		try {
			int nt = nextInt();
			for (int it = 1; it <= nt; it++) {
                int res = solve();
				out.format("Case #%d: %s%n", it, res);
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			out.close();
		}
	}

    int[] dx = new int[] {1, 0, -1, 0};
    int[] dy = new int[] {0, 1, 0, -1};

    private int solve() throws Exception {
        int r = nextInt();
        int c = nextInt();
        int m = r * c;
        int n = nextInt();

        int M = 1 << m;
        int res = m * 4;
        boolean[][] u = new boolean[r][c];
        for (int I = 0; I < M; I++) {
            int b = 0;
            for (int i = 0; i < m; i++) {
                boolean ui = ((I & (1 << i)) > 0);
                u[i / c][i % c] = ui;
                if (ui) {
                    b++;
                }
            }
            if (b != n) {
                continue;
            }
            int tr = 0;
            for (int ix = 0; ix < r; ix++) {
                for (int iy = 0; iy < c; iy++) {
                    if (!u[ix][iy]) {
                        continue;
                    }
                    for (int i = 0; i < 4; i++) {
                        int jx = ix + dx[i];
                        int jy = iy + dy[i];
                        if (jx < 0 || r <= jx || jy < 0 || c <= jy) {
                            continue;
                        }
                        if (u[jx][jy]) {
                            tr++;
                        }
                    }
                }
            }
            res = Math.min(res, tr);
        }

        return res / 2;
    }

    static {
		Locale.setDefault(Locale.US);
	}
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;

	public B() throws FileNotFoundException {
		in = new BufferedReader(new FileReader(new File(fileName + ".in")));
		out = new PrintWriter(fileName + ".out");
		st = new StringTokenizer("");
	}

	public static void main(String[] args) throws FileNotFoundException {
		new Thread(new B()).start();
	}

	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}
	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(next());
	}
	double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(next());
	}
	long nextLong() throws NumberFormatException, IOException {
		return Long.parseLong(next());
	}
}