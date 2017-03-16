/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package round1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

/**
 *
 * @author ozdemir
 */
public class partA {

    public static void main(String argv[]) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.txt"));
        PrintStream out = new PrintStream(new File("output.txt"));

        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            int N = in.nextInt();
            String arr[] = new String[N];
            for (int j = 0; j < N; j++) {
                arr[j] = in.next();
            }

            out.println("Case #" + (i + 1) + ": " + process(arr));
        }
    }

    private static String process(String arr[]) {
        int N = arr.length;

        String unique[] = new String[N];
        int counter[][] = new int[N][100];
        for (int i = 0; i < N; i++) {
            int size = 0;
            char ch = arr[i].charAt(0);
            unique[i] = Character.toString(ch);
            counter[i][size] = 1;
            for (int j = 1; j < arr[i].length(); j++) {
                if (ch != arr[i].charAt(j)) {
                    ch = arr[i].charAt(j);
                    counter[i][++size] = 1;
                    unique[i] += ch;
                } else {
                    counter[i][size]++;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (!unique[i].equals(unique[j])) {
                    return "Fegla Won";
                }
            }
        }

        int result = 0;
        for (int i = 0; i < 100; i++) {
            if (counter[0][i] > 0) {
                int best = Integer.MAX_VALUE;
                for (int j = 0; j <= 100; j++) {
                    int curr = 0;
                    for (int k = 0; k < N; k++) {
                        curr += Math.abs(j - counter[k][i]);
                    }
                    if (curr < best) {
                        best = curr;
                    }
                }
                result += best;
            } else {
                break;
            }
        }
        return Integer.toString(result);
    }

}
