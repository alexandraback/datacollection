package com.mycompany.r1ap2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {
    
    public static int solveSmall(long line, long[] barbers) {
        
        if (line == 0) {
            return 1;
        }
        
        long[] times = new long[barbers.length];
        for (int i = 0; i < barbers.length; i++) {
            times[i] = 0;
        }
        
        while (true) {
            long nextTime = Long.MAX_VALUE;
            int nextBarber = 0;
            
            // find
            for (int i = 0; i < times.length; i++) {
                if (times[i] == 0) {
                    nextTime = 0;
                    nextBarber = i;
                    break;
                } else {
                    if (times[i] < nextTime) {
                        nextTime = times[i];
                        nextBarber = i;
                    }
                }
            }
            if (line % 1000000 == 0) {
                System.out.println("line: " + line);
            }
            
            // time
            if (nextTime != 0) for (int i = 0; i < times.length; i++) {
                times[i] -= nextTime;
            }
            
            // seat
            times[nextBarber] = barbers[nextBarber];
            line -= 1;
            
            // done
            if (line == 0) {
                return nextBarber + 1;
            }
        }
    }
    
    private static long gcd(long a, long b) {
        while (b > 0)
        {
            long temp = b;
            b = a % b; // % is remainder
            a = temp;
        }
        return a;
    }

    private static long gcd(long[] input) {
        long result = input[0];
        for(int i = 1; i < input.length; i++) result = gcd(result, input[i]);
        return result;
    }
    
    private static long lcm(long a, long b) {
        return a * (b / gcd(a, b));
    }

    private static long lcm(long[] input) {
        long result = input[0];
        for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
        return result;
    }
    
    public static int solve(long line, long[] barbers) {
        
        long n = lcm(barbers);
        
        long count = 0;
        for (int i = 0; i < barbers.length; i++) {
            count += n / barbers[i];
        }
        
        line = ((line - 1) % count) + 1;
        return solveSmall(line, barbers);
    }
    
    public static void main(String[] args) {
        
        try {
            BufferedReader br = new BufferedReader(new FileReader("input.txt"));
            PrintWriter writer = new PrintWriter("output.txt");
            int count = Integer.valueOf(br.readLine());
            
            for (int ii = 0; ii < count; ii++) {
                int line = Integer.valueOf(br.readLine().split(" ")[1]);
                String[] t = br.readLine().split(" ");
                long[] barbers = new long[t.length];
                for (int i = 0; i < t.length; i++) {
                    barbers[i] = Long.valueOf(t[i]);
                }
                
                //System.out.println("Case #" + (ii+1) + ": " + solve(line, barbers));
                writer.println("Case #" + (ii+1) + ": " + solve(line, barbers));
            }
            
            br.close();
            writer.close();
        } catch (IOException e) {
            System.err.println(e.getMessage());
        }
    }
    
}
