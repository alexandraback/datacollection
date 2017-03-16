/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package com.podervisual.codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;

/**
 *
 * @author osdroid
 */
public class QMagicTrick {

    private static String solve(BufferedReader reader) throws Exception {
        int row = Integer.parseInt(reader.readLine()) - 1;
        boolean[] availableOptions = new boolean[16];
        for (int i = 0; i < 4; i++) {
            String line = reader.readLine();
            if (i == row) {
                String[] pieces = line.split(" ");
                for (int j = 0; j < 4; j++) {
                    availableOptions[Integer.parseInt(pieces[j]) - 1] = true;
                }
            }
        }
        row = Integer.parseInt(reader.readLine()) - 1;
        int count = 0;
        String match = null;
        for (int i = 0; i < 4; i++) {
            String line = reader.readLine();
            if (i == row) {
                String[] pieces = line.split(" ");
                for (int j = 0; j < 4; j++) {
                    if (availableOptions[Integer.parseInt(pieces[j]) - 1]) {
                        count++;
                        match = pieces[j];
                    }
                }
            }
        }
        switch (count) {
            case 0:
                return "Volunteer cheated!";
            case 1:
                return match;
            default:
                return "Bad magician!";
        }
    }
    private static void solve(String filename) throws Exception {
        BufferedReader reader = new BufferedReader(
                new InputStreamReader(new FileInputStream(filename + ".in")));
        PrintStream writer = new PrintStream(new File(filename + ".out"));
        int numCases = Integer.parseInt(reader.readLine());
        for (int i = 0; i < numCases; i++) {
            writer.println(String.format("Case #%d: %s", i + 1, solve(reader)));
        }
        writer.close();
    }
    
    public static void main(String[] args) throws Exception {
        System.out.println("File?: ");
        BufferedReader lector = new BufferedReader(
                new InputStreamReader(System.in));
        String filename = lector.readLine();
        solve(filename);
    }
    
}
