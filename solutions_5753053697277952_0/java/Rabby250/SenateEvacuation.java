package com.rabby250.codejam;

import java.util.Comparator;
import java.util.PriorityQueue;

public class SenateEvacuation implements Comparator<SenateEvacuation.Party> {

    @Override
    public int compare(Party o1, Party o2) {
        if (o1.count > o2.count) return -1;
        else if (o1.count == o2.count) return 0;
        else return 1;
    }

    static class Party {
        public char name;
        public int count;
    }

    public String solve(int[] counts) {
        return counts.length == 2 ? solve2(counts) : solveN(counts);
    }

    public String solveN(int[] counts) {
        final PriorityQueue<Party> q
                = new PriorityQueue<>(counts.length, this);
        int total = 0;
        for (int i = 0; i < counts.length; i++) {
            Party p = new Party();
            p.name = (char) (65 + i);
            p.count = counts[i];
            q.add(p);
            total += counts[i];
        }
        final StringBuilder sb = new StringBuilder(52000);
        for (int i = 0; i < total - 2; i++) {
            Party p = q.poll();
            sb.append(p.name).append(' ');
            p.count = p.count - 1;
            q.add(p);
        }
        sb.append(q.poll().name).append(q.poll().name);
        return sb.toString();
    }

    public String solve2(int[] counts) {
        StringBuilder sb = new StringBuilder();
        while (counts[0] > counts[1]) {
            sb.append('A').append(' ');
            counts[0]--;
        }
        while (counts[1] > counts[0]) {
            sb.append('B').append(' ');
            counts[1]--;
        }
        while (counts[0] > 0) {
            sb.append('A').append('B').append(' ');
            counts[0]--;
        }
        sb.setLength(sb.length() - 1);
        return sb.toString();
    }
}
