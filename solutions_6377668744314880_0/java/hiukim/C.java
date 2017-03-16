import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class C {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
    
    public void task() throws IOException {
        int N = nextInt();
        long[][] points = new long[N][];
        for (int i = 0; i < N; i++) {
            points[i] = new long[] {nextLong(), nextLong(), i};
        }

//        if (true) {
//            boolean[] on  = compute(points, N);
//            out.println(Arrays.toString(on));
//            return;
//        }

        int[] ans = new int[N];
        Arrays.fill(ans, Integer.MAX_VALUE / 2);
        int mask = (1 << N);
        for (int m = 1; m < mask; m++) {
            ArrayList<Integer> ps = new ArrayList<Integer>();
            for (int i = 0; i < N; i++) {
                if ((m & (1 << i)) != 0) {
                    ps.add(i);
                }
            }
            long[][] pps = new long[ps.size()][];
            for (int i = 0; i < ps.size(); i++) {
                pps[i] = points[ps.get(i)];
            }
            int removed = N - ps.size();

            boolean[] onBoundary = compute(pps, N);
            for (int i = 0; i < N; i++) {
                if( onBoundary[i]) {
                    ans[i] = Math.min(ans[i], removed);
                }
            }
        }

        out.println();
        for (int i = 0; i < N; i++) {
            out.println(ans[i]);
        }

    }

    public boolean[] compute(long[][] points, int TN) {
        int N = points.length;

        Arrays.sort(points, new Comparator<long[]>() {
            @Override
            public int compare(long[] a, long[] b) {
                if (a[1] < b[1]) return -1;
                if (a[1] > b[1]) return 1;
                return a[0] < b[0]? -1: 1;
            }
        });

        final long[] first = new long[] {points[0][0], points[0][1]};
        Arrays.sort(points, new Comparator<long[]>() {
            @Override
            public int compare(long[] a, long[] b) {
                if (a[0] == first[0] && a[1] == first[1]) return -1;
                if (b[0] == first[0] && b[1] == first[1]) return 1;

                boolean positiveA = a[0] >= first[0];
                boolean positiveB = b[0] >= first[0];

                if (positiveA && !positiveB) return -1;
                if (positiveB && !positiveA) return 1;

                long tmp = (a[1] - first[1]) * (b[0] - first[0]) - (b[1] - first[1]) * (a[0] - first[0]);
                if (tmp == 0) {
                    long dA = (a[0] - first[0]) * (a[0] - first[0]) + (a[1] - first[1]) * (a[1] - first[1]);
                    long dB = (b[0] - first[0]) * (b[0] - first[0]) + (b[1] - first[1]) * (b[1] - first[1]);
                    return dA < dB? -1: 1;
                } else {
//                    return tmp > 0? -1: 1;
                    return tmp < 0? -1: 1;
                }
            }
        });

//        for (int i = 0; i < N; i++) {
//            out.println(points[i][0] + ", " + points[i][1]);
//        }

        int[] indexes = new int[N];
        int end = 0;
        for (int i = 0; i < N; i++) {
            while (end >= 2) {
                int i1 = indexes[end-2];
                int i2 = indexes[end-1];
                int i3 = i;
                long[] p1 = points[i1];
                long[] p2 = points[i2];
                long[] p3 = points[i3];

                long tmp = (p2[0] - p1[0]) * (p3[1] - p1[1]) - (p2[1] - p1[1]) * (p3[0] - p1[0]);
                if (tmp <= 0) end--;
                else break;
            }
            indexes[end++] = i;
        }

//        out.println("indexes: " + Arrays.toString(indexes) + ". end: " + end);

        boolean[] onBoundary = new boolean[TN];
        for (int i = 0; i < end; i++) {
            long[] pt = points[indexes[i]];
            for (int j = 0; j < N; j++) {
                if (points[j][0] == pt[0] && points[j][1] == pt[1]) {

                    onBoundary[(int) points[j][2]] = true;
                }
            }
        }
        for (int i = 1; i <= end; i++) {
            long[] p1 = points[indexes[i-1]];
            long[] p2 = points[indexes[i % end]];
            for (int j = 0; j < N; j++) {
                long[] p3 = points[j];
                long tmp = (p2[0] - p1[0]) * (p3[1] - p1[1]) - (p2[1] - p1[1]) * (p3[0] - p1[0]);
                if (tmp == 0) onBoundary[(int) p3[2]] = true;
            }
        }

        return onBoundary;
    }
        
	public void solve() throws IOException {
		int T = nextInt();
		for(int t = 1; t <= T; t++){
			out.print("Case #" + (t) + ": ");
			task();
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new C().run();
	}
	
	public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            out = new PrintWriter(System.out);
            solve();
            reader.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

}
