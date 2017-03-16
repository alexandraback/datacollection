import java.io.*;
import java.math.*;
import java.util.*;
import java.util.concurrent.locks.ReentrantReadWriteLock.ReadLock;

public class Round1B_A implements Runnable {
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;
	boolean file = true;
	String fileName = "A-small";

	public static void main(String[] args) throws Exception {
		new Round1B_A().run();
	}

	private String next() throws Exception {
		if (st == null || !st.hasMoreElements())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	private int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	private long nextLong() throws Exception {
		return Long.parseLong(next());
	}

	private double nextDouble() throws Exception {
		return Double.parseDouble(next());
	}

	public void run() {
		try {
			if (file)
				in = new BufferedReader(new FileReader(fileName+".in"));
			else
				in = new BufferedReader(new InputStreamReader(System.in));
			if (file)
				out = new PrintWriter(new FileWriter(fileName+".out"));
			else
				out = new PrintWriter(System.out);
			solve();
		} catch (Exception ex) {
			throw new RuntimeException(ex);
		} finally {
			out.close();
		}
	}

	public void solve() throws Exception {
		long oo = 100000000000L;
		int cases = Integer.parseInt(in.readLine());
		for(int step = 1; step <= cases; step++){
			int n = nextInt();
			String []sp = new  String[n];
			List<Integer> a[] = new List[n];
			TreeSet<String> set = new TreeSet<String>();
			for(int i=0; i<n; i++) {
				a[i] = new ArrayList<Integer>();
				sp[i] = next();
				char cc = sp[i].charAt(0);
				int cnt = 0;
//				System.out.println(sp[i]);
				String res = "";
				for(int j=0; j<sp[i].length(); j++) {
					if(sp[i].charAt(j) == cc) {
						res += cc;
						while(j<sp[i].length() && sp[i].charAt(j) == cc) {
							cnt++;
							j++;
						}
						
						if (j < sp[i].length())
							cc = sp[i].charAt(j);
						a[i].add(cnt);
						cnt = 0;
						j--;
					}
				}
				set.add(res);
			}
			if(set.size() > 1) {
				out.println("Case #"+step+": Fegla Won");
				continue;
			}
			int total = 0;
			for(int i = 0; i<a[0].size(); i++) {
				int from = Integer.MAX_VALUE/2, to = 0;
				for(int j=0; j<n; j++){
					from = Math.min(from, a[j].get(i));
					to = Math.max(to, a[j].get(i));
				}
				int min = Integer.MAX_VALUE/2;
				for(int tst = from; tst <= to; tst++) {
					int curSum = 0;
					for(int j=0; j<n; j++){
						curSum += Math.abs(tst-a[j].get(i));
					}
					if(curSum < min)
						min = curSum;
				}
				total += min;
			}
//			for(int i=0; i<n; i++) {
//				System.out.println(a[i]);
//			}
//			System.out.println(set);
			out.println("Case #"+step+": "+total);
		}
	}
}