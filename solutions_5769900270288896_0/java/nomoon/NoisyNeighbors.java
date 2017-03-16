import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by noMoon on 2015-05-02.
 */
public class NoisyNeighbors {

    public static void main(String[] args) throws IOException {
//        System.out.println(reverse(19));

        File file = new File("B-small-attempt2.in.txt");
//        File file = new File("NoisyNeighbors.in");
        File outputFile = new File("NoisyNeighbors.out");
        BufferedWriter bw = new BufferedWriter(new FileWriter(outputFile));
        BufferedReader br = new BufferedReader(new InputStreamReader(
                new FileInputStream(file)));
        int numberOfTestCases = Integer.valueOf(br.readLine());
        int count = 0;
        while (count++ < numberOfTestCases) {
            String line = br.readLine();
            String[] params = line.split(" ");
            int R = Integer.valueOf(params[0]);
            int C = Integer.valueOf(params[1]);
            int n = Integer.valueOf(params[2]);
            int number = R * C;
            if (R % 2 == 0 && C % 2 == 0) {
                if (n <= number / 2) {
                    bw.write("Case #" + String.valueOf(count) + ": 0");
                    bw.newLine();
                } else if (n <= number / 2 + 2) {
                    bw.write("Case #" + String.valueOf(count) + ": " + String.valueOf((n - number / 2) * 2));
                    bw.newLine();
                } else if (n <= number / 2 + R + C - 2) {
                    bw.write("Case #" + String.valueOf(count) + ": " + String.valueOf(4 + (n - number / 2 - 2) * 3));
                    bw.newLine();
                } else {
                    int numberOfTwo = 4;
                    int numberOfThree = (R + C - 4) * 3;
                    int numberOfFour = (n - (number / 2 + R + C - 2)) * 4;
                    int total = numberOfTwo + numberOfThree + numberOfFour;
                    bw.write("Case #" + String.valueOf(count) + ": " + String.valueOf(total));
                    bw.newLine();
                }
            } else if (R == 1 || C == 1) {
                if (number % 2 == 1) {
                    if (n <= number / 2 + 1) {
                        bw.write("Case #" + String.valueOf(count) + ": 0");
                        bw.newLine();
                    }else{
                        bw.write("Case #" + String.valueOf(count) + ": "+String.valueOf((n - number / 2-1) * 2));
                        bw.newLine();
                    }
                } else {
                    if (n <= number / 2) {
                        bw.write("Case #" + String.valueOf(count) + ": 0");
                        bw.newLine();
                    }else if (n <= number / 2 + 1) {
                        bw.write("Case #" + String.valueOf(count) + ": 1");
                        bw.newLine();
                    }else{
                        bw.write("Case #" + String.valueOf(count) + ": "+String.valueOf((n - number / 2-1) * 2+1));
                        bw.newLine();
                    }
                }


            } else if (number % 2 == 1) {
                if (n <= number / 2 + 1) {
                    bw.write("Case #" + String.valueOf(count) + ": 0");
                    bw.newLine();
                } else if (n == R * (C / 2 + 1) + (R / 2 + 1) * (C / 2)) {
                    bw.write("Case #" + String.valueOf(count) + ": " + String.valueOf(R * (C - 1) + C * (R - 1) - 4 * (R / 2 * (C / 2))));
                    bw.newLine();
                } else if (n <= number / 2 + 1 + R / 2 * 2 + C / 2 * 2) {
                    bw.write("Case #" + String.valueOf(count) + ": " + String.valueOf((n - number / 2 - 1) * 3));
                    bw.newLine();
                } else {
                    int numberOfThree = (R / 2 * 2 + C / 2 * 2) * 3;
                    int numberOfFour = (n - (number / 2 + 1 + R / 2 * 2 + C / 2 * 2)) * 4;
                    int total = numberOfThree + numberOfFour;
                    bw.write("Case #" + String.valueOf(count) + ": " + String.valueOf(total));
                    bw.newLine();
                }
            } else {
                int odd, even;
                if (R % 2 == 1) {
                    odd = R;
                    even = C;
                } else {
                    odd = C;
                    even = R;
                }
                int numberOfThree = even - 2 + odd / 2 * 2 - 1;
                if (n <= number / 2) {
                    bw.write("Case #" + String.valueOf(count) + ": 0");
                    bw.newLine();
                } else if (n <= number / 2 + 2) {
                    bw.write("Case #" + String.valueOf(count) + ": " + String.valueOf((n - number / 2) * 2));
                    bw.newLine();
                } else if (n <= number / 2 + 2 + numberOfThree) {
                    bw.write("Case #" + String.valueOf(count) + ": " + String.valueOf(4 + (n - number / 2 - 2) * 3));
                    bw.newLine();
                } else {
                    int noiseOfTwo = 4;
                    int noiseOfThree = numberOfThree * 3;
                    int noiseOfFour = (n - (number / 2 + 2 + numberOfThree)) * 4;
                    int total = noiseOfTwo + noiseOfThree + noiseOfFour;
                    bw.write("Case #" + String.valueOf(count) + ": " + String.valueOf(total));
                    bw.newLine();
                }
            }
        }

        bw.close();
        br.close();
    }
}
