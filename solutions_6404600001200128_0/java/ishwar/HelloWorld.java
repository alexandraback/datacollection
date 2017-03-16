package com.example;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

import static java.util.Arrays.deepToString;

public class HelloWorld {


    static PrintWriter out = null;
    static FileInputStream in = null;
    Scanner sc;

    int N;
    List<Integer> list;

    static <K, V extends Comparable<? super V>> SortedSet<Map.Entry<K, V>> entriesSortedByValues(Map<K, V> map) {
        SortedSet<Map.Entry<K, V>> sortedEntries = new TreeSet<Map.Entry<K, V>>(new Comparator<Map.Entry<K, V>>() {
            public int compare(Map.Entry<K, V> e1, Map.Entry<K, V> e2) {
                int res = e1.getValue().compareTo(e2.getValue());
                return res != 0 ? res : 1;
            }
        });
        sortedEntries.addAll(map.entrySet());
        return sortedEntries;
    }

    void read() {
        list = new ArrayList<Integer>();
        N = sc.nextInt();

        for (int i = 1; i <= N; i++) {
            list.add(sc.nextInt());
        }
    }

    void solve() {
        int ans_a = 0, ans_b = 0, last = 0, max_rate = 0;
        for (Integer i : list) {
            if (i < last) {
                ans_a += last - i;
                if (last - i > max_rate) {
                    max_rate = last - i;
                }
            }
            last = i;
        }
        last = 0;

        for (Integer i : list) {
            if (last < max_rate) {
                ans_b += last;
            } else {
                ans_b += max_rate;
            }
            last = i;
        }


        out.println(ans_a + " " + ans_b);
        System.out.println(ans_a + " " + ans_b);
    }

    void run() {
        try {
            in = new FileInputStream("src/com/resources/smallInput.txt");
            out = new PrintWriter("src/com/resources/output.txt");
        } catch (FileNotFoundException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
        sc = new Scanner(in);
        int caseN = sc.nextInt();
        for (int caseID = 1; caseID <= caseN; caseID++) {
            read();
            out.printf("Case #%d: ", caseID);
            System.out.printf("Case #%d: ", caseID);
            solve();
            System.out.flush();
        }
        out.close();
    }

    void debug(Object... os) {
        System.err.println(deepToString(os));
    }

    public static void main(String[] args) {
        try {
            System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (HelloWorld.class.getName() + ".in"))));
        } catch (Exception e) {
        }
        new HelloWorld().run();
    }

    private static long gcd(long a, long b) {
        while (b > 0) {
            long temp = b;
            b = a % b; // % is remainder
            a = temp;
        }
        return a;
    }

    private static long lcm(long a, long b) {
        return (a * (b / gcd(a, b)));
    }
}
