package codejam2015.round1A;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class ProblemB {

	public static void main(String[] args) {
		String fileName = "B-small-attempt2";
		File folder = new File(new File("files", "codejam2015"), "round1A");
		File inputFile = new File(folder, fileName + ".in");
		File outputFile = new File(folder, fileName + ".out");
		try (BufferedReader reader = new BufferedReader(new FileReader(inputFile))) {
			try (PrintWriter writer = new PrintWriter(new FileWriter(outputFile))) {
				int count = Integer.parseInt(reader.readLine());
				for (int i = 0; i < count; i++) {
					String[] parameters = reader.readLine().split("\\s");
					int b = Integer.parseInt(parameters[0]);
					int n = Integer.parseInt(parameters[1]);
//					System.out.println(i+1);
					String line = reader.readLine();
					writer.printf("Case #%d: %s\n", i+1,
							solveIt(b, n, readBigIntegers(line), readIntegers(line)));
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		System.out.println("Done.");
	}

	private static String solveIt(int b, int n, BigInteger[] barberTime, int[] m) {
		int[] t = new int[b];
		int assigned = -1;
		BigInteger loopDuration = mmc(barberTime);
		Map<Integer, List<Integer>> map = new TreeMap<Integer, List<Integer>>();
		BigInteger customersPerLoop = BigInteger.ZERO;
		for (int i = 0; i < b; i++) {
			customersPerLoop = customersPerLoop.add(loopDuration.divide(barberTime[i]));
		}
		System.out.print(n + " mod "+customersPerLoop+" = ");
		n = BigInteger.valueOf(n-1).mod(customersPerLoop).intValue() + 1;
		System.out.println(n);
		for (int customer = 0; customer < n; customer++) {
			assigned = assignBarber(m, t);
//			System.out.println(customer+1 + ": "+(assigned + 1));
		}
		return String.valueOf(assigned + 1);
	}

	private static int assignBarber(int[] m, int[] t) {
		int minT = Integer.MAX_VALUE;
		int firstBarber = -1;
		for (int i = 0; i < t.length; i++) {
			if (minT > t[i]) {
				minT = t[i];
				firstBarber = i;
			}
		}
		t[firstBarber] += m[firstBarber];
		return firstBarber;
	}

	private static int[] readIntegers(String line) throws IOException {
		String[] strings = line.split("\\s");
		int[] numbers = new int[strings.length];
		for (int i = 0; i < strings.length; i++) {
			numbers[i] = Integer.parseInt(strings[i]);
		}
		return numbers;
	}

	private static BigInteger[] readBigIntegers(String line) throws IOException {
		String[] strings = line.split("\\s");
		BigInteger[] numbers = new BigInteger[strings.length];
		for (int i = 0; i < strings.length; i++) {
			numbers[i] = new BigInteger(strings[i]);
		}
		return numbers;
	}

	private static BigInteger mmc(BigInteger... t) {
		BigInteger mmc = t[0];
		for (int i = 1; i < t.length; i++) {
			mmc = mmc(mmc, t[i]);
		}
		return mmc;
	}

	private static BigInteger mmc(BigInteger t1, BigInteger t2) {
		return t1.divide(mdc(t1, t2)).multiply(t2);
	}

	private static BigInteger mdc(BigInteger t1, BigInteger t2) {
		BigInteger mod = t1;
		while (mod.compareTo(BigInteger.ZERO) != 0) {
			t1 = mod;
			mod = mod(t2, t1);
			t2 = t1;
		}
		return t1;
	}

	private static BigInteger mod(BigInteger t2, BigInteger t1) {
		return t2.divideAndRemainder(t1)[1];
	}
}
