import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        PrintWriter writer = new PrintWriter(new FileWriter("answer.txt"));

        for (int nt = 1; nt <= T; nt++) {
            int[] possible = new int[20];
            int np = 0;
            int pos = 0;
            int answer1 = in.nextInt();
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    int t = in.nextInt();
                    if ((i+1) == answer1) {
                        possible[t] = 1;
                    }
                }
            }

            int answer2 = in.nextInt();
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    int t = in.nextInt();
                    if ((i+1)==answer2) {
                        if (possible[t] != 0) {
                            np = np+1;
                            pos = t;
                        }
                    }
                }
            }

            writer.print("Case #" + nt + ": ");
            if (np > 1) {
                writer.println("Bad magician!");
            } else if (np == 0) {
                writer.println("Volunteer cheated!");
            } else if (np == 1) {
                writer.println(pos);
            }
        }

        writer.close();
    }
}
