/*
 * CONFIDENTIAL
 * Copyright 2013 Webalo, Inc.  All rights reserved.
 */

package mahfouz.google.codejam.y2014.qual;

import java.io.File;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Solution of "Snapper Chain" problem (Qualification 2010).
 */
public final class Problem1 {

    public static void main(String[] args) throws Exception{
        Scanner s = new Scanner(new File("C:\\Users\\amahfouz\\Downloads\\cj.in"));
        PrintStream out = new PrintStream(new File("C:\\Users\\amahfouz\\Desktop\\solution.txt"));

        int numCases = s.nextInt();

        for (int i = 0; i < numCases; i++) {
            solveCase(i + 1, s, out);
        }
    }

    private static void solveCase(int caseNum, Scanner in, PrintStream out) {
        long firstAnswer = in.nextInt();

        Set<Integer> firstSet = new HashSet();

        int card;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                card = in.nextInt();
                if (i + 1 == firstAnswer) {
                    firstSet.add(card);
                }
            }
        }

        Set<Integer> secondSet = new HashSet();

        long secondAnswer = in.nextInt();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                card = in.nextInt();
                if (i + 1 == secondAnswer) {
                    secondSet.add(card);
                }
            }
        }

        Set intersection = getIntersection(firstSet, secondSet);
        int size = intersection.size();

        String result = size > 1
            ? "Bad magician!"
            : (size < 1)
                ? "Volunteer cheated!"
                : String.valueOf(intersection.iterator().next());

        outputCase(out, caseNum, result);
    }

    public static Set getIntersection(Set<Integer> set1, Set<Integer> set2) {
        boolean set1IsLarger = set1.size() > set2.size();
        Set<Integer> cloneSet = new HashSet<Integer>(set1IsLarger ? set2 : set1);
        cloneSet.retainAll(set1IsLarger ? set1 : set2);
        return cloneSet;
    }

    private static void outputCase(PrintStream out, int caseNum, String output) {
        out.println("Case #" + caseNum + ": " + output);
    }
}

