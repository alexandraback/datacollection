package Round1B;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.LinkedList;

public class Prob1 {
	private static BufferedReader r;
	private static PrintStream outFile;
	private static PrintStream out = new PrintStream(new OutputStream() {
		@Override
		public void write(int b) throws IOException {
			System.out.write(b);
			outFile.write(b);
		}
	});

	public static void main(String[] args) throws IOException {
		File f = new File("/home/blarson/input");
		r = new BufferedReader(new FileReader(f));
		outFile = new PrintStream(new FileOutputStream(new File(
				"/home/blarson/output")));
		final int numCases = readInt();

		for (int i = 0; i < numCases; i++) {
			out.print("Case #" + (i + 1) + ": ");

			solve();

			out.println();
		}

		out.close();
	}

	private static void solve() throws IOException {
		int n = readInt();
		String[] strings = new String[n];
		for (int i = 0; i < n; i++) {
			strings[i] = r.readLine().trim();
		}

		ArrayList<LinkedList<Entry>> entries = new ArrayList<LinkedList<Entry>>(n);
		for (int i = 0; i < n; i++) {
			LinkedList<Entry> list = new LinkedList<Entry>();
			entries.add(list);
			char letter = ' ';
			for(int j = 0; j < strings[i].length(); j++) {
				char l = strings[i].charAt(j);
				if(letter == l) {
					list.peekLast().count++;
				} else {
					list.add(new Entry(l));
					letter = l;
				}
			}
		}
		
		int numEntries = entries.get(0).size();
		for (int i = 0; i < n; i++) {
			if(entries.get(i).size() != numEntries) {
				out.print("Fegla Won");
				return;
			}
		}
		
		for(int i = 0; i < numEntries; i++) {
			char letter = entries.get(0).get(i).letter;
			for(int j = 1; j < n; j++) {
				if(entries.get(j).get(i).letter != letter) {
					out.print("Fegla Won");
					return;
				}
			}
		}
		
		int moves = 0;
		for(int i = 0; i < numEntries; i++) {
			int max = entries.get(0).get(i).count;
			int min = entries.get(0).get(i).count;
			for(int j = 1; j < n; j++) {
				if(entries.get(j).get(i).count > max) {
					max = entries.get(j).get(i).count;
				}
				if(entries.get(j).get(i).count < min) {
					min = entries.get(j).get(i).count;
				}
			}
			moves += max - min;
		}
		
		out.print(moves);
	}
	
	private static class Entry {
		public final char letter;
		public int count;
		public Entry(char letter) {
			this.letter = letter;
			this.count = 1;
		}
	}

	private static double[] readDoubleArray(int maxItems) throws IOException {
		double[] array = new double[maxItems];
		String line = r.readLine().trim();
		String[] data = line.split(" ");
		for (int i = 0; i < data.length && i < maxItems; i++) {
			array[i] = Double.parseDouble(data[i]);
		}
		return array;
	}

	private static int[] readIntArray(int maxItems) throws IOException {
		int[] array = new int[maxItems];
		String line = r.readLine().trim();
		String[] data = line.split(" ");
		for (int i = 0; i < data.length && i < maxItems; i++) {
			array[i] = Integer.parseInt(data[i]);
		}
		return array;
	}

	private static int readInt() throws IOException {
		String line = r.readLine().trim();
		return new Integer(line);
	}
}
