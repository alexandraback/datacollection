
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.StringTokenizer;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Trung Pham
 */
public class Solution {

    public static long Mod = 1000000007;
    public static String[][][][] dp;
    public static int step;
    public static int[] x = {0, 0, 1, -1};
    public static int[] y = {1, -1, 0, 0};

    public static void main(String[] args) throws FileNotFoundException {
        PrintWriter out = new PrintWriter(new FileOutputStream(new File("output.txt")));
        //PrintWriter out = new PrintWriter(System.out);
        Scanner in = new Scanner();

        int t = in.nextInt();
        //System.out.println(t);
        for (int z = 0; z < t; z++) {
            // System.out.println("HE HE");
            int n = in.nextInt();
            String[] data = new String[n];
            for (int i = 0; i < n; i++) {
                data[i] = in.next();
            }
            ArrayList<Count>[] list = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                list[i] = new ArrayList();
                int c = -1;
                char last = ' ';
                for (int j = 0; j < data[i].length(); j++) {
                    if (data[i].charAt(j) == last) {
                        c++;
                    } else {
                        if (c > 0) {
                            list[i].add(new Count(last, c));
                        }
                        c = 1;
                        last = data[i].charAt(j);
                    }
                }
                list[i].add(new Count(last, c));
            }
            boolean ok = true;
            int size = list[0].size();
            for (int i = 0; i < n; i++) {
                if (list[i].size() != size) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                int result = 0;
                for (int i = 0; i < size && ok; i++) {
                    char c = list[0].get(i).a;
                    int max = 0;
                    for (int j = 0; j < n; j++) {
                        max = Math.max(list[j].get(i).c, max);
                        if (list[j].get(i).a != c) {
                            ok = false;
                            break;
                        }
                    }
                    int min = Integer.MAX_VALUE;
                    for (int j = 1; j <= max; j++) {
                        int temp = 0;
                        for (int k = 0; k < n; k++) {
                            temp += Math.abs(list[k].get(i).c - j);
                        }
                        min = Math.min(temp, min);
                    }
                    result += min;
                }
                if (ok) {
                    out.println("Case #" + (z + 1) + ": " + result);
                } else {
                    out.println("Case #" + (z + 1) + ": Fegla Won");
                }
            } else {
                out.println("Case #" + (z + 1) + ": Fegla Won");
            }


        }
        out.close();
    }

    public static class Count {

        char a;
        int c;

        public Count(char a, int c) {
            this.a = a;
            this.c = c;
        }
    }

    public static long pow(long a, int b) {
        if (b == 0) {
            return 1;
        }
        long val = pow(a, b / 2);
        if (b % 2 == 0) {
            return val * val;
        }
        return val * val * a;
    }

    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static class Scanner {

        BufferedReader br;
        StringTokenizer st;

        public Scanner() throws FileNotFoundException {
            //System.setOut(new PrintStream(new BufferedOutputStream(System.out), true));
            //br = new BufferedReader(new InputStreamReader(System.in));
            br = new BufferedReader(new FileReader(new File("A-large.in")));
        }

        public String next() {


            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
                    throw new RuntimeException();
                }
            }
            return st.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() {
            st = null;
            try {
                return br.readLine();
            } catch (Exception e) {
                throw new RuntimeException();
            }
        }

        public boolean endLine() {
            try {
                String next = br.readLine();
                while (next != null && next.trim().isEmpty()) {
                    next = br.readLine();
                }
                if (next == null) {
                    return true;
                }
                st = new StringTokenizer(next);
                return st.hasMoreTokens();
            } catch (Exception e) {
                throw new RuntimeException();
            }
        }
    }
}
