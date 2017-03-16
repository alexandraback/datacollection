package codejam;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * Created by evgen on 08.05.2016.
 */
public class SenateEvacuation {


    final static String PROBLEM_NAME = "senat";
    final static String WORK_DIR = "C:\\Users\\evgen\\Desktop\\" + PROBLEM_NAME + "\\";
    final static String INPUT_FILE_NAME = "A-small-attempt0.in";
    final static String OUTPUT_FILE_NAME = "A-large.out";


    public static final String OUT_FORMATTER = "Case #%d: %s";


    String solve(Scanner in, PrintWriter pw) {
        long N = in.nextLong();

        PriorityQueue<Party> pq = new PriorityQueue<>();
        long totalSize = 0;
        for (int i = 0; i < N; i++) {
            int num = in.nextInt();
            totalSize += num;
            String name = "" + (Character.valueOf((char) ('A' + i)));
            pq.add(new Party(name, num));
        }

        StringBuilder sb = new StringBuilder();

        while (!pq.isEmpty()) {
            Party p1= pq.poll();
            p1.count--;
            totalSize--;
            if (p1.count > 0) {
                pq.add(p1);
            }
            sb.append(p1.name);
            if (totalSize == 2) {
                sb.append(" ");
                continue;
            } else {
                Party p2= pq.poll();
                p2.count--;
                totalSize--;
                if (p2.count > 0) {
                    pq.add(p2);
                }
                sb.append(p2.name).append(" ");
            }
        }


        return sb.toString();
    }

    static class Party implements Comparable<Party> {
        String name;
        int count;

        public Party(String name, int count) {
            this.name = name;
            this.count = count;
        }

        @Override
        public int compareTo(Party o) {
            return o.count - count;
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + INPUT_FILE_NAME));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR
                + OUTPUT_FILE_NAME));
        int caseCnt = sc.nextInt();
        SenateEvacuation countingSheep = new SenateEvacuation();
        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            String r = String.format(OUT_FORMATTER, (caseNum + 1), countingSheep.solve(sc, pw));
            System.out.println(r);
            pw.println(r);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
