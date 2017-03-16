import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class A {

	static InputReader in = new InputReader();
	static int total = 0;

	public static void main(String[] args) throws IOException {
		int noCases = in.nextInt();
		BufferedWriter out = new BufferedWriter(new FileWriter(new File("a-small.out")));
		for (int c = 1; c <= noCases; c++) {
			int noParties = in.nextInt();
			String ans = "";
			ArrayList<Packet> people = new ArrayList<>(noParties);
			for (int i = 0; i < noParties; i++) {
				people.add(new Packet());
				people.get(i).no = in.nextInt();
				people.get(i).letter = (char) ((int) 'A' + i);
			}
			Collections.sort(people);

			for (Packet i : people) {
				total += i.no;
			}

			while (total > 0) {
				if (people.get(0).no >= 2 && people.get(1).no * 1.0 <= ((total - 2)) / 2.0) {
					total -= 2;
					people.get(0).no -= 2;
					ans += people.get(0).letter + "" + people.get(0).letter + " ";
					if (people.get(0).no <= 0) {
						people.remove(0);
					}
					Collections.sort(people);
				} else if (people.size() > 2 && people.get(2).no * 1.0 <= ((total - 2) / 2.0)) {
					total -= 2;
					people.get(0).no--;
					people.get(1).no--;
					ans += people.get(0).letter + "" + people.get(1).letter + " ";
					if (people.get(1).no <= 0) {
						people.remove(1);
					}
					if (people.get(0).no <= 0) {
						people.remove(0);
					}
					Collections.sort(people);
				} else if (people.size() == 2) {
					total -= 2;
					people.get(0).no--;
					people.get(1).no--;
					ans += people.get(0).letter + "" + people.get(1).letter + " ";
					if (people.get(1).no <= 0) {
						people.remove(1);
					}
					if (people.get(0).no <= 0) {
						people.remove(0);
					}
					Collections.sort(people);
				} else {
					total -= 1;
					people.get(0).no--;
					ans += people.get(0).letter + " ";
					if (people.get(0).no <= 0) {
						people.remove(0);
					}
					Collections.sort(people);
				}
			}

			// System.out.println("Case #" + c + ": " + ans);
			out.write("Case #" + c + ": " + ans + "\n");
		}
		out.close();
	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader() {
			// reader = new BufferedReader(new InputStreamReader(System.in));
			try {
				reader = new BufferedReader(new FileReader(new File("A-small.in")));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public String readLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
	}

}

class Packet implements Comparable<Packet> {
	public int no;
	public char letter;

	@Override
	public int compareTo(Packet arg0) {
		return arg0.no - this.no != 0 ? arg0.no - this.no : (int) arg0.letter - (int) this.letter;
	}

	public String toString() {
		return this.letter + ":" + this.no;
	}

}
