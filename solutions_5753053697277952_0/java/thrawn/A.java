package de.shadowhunt.codejam.c4314486;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class A {

    static class P implements Comparable<P> {
        int count;
        char name;
        
        P(int count, char name) {
            this.count = count;
            this.name = name;
        }

        @Override
        public int compareTo(P o) {
            int result = Integer.compare(o.count, count);
            if (result != 0) {
                return result;
            }
            return Character.compare(name, o.name);
        }

        @Override
        public String toString() {
            return "P [count=" + count + ", name=" + name + "]";
        }
        
        
    }
    
    public static void main(String[] args) throws Exception {
        solve(System.in, System.out);
    }
    
    public static void solve(final InputStream in, final PrintStream out) throws Exception {
        final BufferedReader br = new BufferedReader(new InputStreamReader(in));
        final int t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; i++) {
            int N = Integer.parseInt(br.readLine());
            final ArrayList<P> p = new ArrayList<>(N);
            String[] tmp = br.readLine().split(" ");
            for (int n = 0; n < N; n++) {
                int count = Integer.parseInt(tmp[n]);
                p.add(new P(count, (char) ('A' + n)));
            }
            
            out.print("Case #" + i + ":");
            while (p.size() > 2) {
                Collections.sort(p);
                P p2 = p.get(0);
                out.print(' ');
                out.print(p2.name);
                p2.count -= 1;
                
//                if (p2.count > 1) {
//                    out.print(p2.name);
//                    p2.count -= 1;
//                }
                
                if (p2.count == 0) {
                    p.remove(0);
                }
            }
            
            Collections.sort(p);
            
            P a = p.get(0);
            P b = p.get(1);
            if (a.count > b.count) {
                int d = a.count - b.count;
                while (d > 2) {
                    out.print(' ');
                    out.print(a.name);
                    out.print(a.name);
                    a.count -= 2;
                    d -= 2;
                }
                out.print(' ');
                out.print(a.name);
                a.count -= 1;
            }
            
            for (int j = 0; j < b.count; j++) {
                out.print(' ');
                out.print(a.name);
                out.print(b.name);
            }
            out.println();
        }
    }
}
