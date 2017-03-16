import java.io.*;
import java.util.*;


public class A {
	static BufferedReader in;
	static StringTokenizer st;
	static PrintWriter out;
	
	static String nextToken() throws IOException {
		while(st==null || !st.hasMoreTokens()) st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader("A.in"));
		out = new PrintWriter(new FileWriter("A.out"));
		
		int ttt = nextInt();
		for (int tt=1; tt<=ttt; tt++) {
			out.printf("Case #%d: ", tt);
			
			int num = nextInt();
			String[] store = new String[num]; 
			List<Character> sequence = new ArrayList<Character>();
			ArrayList<int[]> freq = new ArrayList<int[]>();
			boolean flag = false;
			
			String first = nextToken();
			for (int i=0; i<first.length(); i++) {
				if (i==0 || first.charAt(i) != first.charAt(i-1)) {
					sequence.add(first.charAt(i));
					freq.add(new int[num]);
					freq.get(freq.size()-1)[0] = 1;
				} else
					freq.get(freq.size()-1)[0]++;
			}
			
			for (int i=1; i<num; i++) {
				String curr = nextToken();
				if (flag) continue;
				int track = -1;
				for (int j=0; j<curr.length(); j++) {
					if (j==0 || curr.charAt(j) != curr.charAt(j-1)) {
						track++;
						if (track >= sequence.size()) break;
						if(curr.charAt(j) != sequence.get(track)) {
							flag = true; break;
						}
						freq.get(track)[i] = 1;
					} else
						freq.get(track)[i]++;
				}
				if (track+1 != sequence.size()) flag = true;
			}
			
			if (flag) out.println("Fegla Won");
			else {
				int ans = 0;
				for (int[] f : freq) {
					Arrays.sort(f);
					for (int i=0; i<f.length; i++)
						ans += Math.abs(f[i] - f[f.length/2]);
				}
				out.println(ans);
			}
		}
		out.close();
	}
}
