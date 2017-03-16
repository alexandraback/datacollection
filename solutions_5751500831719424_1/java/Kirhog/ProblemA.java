import java.io.File;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

/**
 * @author Alexander Gulko
 */
public class ProblemA {

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);

//        String file = "A-small-attempt1";
        String file = "A-large";
//        String file = "problem-a-test";

        String inFile = file + ".in";
        System.setOut(new PrintStream(file + ".out"));

        Scanner scan = new Scanner(new File(inFile));

        ProblemA problem = new ProblemA();

        int tests = scan.nextInt();
        for (int test = 1; test <= tests; ++test) {
            problem.solve(test, scan);
        }

        scan.close();
    }

    void solve(int test, Scanner scan) {
        int n = scan.nextInt();

        String[] strings = new String[n];
        for (int i = 0; i < n; ++i) {
            strings[i] = scan.next("[a-z]+");
        }

        int[] cursors = new int[n];
        int sum = 0;
        boolean ok = true;
        boolean stop = false;
        while (!stop) {
            boolean c1 = false;
            boolean c2 =false;
            for (int i = 0; i < n; ++i) {
                if (cursors[i] >= strings[i].length()) {
                    c1 = true;
                } else {
                    c2 = true;
                }
            }

            if (c1) {
                if (c2) {
                    ok = false;
                }
                break;
            }

            char c0 = strings[0].charAt(cursors[0]);
            int counts[] = new int[n];
            for (int i = 0; i < n; ++i) {
                int count = 0;
                String s = strings[i];
                for (int k = cursors[i]; k < s.length(); ++k) {
                    if (s.charAt(k) == c0) {
                        ++count;
                    } else {
                        break;
                    }
                }

                counts[i] = count;
                cursors[i] += count;
                if (count == 0) {
                    ok = false;
                    stop = true;
                    break;
                }
            }


            if (ok) {
                Arrays.sort(counts);
                int median = median(counts);
                for (int i = 0; i < n; ++i) {
                    sum += Math.abs(counts[i] - median);
                }
            } else {
                stop = true;
            }
        }

        System.out.printf("Case #%s: %s\n", test, ok ? sum : "Fegla Won");
    }

    int median(int[] a) {
        int min = -1;
        int res = -1;
        for (int k = a[0], end = a[a.length - 1]; k <= end; ++k) {
            int sum = 0;
            for (int v : a) {
                sum += Math.abs(v - k);
            }

            if (min == -1 || sum < min) {
                min = sum;
                res = k;
            }
        }

        return res;
    }
}
