package com.google.babble;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;

public class Babble {

	static String cj_letter = "A";
	static String cj_input = "small";
	// static String cj_input = "large";
	static String cj_attempt = "0";

	static BufferedWriter bw;

	static int total = 0;

	public static void main(String[] args) throws NumberFormatException, IOException {
		String fileIn = "/home/vys/Downloads/" + cj_letter + "-" + cj_input
				+ (cj_input.equals("small") ? "-attempt" + cj_attempt : "") + ".in";
		bw = new BufferedWriter(new FileWriter(fileIn.replaceAll(".in$", ".out")));
		BufferedReader br;
		if (new File(fileIn).exists()) {
			br = new BufferedReader(new FileReader(fileIn));
		} else {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		int numCases = Integer.parseInt(br.readLine());
		for (int i = 0; i < numCases; i++) {
			solve(br, i + 1);
		}
		bw.flush();
		bw.close();
	}

	public static <T> void out(T o) {
		System.out.print(o);
		try {
			bw.write("" + o);
		} catch (IOException e) {
		}
	}

	public static <T> void outln() {
		System.out.println();
		try {
			bw.write(System.lineSeparator());
		} catch (IOException e) {
		}
	}

	public static <T> void outln(T o) {
		out(o);
		System.out.println();
		try {
			bw.write(System.lineSeparator());
		} catch (IOException e) {
		}
	}

	private static void solve(BufferedReader br, int i) throws IOException {

		int numParties = Integer.parseInt(br.readLine());

		String[] candidates = br.readLine().split(" ");

		int[] numCandidates = new int[numParties];

		for (int j = 0; j < numParties; j++) {
			numCandidates[j] = Integer.parseInt(candidates[j]);
		}
		
		out("Case #" + i + ":");

		while (true) {
			int max = 0;
			int maxIndex = -1;
			StringBuilder sb = new StringBuilder();
			
			for (int j = 0; j < numParties; j++) {
				if (numCandidates[j] > max) {
					max = numCandidates[j];
					maxIndex = j;
				}
			}
			
			sb.append((char) ('A' + maxIndex));
			numCandidates[maxIndex]--;
			
			if (hasMajority(numCandidates)) {
				max = 0;
				maxIndex = -1;
				for (int j = 0; j < numParties; j++) {
					if (numCandidates[j] > max) {
						max = numCandidates[j];
						maxIndex = j;
					}
				}
				
				sb.append((char) ('A' + maxIndex));
				numCandidates[maxIndex]--;
			}
			out(" " + sb.toString());
			
			if (sum(numCandidates) == 0) break;
		}
		
		outln();

		return;
	}

	private static boolean hasMajority(int[] numCandidates) {
		int sum = sum(numCandidates);
		
		for (int i : numCandidates) {
			if (i * 2 > sum) {
				return true;
			}
		}
		return false;
	}

	private static int sum(int[] numCandidates) {
		int sum = 0;
		for (int i : numCandidates) {
			sum += i;
		}
		return sum;
	}
}
