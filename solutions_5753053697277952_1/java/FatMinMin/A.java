package r1c;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 * Created by fatminmin on 5/8/16.
 */
public class A {
//    Scanner sc = new Scanner(System.in);
//    PrintWriter pw = new PrintWriter(System.out);
    Scanner sc = new Scanner(new File("r1c_tc/A-large.in"));
    PrintWriter pw = new PrintWriter("r1c_tc/A-large.out");
    public A() throws FileNotFoundException {
    }

    private void solve() {
        int n = sc.nextInt();
        int[] p = new int[n];
        int[] cur = new int[n];
        for(int i = 0; i < n; i++) {
            p[i] = sc.nextInt();
        }
        int curSum = 0;
        List<String> ans = new ArrayList<>();
        while(true) {
            // try two
            int tmp = curSum + 2;
            int a = -1, b = -1;
            int i = 0;
            while(i < n) {
                if(p[i] > 0 && cur[i] + 1 <= tmp / 2) {
                    cur[i]++;
                    p[i]--;
                    if(a == -1) a = i;
                    else b = i;
                } else {
                    i++;
                }
                if(a != -1 && b != -1) break;
            }
            if(a != -1 && b != -1) {
                String pair = String.valueOf((char)('A' + a)) + String.valueOf((char)('A' + b));
                ans.add(pair);
                curSum += 2;
                continue;
            } else if(a != -1) {
                cur[a]--;
                p[a]++;
            }
            // try one
            tmp = curSum + 1;
            a = -1;
            i = 0;
            while(i < n) {
                if(p[i] > 0 && cur[i] + 1 <= tmp / 2) {
                    cur[i]++;
                    p[i]--;
                    a = i;
                    break;
                }
                i++;
            }
            if(a != -1) {
                ans.add(String.valueOf((char)('A' + a)));
                curSum += 1;
            } else {
                break;
            }
        }
        Collections.reverse(ans);
        pw.println(String.join(" ", ans));
    }

    public void run() {
        int t = sc.nextInt();
        for(int cs = 1; cs <= t; cs++) {
            pw.print(String.format("Case #%d: ", cs));
            solve();
        }
        pw.flush();
    }

    public static void main(String[] args) throws FileNotFoundException {
        new A().run();
    }
}
