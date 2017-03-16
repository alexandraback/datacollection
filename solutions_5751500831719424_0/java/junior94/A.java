import java.io.*;
import java.util.StringTokenizer;

public class A {
	
	public static Reader in = new Reader();
	public static Writer out = new Writer();

	public static void main(String[] args) {
		final int T = in.readInt();
		
		for(int t=1; t<=T; t++) {
			int N = in.readInt();
			
			String[] strings = new String[N];
			
			for(int i=0; i<N; i++) {
				strings[i] = in.readLine();
			}
			
			out.printfln("Case #%d: %s", t, getAns(strings, N));
		}
		out.close();
	}
	
	public static String getAns(String[] strings, int N) {
		int[] pos = new int[N];
		int[] counts = new int[N];
		
		int ans = 0;
		
		while(pos[0] < strings[0].length()) {
			char c = strings[0].charAt(pos[0]);
			
			int mid = 0;
			
			for(int i=0; i<N; i++) {
				int count = 0;
				for(; pos[i]<strings[i].length() && strings[i].charAt(pos[i])==c; pos[i]++) {
					count++;
				}
				if(count==0) {
					return "Fegla Won";
				}
				counts[i] = count;
				mid += count;
			}
			
			mid /= N;
			
			for(int i=0; i<N; i++) {
				ans += Math.abs(counts[i] - mid);
			}
		}
		
		for(int i=0; i<N; i++) if(pos[i] < strings[i].length()) return "Fegla Won";
		
		return String.valueOf(ans);
	}
}

class Reader {
	private BufferedReader input;
	private StringTokenizer line = new StringTokenizer("");
	
	public Reader() {
		input = new BufferedReader(new InputStreamReader(System.in));
	}

	public Reader(String s) {
		try {
			input = new BufferedReader(new FileReader(s));
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}
	
	public void fill() {
		try {
			if(!line.hasMoreTokens()) line = new StringTokenizer(input.readLine());
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}
	
	public double nextDouble() {
		fill();
		return Double.parseDouble(line.nextToken());
	}
	
	public String nextWord() {
		fill();
		return line.nextToken();
	}
	
	public int nextInt() {
		fill();
		return Integer.parseInt(line.nextToken());
	}

	public long nextLong() {
		fill();
		return Long.parseLong(line.nextToken());
	}
	
	public double readDouble() {
		double d = 0;
		try {
			d = Double.parseDouble(input.readLine());
		} catch(IOException io) {io.printStackTrace(); System.exit(0);}
		return d;
	}
	
	public int readInt() {
		int i = 0;
		try {
			i = Integer.parseInt(input.readLine());
		} catch(IOException io) {io.printStackTrace(); System.exit(0);}
		return i;
	}
	
	public int[] readInts(int n) {
		int[] a = new int[n];
		for(int i=0; i<n; i++)
			a[i] = nextInt();
		return a;
	}
	
	public void fillInts(int[] a) {
		for(int i=0; i<a.length; i++)
			a[i] = nextInt();
	}
	
	public long readLong() {
		long l = 0;
		try {
			l = Long.parseLong(input.readLine());
		} catch(IOException io) {io.printStackTrace(); System.exit(0);}
		return l;
	}
	
	public String readLine() {
		String s = "";
		try {
			s = input.readLine();
		} catch(IOException io) {io.printStackTrace(); System.exit(0);}
		return s;
	}
}

class Writer {
	
	private BufferedWriter output;
	
	public Writer() {
		output = new BufferedWriter(new OutputStreamWriter(System.out));
	}
	
	public Writer(String s) {
		try {
			output = new BufferedWriter(new FileWriter(s));
		} catch(Exception ex) { ex.printStackTrace(); System.exit(0);}
	}
	
	public void println() {
		try {
			output.append("\n");
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}

	public void print(Object o) {
		try {
			output.append(o.toString());
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}
	
	public void println(Object o) {
		try {
			output.append(o.toString()+"\n");
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}

	public void printf(String format, Object... args) {
		try {
			output.append(String.format(format, args));
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}
	
	public void printfln(String format, Object... args) {
		try {
			output.append(String.format(format, args)+"\n");
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}
	
	public void flush() {
		try {
			output.flush();
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}
	
	public void close() {
		try {
			output.close();
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}
}