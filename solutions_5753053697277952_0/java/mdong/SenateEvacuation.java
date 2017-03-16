package Round1C;

import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/**
 * Created by Michael on 5/8/2016.
 */
public class SenateEvacuation {
    public static BufferedReader in;
    public static BufferedWriter out;
    public static int n;
    public static PriorityQueue<Party> q = new PriorityQueue<>();

    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new FileReader("Google CodeJam 2016/Round1C/A-small-attempt0.in"));
        out = new BufferedWriter(new FileWriter("Google CodeJam 2016/Round1C/A-small-attempt0.out"));
        n = Integer.parseInt(in.readLine());
        for (int i = 0; i < n; i++) {
            int size = 0;
            int party = Integer.parseInt(in.readLine());
            StringTokenizer tokenizer = new StringTokenizer(in.readLine());
            q = new PriorityQueue<>();
            for (int j = 0; j < party; j++) {
                int temp = Integer.parseInt(tokenizer.nextToken());
                size += temp;
                q.add(new Party((char) (65 + j), temp));
            }
            solve(i + 1, size);
        }
        out.close();
    }

    public static void solve(int i, int size) throws IOException{
        ArrayList<String> strings = new ArrayList<>();
        while (size != 0) {
            Party first = q.poll();
            String temp = "" +first.name;
            first.size -= 1;
            size -= 1;
            q.offer(first);
            if (q.peek().size > size / 2) {
                Party second = q.poll();
                temp += second.name;
                second.size -= 1;
                size--;
                q.offer(second);
            }
            strings.add(temp);
        }
        String word = "";
        for (int j = 0; j < strings.size(); j++) {
            word += strings.get(j) + " ";
        }
        out.write("Case #" + i + ": " + word + "\n");

    }

    private static class Party implements Comparable<Party>{
        private Character name;
        private int size;
        public Party(Character name, int size) {
            this.name = name;
            this.size = size;
        }

        public int compareTo(Party p) {
            return p.size - size;
        }
    }

}
