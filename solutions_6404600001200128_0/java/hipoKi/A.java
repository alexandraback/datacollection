/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	public void solve() throws IOException 
	{
		BufferedReader f = new BufferedReader(new FileReader("A-small-attempt0.in"));
		  // input file name goes above
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("a.out")));
		//PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(f);
		int T = in.nextInt();
		for(int i = 0; i < T; i++)
		{
			out.print("Case #" + (i+1) + ": ");
			
			int N = in.nextInt();
                        int[] tests = new int[N];
                        int res1 = 0;
                        int res2 = 0;
                        for(int k = 0; k < N; k++)
                        {
                            tests[k] = in.nextInt();
                        }
                        
                        int ant = tests[0];
                        int maxDif = 0;
                        for(int k = 1; k < N; k++)
                        {
                            int act = tests[k];
                            int dif = Math.max(0, ant - act);
                            res1 += dif;
                            maxDif = Math.max(maxDif, dif);
                            ant = act;
                        }
                        
                        for(int k = 0; k < N - 1; k++)
                        {
                            res2 += Math.min(tests[k], maxDif);
                        }
                        out.println(res1 + " " + res2);
		}
		
		out.close();
		in.close();
	}

	public static void main(String ... args) throws IOException
	{
		A solver = new A();
		solver.solve();
		System.exit(0);
	}
}
