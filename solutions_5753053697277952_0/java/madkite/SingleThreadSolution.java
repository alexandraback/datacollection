package com.google;

import java.io.*;
import java.util.concurrent.*;

/**
 * @author Roman Kosenko <madkite@gmail.com>
 */
public abstract class SingleThreadSolution<V> implements Callable<V> {
	protected static void solve(SolutionFactory<?> factory) throws Exception {
		solve(factory, "input.txt", null);
	}
	protected static void solve(SolutionFactory<?> factory, String input) throws Exception {
		String output = null;
		if(input.endsWith(".in"))
			output = input.substring(0, input.length() - 2) + "out";
		solve(factory, input, output);
	}
	protected static void solve(SolutionFactory<?> factory, String input, String output) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(input));
		if(output != null)
			System.setOut(new PrintStream(output));
		solve(factory, br);
	}
	protected static void solve(SolutionFactory<?> factory, BufferedReader br) throws Exception {
		long time = System.currentTimeMillis();
		int t = Integer.parseInt(br.readLine());
		for(int i = 0; i < t; i++)
			System.out.println("Case #" + (i + 1) + ": " + factory.read(br).call());
		time = System.currentTimeMillis() - time;
		Thread.sleep(100);
		System.err.println(time);
	}
}
