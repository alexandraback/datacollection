import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Neighbors {
	private static Scanner scanner = new Scanner(System.in);
	private static PrintWriter sortie;

	public static void main(String[] args) {
		start();

	    int T = scanner.nextInt();

	    for (int i = 0; i < T; i++) {
	    	int r = scanner.nextInt();
	    	int c = scanner.nextInt();
	    	int n = scanner.nextInt();

			sortie.println("Case #" + (i + 1) + ": " + counter(r, c, n));
		}

	    end();
	}

	private static int counter(int r, int c, int n) {
		boolean[][] values = initialize(r, c);

		int count = r * c, val = conflicts(values);

		while (count > n) {
			Pair cell = findBestCell(values);

			values[cell.i][cell.j] = false;
			val -= cell.value * 2;
			count--;
		}

		return val >> 1;
	}

	private static boolean[][] initialize(int r, int c) {
		boolean[][] values = new boolean[r][c];

		for (int i = 0; i < values.length; i++) {
			int size = values[0].length;
			for (int j = 0; j < size; j++) {
				values[i][j] = true;
			}
		}

		return values;
	}


	private static int conflicts(boolean[][] values) {
		int problems = 0;

		for (int i = 0; i < values.length; i++) {
			int size = values[0].length;

			for (int j = 0; j < size; j++) {
				if (values[i][j]) {
					problems += getNumberOfProblems(values, i, size, j);
				}
			}
		}

		return problems;
	}

	private static Pair findBestCell(boolean[][] values) {
		Pair result = new Pair(0, 0, -42);

		for (int i = 0; i < values.length; i++) {
			int size = values[0].length;
			for (int j = 0; j < size; j++) {
				if (values[i][j]) {
					int problems = getNumberOfProblems(values, i, size, j);

					if (problems > result.value) {
						result = new Pair(i, j, problems);
					}
				}
			}
		}

		return result;
	}

	public static class Pair {
		int i;
		int j;
		int value;

		public Pair(int i, int j, int value) {
			this.i = i;
			this.j = j;
			this.value = value;
		}

		public String toString() {
			return i + " " + j +" (" + value + ")";
		}
	}

	private static int getNumberOfProblems(
			boolean[][] values, int i, int size, int j) {
		int problems = 0;

		if (i > 0 && values[i-1][j]) {
			problems++;
		}

		if (i < values.length - 1 && values[i+1][j]) {
			problems++;
		}

		if (j > 0 && values[i][j-1]) {
			problems++;
		}

		if (j < size - 1 && values[i][j+1]) {
			problems++;
		}

		return problems;
	}

	//////////// UTILITIES

	private static void end() {
	    sortie.close();
	    try {
		    InputStream ips=new FileInputStream("C:\\Users\\Thomas\\Desktop\\output.txt");
			InputStreamReader ipsr=new InputStreamReader(ips);
			BufferedReader br=new BufferedReader(ipsr);
			String ligne;
			while ((ligne=br.readLine())!=null) System.out.println(ligne);
			br.close();
	    } catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static void start() {
		try {
			sortie =  new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\Thomas\\Desktop\\output.txt")));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
