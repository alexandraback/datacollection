package codeJam.google.com;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

class Pairs {
	int count;
	char c;

	public Pairs(char c, int count) {
		this.c = c;
		this.count = count;
	}
}

public class TheRepeater {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File(
				"C:/Users/Zhenyi/Downloads/A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(
				"C:/Users/Zhenyi/Downloads/A-small.out");
		int T = in.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int N = in.nextInt();
			String[] s = new String[N];
			for (int i = 0; i < N; i++) {
				s[i] = in.next();
			}
			ArrayList<ArrayList<Pairs>> list = new ArrayList<ArrayList<Pairs>>();
			for (int i = 0; i < N; i++) {
				char prev = '!';
				ArrayList<Pairs> tmp = new ArrayList<Pairs>();
				for (int j = 0; j < s[i].length(); j++) {
					char cur = s[i].charAt(j);
					if (cur == prev) {
						Pairs p = tmp.get(tmp.size() - 1);
						p.count++;
					} else {
						tmp.add(new Pairs(cur, 1));
					}
					prev = cur;
				}
				list.add(tmp);
			}
			boolean solvable = true;
			int n = list.get(0).size();
			for (int i = 1; i < list.size(); i++) {
				if (n != list.get(i).size()) {
					solvable = false;
					break;
				}
			}
			for (int i = 0; solvable &&i < n; i++) {
				char cc = list.get(0).get(i).c;
				for (int j = 1; j < list.size(); j++) {
					if (cc != list.get(j).get(i).c) {
						solvable = false;
						break;
					}
				}
			}
			if(solvable){
				int result = 0;
				
				for(int i = 0; i < n; i++){
					int min = Integer.MAX_VALUE;
					for(int j = 0; j < list.size(); j++){
						int num = 0;
						int tmp = list.get(j).get(i).count;
						for(int k = 0; k < list.size(); k++){
							num += Math.abs(tmp - list.get(k).get(i).count);
						}
						if(num < min){
							min = num;
						}
					}
					result += min;
				}
				out.write("Case #" + tc + ": " + result + "\n");
			}else{
				out.write("Case #" + tc + ": Fegla Won\n");
			}
		}
		in.close();
		out.flush();
		out.close();
	}
}
