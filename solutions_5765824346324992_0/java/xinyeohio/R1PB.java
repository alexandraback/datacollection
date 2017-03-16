package codeJam2015;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;

public class R1PB extends Cases {

	static int B;
	static int N;
	
	public static long gcd(long a, long b) {
		if(a <= 0 || b <= 0)
			throw new IllegalArgumentException();
		if(a == b)
			return a;
		if(a % b == 0)
			return b;
		if(b % a == 0)
			return a;
		int d = 0;
		while(a % 2 == 0 && b % 2 == 0) {
			a = a >>> 1;
			b = b >>> 1;
			d++;
		}
		while(a % 2 == 0) {
			a = a >>> 1;
		}
		while(b % 2 == 0) {
			b = b >>> 1;
		}
		long c;
		while(a != b) {
			c = a > b ? (a - b) : (b - a);
			while(c % 2 == 0)
				c = c >>> 1;
			if(a > b)
				a = c;
			else
				b = c;
		}
		return a * (long)Math.pow(2, d);
	}
	
	public static void operate(Case[] cases) {
		for(Case ca : cases) {
		//for(int nnn = 0; nnn < 1; nnn++) {
			//Case ca = cases[0];
			String[] ins = ca.input.get(0).split(" ");
			B = Integer.parseInt(ins[0]);
			N = Integer.parseInt(ins[1]);
			ins = ca.input.get(1).split(" ");
			long[] M = new long[ins.length];
			for(int i = 0; i < ins.length; i++) {
				M[i] = Integer.parseInt(ins[i]);
			}
			System.out.println(B + " " + N + " " + Arrays.toString(M));
			long gm = gcm(M);
			long total = preprocess(M, gm);
			System.out.println(total);
			if(N > total) {
				N = (int) (N % total + total);
			}
			System.out.println("new N: " + N);
			int result = lastStep(M, N);
			System.out.println("result: " + result);
			ca.output += result;
			//int result = lastStep2(M);
			//System.out.println("result: " + result);
			//ca.output += result;
		}
	}
	
	private static int lastStep2(long[] M) {
		if(N <= B)
			return N;
		long[] tmp = new long[B];
		for(int i = 0; i < B; i++) {
			tmp[i] = M[i];
		}
		N -= B;
		while(true) {
			long min = findMin(tmp);
			for(int i = 0; i < B; i++) {
				tmp[i] = tmp[i] - min;
			}
			for(int i = 0; i < B; i++) {
				if(tmp[i] == 0) {
					tmp[i] = M[i];
					N--;
					if(N == 0) {
						return i + 1;
					}
				}
			}
		}
	}
	
	private static int lastStep(long[] M, int N) {
		if(N == 0) {
			return B;
		}
		if(N <= B) {
			return N;
		}
		int newN = N - B;
		long[] tmp = new long[B];
		for(int i = 0; i < B; i++) {
			tmp[i] = M[i];
		}
		while(true) {
			long min = findMin(tmp);
			for(int i = 0; i < B; i++) {
				tmp[i] = tmp[i] - min;
			}
			for(int i = 0; i < B; i++) {
				if(tmp[i] == 0) {
					tmp[i] = M[i];
					newN--;
					if(newN == 0) {
						return i + 1;
					}
				}
			}
		}
	}
	
	private static long findMin(long[] tmp) {
		long min = Long.MAX_VALUE;
		for(long v : tmp) {
			if(v < min) {
				min = v;
			}
		}
		return min;
	}
	
	private static long preprocess(long[] M, long gm) {
		long total = 0;
		for(long v : M) {
			total += (gm / v);
		}
		return total;
	}
	
	private static long gcm(long[] M) {
			long a = M[0];
			long b = M[1];
			long g = gcd(a, b);
			
			a /= g;
			b /= g;
			long c = a * b;
			c *= g;
			a = c;
			
			for(int i = 2; i < M.length; i++) {
				b = M[i];
				g = gcd(a, b);
				a /= g;
				b /= g;
				c = a * b;
				c *= g;
				a = c;
			}
			return a;
	}
	
	public static void main(String[] args) throws IOException {
		String inputFile = "B-small-attempt2.in";
		//inputFile = "bs.in";
		int caseSize = 2;	/////////////////////////////////////// remember to set caseSize here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(args.length > 0)
			inputFile = args[0];
		String outputFile = inputFile.substring(0, inputFile.length() - 3) + ".out";
		Case[] cases = readAllCases(inputFile, caseSize);
		operate(cases);
		writeOutput(outputFile, cases);
	}
}
