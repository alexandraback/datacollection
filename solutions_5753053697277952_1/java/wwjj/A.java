package r1c;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;

public class A {

    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(Files.newInputStream(Paths.get("in.txt")));
//        Scanner sc = new Scanner(Files.newInputStream(Paths.get("A-small-attempt0.in")));
//        Scanner sc = new Scanner(Files.newInputStream(Paths.get("A-small-attempt1.in")));
        Scanner sc = new Scanner(Files.newInputStream(Paths.get("A-large.in")));
//        Scanner sc = new Scanner(Files.newInputStream(Paths.get("")));

        int num = sc.nextInt();
        String s = "";
        for (int i = 0; i < num; i++) {
            
            int n = sc.nextInt();
            int[] counts = new int[n];
            int total = 0;

            for (int j = 0; j < counts.length; j++) {
                counts[j] = sc.nextInt();
                total += counts[j];
            }

            String line = String.format("Case #%d: %s\n", i + 1, solve(counts, total));
            System.out.print(line);
            s += line;
        }

        Files.write(Paths.get("out.txt"), s.getBytes());
    }

    private static String solve(int[] counts, int total) {
        StringBuilder ret = new StringBuilder();

        while (true) {
            if (total == 2) {
                for (int i = 0; i < counts.length; i++) {
                    if (counts[i] > 0) {
                        ret.append((char) ('A' + i));
                    }
                }
                break;
            }

            while (true) {
                int maxIdx = 0;
                for (int i = 0; i < counts.length; i++) {
                    if (counts[i] > counts[maxIdx]) {
                        maxIdx = i;
                    }
                }

                counts[maxIdx]--;
                total--;
                ret.append((char) ('A' + maxIdx));

                if (isMaj(counts, total)) {
                    continue;
                } else {
                    break;
                }
            }

            ret.append(" ");
        }

        return ret.toString().trim();
    }

    private static boolean isMaj(int[] counts, int total) {
        for (int i = 0; i < counts.length; i++) {
            if (counts[i] > total / 2) {
                return true;
            }
        }
        return false;
    }

}
