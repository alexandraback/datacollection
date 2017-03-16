import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		//InputStream inputStream = System.in;
		//OutputStream outputStream = System.out;

		InputStream inputStream = new FileInputStream("input.txt");
		OutputStream outputStream = new FileOutputStream("output.txt");

		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);

		TaskB solver = new TaskB();
		int t = in.nextInt();
		for(int i=0; i<t; i++)
			solver.solve(in, out, i+1);

		out.close();
	}
}

class TaskB {

	public void solve(InputReader in, OutputWriter out, int test) {
		int r = in.nextInt();
		int c = in.nextInt();
		int n = in.nextInt();
		int pow=1,p=1;
		pow = 1<<(r*c);
		p = r*c;
		//ile(pow<=r*c) { pow<<=1; p++; }
		int[] pow2 = new int[p];
		pow2[0] = 1;
		for(int i=1; i<p; i++) pow2[i] = pow2[i-1]*2;
		
		int ans=c*(r-1)+r*(c-1);
		for(int mask=0; mask<pow; mask++){
			if(Integer.bitCount(mask)!=n) continue;
			int ii=0,jj=0;
			int[][] a = new int[r][c];
			for(int j=0; j<p; j++){
				a[ii][jj] = (mask&pow2[j]) > 0 ? 1 : 0;
				jj++; if(jj==c) { jj=0; ii++; }
			}
			
			int cnt=0;
			for(int j=0; j<r; j++){
				for(int k=0; k<c-1; k++){
					if(a[j][k]==1 && a[j][k+1]==1) cnt++;
				}
			}
			for(int j=0; j<c; j++)
				for(int k=0; k<r-1; k++)
					if(a[k][j]==1 && a[k+1][j]==1) cnt++;
			
			ans = Math.min(ans, cnt);
		}
		
		out.writeln("Case #"+test+": "+ans);
		
	}

}

class InputReader {

	BufferedReader reader;
	StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		tokenizer = null;
		reader = new BufferedReader(new InputStreamReader(stream));
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException();
			}
		}

		return tokenizer.nextToken();
	}

	public String nextLine() {
		tokenizer = null;
		try {
			return reader.readLine();
		} catch (IOException e) {
			throw new RuntimeException();
		}
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

	public int[] nextIntArray(int n) {
		int[] res = new int[n];
		for (int i = 0; i < n; i++)
			res[i] = nextInt();

		return res;
	}

}

class OutputWriter {

	PrintWriter out;

	public OutputWriter(OutputStream stream) {
		out = new PrintWriter(
				new BufferedWriter(new OutputStreamWriter(stream)));
	}

	public void write(Object... o) {
		for (Object cur : o)
			out.print(cur);
	}

	public void writeln(Object... o) {
		write(o);
		out.println();
	}

	public void flush() {
		out.flush();
	}

	public void close() {
		out.close();
	}

}