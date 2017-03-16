import java.util.*;
import java.io.*;

public class MagicTrick {
	
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		
		int T = io.getInt();
		for (int test = 1; test <= T; test++) {
			HashSet<Integer> nums = new HashSet<Integer>();
			int r = io.getInt();
			for (int i = 1; i <= 4; i++) {
				for (int j = 1; j <= 4; j++) {
					int num = io.getInt();
					if (i == r) {
						nums.add(num);
					}
				}
			}
			r = io.getInt();
			int res = -1;
			for (int i = 1; i <= 4; i++) {
				for (int j = 1; j <= 4; j++) {
					int num = io.getInt();
					if (i == r && nums.contains(num)) {
						if (res == -1) {
							res = num;
						} else {
							res = -2;
						}
					}
				}
			}
			io.print("Case #" + test + ": ");
			if (res == -2) {
				io.println("Bad magician!");
			} else if (res != -1) {
				io.println(res);
			} else {
				io.println("Volunteer cheated!");
			}
		}
		
		io.close();
	}
	
	static class Kattio extends PrintWriter {
	    public Kattio(InputStream i) {
		super(new BufferedOutputStream(System.out));
		r = new BufferedReader(new InputStreamReader(i));
	    }
	    public Kattio(InputStream i, OutputStream o) {
		super(new BufferedOutputStream(o));
		r = new BufferedReader(new InputStreamReader(i));
	    }

	    public boolean hasMoreTokens() {
		return peekToken() != null;
	    }

	    public int getInt() {
		return Integer.parseInt(nextToken());
	    }

	    public double getDouble() { 
		return Double.parseDouble(nextToken());
	    }

	    public long getLong() {
		return Long.parseLong(nextToken());
	    }

	    public String getWord() {
		return nextToken();
	    }

	    private BufferedReader r;
	    private String line;
	    private StringTokenizer st;
	    private String token;

	    private String peekToken() {
		if (token == null) 
		    try {
			while (st == null || !st.hasMoreTokens()) {
			    line = r.readLine();
			    if (line == null) return null;
			    st = new StringTokenizer(line);
			}
			token = st.nextToken();
		    } catch (IOException e) { }
		return token;
	    }

	    private String nextToken() {
		String ans = peekToken();
		token = null;
		return ans;
	    }
	}
}
