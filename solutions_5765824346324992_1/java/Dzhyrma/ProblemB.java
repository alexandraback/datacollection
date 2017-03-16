/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package round1a2015;

/**
 *
 * @author Andrii
 */
import qr2015.*;
import java.util.NavigableSet;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.util.Collections;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.io.FileInputStream;
import java.util.TreeSet;
import java.io.InputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.io.FileOutputStream;
import java.util.SortedSet;
import java.io.File;
import java.util.Arrays;
import java.util.Set;

public class ProblemB {

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "B-(small|large).*[.]in";
            File directory = new File(".");
            File[] candidates = directory.listFiles(new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return name.matches(regex);
                }
            });
            File toRun = null;
            for (File candidate : candidates) {
                if (toRun == null || candidate.lastModified() > toRun.lastModified()) {
                    toRun = candidate;
                }
            }
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("b.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskB solver = new TaskB();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++) {
            solver.solve(i, in, out);
        }
        out.close();
    }
}

class TaskB {

    int[] M;
    int B, N2;

    private long getN(long t) {
        long res = 0;
        for (int i = 0; i < B; i++) {
            res += t / M[i];
        }
        return res;
    }

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        B = in.readInt();
        N2 = in.readInt();
        M = new int[B];
        for (int i = 0; i < B; i++) {
            M[i] = in.readInt();
        }
        if (N2 <= B) {
            out.printLine("Case #" + testNumber + ":", N2);
            return;
        }
        int N  = N2 - B;
        long Hi = 1000000001L * 100000;
        long Lo = 1;
        while (Hi > Lo) {
            long m = (Hi + Lo) / 2;
            if (getN(m) < N) {
                Lo = m + 1;
            } else {
                Hi = m;
            }
        }
        long t = getN(Lo);
        while (getN(Lo) == t)
        {
            Lo--;
        }
        long left = getN(Lo);
        Lo++;
        for (int i = 0; i < B; i++) {
            if (Lo % M[i] == 0) {
                if (left < N - 1) {
                    left++;
                } else {
                    out.printLine("Case #" + testNumber + ":", i + 1);
                    return;
                }
            }
        }
        out.printLine("Case #" + testNumber + ":", "1");
    }
}
