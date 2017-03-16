import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Q1 {
	public static Problem[] probs;

	static class Problem {
		public int N;
		public String[] strings;
	}
				
	
	public static void main(String[] args) {
		String inputFile = args[0];
		parseFile(inputFile);
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(inputFile + ".out"));
			for (int i=0; i<probs.length; i++) {
				String output = solveProblem(probs[i]);
				System.out.println(output);
				bw.write("Case #" + (i+1) + ": " + output + "\n");
			}
			bw.flush();
			bw.close();
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}

	private static ArrayList<Character> indexString(String s) {
		ArrayList<Character> index = new ArrayList<Character>();
		char cur_char = s.charAt(0);
		for (int i=1; i<s.length(); i++) {
			if (cur_char==s.charAt(i)) {
				continue;
			} else {
				index.add(cur_char);
				cur_char = s.charAt(i);
			}
		}
		index.add(cur_char);
		return index;
	}
	
	private static ArrayList<Integer> seqString(String s) {
		ArrayList<Integer> seq = new ArrayList<Integer>();
		int cur_seq = 1;
		char cur_val = s.charAt(0);
		int index = 1;
		while (index<s.length()) {
			if (s.charAt(index)==cur_val) {
				cur_seq++;
			} else {
				seq.add(cur_seq);
				cur_seq = 1;
				cur_val = s.charAt(index);
			}
			index++;
		}
		seq.add(cur_seq);
		return seq;
	}
	
	private static String solveSmall(Problem p) {
		//if chars don't appear in the same order, can't solve
		ArrayList<ArrayList<Character>> indices = new ArrayList<ArrayList<Character>>();
		for (int i=0; i<p.N; i++) {
			indices.add(indexString(p.strings[i]));
		}
		ArrayList<Character> ref = indices.get(0);
		//check length
		for (int i=1; i<p.N; i++) {
			if (indices.get(i).size()!=ref.size()) {
				return "Fegla Won";
			}
			for (int j=0; j<ref.size(); j++) {
				if (indices.get(i).get(j)!=ref.get(j)) {
					return "Fegla Won";
				}
			}
		}
		
		//Seems plausible
		//Work through in order
		int cumulative_mods = 0;
		ArrayList<ArrayList<Integer>> seqs = new ArrayList<ArrayList<Integer>>();
		for (int i=0; i<p.N; i++) {
			seqs.add(seqString(p.strings[i]));
		}
		for (int i=0; i<seqs.get(0).size(); i++) {
			//count up how many with each number
			int[] count = new int[101];
			int min = 101;
			int max = -1;
			for (int j=0; j<101; j++) {
				count[j] = 0;
			}
			for (int j=0; j<p.N; j++) {
				int ct = seqs.get(j).get(i);
				count[ct]++;
				if (ct>max) {
					max = ct;
				}
				if (ct<min) {
					min = ct;
				}
			}
			//Try all values between min and max, see how many changes
			int best_mods = 100000;
			for (int j=min; j<=max; j++) {
				int mods = 0;
				for (int k=min; k<=max; k++) {
					mods += count[k]*Math.abs(j-k);
				}
				if (mods < best_mods) {
					best_mods = mods;
				}
			}
			cumulative_mods += best_mods;
		}
		return "" + cumulative_mods;
	}
	
	private static String solveProblem(Problem p) {
		return solveSmall(p);
	}

	public static void parseFile(String inputFile) {
		BufferedReader br;
		try {
			br = new BufferedReader(new FileReader(inputFile));
			String line = br.readLine();
			probs = new Problem[Integer.parseInt(line)];
			line = br.readLine();
			for (int i=0; i<probs.length; i++) {
				probs[i] = new Problem();
				probs[i].N = Integer.parseInt(line);
				probs[i].strings = new String[probs[i].N];
				line = br.readLine();
				for (int j=0; j<probs[i].N; j++) {
					probs[i].strings[j] = line;
					line = br.readLine();
				}
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}