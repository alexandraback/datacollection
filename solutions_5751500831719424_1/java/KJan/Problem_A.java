

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Problem_A {

	public static void main(String[] args) throws Throwable {
		Problem_A a = new Problem_A();
		a.go("A.in", "A.out");
	}
	public void go(String inf, String outf) throws Throwable {
		BufferedReader br = new BufferedReader(new FileReader(inf));
		String line = br.readLine();
        int T = Integer.parseInt(line);
        StringBuilder output = new StringBuilder();
        
		for (int t = 1; t<=T; t++) {
			int N = Integer.parseInt(br.readLine());
	
			String[] words = new String[N];
			
			for (int i = 0; i<N; i++) {
				words[i] = br.readLine();
			}
			
			List<Integer> num = new ArrayList<>();
			
			char cur = words[0].charAt(0);
			StringBuilder outcome = new StringBuilder(101);
			outcome.append(cur);
			int rep = 1;
			for (int i = 1; i<words[0].length(); i++) {
				if (words[0].charAt(i)==cur) {
					rep++;
				} else {
					cur = words[0].charAt(i);
					outcome.append(cur);
					num.add(rep);
					rep = 1;
				}
			}
			num.add(rep);
			
			List< List<Integer> > all = new ArrayList<>();
			all.add(num);
			Boolean abort = false;
			for (int i = 1; i<N; i++) {
				List<Integer> temp = count(words[i], outcome.toString());
				if (temp.get(0)==-1) {
					abort = true;
					break;
				}
				all.add(temp);
			}
			if (abort) {
				output.append("Case #"+t+": Fegla Won\n");
				continue;
			}
			int moves = 0;
			for (int i = 0; i<outcome.toString().length(); i++) {
				int min = 99999;
				for (int j = 0; j<N; j++) {
					int m2 = 0;
					for (int k = 0; k<N; k++) {
						m2 += Math.abs(all.get(j).get(i)-all.get(k).get(i));
					}
					if (m2<min) {
						min = m2;
					}
				}
				moves += min;
			}
			
			output.append("Case #"+t+": "+moves+"\n");
		}
		br.close();
		writeFile(output.toString(), outf);
	}
	private void writeFile(String output, String filename) throws IOException {
		PrintWriter writer = new PrintWriter(new FileWriter(filename));
		writer.print(output);
		writer.close();
	}
	
	private List<Integer> count(String word, String refWord) {
		List<Integer> num = new ArrayList<>();
		char cur = word.charAt(0);
		StringBuilder outcome = new StringBuilder(101);
		outcome.append(cur);
		int rep = 1;
		for (int i = 1; i<word.length(); i++) {
			if (word.charAt(i)==cur) {
				rep++;
			} else {
				cur = word.charAt(i);
				outcome.append(cur);
				num.add(rep);
				rep = 1;
			}
		}
		num.add(rep);
		
		if (outcome.toString().compareTo(refWord)!=0) {
			List<Integer> num1 = new ArrayList<>();
			num1.add(-1);
			return num1;
		}
		return num;
	}
}
