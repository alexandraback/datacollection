import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Logging {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(new File("C-input.in"));
                BufferedWriter bw = new BufferedWriter(new FileWriter(new File(
                        "C-output.out")))) {
            
            int t = sc.nextInt();
            for (int i = 0; i < t; i++) {
                long n = sc.nextInt();
                List<Integer> xList = new ArrayList<>();
                List<Integer> yList = new ArrayList<>();
                for (int j = 0; j < n; j++) {
                    xList.add(sc.nextInt());
                    yList.add(sc.nextInt());
                    
                }
                System.out.println("Case #" + (i + 1) + ":");
                bw.write("Case #" + (i + 1) + ":");
                bw.newLine();
                for (int j = 0; j < n; j++) {
                    int answer = solve(xList, yList, xList.get(j),
                            yList.get(j));
                    bw.write(String.valueOf(answer));
                    bw.newLine();
                    System.out.println(answer);
                }
            }
            bw.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    private static int solve(List<Integer> xList, List<Integer> yList,
            int x, int y) {
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < xList.size(); i++) {
            int thisX = xList.get(i);
            int thisY = yList.get(i);
            if (x == thisX && y == thisY) {
                continue;
            }
            float a = (float) (thisY - y) / (float) (thisX - x);
            int big = 0;
            int small = 0;
            for (int j = 0; j < xList.size(); j++) {
                int thatX = xList.get(j);
                int thatY = yList.get(j);
                if (thatX == thisX && thatY == thisY) {
                    continue;
                }
                if (thatX == x && thatY == y) {
                    continue;
                }
                float newY = a * (thatX - x) + y;
                if (thatY > newY) {
                    big++;
                } else if (thatY < newY) {
                    small++;
                }
            }
            min = Math.min(min, Math.min(big, small));
            
        }
        if (min == Integer.MAX_VALUE) {
            return 0;
        }
        return min;
        
    }
    
}
