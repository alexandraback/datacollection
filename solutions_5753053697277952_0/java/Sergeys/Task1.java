package by.home.sss;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * Created by Sergey on 5/8/2016.
 */

public class Task1 {

    private static final String CHARSET_NAME = "US-ASCII";

    private List<String> results;

    private static class Internal implements Comparable<Internal> {
        private final char letter;
        private final int priority;

        public Internal(char letter, int priority) {
            this.letter = letter;
            this.priority = priority;
        }

        public int compareTo(Internal o) {
            return o.priority - this.priority;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Internal internal = (Internal) o;

            return priority == internal.priority;

        }

        @Override
        public int hashCode() {
            return priority;
        }
    }


    private void init() throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("input.txt"), CHARSET_NAME);
        try {
            if (scanner.hasNext()) {
                int numberOfTest = scanner.nextInt();
                results = new ArrayList<String>(numberOfTest);
                for (int i = 0;i < numberOfTest; i++){
                    if (scanner.hasNext()) {
                        StringBuilder sb = new StringBuilder();
                        int parties = scanner.nextInt();
                        PriorityQueue<Internal> queue = new PriorityQueue<Internal>();
                        for (int j = 0; j <parties;j++){
                            char ch = (char)('A' + j);
                            int priority = scanner.nextInt();
                            queue.add(new Internal(ch, priority));
                        }
                        while (!queue.isEmpty()) {
                            sb.append(" ");
                            Internal in = queue.poll();
                            sb.append(in.letter);

                            if (in.priority > 1) {
                                queue.add(new Internal(in.letter, in.priority-1));
                            }

                            Internal in2 = queue.poll();

                                if (queue.size() != 1 || queue.peek().priority != in2.priority){
                                    sb.append(in2.letter);
                                    if (in2.priority > 1) {
                                        queue.add(new Internal(in2.letter, in2.priority - 1));
                                    }
                                } else {
                                    queue.add(new Internal(in2.letter, in2.priority));
                                }


                        }
                        results.add(sb.toString());
                    }
                }
            }
        }
        finally {
            scanner.close();
        }
    }

    private void saveResults () throws FileNotFoundException, UnsupportedEncodingException {
        PrintWriter writer = new PrintWriter("output.txt",CHARSET_NAME);
        try {
            for (int i = 0; i < results.size(); i++) {
                writer.print(String.format("Case #%d:", i+1));
                writer.println(results.get(i));
            }
        }
        finally {
            writer.close();
        }

    }

    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        Task1 problem = new Task1();
//        problem.genInput();
        long start = System.currentTimeMillis();
        problem.init();
//        problem.solve();
        problem.saveResults();
        System.out.println(System.currentTimeMillis()-start);

    }
}
