
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Madi
 */
public class CodeJam3_A {

    private static char[] c = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    public static void main(String[] args) throws FileNotFoundException, IOException {
        try (BufferedReader br = new BufferedReader(new FileReader("C:/Users/Madi/codejam/A-small-practice.in"));
                BufferedWriter bw = new BufferedWriter(new FileWriter("C:/Users/Madi/codejam/A-small-practice.out"))) {

            int t = Integer.parseInt(br.readLine());

            for (int i = 0; i < t; i++) {
                int n = Integer.parseInt(br.readLine());
                String[] s = br.readLine().split(" ");
                Party[] p = new Party[s.length];
                for (int j = 0; j < s.length; j++) {
                    p[j] = new Party(Integer.parseInt(s[j]), j);
                }
                solve(i + 1, n, p, bw);
            }

        }

    }

    private static void solve(int cs, int n, Party[] p, BufferedWriter bw) throws FileNotFoundException, IOException {

        bw.write("Case #" + cs + ": ");

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += p[i].n;
        }
        while (sum > 0) {

            Arrays.sort(p);

            
            if (p[n - 1].n == p[n - 2].n && (sum > 3 || sum == 2)) {
                bw.write(c[p[n - 1].index] + "" + c[p[n - 2].index] + " ");
                p[n - 1].n--;
                p[n - 2].n--;
            } else {
                bw.write(c[p[n - 1].index] + " ");
                p[n - 1].n--;
            }

            sum = 0;
            for (int i = 0; i < n; i++) {
                sum += p[i].n;
            }
        }
        bw.write("\n");
        bw.flush();
    }
}

class Party implements Comparable<Party> {

    int n;
    int index;

    public Party(int n, int index) {
        this.n = n;
        this.index = index;
    }

    @Override
    public int compareTo(Party o) {
        return n - o.n;
    }

}
