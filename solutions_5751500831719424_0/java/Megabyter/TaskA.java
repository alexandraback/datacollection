import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TaskA {
    private class FastReader {
        private BufferedReader br;
        private StringTokenizer st;

        public FastReader(File f) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(f));
        }

        public FastReader(InputStream is) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(is));
        }

        public String next() {
            if ((st == null) || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
    }

    String getPattern(String word) {
        char prev = word.charAt(0);
        StringBuilder pattern = new StringBuilder("(" + prev + "+)");
        for (int i = 1; i < word.length(); i++) {
            char cur = word.charAt(i);
            if (cur != prev) {
                pattern.append("(").append(cur).append("+)");
                prev = cur;
            }
        }
        return "^" + pattern.toString() + "$";
    }

    int colDistance(List<List<Integer>> sizes, int col, int val) {
        int ans = 0;
        for (int i = 0; i < sizes.size(); i++) {
            ans += Math.abs(sizes.get(i).get(col) - val);
        }
        return ans;
    }

    int minimalDistance(List<String> words) {
        Pattern pattern = Pattern.compile(getPattern(words.get(0)));
        List<List<Integer>> sizes = new ArrayList<>();
        for (String word : words) {
            Matcher matcher = pattern.matcher(word);
            if (!matcher.matches()) {
                return -1;
            }
            List<Integer> sizesRow = new ArrayList<Integer>();
            sizes.add(sizesRow);
            for (int i = 1; i <= matcher.groupCount(); i++) {
                sizesRow.add(matcher.group(i).length());
            }
        }
        int ans = 0;
        for (int i = 0; i < sizes.get(0).size(); i++) {
            int min = Integer.MAX_VALUE;
            for (int val = 1; val <= 100; val++) {
                int t = colDistance(sizes, i, val);
                if (t < min) {
                    min = t;
                }
            }
            ans += min;
        }
        return ans;
    }

    void printAnswer(int n, String ans) {
        printer.println("Case #" + n + ": " + ans);
    }

    private FastReader reader;
    private PrintWriter printer;

    public void solve() throws IOException {
        reader = new FastReader(new File("input.txt"));
        printer = new PrintWriter(new File("output.txt"));
        int testNum = reader.nextInt();
        for (int test = 1; test <= testNum; test++) {
            int n = reader.nextInt();
            List<String> words = new ArrayList<String>();
            for (int i = 0; i < n; i++) {
                String s = reader.next();
                words.add(s);
            }
            int ans = minimalDistance(words);
            if (ans == -1) {
                printAnswer(test, "Fegla Won");
            } else {
                printAnswer(test, String.valueOf(ans));
            }
        }
        printer.close();
    }

    public static void main(String[] args) {
        try {
            new TaskA().solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}