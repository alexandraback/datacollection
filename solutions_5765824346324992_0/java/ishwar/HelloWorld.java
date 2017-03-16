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

    int N, pos, fastest;
    Map<Integer, Integer> map;
    SortedSet<Map.Entry<Integer, Integer>> entries;

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
        fastest = -1;
        map = new TreeMap<Integer, Integer>();

        N = sc.nextInt();
        pos = sc.nextInt();

        for (int i = 1; i <= N; i++) {
            map.put(i, sc.nextInt());
            if(fastest == -1 || map.get(i) <= map.get(fastest)) fastest = i;
        }

        entries = entriesSortedByValues(map);
//        System.out.println(entries);
    }

    void solve() {
        Map<Integer, Integer> summation = new HashMap<Integer, Integer>();
        int i = 0;
        int prev = 1;
        int highest = 0;

        for (Map.Entry<Integer, Integer> entry : entries) {
            i++;
            if (i == 1) {
                summation.put(entry.getKey(), entry.getValue());
                prev = entry.getValue();
            } else {
                summation.put(entry.getKey(), lcm(prev, entry.getValue()));
                prev = summation.get(entry.getKey());
            }
            if (summation.get(entry.getKey()) > highest) {
                highest = summation.get(entry.getKey());
            }
        }

        int devide = 0;
        for (i = 1; i <= N; i++) {
            devide += highest/map.get(i);
        }

        pos = pos % devide;
        if (pos == 0) {
            out.println(fastest);
            System.out.println(fastest);
            return;
        }

        Map<Integer, Integer> barbers = new HashMap<Integer, Integer>();

        for (i = 1; i <= N; i++) {
            barbers.put(i, 0);
        }

        int min;
        while (pos > 0) {
            for (i = 1; i <= N; i++) {
                if (barbers.get(i) == 0) {
                    pos--;
                    barbers.put(i, map.get(i));

                    if (pos == 0) {
                        out.println(i);
                        System.out.println(i);
                        return;
                    }
                }
            }

            min = Collections.min(barbers.values());
            for (i = 1; i <= N; i++) {
                barbers.put(i, barbers.get(i) - min);
            }
        }
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

    private static int lcm(long a, long b) {
        return (int) (a * (b / gcd(a, b)));
    }
}
