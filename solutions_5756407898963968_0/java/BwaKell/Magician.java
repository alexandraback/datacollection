import java.util.*;
import java.io.*;

public class Magician
{
	public static void main(String[] klein)
	{
		final Kattio in = new Kattio(System.in);
		final PrintWriter out = new PrintWriter(System.out);

		int T = in.getInt();
		loop:for(int t = 1; t<=T; t++)
		{
			final int[][] M = new int[4][4];
			final int[] cnt = new int[17];

			final int r1 = in.getInt()-1;
			for(int i = 0; i<4; i++)
				for(int j = 0; j<4; j++)
					M[i][j] = in.getInt();
			for(int i = 0; i<4; i++) cnt[M[r1][i]]++;

			final int r2 = in.getInt()-1;
			for(int i = 0; i<4; i++)
				for(int j = 0; j<4; j++)
					M[i][j] = in.getInt();
			for(int i = 0; i<4; i++) cnt[M[r2][i]]++;

			int ans = -1, num = 0;
			for(int i = 1; i<=16; i++) if(cnt[i]==2){ ans = i; ++num; }

			out.print("Case #"+t+": ");
			if(num==1) out.println(ans);
			else if(num>1) out.println("Bad magician!");
			else out.println("Volunteer cheated!");
		}

		out.flush();
	}

	private static class Kattio
	{
		public Kattio(final InputStream i)
		{
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

		public float getFloat()
		{
			return Float.parseFloat(nextToken());
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
