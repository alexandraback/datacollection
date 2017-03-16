
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * @author Abhimanyu Singh
 *
 */
public class A {

    private InputStream input;
    private PrintStream output;
    private Scanner inputSc;

    public A(InputStream input, PrintStream output) {
        this.input = input;
        this.output = output;
        init();
    }

    private void init() {
        inputSc = new Scanner(input);
    }

    static int lineToInt(String line) {
        return Integer.parseInt(line);
    }

    public void solve() {
        int testCaseCount = lineToInt(inputSc.nextLine());
        for (int testN = 1; testN <= testCaseCount; testN++) {
            solveTestCase(testN);
        }
    }

    String getBase(String s) {
        String ans = "";
        char lastChar = '0';
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == lastChar) {
            } else {
                lastChar = ch;
                ans += ch;
            }
        }
        return ans;
    }

    private void solveTestCase(int testN) {
        Scanner tempSc = new Scanner(inputSc.next());
        int N = tempSc.nextInt();
        String a[] = new String[N];
        for (int i = 0; i < N; i++) {
            a[i] = inputSc.next().trim();
        }
        String base = getBase(a[0]);
        for (int i = 1; i < N; i++) {
            String b = getBase(a[i]);
            if (!b.equals(base)) {
                output.println("Case #" + testN + ": " + "Fegla Won");
                return;
            }
        }
        int m = base.length();
        int count[][] = new int[N][m];
        int max[] = new int[m];
        for (int i = 0; i < N; i++) {
            String s = a[i];
            char lastCh = '0';
            int index = -1;
            for (int j = 0; j < s.length(); j++) {
                char ch = s.charAt(j);
                if (ch != lastCh) {
                    lastCh = ch;
                    index++;
                }
                count[i][index]++;
            }
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < N; i++) {
                max[j] = Math.max(count[i][j], max[j]);
            }
        }
        int ans = 0;
        for (int j = 0; j < m; j++) {
            int minSubStep = max[j];
            for (int v = 1; v <= max[j]; v++) {
                int step = 0;
                for (int i = 0; i < N; i++) {
                    step += (Math.abs(count[i][j] - v));
                }
                minSubStep = Math.min(minSubStep, step);
            }
            ans += minSubStep;
        }
        output.println("Case #" + testN + ": " + ans);
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        A a = new A(System.in, System.out);
        a.solve();
    }
}
