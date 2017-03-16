import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

/**
 * Created by david on 5/8/16.
 */
public class Senators {
    public static void main(String[] args) {
        new Senators();
    }

    public Senators() {
        try {
            Scanner sc = new Scanner(System.in);
            PrintWriter pw = new PrintWriter("solution.txt", "UTF-8");

            int T = sc.nextInt();
            sc.nextLine();
            for (int i = 1; i <= T; ++i) {
                pw.print(String.format("Case #%d:", i));
                run(sc, pw);
            }
            pw.close();
        } catch (FileNotFoundException | UnsupportedEncodingException e) {
            e.printStackTrace();
        }
    }

    protected void run(Scanner scanner, PrintWriter writer) {
        int parties = scanner.nextInt();
        int[] senators = new int[parties];
        int count = 0;
        for (int i = 0; i < parties; ++i) {
            senators[i] = scanner.nextInt();
            count += senators[i];
        }

        while (count != 0) {
            int max = 0;
            int second = 0;
            for (int i = 0; i < parties; ++i) {
                if (senators[max] <= senators[i]) {
                    second = max;
                    max = i;
                }
            }

            if (senators[max] == senators[second] && count != 1) {
                if(senators[max] == 1 && count == 3){

                } else {
                    writer.print(" " + Character.toString((char) (max + 65)) + Character.toString((char) (65 + second)));
                    --senators[max];
                    --senators[second];
                    count -= 2;
                    continue;
                }
            }
            writer.print(" " + ((char) (65 + max)));
            --senators[max];
            --count;

        }

        writer.println();
    }
}
