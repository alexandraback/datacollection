import java.io.*;
import java.util.*;

public class A {
    private static InputReader in;
    private static PrintWriter out;
    public static boolean SUBMIT = false;
    public static final String NAME = "A-large";
    private static int n;
    private static int[] arr;
    private static final int MAX = 1001;
    private static HashSet[] set = new HashSet[MAX];

    public static void main(String[] args) throws IOException {
        if (args != null && args.length > 0) {
            SUBMIT = args[0].equals("true") ? true : false;
        }

        if (SUBMIT) {
            in = new InputReader(new FileInputStream(new File(NAME + ".in")));
            out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));
        } else {
            in = new InputReader(System.in);
            out = new PrintWriter(System.out, true);
        }


        int numCases = in.nextInt();
        for (int test = 1; test <= numCases; test++) {
            for (int i = 0; i < MAX; i++) {
                set[i] = new HashSet<Integer>();
            }

            n = in.nextInt();
            arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = in.nextInt();
                set[arr[i]].add(i);
            }

            out.println("Case #" + test + ":" + solve());
        }

        out.close();
        System.exit(0);
    }

    private static String solve() {

        /* ArrayIndexComparator comparator = new ArrayIndexComparator(arr);
        Integer[] indexes = comparator.createIndexArray();
        Arrays.sort(indexes, comparator);

        StringBuilder sb = new StringBuilder();
        Integer zero = new Integer(0);
        for (int i = 0; i < n; i++) {
            char ch = (char) ('A' + indexes[i] - zero);
            sb.append(ch + " ");
        } */

        StringBuilder sb = new StringBuilder();
        for (int i = MAX - 1; i > 0; i--) {
            Iterator<Integer> iterator = set[i].iterator();
            while (iterator.hasNext()) {
                int size = set[i].size();
                if (size % 2 == 1) {
                    Integer e = (Integer) iterator.next();
                    iterator.remove();

                    char ch = (char) ('A' + e);
                    sb.append(" " + ch);
                    set[i - 1].add(e);
                } else {
                    Integer e1 = (Integer) iterator.next();
                    iterator.remove();
                    Integer e2 = (Integer) iterator.next();
                    iterator.remove();

                    char ch1 = (char) ('A' + e1);
                    char ch2 = (char) ('A' + e2);
                    sb.append(" " + ch1);
                    sb.append(ch2);
                    set[i - 1].add(e1);
                    set[i - 1].add(e2);
                }
            }
        }

        return sb.toString();
    }

    public static class ArrayIndexComparator implements Comparator<Integer> {
        private final int[] array;

        public ArrayIndexComparator(int[] array) {
            this.array = array;
        }

        public Integer[] createIndexArray() {
            Integer[] indexes = new Integer[array.length];
            for (int i = 0; i < array.length; i++)
            {
                indexes[i] = i; // Autoboxing
            }
            return indexes;
        }

        @Override
        public int compare(Integer index1, Integer index2) {
             // Autounbox from Integer to int to use as array indexes
            return -(array[index1] - array[index2]);
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }
}
