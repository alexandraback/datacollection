
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;


public class TheRepeater {

	public static void main(String[] args) {
		Scanner s = new Scanner(Logger.in);
		int T = Integer.parseInt(s.nextLine());
		for(int t = 0; t < T; t++) {
			int N = Integer.parseInt(s.nextLine());
			List<Entry> le = new LinkedList<>();
			for(int n = 0; n < N; n++) {
				String line = s.nextLine().trim();
				Entry e = new Entry(line.length());
				e.count = process(line, e.c, e.i);
				le.add(e);
			}
			boolean ok = true;
			for(int n = 1; n < N; n++) {
				if(le.get(0).count != le.get(n).count) {
					ok = false;
					break;
				}
				if(!check(le.get(0).c,le.get(n).c, le.get(0).count)) {
					ok = false;
					break;
				}
			}
			if(!ok) {
				Logger.out.println("Case #" + (t + 1) + ": Fegla Won");
			} else {
				int steps = 0;
				for(int j = 0; j < le.get(0).count; j++) {
					List<Integer> li = new LinkedList<>();
					for(Entry e : le) {
						li.add(e.i[j]);
					}
					Collections.sort(li);
					int median = li.get(li.size() / 2);
					for(Integer ii : li) {
						steps += Math.abs(ii - median);
					}
				}
				Logger.out.println("Case #" + (t + 1) + ": " + steps);
			}
		}
		s.close();
	}
	
	public static class Entry {
		public Entry(int size) {
			c = new char[size];
			i = new int[size];
		}
		int count;
		char[] c;
		int[] i;
	}
	
	public static int process(String str, char[] carr, int[] iarr) {
		char lastc = 0;
		int count = 0;
		char[] chars = str.toCharArray();
		for (int i = 0, n = chars.length; i < n; i++) {
		    char c = chars[i];
		    if(lastc != c) {
		    	lastc = c;
		    	carr[count] = c;
		    	iarr[count] = 1;
		    	count++;
		    } else {
		    	iarr[count - 1]++;		    	
		    }
		}
		return count;
	}
	
	public static boolean check(char[] c1, char[] c2, int count) {
		for(int i = 0; i < count; i++) {
			if(c1[i] != c2[i])
				return false;
		}
		return true;
	}
}
