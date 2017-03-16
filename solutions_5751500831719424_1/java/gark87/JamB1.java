import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class JamB1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        Pattern compile = Pattern.compile("(.)\\1*");
        for (int i = 1; i <= T; i++) {
            int N = in.nextInt();
            ArrayList<String> all = new ArrayList<String>(N);
            for (int j = 0; j < N; j++)
                all.add(in.next());
            HashSet<String> uniq = new HashSet<String>();
            for (String s : all)
                uniq.add(compile.matcher(s).replaceAll("$1"));
            String answer = "Fegla Won";
            if (uniq.size() == 1) {
                int length = uniq.iterator().next().length();
                int[][] count = new int[N][length];
                for (int j = 0; j < all.size(); j++) {
                    String s = all.get(j);
                    Matcher matcher = compile.matcher(s);
                    int start = 0;
                    int k =0;
                    while(matcher.find(start)) {
                        int end = matcher.end();
                        count[j][k++] = end-start;
                        start = end;
                    }
                }
                int[] median = new int[length];
                for (int k = 0; k < length; k++) {
                    for (int j = 0; j < N; j++) {
                        median[k] += count[j][k];
                    }
                    median[k] = median[k]/ N;
                }
                int result = 0;
                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < length; k++) {
                        result += Math.abs(count[j][k] - median[k]);
                    }
                }
                answer = String.valueOf(result);
            }
            System.out.println("Case #" + i + ": " + answer);
        }
        in.close();
    }
}
