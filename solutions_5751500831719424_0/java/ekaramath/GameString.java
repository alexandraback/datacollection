package codejamb;


import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ehsan
 */
public class GameString {
    public void Solve(String fname) throws FileNotFoundException, IOException {
        Scanner sc = new Scanner(new File(fname));
        FileWriter fw = new FileWriter("/home/ehsan/result.txt");
        int T = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < T; i++) {
            int N = Integer.parseInt(sc.nextLine());
            String[] s = new String[N];
            for (int n = 0; n < N; n++) s[n] = sc.nextLine();            
            int moves = minMoves(s);
            if (moves == -1) {
                fw.write("Case #" + (i + 1) + ": " + "Fegla Won" + "\n");
            }
            else {
                fw.write("Case #" + (i + 1) + ": " + moves + "\n");
            }
        }
        fw.close();
    }
    int minMoves(String[] s) {
        int nmoves = 0;
        int[] p = new int[s.length];
        while (true) {
            int[] sizes = new int[s.length];            
            ArrayList<char[]> runs = new ArrayList<>();
            for (int i = 0; i < s.length; i++) {
                char[] run = nextRun(s[i], p[i]);                
                runs.add(run);
                if (run != null) sizes[i] = run.length;
            }
            if (sizes[0] > 0) {
                char c = runs.get(0)[0];
                for (int j = 1; j < s.length; j++) {
                    if (runs.get(j) == null) return -1;
                    if (runs.get(j)[0] != c) return -1;
                }
            }
            // verify
            boolean one_ends = false, all_ends = true;
            for (int i = 0; i < s.length; i++) {
                if (sizes[i] == 0) one_ends = true;
                else all_ends = false;
            }
            if (one_ends && !all_ends) return -1;
            if (all_ends) return nmoves;
            Arrays.sort(sizes);
            int median_index = sizes.length / 2;
            int tlen = sizes[median_index];
            for (int i = 0; i < sizes.length; i++) {
                nmoves += Math.abs(sizes[i] - tlen);
                p[i] = p[i] + runs.get(i).length;
            }
        }
    }
    
    
    char[] nextRun(String s, int pos) {
        if (pos == s.length()) return null;
        ArrayList<Character> r = new ArrayList<>();
        r.add(s.charAt(pos++));
        if (pos < s.length()) {
            while (s.charAt(pos) == r.get(0)) {
                r.add(s.charAt(pos++));
                if (pos == s.length()) break;
            }
        }
        char[] c = new char[r.size()];
        for (int i = 0; i < c.length; i++) c[i] = r.get(i);
        return c;
    }
}

