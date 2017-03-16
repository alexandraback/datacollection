package codeJam2015;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;

public class R1PA extends Cases {

	static int N;
	
	public static void operate(Case[] cases) {
		for(Case ca : cases) {
		//for(int nnn = 0; nnn < 1; nnn++) {
			//Case ca = cases[2];
			N = Integer.parseInt(ca.input.get(0));
			String[] ins = ca.input.get(1).split(" ");
			int[] mush = new int[ins.length];
			for(int i = 0; i < mush.length; i++) {
				mush[i] = Integer.parseInt(ins[i]);
			}
			
			int result1 = case1(mush);
			System.out.println(Arrays.toString(mush) + " " + result1);
			int result2 = case2(mush);
			System.out.println(result2);
			ca.output = Integer.toString(result1) + " " + Integer.toString(result2);
		}
	}
	
	private static int case1(int[] mush) {
		int len = mush.length;
		int total = 0;
		for(int i = 0; i < len - 1; i++) {
			int pre = mush[i];
			int next = mush[i + 1];
			if(pre > next) {
				total += pre - next;
			}
		}
		return total;
	}
	
	private static int case2(int[] mush) {
		int total = 0;
		int max = 0;
		int len = mush.length;
		for(int i = 0; i < len - 1; i++) {
			int dif = mush[i] - mush[i + 1];
			if(dif > max) {
				max = dif;
			}
		}
		System.out.println(max);
		for(int i = 0; i < len - 1; i++) {
			int num = mush[i];
			if(num <= max) {
				total += num;
			} else {
				total += max;
			}
		}
		return total;
	}
	
	public static void main(String[] args) throws IOException {
		String inputFile = "A-large.in";
		int caseSize = 2;	/////////////////////////////////////// remember to set caseSize here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(args.length > 0)
			inputFile = args[0];
		String outputFile = inputFile.substring(0, inputFile.length() - 3) + ".out";
		Case[] cases = readAllCases(inputFile, caseSize);
		operate(cases);
		writeOutput(outputFile, cases);
	}
}
