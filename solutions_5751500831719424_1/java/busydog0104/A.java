package Round1B;

import java.util.*;
import java.io.*;

/*
 * author:yanghui
 */
public class A {

	class FastIO {
		BufferedReader br;
		StringTokenizer st;
		PrintWriter out;

		public FastIO(File in, File o) {
			try {
				br = new BufferedReader(new FileReader(in));
				out = new PrintWriter(new FileWriter(o));
			} catch (Exception e) {
				e.printStackTrace();
			}
			eat("");
		}

		public FastIO() {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			eat("");
		}

		public void eat(String s) {
			st = new StringTokenizer(s);
		}

		public String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				throw new IOError(e);
			}
		}

		public boolean hasNext() {
			while (!st.hasMoreTokens()) {
				String s = nextLine();
				if (s == null)
					return false;
				eat(s);
			}
			return true;
		}

		public String next() {
			hasNext();
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public void print(String ans) {
			out.print(ans);
			out.flush();
		}

		public void print(int ans) {
			out.print(ans);
			out.flush();
		}

		public void print(long ans) {
			out.print(ans);
			out.flush();
		}

		public void print(double ans) {
			out.print(ans);
			out.flush();
		}

		public void println(String ans) {
			out.println(ans);
			out.flush();
		}

		public void println(int ans) {
			out.println(ans);
			out.flush();
		}

		public void println(long ans) {
			out.println(ans);
			out.flush();
		}

		public void println(double ans) {
			out.println(ans);
			out.flush();
		}

		public void println() {
			println("");
			out.flush();
		}

		public void printf(String arg0, Object... arg1) {
			out.printf(arg0, arg1);
			out.flush();
		}

		public void println(int[] ans) {
			for (int i = 0; i < ans.length; i++)
				print(ans[i] + " ");
			println();
		}

		public void println(long[] ans) {
			for (int i = 0; i < ans.length; i++)
				print(ans[i] + " ");
			println();
		}

		public void println(double[] ans) {
			for (int i = 0; i < ans.length; i++)
				print(ans[i] + " ");
			println();
		}

		public void println(Object... ans) {
			for (Object cur : ans)
				print(cur.toString() + " ");
			println();
		}

		public void println(Object ans[][]) {
			for (int i = 0; i < ans.length; i++) {
				for (int j = 0; j < ans[i].length; i++) {
					print(ans[i] + " ");
				}
				println();
			}
		}

		public void println(int ans[][]) {
			for (int i = 0; i < ans.length; i++) {
				for (int j = 0; j < ans[i].length; i++) {
					print(ans[i] + " ");
				}
				println();
			}
		}

		public void println(long ans[][]) {
			for (int i = 0; i < ans.length; i++) {
				for (int j = 0; j < ans[i].length; i++) {
					print(ans[i] + " ");
				}
				println();
			}
		}

		public void println(double ans[][]) {
			for (int i = 0; i < ans.length; i++) {
				for (int j = 0; j < ans[i].length; i++) {
					print(ans[i] + " ");
				}
				println();
			}
		}

		public void println(List<Object> ans) {
			for (Object i : ans) {
				print(i.toString() + " ");
			}
			println();
		}

		public void close() {
			out.flush();
			out.close();
		}
	}

	FastIO scan = new FastIO(new File("in"), new File("out"));

	// FastIO scan = new FastIO();
	public class data{
		char cur;
		int cnt;
		public data(char cur , int cnt){
			this.cur = cur;
			this.cnt = cnt;
		}
		@Override
		public String toString() {
			return "data [cur=" + cur + ", cnt=" + cnt + "]";
		}
	}

	public ArrayList<data> solve(String str) {
		ArrayList<data> list = new ArrayList<data>();
		char pre = ' ';
		int cnt = 1;
		for (int i = 0; i < str.length(); i++) {
			if (pre == ' ') {
				pre = str.charAt(i);
				continue;
			} else {
				if (pre == str.charAt(i)) {
					cnt ++;
					continue;
				} else {
					list.add(new data(pre,cnt));
					pre = str.charAt(i);
					cnt = 1;
				}
			}
		}
		list.add(new data(pre,cnt));
		return list;
	}

	public void work() {
		int n = scan.nextInt();
		String re[] = new String[n];
		ArrayList<data> result[] = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			re[i] = scan.next();
			result[i] = solve(re[i]);
		}
		boolean flag = true;
		int size = result[0].size();
		for(int i = 0 ; i < n ; i ++){
			if(result[i].size() != size){
				flag = false;
				break;
			}
		}
		if(flag){
			ArrayList<data> temp = result[0];
			int cnt[][] = new int[n][temp.size()];
			int max[] = new int[temp.size()];
			int min_[] = new int[temp.size()];
			Arrays.fill(min_, Integer.MAX_VALUE);
			for(int i = 0 ; i < cnt[0].length ; i ++){
				cnt[0][i] = temp.get(i).cnt;
			}
			boolean f = true;
			for(int i = 1 ; i < n ; i ++){
				for(int j = 0 ; j < temp.size() ; j ++){
					if(result[i].get(j).cur == temp.get(j).cur){
						cnt[i][j] = result[i].get(j).cnt;
						max[j] = Math.max(max[j], cnt[i][j]);
						min_[j] = Math.min(min_[j], cnt[i][j]);
					}else{
						f = false;
						break;
					}
				}
			}
			if(f){
				int ans = 0;
				for(int j = 0 ; j < temp.size() ; j ++){
					int min = Integer.MAX_VALUE;
					for(int k = min_[j] ; k <= max[j]; k ++){
						int tt = 0;
						for(int i = 0 ; i < n ; i ++){
							tt += Math.abs(cnt[i][j] - k);
						}
						min = Math.min(tt, min);
					}
					ans += min;
				}
				scan.println(ans);
			}else{
				scan.println("Fegla Won");
			}
		}else{
			scan.println("Fegla Won");
		}

	}

	public void run() {

		int t = scan.nextInt();
		for (int i = 1; i <= t; i++) {
			scan.print("Case #" + i + ": ");
			work();
		}
		scan.close();
	}

	public static void main(String args[]) throws Exception {
		new A().run();
	}
}
