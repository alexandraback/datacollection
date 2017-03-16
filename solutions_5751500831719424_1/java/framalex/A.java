import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {
	
	class Group {
		char c;
		int num;
		public Group(char c, int num) {
			this.c = c;
			this.num = num;
		}
	}
	public void run() {
		int cases = nextInt();
		for (int cs = 0; cs < cases; ++cs) {
			int n = nextInt();
			String[] str = new String[n];
			for (int i = 0; i < n; ++i) {
				str[i] = nextWord();
			}
			
			ArrayList<Group>[] gg = new ArrayList[n];
			for (int i = 0; i < n; ++i) {
				gg[i] = new ArrayList<Group>();
				
				int cnt = 0;
				for (int j = 0; j < str[i].length(); ++j) {
					++cnt;
					if (j + 1 >= str[i].length() || str[i].charAt(j) != str[i].charAt(j + 1)) {
						gg[i].add(new Group(str[i].charAt(j), cnt));
						cnt = 0;
					}
				}
			}
			
			boolean fail = false;
			for (int i = 0; i < n; ++i) {
				if (gg[i].size() != gg[0].size()) {
					fail = true;
					break;
				}
			}
			int ans = 0;
			if (!fail) {
				for (int i = 0; i < gg[0].size(); ++i) {
					int[] nums = new int[n];
					int min = 1000000;
					int max = 0;
					for (int j = 0; j < n; ++j) {
						if (gg[j].get(i).c != gg[0].get(i).c) {
							fail = true;
							break;
						}
						
						nums[j] = gg[j].get(i).num;
						min = Math.min(min, nums[j]);
						max = Math.max(max, nums[j]);
					}
					
					int curAns = Integer.MAX_VALUE;
					for (int j = min; j <= max; ++j) {
						int tmp = 0;
						for (int k = 0; k < n; ++k) {
							tmp += Math.abs(nums[k] - j);
						}
						
						if (tmp < curAns) {
							curAns = tmp;
						}
					}
					ans += curAns;
				}
			}
			if (fail) {
				out.println("Case #" + (cs+1) + ": Fegla Won");
			}
			else {
				out.println("Case #" + (cs+1) + ": " + ans);
			}
		}
		out.flush();
	}
	
	private static BufferedReader br = null;
	private static StringTokenizer stk = null;
	private static PrintWriter out = null;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(new File("D:\\A2.txt")));
		out = new PrintWriter("D:\\AA.txt");
		(new Thread(new A())).start();
	}
	
	public void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public String nextLine() {
		try {
			return (br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	public int nextInt() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Integer.parseInt(stk.nextToken());
	}
	
	public long nextLong() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Long.parseLong(stk.nextToken());
	}
	
	public double nextDouble() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Double.parseDouble(stk.nextToken());
	}
	
	public String nextWord() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return (stk.nextToken());
	}
}
