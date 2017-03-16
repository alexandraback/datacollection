import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Mushroom {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(new File("A-input.in"));
                BufferedWriter bw = new BufferedWriter(new FileWriter(new File(
                        "A-output.out")))) {
            
            int t = sc.nextInt();
            for (int i = 0; i < t; i++) {
                int n = sc.nextInt();
                List<Long> list = new ArrayList<>();
                for (int j = 0; j < n; j++) {
                    list.add(sc.nextLong());
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
    
    private static String solve(int n, List<Long> list) {
        long result1 = 0;
        long result2 = 0;
        long maxDiff = 0;
        long last = list.get(0);
        for (int i = 1; i < n; i++) {
            long diff = list.get(i) - last;
            if (diff < 0) {
                result1 += -diff;
                maxDiff = Math.max(maxDiff, Math.abs(diff));
            }
            last = list.get(i);
        }
        for (int i = 0; i < n - 1; i++) {
            result2 += Math.min(maxDiff, list.get(i));
        }
        return result1 + " " + result2;
    }
}
