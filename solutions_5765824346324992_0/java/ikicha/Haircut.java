import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Haircut {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(new File("B-input.in"));
                BufferedWriter bw = new BufferedWriter(new FileWriter(new File(
                        "B-output.out")))) {
            
            int t = sc.nextInt();
            for (int i = 0; i < t; i++) {
                int b = sc.nextInt();
                long n = sc.nextLong();
                List<Integer> list = new ArrayList<>();
                for (int j = 0; j < b; j++) {
                    list.add(sc.nextInt());
                }
                long lcm = lcm(list);
                long value = getValue(list, lcm);
                n %= value;
                if (n == 0) {
                    n = value;
                }
                String answer = "Case #" + (i + 1) + ": "
                        + solve(n, list);
                bw.write(answer);
                bw.newLine();
                System.out.println(answer);
            }
            bw.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    private static int getValue(List<Integer> list, long lcm) {
        int result = 0;
        for (int l : list) {
            result += lcm / l;
        }
        return result;
    }
    
    private static int solve(long n, List<Integer> list) {
        List<Integer> lastTime = new ArrayList<>();
        for (int i = 0; i < list.size(); i++) {
            lastTime.add(0);
        }
        int emptyBarber = -1;
        for (long i = 0; i < n; i++) {
            while (getFirstEmpty(lastTime) == -1) {
                minusMinAll(lastTime);
            }
            emptyBarber = getFirstEmpty(lastTime);
            lastTime.set(emptyBarber, list.get(emptyBarber));
        }
        return emptyBarber + 1;
    }
    
    private static void minusMinAll(List<Integer> list) {
        int min = Collections.min(list);
        if (min <= 0) {
            return;
        }
        for (int i = 0; i < list.size(); i++) {
            list.set(i, list.get(i) - min);
        }
    }
    
    private static int getFirstEmpty(List<Integer> list) {
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i) == 0) {
                return i;
            }
        }
        return -1;
    }
    
    private static long lcm(long a, long b)
    {
        return a * (b / gcd(a, b));
    }
    
    private static long lcm(List<Integer> list)
    {
        long result = list.get(0);
        for (int i = 1; i < list.size(); i++)
            result = lcm(result, list.get(i));
        return result;
    }
    
    private static long gcd(long a, long b)
    {
        while (b > 0)
        {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
