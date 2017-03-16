package RoundA;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class B_Haircut {
	public static BigInteger lcm(BigInteger a, BigInteger b)
	{
		return a.multiply(b).divide(a.gcd(b));
	}
	
	
	public static int solve(int[] m, int n)
	{
		BigInteger l = new BigInteger(String.valueOf(m[0]));
		for(int i = 1; i < m.length; i++)
			l = lcm(l, new BigInteger(String.valueOf(m[i])));
		if(l.compareTo(new BigInteger(String.valueOf(n))) == -1)
		{
			int ln = l.intValue();
			int p = 0;
			for(int x:m)
				p += ln / x;
			n = n % p;
		}
			
		int result = 0;
		int[] time = new int[m.length];
		int t = 0;
		while(t <= n)
		{
			int min = Integer.MAX_VALUE;
			for(int i = 0; i < m.length; i++)
			{
				if(time[i] == 0){
					time[i] = m[i];
					if(t == n)
						return i;
					t ++;
				}
				if(time[i] < min)
					min = time[i];
			}
			for(int i = 0; i < m.length; i++)
				time[i] -= min;
		}
		return result;
	}
	public static void main(String[] args) {
		File fin = new File("src/RoundA/B-small-attempt1.in.txt");
		Scanner scan;
		try {
			scan = new Scanner(fin);
		
			PrintWriter output = new PrintWriter("src/RoundA/B-small-attempt1.out.txt");
			int N = scan.nextInt();
			for(int i = 0; i < N; i++)
			{
				int b = scan.nextInt();
				int n = scan.nextInt();
				int array[] = new int[b];
				for(int j = 0; j < b; j++)
					array[j] = scan.nextInt();
				
				output.println("Case #" + (i + 1) + ": " + (solve(array, n - 1) + 1) );
			}
			scan.close();
			output.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
