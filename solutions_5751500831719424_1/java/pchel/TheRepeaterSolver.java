import java.io.*;
import java.util.Locale;
import java.util.Scanner;

public class TheRepeaterSolver {
        private static final String INPUT_FILE_NAME = "A-large.in";
//                                private static final String INPUT_FILE_NAME = "A-small-attempt0.in";
//                                private static final String INPUT_FILE_NAME = "A-small-attempt1.in";
//    private static final String INPUT_FILE_NAME = "input2.in";
        private static final String OUTPUT_FILE_NAME = "A-large.out";
//                            private static final String OUTPUT_FILE_NAME = "A-small-attempt0.out";
//                            private static final String OUTPUT_FILE_NAME = "A-small-attempt1.out";
//    private static final String OUTPUT_FILE_NAME = "output2.out";

    private int n;
    private String[] data;
    private int[][] codes;
    private String sample;

    public static void main(String[] args) throws IOException {
        StringBuilder builder = new StringBuilder();

        try (BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(INPUT_FILE_NAME)))) {
            Scanner scanner = new Scanner(reader);
            scanner.useLocale(Locale.ENGLISH);
            int testCasesCount = scanner.nextInt();

            for (int i = 1; i <= testCasesCount; i++) {
                System.out.println("Case #" + i);
                scanner.nextLine();
                TheRepeaterSolver solver = new TheRepeaterSolver();

                solver.readData(scanner);
                int solution = solver.solve();

                builder.append("Case #");
                builder.append(i);
                builder.append(": ");
                builder.append(solution < 0 ? "Fegla Won" : solution);
                builder.append("\r\n");
            }
        }

        try (BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(OUTPUT_FILE_NAME)
        ))) {
            writer.write(builder.toString());
        }
    }

    private int solve() {
        sample = getSample(data[0]);
        codes = new int[n][sample.length()];
        codes[0] = getCode(data[0]);

        for (int i = 1; i < n; i++) {
            if (!sample.equals(getSample(data[i]))) {
                return -1;
            }
            codes[i] = getCode(data[i]);
        }

        int result = 0;

        // choose place in sample
        for (int j = 0; j < sample.length(); j++) {
            int minLetterResult = Integer.MAX_VALUE;

            // iterate through possible sizes
            for (int k = 1; k <= 100; k++) {
                int letterResult = 0;

                // calculate number of moves for each string
                for (int i = 0; i < n; i++) {
                    letterResult += Math.abs(codes[i][j] - k);
                }

                if (letterResult < minLetterResult) {
                    minLetterResult = letterResult;
                }
            }

            result += minLetterResult;
        }

        return result;
    }

    private String getSample(String s) {
        StringBuilder result = new StringBuilder();
        char prev = '1';

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c != prev) {
                result.append(c);
            }
            prev = c;
        }

        return result.toString();
    }

    private int[] getCode(String s) {
        int[] result = new int[sample.length()];
        int j = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == sample.charAt(j)) {
                result[j]++;
            } else {
                i--;
                j++;
            }
        }

        return result;
    }

    private void readData(Scanner scanner) {
        n = scanner.nextInt();

        data = new String[n];
        for (int i = 0; i < n; i++) {
            data[i] = scanner.next();
        }
    }
}
