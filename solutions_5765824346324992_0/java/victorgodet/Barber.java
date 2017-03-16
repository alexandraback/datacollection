import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Scanner;


public class Barber {
	
	public static long gcd(long a, long b){
	    if (a<b) return gcd(b,a);
	    if (a%b==0) return b;
	    else return gcd(b, a%b);
	}
	
	public static long lcm(long a, long b){
	    return (a*b)/gcd(a, b);
	}
	
	public static long lcmArray(int[] m)
	{
		long res = m[0];
		for(int i = 1; i < m.length; i++)
			res = lcm(res, m[i]);
		return res;
	}
	
	public static int who(int b, int[] m, long n)
	{
		if(n <= b)
			return (int)n;
		
		int[] wait = new int[b];
		
		for(int i = 0; i < b; i++)
			wait[i] = m[i];
		
		n -= b;
		
		int min = wait[0];
		
		while(n > 0)
		{
			
			for(int i = 0; i < b; i++)
				if(min > wait[i])
					min = wait[i];
			
			for(int i = 0; i < b; i++)
			{
				wait[i] -= min;
				if(wait[i] == 0)
				{
					wait[i] = m[i];
					if(n == 1)
						return i+1;
					n--;
				}
			}
		}
		return -1;
	}
	
	public static void main(String[] args)
	{
		
		Scanner s = new Scanner(System.in);
		try {
			s = new Scanner(new FileReader("input.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			s.close();
			return;
		}
		
		Writer out = null;
		
		try {
			out = new BufferedWriter(new OutputStreamWriter(
	              new FileOutputStream("output.txt"), "utf-8"));
		}
		
		catch ( IOException e ) {
            e.printStackTrace();
        }
		
		
		
		int t = s.nextInt();
		

		
		int b, res;
		
		long n;
		
		for(int i = 0; i < t; i++)
		{ 	
			System.out.println("Case #" + (i+1));
			
			b = s.nextInt();
			n = s.nextInt();
			
			int[] m = new int[b];
			
			for(int j = 0; j < b; j++)
				m[j] = s.nextInt();
			
			long ppcm = lcmArray(m);
			
			long period = 0;
			for(int j = 0; j < b; j++)
				period += ppcm/m[j];
			
			if(period != 0)
				n = n % period;
			if(n == 0)
				n = period;
			
			res = who(b, m, n);
			
			try {
				out.write("Case #"+(i+1)+": "+ res + "\n");
			}
			catch ( IOException e ) {
	            e.printStackTrace();
	        }
		}
		
		
		
		try {
		out.close();
		}
		catch ( IOException e ) {
            e.printStackTrace();
        }
		
		s.close();
		
	}
}
