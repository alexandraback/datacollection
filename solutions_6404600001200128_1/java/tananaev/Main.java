package com.mycompany.r1ap1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {
    
    public static int solve1(int[] history) {
        int r = 0;
        int x = history[0];
        for (int i = 1; i < history.length; i++) {
            if (history[i] < x) {
                r += x - history[i];
            }
            x = history[i];
        }
        return r;
    }
    
    public static double getRate(int[] history) {
        double rate = 0;
        for (int i = 1; i < history.length; i++) {
            if (history[i] < history[i-1]) {
                double r = (history[i-1] - history[i]) / 10.0;
                if (r > rate) {
                    rate = r;
                }
            }
        }
        return rate;
    }
    
    public static int solve2(int[] history) {
        double rate = getRate(history);
        
        int r = 0;
        int x = history[0];
        for (int i = 1; i < history.length; i++) {
            r += Math.min(x, (int) (rate * 10));
            x = history[i];
        }

        return r;
    }
    
    public static void main(String[] args) {
        
        try {
            BufferedReader br = new BufferedReader(new FileReader("input.txt"));
            PrintWriter writer = new PrintWriter("output.txt");
            int count = Integer.valueOf(br.readLine());
            
            for (int ii = 0; ii < count; ii++) {
                br.readLine();
                String line = br.readLine();
                String[] tmp = line.split(" ");
                int[] history = new int[tmp.length];
                
                for (int i = 0; i < tmp.length; i++) {
                    history[i] = Integer.valueOf(tmp[i]);
                }
                
                //System.out.println("Case #" + (ii+1) + ": " + solve1(history) + " " + solve2(history));
                writer.println("Case #" + (ii+1) + ": " + solve1(history) + " " + solve2(history));
            }
            
            br.close();
            writer.close();
        } catch (IOException e) {
            System.err.println(e.getMessage());
        }
    }
    
}
