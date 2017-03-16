import javafx.util.Pair;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * Created by eguliyev on 4/17/15.
 */
public class ProblemB {

    public static Comparator<Pair<BigInteger,Integer>> comparator = new Comparator<Pair<BigInteger, Integer>>() {
        @Override
        public int compare(Pair<BigInteger, Integer> o1, Pair<BigInteger, Integer> o2) {
            int r = o1.getKey().compareTo(o2.getKey());
            return r == 0 ? o1.getValue().compareTo(o2.getValue()) : r;
        }
    };

    public static Integer simplify(BigInteger[] ms, Integer n) {
        if (n == 0) {
            return 0;
        }

        BigInteger lcm = BigInteger.ONE;
        BigInteger used = BigInteger.ZERO;
        for (BigInteger m : ms) {
            BigInteger gcd = lcm.gcd(m);
            lcm = lcm.multiply(m.divide(gcd));
        }

        for (BigInteger m : ms) {
            used = used.add(lcm.divide(m));
        }

        int ans = n % used.intValue();
        return ans == 0 ? used.intValue() : ans;
    }

    public static Integer solve(BigInteger[] ms, Integer n) {
        PriorityQueue<Pair<BigInteger,Integer>> finishTimes = new PriorityQueue<Pair<BigInteger, Integer>>(ms.length, comparator);

        int usedCount = 1;

        for (int i = 0; i < ms.length; i++) {
            finishTimes.add(new Pair<BigInteger, Integer>(BigInteger.ZERO, i));
        }

        while (usedCount < n) {
            Pair<BigInteger, Integer> current = finishTimes.poll();
            BigInteger currentTime = current.getKey();
            Integer barberIdx = current.getValue();
            finishTimes.add(new Pair<BigInteger,Integer>(currentTime.add(ms[barberIdx]), barberIdx));
            usedCount++;
        }

        return finishTimes.peek().getValue() + 1;
    }

    public static void solveProblem(int i, String bottomLine, Integer n) {
        BigInteger[] myMs = turnToLongs(bottomLine.split(" "));
        Integer result = solve(myMs, simplify(myMs, n));
        System.out.println("Case #" + i + ": " + result.toString());
    }

    public static BigInteger[] turnToLongs(String[] xs) {
        BigInteger[] ys = new BigInteger[xs.length];
        for (int i = 0; i < xs.length; i++) {
            ys[i] = BigInteger.valueOf(Long.parseLong(xs[i]));
        }
        return ys;
    }

    public static void main(String[] args) throws IOException {
//        solveProblem(1, "7 7 7", 12);

        InputStreamReader in = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(in);
        Integer a = Integer.parseInt(br.readLine());

        for (int i = 1; i <= a; i++) {
            String topLine = br.readLine();
            String bottomLine = br.readLine();
            solveProblem(i, bottomLine, Integer.parseInt(topLine.split(" ")[1]));
        }
    }
}
