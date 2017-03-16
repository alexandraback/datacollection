//Uses Java 8

import java.io.*;
import java.util.*;

public class GCJ161CA {

    static Scanner sc = new Scanner(System.in);

    public void run(int Case) {
        int N = sc.nextInt();
        PriorityQueue<Pair> Q = new PriorityQueue();
        int count = 0;
        for (int i = 0; i < N; i++) {
            int K = sc.nextInt();
            Q.add(new Pair(K, (char) ('A' + i)));
            count += K;
        }

        String answer = "Case #" + Case + ":";
        System.out.print(answer);

        while (!Q.isEmpty()) {
            Pair pair = Q.poll();
            if (pair.K == 1) {
                if (Q.size() == 2) {
                    System.out.print(" " + pair.V);
                    count -= 1;
                } else if (Q.size() == 1) {
                    System.out.print(" " + pair.V + Q.poll().V);
                    count -= 2;
                    break;

                } else {
                    System.out.print(" " + pair.V + Q.poll().V);
                    count -= 2;
                }
            } else {
                if (Q.peek().K <= Math.floor((count - 2) / 2.0)) {
                    System.out.print(" " + pair.V + pair.V);
                    //System.err.println(Case + " " + pair.K + pair.V + " " + Q.peek().K + Q.peek().V);
                    pair.K -= 2;
                    count -= 2;
                } else {
                    Pair second = Q.poll();
                    if (Q.isEmpty()) {
                        System.out.print(" " + pair.V + second.V);
                        pair.K -= 1;
                        second.K -= 1;
                        count -= 2;
                    } else if (Q.peek().K <= Math.floor((count - 2) / 2.0)) {
                        System.out.print(" " + pair.V + second.V);
                        pair.K -= 1;
                        second.K -= 1;
                        count -= 2;
                    } else {
                        System.out.print(" " + pair.V);
                        pair.K -= 1;
                        count -= 1;
                    }
                    if (second.K > 0) {
                        Q.add(second);
                    }
                }
                if (pair.K > 0) {
                    Q.add(pair);
                }
            }
        }

        System.out.println("");

    }

    public static void main(String[] args) throws FileNotFoundException {
        //Generates output file, can be removed to get everything from default output
        System.setOut(new PrintStream(new BufferedOutputStream(new FileOutputStream("C://Users/s142589/Desktop/output.txt")), true));

        int runs = sc.nextInt();
        for (int i = 0; i < runs; i++) {
            new GCJ161CA().run(i + 1);
        }
    }

    class Pair implements Comparable<Pair> {

        int K;
        char V;

        Pair(int k, char v) {
            K = k;
            V = v;
        }

        @Override
        public int compareTo(Pair other) {
            return (other.K - K);
        }
    }
}
