package com.spawn.codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.NavigableSet;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.concurrent.atomic.AtomicInteger;


// https://github.com/google/guava/
import com.google.common.collect.*;

class Case {

	public int caseNumber;
	public String result;

	public Case(int i, Scanner s) {
		caseNumber = i;
		parse(s);
	}

	public String getResult() {
		return "Case #" + caseNumber + ": " + result + "\n";
	}

	int n;
	int b;
	int[] m;
	TreeMultimap<Integer, Integer> map = TreeMultimap.create();

	public void parse(Scanner s) {
		b = s.nextInt();
		n = s.nextInt()-1;
		m = new int[b];
		for (int i = 0; i < b; i++){
			m[i] = s.nextInt();
			map.put(m[i], i);
		}
	}

	
	public int s(){
		if(n <= b)
			return n;

		int count = b;
		while(true){
			int t = map.keySet().first();
			SortedSet<Integer> bs = map.removeAll(t);
			if(map.isEmpty())
			{
				n = n % count;
				count = 0;
			}
			for(int i : bs){
				if(count == n)
					return i;
				count++;
				map.put(t+m[i], i);
			}
		}

	}

	public void solve() {
		result = Integer.toString(s() +1);

		System.out.println("#" + caseNumber + " done; "
				+ Main.casesRemaining.decrementAndGet() + " remaining");
	}
}

public class Main {

	public static AtomicInteger casesRemaining = new AtomicInteger();

	public static void main(String[] args) {
		try {
			String name = readLine();
			Scanner s = new Scanner(new File("../" + name + ".in"));

			int t = s.nextInt();
			casesRemaining.set(t);
			ArrayList<Case> cases = new ArrayList<Case>(t);
			File f = new File("../" + name + ".out");
			FileWriter output = new FileWriter(f);
			for (int i = 0; i < t; i++) {
				cases.add(i, new Case(i + 1, s));
			}
			if (name.equals("test"))
				cases.stream().forEach(Case::solve);
			else
				cases.parallelStream().forEach(Case::solve);

			for (int i = 0; i < t; i++) {
				output.write(cases.get(i).getResult());
			}
			output.close();
			s.close();

		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static String readLine() throws IOException {
		if (System.console() != null) {
			return System.console().readLine();
		}
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				System.in));
		return reader.readLine();
	}

}
