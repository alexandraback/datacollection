import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        File file = new File("dataset");
        Scanner sc = null;
        try {
            sc = new Scanner(file);
            int cases = sc.nextInt();
            String string = sc.nextLine();

            for (int i = 1; i <= cases; i++) {
                System.out.print("Case #" + i + ": ");
                int N = sc.nextInt();
                int[] scenators = new int[N];
                for (int j = 0; j < N; j++)
                    scenators[j] = sc.nextInt();
                char A = 'A';
                while (!done(scenators)) {
                    int removed = 0;

                    for (int j = 0; j < N; j++) {
                        for (int k = j; k < N; k++) {
                            if (scenators[j] > 0 && scenators[k] > 0) {
                                scenators[j]--;
                                scenators[k]--;
                            } else
                                continue;

                            if (!majorityOk(scenators)) {
                                scenators[j]++;
                                scenators[k]++;
                            } else {
                                System.out.print(" " + (char)(A+j));
                                System.out.print((char)(A+k));
                                removed += 2;
                            }
                            if (removed == 2)
                                break;
                        }
                    }

                    for (int j = 0; j < N; j++) {
                        if (scenators[j] > 0)
                            scenators[j]--;
                        else
                            continue;
                        if (!majorityOk(scenators))
                            scenators[j]++;
                        else {
                            System.out.print(" " + (char)(A+j));
                            removed++;
                        }

                        if (removed > 0)
                            break;
                    }
                }
                System.out.println();
            }
        } catch (FileNotFoundException e) {
            System.out.println("File not found");
        }

    }

    public static boolean done(int[] scenators) {
        for (int sc : scenators) {
            if (sc > 0) {
                return false;
            }
        }

        return true;
    }

    public static boolean majorityOk(int[] scenators) {
        int sum = sum(scenators);

        for (int sc : scenators) {
            if (sc != 0 && sum / sc < 2)
                return false;
        }
        return true;
    }

    public static int sum(int[] scenators) {
        int sum = 0;

        for (int sc : scenators)
            sum += sc;

        return sum;
    }

}
