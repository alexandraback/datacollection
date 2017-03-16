import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.TreeMap;

public class ProblemA {
	private static Scanner in;
	private static PrintWriter out;
	private static int n, l;

	private void solve() {
		int n, min, max, count, actions;
		StringBuilder[] strs;
		char cur;
		boolean end;
		TreeMap<Integer, Integer> map;
		
		n = in.nextInt();
		strs = new StringBuilder[n];
		for (int i = 0; i < n; i++) {
			strs[i] = new StringBuilder(in.next());
		}
		map = new TreeMap<>();
		cur = strs[0].charAt(0);
		end = false;
		actions = 0;
		while (!end) {
			map.clear();
			for (int i = 0; i < n; i++) {
				count = 0;
				while (strs[i].length() > 0 && strs[i].charAt(0) == cur) {
					count++;
					strs[i].deleteCharAt(0);
				}
				if (count == 0) {
					out.print("Fegla Won");
					return;
				}
				map.put(count, map.containsKey(count) ? map.get(count) + 1 : 1);
			}
			while(map.size() > 1) {
				min = map.firstKey();
				max = map.lastKey();
				if (map.get(min) < map.get(max)) {
					actions += map.get(min);
					map.put(min + 1, map.containsKey(min + 1) ? map.get(min + 1) + map.get(min) : map.get(min));
					map.remove(min);
				} else {
					actions += map.get(max);
					map.put(max - 1, map.containsKey(max - 1) ? map.get(max - 1) + map.get(max) : map.get(max));
					map.remove(max);
				}
			}
			end = true;
			for (int i = 0; i < n; i++) {
				if (strs[i].length() >= 1) {
					end = false;
					cur = strs[i].charAt(0);
					break;
				}
			}
		}
		out.print(actions);
	}

	public static void main(String[] args) {
		try {
			in = new Scanner(new FileReader(args[0]));
			out = new PrintWriter(new FileWriter(args[1]));
			int tests = in.nextInt();
			for (int test = 1; test <= tests; test++) {
				System.out.println("Processing case #" + test);
				out.print("Case #" + test + ": ");
				new ProblemA().solve();
				out.println();
			}
			in.close();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
