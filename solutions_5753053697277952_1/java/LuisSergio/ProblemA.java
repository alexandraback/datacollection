import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class ProblemA {

	private static BufferedWriter writer;
	private static Scanner scanner;

	private static List<Party> input;
	private static int count;

	private static List<String> result = new ArrayList<>();

	static class Party implements Comparable<Party> {
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + name;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Party other = (Party) obj;
			if (name != other.name)
				return false;
			return true;
		}

		@Override
		public String toString() {
			return "Party [count=" + count + ", name=" + name + "]";
		}

		int count;
		char name;

		@Override
		public int compareTo(Party o) {
			int r = -Integer.compare(count, o.count);
			if (r == 0) {
				return Character.compare(name, o.name);
			}
			return r;
		}
	}

	private static void processCase(int i) throws IOException {
		readInput();
		solve();
		outputResults(i);
	}

	private static void solve() {
		result.clear();
		while (input.size() > 0) {
			String path;
			Iterator<Party> iterator = input.iterator();
			Party p1 = iterator.next();
			path = String.valueOf(p1.name);
			count--;
			p1.count--;
			if (input.size() > 0) {
				Party p2 = iterator.next();
				if (p2.count >= 1 + count / 2) {
					path = path + p2.name;
					p2.count--;
					count--;
				}
				if (p2.count == 0) {
					input.remove(p2);
				}
			}
			if (p1.count == 0) {
				input.remove(p1);
			}
			Collections.sort(input);
			result.add(path);
		}
	}

	private static void outputResults(int testCase) throws IOException {
		String out = String.format("Case #%d: %s", testCase + 1, result.stream().collect(Collectors.joining(" ")));
		System.err.println(out);
		writer.write(out);
		writer.newLine();
	}

	private static void readInput() {
		int n = scanner.nextInt();
		input = new ArrayList<>();
		count = 0;
		for (int i = 0; i < n; i++) {
			int np = scanner.nextInt();
			Party p = new Party();
			p.count = np;
			p.name = (char) ('A' + i);
			count += p.count;
			input.add(p);
		}
		Collections.sort(input);

	}

	public static void main(String[] args) throws IOException {
		Path input = Paths.get("src/input.in");
		Path output = Paths.get("src/output.txt");
		scanner = new Scanner(input);
		writer = Files.newBufferedWriter(output);
		int testCases = scanner.nextInt();
		scanner.nextLine();
		for (int i = 0; i < testCases; i++) {
			processCase(i);
		}
		writer.close();

	}

}
