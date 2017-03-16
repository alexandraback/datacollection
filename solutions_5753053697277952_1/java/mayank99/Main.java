import java.util.*;
import java.io.*;

public class Main {
	public static void main(String args[]) {
		Input input = new Input();
		Output output = new Output();

		int t = input.nextInt();

		for(int ii=1;ii<=t;ii++) {
			int n = input.nextInt();
			int[] a = new int[n];

			for (int i=0;i<n;i++) {
				a[i] = input.nextInt();
			}
			output.print("Case #"+ii+": ");

			int max=0;
			int mi=-1;
			int ms=-1;
			int cnt=1000;
			while(cnt!=0) {
				cnt = 0;
				max=0;
				mi=-1;
				ms=-1;
				for (int i=0;i<n;i++) {
					if (a[i]>=max) {
						max=a[i];
						ms=mi;
						mi=i;
					} else if((ms==-1)||(a[i]>=a[ms])) {
						ms = i;
					}
					cnt+=a[i];
				}
				//System.out.println(" mi is "+ mi +" ms is "+ ms);

				if(cnt>0) {
					if (a[mi]==a[ms]) {
						if((a[mi]==1)&&(cnt==3)) {
								char ch1 = (char)('A' + mi);
								output.print(ch1);
								output.print(" ");
								a[mi]--;
								cnt-=1;
						} else {
								char ch1 = (char)('A' + mi);
								char ch2 = (char)('A' + ms);
								output.print(ch1);
								output.print(ch2);
								output.print(" ");
								a[mi]--;
								a[ms]--;
								cnt-=2;
						}
					} else {
						char ch1 = (char)('A' + mi);
						output.print(ch1);
						if(a[mi]>1) {
							output.print(ch1);
							a[mi]--;	
							cnt-=1;
						}
						a[mi]--;
						cnt-=1;
						output.print(" ");
					}
				}
			}
			output.println();
		//	output.flush();
		}
		output.flush();
	}
}
class Input {
	StringTokenizer st;
	BufferedReader br;

	Input() {
		InputStreamReader isr = new InputStreamReader(System.in);
		br = new BufferedReader(isr);
	}

	private String nextToken() {
		String res = "";
		try {
			while (st==null || (!st.hasMoreElements())) {
				String line = br.readLine();
				st = new StringTokenizer(line);
			}
			res = st.nextToken();
		} catch (IOException e) {
			res = null;
		}
		return res;
	}

	public long nextLong() {
		String res = nextToken();
		return Long.parseLong(res);
	}

	public int nextInt() {
		String res = nextToken();
		return Integer.parseInt(res);
	}

	public String nextString() {
		return nextToken();
	}

	public double nextDouble() {
		String res = nextToken();
		return Double.parseDouble(res);
	}
}

class Output {
	PrintWriter pw;
	Output() {
		OutputStreamWriter osw = new OutputStreamWriter(System.out);
		pw = new PrintWriter(osw);
	}

	public void print(Object a) {
		pw.print(a);
	}

	public void println(Object a) {
		pw.println(a);
	}

	public void println() {
		pw.println();
	}

	public void flush() {
		pw.flush();
	}
}