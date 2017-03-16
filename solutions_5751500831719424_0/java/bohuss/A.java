package actual;
import java.io.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;

public class A
{
	String line;
	StringTokenizer inputParser;
	BufferedReader is;
	FileInputStream fstream;
	DataInputStream in;
	
	void openInput(String file)
	{

		//is = new BufferedReader(new InputStreamReader(System.in));//stdin
		try{
			fstream = new FileInputStream(file);
			in = new DataInputStream(fstream);
			is = new BufferedReader(new InputStreamReader(in));
		}catch(Exception e)
		{
			System.err.println(e);
		}

	}
	
	void readNextLine()
	{
		try {
			line = is.readLine();
			inputParser = new StringTokenizer(line, " ");
			//System.err.println("Input: " + line);
		} catch (IOException e) {
			System.err.println("Unexpected IO ERROR: " + e);
		}	
		
	}
	
	int NextInt()
	{
		String n = inputParser.nextToken();
		int val = Integer.parseInt(n);
		
		//System.out.println("I read this number: " + val);
		return val;
	}
	
	long NextLong()
	{
		String n = inputParser.nextToken();
		long val = Long.parseLong(n);
		
		//System.out.println("I read this number: " + val);
		return val;
	}
	
	String NextString()
	{
		String n = inputParser.nextToken();
		return n;
	}
	
	void closeInput()
	{
		try {
			is.close();
		} catch (IOException e) {
			System.err.println("Unexpected IO ERROR: " + e);
		}
			
	}
	
	public static void main(String [] argv)
	{
		new A(argv[0]);
	}
	
	
	public A(String inputFile)
	{
		openInput(inputFile);
		readNextLine();

		int TC = NextInt();
		
		
		for(int tt=0; tt<TC; tt++)
		{	
			
			String output=solve();
			System.out.println("Case #"+(tt+1)+": "+output);
		}
		closeInput();
	}
	
	private String solve() {
		readNextLine();
		int N=NextInt();
		String [] s = new String[N];
		
		for(int i=0; i<N; i++)
		{
			readNextLine();
			s[i]=line;
			
		}
		String x=trim(s[0]);
		for(int i=0; i<N; i++)
		{
			if(trim(s[i]).compareTo(x)!=0)return "Fegla Won";
		}
		int c=cnt(x);
		int [] [] p = new int[N][];
		int [] max = new int[c];
		for(int i=0; i<N; i++)
		{
			p[i]=getCnts(s[i], c);
			for(int j=0; j<c; j++)
				max[j]=Math.max(max[j], p[i][j]);
		}
		
		int ret=0;
		for(int i=0; i<c; i++)
		{
			int now=Integer.MAX_VALUE;
			for(int j=1; j<=max[i]; j++)
			{
				int cnt=0;
				for(int k=0; k<N; k++)
					cnt+=Math.abs(p[k][i]-j);
				now=Math.min(now, cnt);
			}
			ret+=now;
		}
		return ""+ret;
	}
	
	private int[] getCnts(String s, int c) {
		int [] ret = new int[c];
		int N=s.length();
		char x='?';
		int id=-1;
		int cnt=0;
		for(int i=0; i<N; i++)
		{
			
			if(s.charAt(i)!=x)
			{
				x=s.charAt(i);
				id++;
			}
			ret[id]++;
		}
		return ret;
	}

	private int get(String a, String b) {
		int ret=0;
		
		return ret;
	}

	String trim(String s)
	{
		String r="";
		int N=s.length();
		char x='?';
		for(int i=0; i<N; i++)
		{
			if(s.charAt(i)!=x)
			{
				x=s.charAt(i);
				r+=x;
			}
		}
		return r;
	}
	
	int cnt(String s)
	{
		int r=0;
		int N=s.length();
		char x='?';
		for(int i=0; i<N; i++)
		{
			if(s.charAt(i)!=x)
			{
				x=s.charAt(i);
				r++;
			}
		}
		return r;
	}
}

