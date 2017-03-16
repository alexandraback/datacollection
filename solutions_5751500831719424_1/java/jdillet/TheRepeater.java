import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Locale;

public class TheRepeater {
    
    private void processInput() throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.valueOf(in.readLine());        

        for (int testCase = 1; testCase <= T; testCase++) {
            int n = Integer.valueOf(in.readLine());
            StringBuilder[] str = new StringBuilder[n];
            for (int j = 0; j < n; j++) {
                str[j] = new StringBuilder(in.readLine());
            }

            String res = go(n, str);

            System.out.printf(Locale.ENGLISH, "Case #%d: %s\n", testCase, res);
        }
        
        in.close();
    }
    
    String err = "Fegla Won";
    private String go(int n, StringBuilder[] str) {
        int res = 0;
        
        int[] prefLen = new int[n];
        
        while (true) {
            boolean allZero = true;
            for (int i = 0; i < n; i++) {
                if (str[i].length() != 0) {
                    allZero = false;
                }
            }
            if (allZero) {
               break;
            }
            Arrays.fill(prefLen, 0);
            if (str[0].length() == 0) {
                return err;
            }
            char c = str[0].charAt(0);
            
            int maxPref = -1;
            for (int i = 0; i < n; i++) {
                int j = 0;
                while (j < str[i].length() && str[i].charAt(j) == c) {
                    j++;
                }
                prefLen[i] = j;
                str[i].delete(0, j);
                if (prefLen[i] == 0) {
                    return err;
                }
                maxPref = Math.max(maxPref, prefLen[i]);
            }
            int best = 1000000000;
            for (int len = 1; len <= maxPref; len++) {
                int val = 0;
                for (int i = 0; i < n; i++) {
                    val += Math.abs(prefLen[i] - len);
                }
                best = Math.min(best, val);
            }
            res += best;
        }

        return String.valueOf(res);
    }

    public static void main(String[] args) throws Exception {
        TheRepeater main = new TheRepeater();
        main.processInput();
    }
}
