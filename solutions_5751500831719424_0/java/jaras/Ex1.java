package jaras.codejam2014_1b;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Ex1 {

    private static final Logger LOG = Logger.getLogger(Ex1.class.getName());

    public static void main(String[] args) {

        String dir = System.getProperty("user.home") + "\\Downloads\\";

        File in;
        File out;

        int type = 1;

        if (type == 1) {
            in = new File(dir + "A-small-attempt0.in");
            out = new File(dir + "A-small-attempt0-output.out");
        } else {
            in = new File(dir + "1-large.in");
            out = new File(dir + "1-large-output.out");
        }

        FileInputStream is = null;
        FileOutputStream os = null;

        try {
            is = new FileInputStream(in);
            os = new FileOutputStream(out);
            entryPoint(is, os);
        } catch (FileNotFoundException ex) {
            LOG.log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            LOG.log(Level.SEVERE, null, ex);
        } finally {
            if (is != null) {
                try {
                    is.close();
                } catch (IOException ex) {
                    LOG.log(Level.SEVERE, null, ex);
                }
            }
            if (os != null) {
                try {
                    os.close();
                } catch (IOException ex) {
                    LOG.log(Level.SEVERE, null, ex);
                }
            }
        }
    }

    public static void entryPoint(InputStream is, OutputStream os) throws
            UnsupportedEncodingException, IOException {
        Scanner s = new Scanner(is);
        int cases = s.nextInt();
        for (int testCase = 0; testCase < cases; testCase++) {
            int strings = s.nextInt();
            String[] words = new String[strings];
            for (int i = 0; i < strings; i++) {
                words[i] = s.next();
            }
            String out = solve(testCase, strings, words);
            os.write(out.getBytes("UTF-8"));
        }

    }

    public static String solve(int tc, int n, String[] words) {

        int length = -1;
        boolean solvable = true;

        Seq[] seqs = new Seq[words.length];
        for (int i = 0; i < words.length; i++) {
            seqs[i] = convert(words[i]);
            if (length == -1) {
                length = seqs[i].size();
            } else if (length != seqs[i].size()) {
                solvable = false;
                break;
            }
        }

        int mods = 0;
        for (int i = 0; i < length && solvable; i++) {
            char ch = ' ';
            int[] counts = new int[seqs.length];
            for (int s = 0; s < seqs.length; s++) {
                counts[s] = seqs[s].get(i).count;
                if (s == 0) {
                    ch = seqs[s].get(i).ch;
                } else if (ch != seqs[s].get(i).ch) {
                    solvable = false;
                    break;
                }
            }
            mods += minModsNeeded(counts);
        }

        String result = solvable ? String.valueOf(mods) : "Fegla Won";
        return "Case #" + (tc + 1) + ": " + result + "\n";
    }

    static class Seq extends ArrayList<StringSeq> {
    };

    static Seq convert(String s) {
        Seq seq = new Seq();
        StringSeq currentStringSeq = null;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (currentStringSeq == null) {
                currentStringSeq = new StringSeq(ch);
                seq.add(currentStringSeq);
            } else if (ch == currentStringSeq.ch) {
                currentStringSeq.add();
            } else {
                currentStringSeq = new StringSeq(ch);
                seq.add(currentStringSeq);
            }
        }
        return seq;
    }

    static int minModsNeeded(int[] counts) {
        int minMods = Integer.MAX_VALUE;
        for (int i = 0; i < counts.length; i++) {
            int target = counts[i];
            int mods = 0;
            for (int j = 0; j < counts.length; j++) {
                mods += Math.abs(target - counts[j]);
            }
            if (mods < minMods) {
                minMods = mods;
            }
        }
        return minMods;
    }

    static class StringSeq {

        public StringSeq(char ch) {
            this.ch = ch;
            this.count = 1;
        }

        int count;
        char ch;

        public void add() {
            count++;
        }
    }
}
