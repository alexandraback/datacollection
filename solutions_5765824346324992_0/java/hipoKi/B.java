/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
	public void solve() throws IOException 
	{
		BufferedReader f = new BufferedReader(new FileReader("B-small-attempt3.in"));
		  // input file name goes above
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("b.out")));
		//PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(f);
		int T = in.nextInt();
		for(int i = 0; i < T; i++)
		{
			out.print("Case #" + (i+1) + ": ");
                        int B = in.nextInt();
                        long N = in.nextLong();
                        long ms[] = new long[B];
                        for(int k = 0; k < B; k++)
                            ms[k] = in.nextLong();
                        long res = find(ms, N);
                        out.println(res);
                        
		}
		
		out.close();
		in.close();
	}

	public static void main(String ... args) throws IOException
	{
		B solver = new B();
		solver.solve();
		System.exit(0);
	}

    private long find(long[] ms, long N) {
        long quick = Long.MAX_VALUE;
        for(int i = 0; i < ms.length; i++)
            quick = Math.min(quick, ms[i]);
        
        long start = 0;
        long end = N * quick; // VER
            
        long count;
        long free;
        long mid;
        while(true)
        {
            mid = (end - start) / 2 + start;
            count = 0;
            free = 0;
            for(int i = 0; i < ms.length; i++)
            {
                count += mid / ms[i];
                if(mid % ms[i] == 0)
                    free++;
                else
                    count++; // está ocupado!
            }
            if(count < N) // todavía no
            {
                if(count + free >= N) // me toca!
                    break;
                else // falta
                    start = mid + 1;
            } else // me pasé
                end = mid;
        }
        long barber = N - count;
        for(int i = 0; i < ms.length; i++)
        {
            if(mid % ms[i] == 0)
                barber--;
            if(barber == 0)
                return i + 1;
        }
        return -1;
    }
}
