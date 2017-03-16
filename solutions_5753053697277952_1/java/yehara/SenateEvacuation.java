package gcj2016.r1;

import java.io.*;
import java.util.Scanner;

public class SenateEvacuation {
    
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        String name = "gcj2016/r1/A-large";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        //out = new PrintWriter(System.out);
        for (int cc = 1; cc <= count; cc++) {
            out.print("Case #" + cc + ": ");
            int n = s.nextInt();
            int[] a = new int[26];
            int sum = 0;
            for(int i=0; i<n; i++) {
                a[i] = s.nextInt();
                sum += a[i];
            }
            solve(a, sum);
            out.println();
        }
        out.close();
    }

    static void solve(int[] a, int sum) {
        while(sum > 2) {
            if(sum % 2 == 0) {
                int h = sum / 2;
                for(int i=0; i<26; i++) {
                    if(a[i] == h) {
                        a[i]--;
                        sum--;
                        out.print((char)('A' + i));
                    }
                }
                if(sum < h * 2) {
                    out.print(" ");
                    continue;
                }
            }
            int max = 0;
            int maxi = 0;
            char maxc = 'A';
            for(int i=0; i<26; i++) {
                if(max < a[i]) {
                    max = a[i];
                    maxi = i;
                    maxc = (char)('A' + i);
                }
            }
            a[maxi]--;
            sum--;
            out.print(maxc);
            out.print(" ");
        }
        for(int i=0; i<26; i++) {
            if(a[i] > 0) out.print((char)('A' + i));
        }
    }

}
