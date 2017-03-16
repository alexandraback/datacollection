
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author ahmad
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    static long a, b, N;
    static long ns[] = new long[1 << 80];

    public static void main(String[] args) throws FileNotFoundException {
        // TODO code application logic here
        Scanner input = new Scanner(new File("input.in"));
        PrintWriter out=new PrintWriter(new File("out"));
        int tc = input.nextInt();
        for (int j = 0; j < tc; j++) {
            a = input.nextInt();
            b = input.nextInt();
            N = input.nextInt();
            long best = a * b * N * 100;
            for (int i = 1; i < (1 << 10000); i++) {
                ns[i] = ns[i - (i & -i)] + 1;
                if (ns[i] == N) {
                    best = Math.min(best, xx(i));
                }
            }
            out.printf("Case #%d: %d\n", (j+1), best);
        }
        out.close();
    }

    static int xx(int i) {
        int answer = 0;
        for (int r = 0; r < a; r++) {
            for (int c = 0; c < b; c++) {
                if (c > 0
                        & (i & (1 << (r * b + c))) > 0
                        && (i & (1 << (r * b + c - 1))) > 0) {
                    answer++;
                }
                if (r > 0 && (i & (1 << (r * b + c))) > 0 && (i & (1 << (r * b + c - b))) > 0) {
                    answer++;
                }
            }
        }
        return answer;
    }
}
