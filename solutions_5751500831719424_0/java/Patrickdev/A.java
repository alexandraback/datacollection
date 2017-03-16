package R1B2014.A;

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;

/**
 * Created by Patrick on 12-4-14.
 */
public class A {

	final static String INPUTFILE = "D:\\Projecten\\GCJ\\src\\R1B2014\\A\\A-small-attempt0.in";

	static void docase(int casenumber) throws Exception {

		int strings = in.nextInt();

		ArrayList<ArrayList<Letter>> seq = new ArrayList<ArrayList<Letter>>();

		for (int i = 0; i < strings ; i++) {
			seq.add(getLetter(in.nextString()));
		}



		Integer lowest = null;
		for (int i = 0; i < strings; i++) {
			int t = 0;

			for (int j = 0; j < seq.get(0).size(); j++) {
				int best = getBestOfNth(seq, j);
				if (best == -1) {
					out.add("Case #" + casenumber + ": Fegla Won");
					return;
				}
				t += best;
			}

			if (lowest == null || lowest > t) {
				lowest = t;
			}
		}

		out.add("Case #" + casenumber + ": " + lowest);

	}

	static int getBestOfNth(ArrayList<ArrayList<Letter>> seq, int n) {
		int lo=-1,hi=-1;

		// is possible?
		for (ArrayList<Letter> l : seq) {
			if (seq.get(0).size() != l.size()) {
				return -1;
			}

			for (int j = 0; j < seq.get(0).size(); j++) {
				if (seq.get(0).get(j).letter != l.get(j).letter) {
					return -1;
				}
			}
		}

		for (int i = 0; i < seq.size(); i++) {
			int occ = seq.get(i).get(n).occ;
			if (occ < lo || lo == -1) {
				lo = occ;
			}
			if (occ > hi || hi == -1) {
				hi = occ;
			}
		}

		int lowest = -1;
		for (int i = lo; i <= hi; i++) {
			int diff = 0;
			for (int j = 0; j < seq.size(); j++) {
				diff += Math.abs(i - seq.get(j).get(n).occ);
			}

			if (diff < lowest || lowest == -1) {
				lowest = diff;
			}
		}
		return lowest;
	}

	static ArrayList<Letter> getLetter(String str1) {

		ArrayList<Letter> result = new ArrayList<Letter>();

		Letter l = null;
		for (Character chr : str1.toCharArray()) {

			if (l != null && chr != l.letter) {
				result.add(l);
				l = null;
			}

			if (l == null) {
				l = new Letter();
				l.letter = chr;
			}

			if (l != null) {
				l.occ++;
			}

		}

		result.add(l);

		return result;

	}

	static class Letter {
		public char letter;
		public int occ = 0;
	}



	public static void main(String args[]) {
		try {

			int totalcases = in.nextInt();

			caseloop:
			for (int currentcase = 1; currentcase <= totalcases; currentcase++) {

				docase(currentcase);

			}

			out.write();

		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}

	static class In {
		BufferedReader br;
		String buffer = "";

		In() throws Exception {
			br = new BufferedReader(new FileReader(INPUTFILE));
		}

		String nextLine() throws Exception {
			buffer = "";
			return br.readLine();
		}

		String nextString() throws Exception {
			if (buffer.equals("")) {
				buffer = nextLine();
			}

			String line = buffer;

			if (line.contains(" ")) {
				int spacePos = line.indexOf(" ");
				buffer = line.substring(spacePos + 1, line.length());
				return line.substring(0, spacePos);
			} else {
				buffer = "";
				return line;
			}

		}

		int nextInt() throws Exception {
			return Integer.parseInt(nextString());
		}

		BigInteger nextBigInteger() throws Exception {
			return new BigInteger(nextString());
		}
	}

	static class Out {
		StringBuilder strBuilder = new StringBuilder();

		void add(Object str) {
			strBuilder.append(str.toString());
			strBuilder.append("\n");
			log(str);
		}

		void write() throws Exception {
			File file = new File(INPUTFILE.replace(".in", ".out"));
			if (file.exists()) {
				file.delete();
				file.createNewFile();
			}

			BufferedWriter bw = new BufferedWriter(new FileWriter(file.getAbsoluteFile()));
			bw.write(strBuilder.toString());
			bw.close();
		}
	}

	static In in;
	static Out out;
	static {
		try {
			in = new In();
			out = new Out();
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}


	static void log(Object o) {
		System.out.println("" + o);
	}
}
