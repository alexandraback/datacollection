package Round2C;

import java.util.*;
import java.io.*;
public class A 
{
	public static void main(String[] args) throws Throwable
	{
		new A().solve();
	}

	FasterScanner in=new FasterScanner();
	PrintWriter out=new PrintWriter(System.out);

	long mod=(int)1e9+7;
	public void solve() throws Throwable
	{
		out = new PrintWriter(new File("src/Round2C/outputA.txt"));
		int tt=in.nextInt();
		for(int ii=1;ii<=tt;ii++)
		{
			int n=in.nextInt();
			s[] arr=new s[n];
			for(int i=0;i<n;i++)
			{
				int x=in.nextInt();
				arr[i]=new s((char)('A'+i),x);
			}
			Arrays.sort(arr);
			out.printf("Case #%d: ", ii);
			int len=arr.length-1;
			
			while(arr[len].count!=arr[len-1].count)
			{
				arr[len].count--;
				out.print(arr[len].c+" ");
			}
			for(int i=0;i<len-1;i++)
			{
				for(int j=0;j<arr[i].count;j++)
				{
					out.print(arr[i].c+" ");
				}
			}
			for(int i=0;i<arr[len].count;i++)
			{
				out.print(arr[len].c+""+arr[len-1].c+" ");
			}
			out.println();
		}
		out.close();
	}

	
	class s implements Comparable<s>
	{
		char c;
		int count;
		public s(char c,int i)
		{
			this.c=c;
			this.count=i;
		}

		@Override
		public int compareTo(s o) {
			// TODO Auto-generated method stub
			if(this.count!=o.count)
				return Integer.compare(this.count, o.count);
			else
				return Integer.compare(this.c, o.c);
		}
	}

	public static class FasterScanner {
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		public int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = System.in.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}
		public String nextLine() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndOfLine(c));
			return res.toString();
		}
		private boolean isEndOfLine(int c) {
			return c=='\n' || c=='\r' || c==-1;
		}
		public String nextString() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}
		private boolean isSpaceChar(int c) {
			return c=='\n' || c=='\r' || c==-1 || c==' ' || c=='\t';
		}
		public long nextLong() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}
		public int nextInt() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}

			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}
		public double nextDouble()
		{
			return Double.parseDouble(nextString());
		}
		public int[] nextIntArray(int n)
		{
			int[] arr=new int[n];
			for(int i=0;i<n;i++)
			{
				arr[i]=nextInt();
			}
			return arr;
		}
		public long[] nextLongArray(int n)
		{
			long[] arr=new long[n];
			for(int i=0;i<n;i++)
			{
				arr[i]=nextLong();
			}
			return arr;
		}
		public int[] nextIntArray10(int n)
		{
			int[] arr=new int[n+1];
			for(int i=1;i<=n;i++)
			{
				arr[i]=nextInt();
			}
			return arr;
		}
		public long[] nextLongArray10(int n)
		{
			long[] arr=new long[n+1];
			for(int i=1;i<=n;i++)
			{
				arr[i]=nextLong();
			}
			return arr;
		}
		public int[] nextIntArray11(int n)
		{
			int[] arr=new int[n+2];
			for(int i=1;i<=n;i++)
			{
				arr[i]=nextInt();
			}
			return arr;
		}
		public long[] nextLongArray11(int n)
		{
			long[] arr=new long[n+2];
			for(int i=1;i<=n;i++)
			{
				arr[i]=nextLong();
			}
			return arr;
		}
	}

}