import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Ex1 {
    private static String input = "A-small-attempt2.in";
    private static String output = "out.txt";
    private PrintWriter out;

    public int execute(int n, int[] sens) {
        int total = 0;
        for (int i=0; i<n; i++) total += sens[i];

        while (total > 3 || total == 2) {
            int max = 0;
            for (int j=0; j<n; j++) if (sens[max] < sens[j]) max = j;
            sens[max]--;
            total--;
            char first = (char)('A'+max);
            out.print(first);

            if (total == 3) break;
            if (total > 0) {
                max=0;
                for (int j=0; j<n; j++) if (sens[max]<sens[j]) max=j;
                char second=(char) ('A'+max);
                sens[max]--;
                total--;
                out.print(second);
            }
            out.print(" ");
        }



        if (total == 3) {
            int max = 0;
            for (int j=0; j<n; j++) if (sens[max] < sens[j]) max = j;
            sens[max]--;
            char first = (char)('A'+max);
            out.print(first+" ");

            max = 0;
            for (int j=0; j<n; j++) if (sens[max] < sens[j]) max = j;
            sens[max]--;
            first = (char)('A'+max);
            out.print(first);

            max = 0;
            for (int j=0; j<n; j++) if (sens[max] < sens[j]) max = j;
            sens[max]--;
            char second= (char)('A'+max);
            out.print(second);
            out.print(" ");
        }
        return 1;
    }



    public void runTests(Scanner input) throws FileNotFoundException {
        out = new PrintWriter(output);
        int testsNo = Integer.valueOf(input.nextLine());

        for (int i=1; i<=testsNo; i++) {
            int N = Integer.valueOf(input.nextLine());
            String[] arr = input.nextLine().split(" ");
            int[] sen = new int[arr.length];
            for (int j=0; j<sen.length; j++)
                sen[j] = Integer.valueOf(arr[j]);

            out.print("Case #"+i+": ");
            execute(N, sen);
            out.println();
        }
        out.close();
    }


    public static void main(String[] args) throws FileNotFoundException {
        Scanner file = new Scanner(new FileInputStream(input));
        new Ex1().runTests(file);
        file.close();
    }
}
