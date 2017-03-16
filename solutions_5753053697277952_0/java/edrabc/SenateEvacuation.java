import java.io.BufferedReader;
import java.io.FileReader;

public class SenateEvacuation {

    public void go(String file) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(file));
        int T = Integer.parseInt(reader.readLine());
        for (int i = 1; i <= T; i++) {
            int N = Integer.parseInt(reader.readLine());
            String[] Ps = reader.readLine().split(" ");
            int total = 0;
            int[] P = new int[Ps.length];
            for (int j = 0; j < Ps.length; j++) {
                P[j] = Integer.parseInt(Ps[j]);
                total += P[j];
            }

            String result = solve(total, P);
            System.out.print("Case #" + i + ": ");
            System.out.println(result);
        }
    }

    private String solve(int total, int[] p) {
        StringBuilder result = new StringBuilder();
        while (total > 0) {
            int maxPos = findMax(p);
            total--;
            p[maxPos]--;
            result.append((char) (maxPos + 65));

            if (total != 2) {
                maxPos = findMax(p);
                total--;
                p[maxPos]--;
                result.append((char) (maxPos + 65));
            }

            result.append(" ");
        }

        return result.toString();
    }

    private int findMax(int[] p) {
        int max = 0;
        int pos = 0;
        for (int i = 0; i < p.length; i++) {
            if (p[i] > max) {
                max = p[i];
                pos = i;
            }
        }
        return pos;
    }

    public static void main(String[] args) throws Exception {
        new SenateEvacuation().go(args[0]);
    }
}
