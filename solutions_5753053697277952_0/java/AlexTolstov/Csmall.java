import java.io.*;
import java.util.*;

public class Csmall {

	Scanner in;

	PrintWriter out;

	private static final String path = "/home/alex/Downloads/";

	private static final String task = "A-small-attempt0";

	static class Party implements Comparable<Party>{
		final char name;
		final int count;
		
		Party(char name, int count) {
			this.name = name;
			this.count = count;
		}
		
		public int compareTo(Party second) {
			if (count == second.count) {
				return Character.compare(name, second.name);
			} else {
				return second.count - this.count;
			}
		}
		
		public String toString() {
			return "" + name;
		}
	}
	
	void add(NavigableSet<Party> parties, Party party) {
		if (party.count > 0) {
			parties.add(party);
		}
	}
	
	void solveOne() {
		int nParties = in.nextInt();
		NavigableSet<Party> parties = new TreeSet<>();
		int totalCount = 0;
		for (int i = 0; i < nParties; i++) {
			Party p = new Party((char)(i + 'A'), in.nextInt());
			totalCount += p.count;
			parties.add(p);
		}
		while (totalCount > 1) {
			Party first = parties.pollFirst();
			Party second = parties.pollFirst();
				// 1 1
			if (first.count >= 2 && second.count * 2 <= totalCount - 2) {
				out.print(first + "" + first + " ");
				add(parties, new Party(first.name, first.count - 2));
				add(parties, second);
				totalCount -= 2;
			} else {
				if (parties.size() == 1) {
					Party third = parties.first();
					if (third.count * 2 >= totalCount - 2) {
						out.print(first + " ");
						add(parties, new Party(first.name, first.count - 1));
						add(parties, second);
						totalCount--;
						continue;
					}
				}
				out.print(first + "" + second + " ");
				add(parties, new Party(first.name, first.count - 1));
				add(parties, new Party(second.name, second.count - 1));
				totalCount-=2;
			}
		}
	}

	static void asserT(boolean e) {
		if (!e) {
			throw new Error();
		}
	}

	void solve() {
		int nTests = in.nextInt();
		for (int i = 1; i <= nTests; i++) {
			out.print("Case #" + i + ": ");
			solveOne();
			out.println();
		}
	}

	void run() {
		try {
			in = new Scanner(new FileReader(path + task + ".in"));
			out = new PrintWriter(new FileWriter(path + task + ".out_"));
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
			out.println(">");
			out.flush();
		}

		try {
			solve();
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) {
		new Csmall().run();
	}
}
