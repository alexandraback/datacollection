import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

import com.google.common.base.Joiner;

public class ProbA {

    private static final String INPUT_FILE = "e:/downloads/A-small-attempt1.in";
    private static final String OUTPUT_FOLDER = "C:/workspaces/algo/GCJ/src/";
    private static final String OUTPUT_FILE = "A-small.out";

    private static class Party implements Comparable<Party> {
        int ind;
        int quantity;

        public Party(int ind, int quantity) {
            super();
            this.ind = ind;
            this.quantity = quantity;
        }

        public void dec() {
            quantity--;
        }

        @Override
        public int compareTo(Party p) {
            return p.quantity - quantity;
        }

        @Override
        public String toString() {
            return "Party [ind=" + ind + ", quantity=" + quantity + "]";
        }

    }

    public static void main(String[] args) throws Exception {
        InputReader in = new InputReader(new FileInputStream(INPUT_FILE));
        PrintWriter pw = new PrintWriter(new File(OUTPUT_FOLDER, OUTPUT_FILE));
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = in.nextInt();
            int total = 0;
            List<Party> parties = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                Party p = new Party(i, in.nextInt());
                parties.add(p);
                total += p.quantity;
            }
            List<String> plans = new ArrayList<>();
            while (total > 0) {
                Collections.sort(parties);
                Party largest = parties.get(0);
                largest.dec();
                total--;
                Party secondLargest = parties.get(1);
                char t1 = (char) ('A' + largest.ind);
                String plan = "" + t1;
                if (secondLargest.quantity > total / 2) {
                    char t2 = (char) ('A' + secondLargest.ind);
                    plan += t2;
                    secondLargest.dec();
                    total--;
                } else if (largest.quantity > total / 2) {
                    char t2 = (char) ('A' + largest.ind);
                    plan += t2;
                    largest.dec();
                    total--;
                }
                plans.add(plan);
                check(parties);
            }
            String res = String.format("Case #%d: %s", t, Joiner.on(' ').join(plans));
            pw.println(res);
            System.out.println(res);
        }
        pw.close();
    }

    public static void check(List<Party> parties) {
        int total = 0;
        for (Party party : parties) {
            total += party.quantity;
        }
        for (Party party : parties) {
            if (party.quantity > total / 2) {
                throw new IllegalStateException("Total " + total + " Party : " + party);
            }
        }
    }

    public static class InputReader {
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

    }

}
