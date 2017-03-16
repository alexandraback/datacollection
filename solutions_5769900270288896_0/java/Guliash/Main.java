import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Artem Gilmudinov
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("B-small-attempt0.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Reader in = new Reader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		solver.solve(1, in, out);
		out.close();
	}
}

class Task {
    public void solve(int testNumber, Reader in, PrintWriter out) {
        int t = in.ni();
        for(int test = 0; test < t; test++) {
            int r, c, n;
            r = in.ni(); c = in.ni(); n = in.ni();
            int maskMax = (1 << r);
            int[][][] dp = new int[c][maskMax][n + 1];
            int[] cnt = new int[maskMax];
            for(int i = 0; i < maskMax; i++) {
                cnt[i] = cntOfBits(i);
            }
            for(int i = 0; i < c; i++) {
                for(int j = 0; j < maskMax; j++) {
                    for(int z = 0; z <= n; z++) {
                        dp[i][j][z] = Integer.MAX_VALUE;
                    }
                }
            }
            for(int i = 0; i < maskMax; i++) {
                if(cnt[i] > n) {
                    continue;
                }
                dp[0][i][cnt[i]] = getHappiness(0, i, true);
            }
            int tempCnt;
            for(int i = 1; i < c; i++) {
                for(int j = 0; j < maskMax; j++) {
                    for(int z = 0; z < maskMax; z++) {
                        tempCnt = cnt[z];
                        for(int k = 0; k <= n; k++) {
                            if(k + tempCnt > n) {
                                break;
                            }
                            if(dp[i - 1][j][k] != Integer.MAX_VALUE) {
                                dp[i][z][k + tempCnt] = Math.min(dp[i][z][k + tempCnt], dp[i - 1][j][k] + getHappiness(j, z, false));
                            }
                        }
                    }
                }
            }
            int min = Integer.MAX_VALUE;
            for(int i = 0; i < maskMax; i++) {
                min = Math.min(dp[c - 1][i][n], min);
            }
            out.println(String.format("Case #%d: %d ", test + 1, min));
        }
    }


    public int cntOfBits(int a) {
        int cnt = 0;
        while(a != 0) {
            cnt += (a % 2 != 0 ? 1 : 0);
            a /= 2;
        }
        return cnt;
    }

    public int getHappiness(int a, int b, boolean flag) {
        int pow = 1;
        int max = 20;
        int bUp, bDown, aUp, aDown;
        int res = 0;
        for(int i = 0; i < max; i++, pow *= 2) {
            bUp = (b & (pow)) == pow ? 1 : 0;
            bDown = (b & (pow * 2)) == pow * 2 ? 1 : 0;
            aUp = (a & (pow)) == pow ? 1 : 0;
            aDown = (a & (pow * 2)) == pow * 2 ? 1 : 0;
            if(bUp == 1) {
                if(bDown == 1) {
                    res++;
                }
                if(aUp == 1) {
                    res++;
                }
            }
            if(aUp == 1 && flag) {
                if(aDown == 1) {
                    res++;
                }
            }

        }
        return res;
    }

    public int rotate(int a) {
        int maxPow = 1;
        while(true) {
            if(maxPow * 10 > a) {
                break;
            }
            maxPow *= 10;
        }
        int res = 0;
        int curPow = 1;
        while(maxPow != 0) {
            res += curPow * (a / maxPow);
            a -= (a / maxPow) * maxPow;
            maxPow /= 10;
            curPow *= 10;
        }
        return res;

    }
}

class Reader {
    private BufferedReader in;
    private StringTokenizer st = new StringTokenizer("");
    private String delim = " ";

    public Reader(InputStream in) {
        this.in = new BufferedReader(new InputStreamReader(in));
    }

    public String next() {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(rl());
        }
        return st.nextToken(delim);
    }

    public String rl() {
        try {
            return in.readLine();
        } catch(IOException e) {
            throw new RuntimeException(e);
        }
    }

    public int ni() {
        return Integer.parseInt(next());
    }

}

