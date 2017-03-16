import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line = stdin.readLine();
        int T = Integer.parseInt(line);
        
        for (int t = 1; t <= T; t++) {
            line = stdin.readLine();
            String[] prms = line.split(" ");
            int b = Integer.parseInt(prms[0]);
            int n = Integer.parseInt(prms[1]);
            
            Barber[] barber = new Barber[b];
            PriorityQueue<Barber> q = new PriorityQueue<Barber>();
            
            line = stdin.readLine();
            prms = line.split(" ");
            barber[0] = new Barber(1, Integer.parseInt(prms[0]));
            q.offer(barber[0]);
            int l = barber[0].m;
            for (int i = 1; i < b; i++) {
                barber[i] = new Barber(i+1, Integer.parseInt(prms[i]));
                q.offer(barber[i]);
                l = lcm(l, barber[i].m);
            }
            
            int o = 0;
            for (int i = 0; i < b; i++) {
                o += l / barber[i].m;
            }
            
            int p = n % o;
            if (p == 0) p = o;
            int r = 0;
            int ans = 0;
            
            while (true) {
                Barber b1 = q.poll();
                r++;
                //System.out.println(b1.id+" : "+n+", "+o+", "+r+", "+p);
                if (r >= p) {
                    ans = b1.id;
                    break;
                }
                b1.t += b1.m;
                q.offer(b1);
            }
            
            System.out.printf("Case #%d: %d\n", t, ans);
        }
    }
    static public int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);
    }
    static public int lcm(int a, int b){
        return a * b / gcd(a, b);
    }
}

class Barber implements Comparable<Barber> {
    int id;
    int m;
    int t;
    public Barber(int id, int m) {
        this.id = id;
        this.m = m;
        t = 0;
    }
    public int compareTo(Barber b) {
        if (t == b.t) {
            return id - b.id;
        } else {
            return t - b.t;
        }
    }
}

