import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Scanner;


public class Round1A {

	public static int first(int[] a)
	{
		int n = a.length, res = 0;
		for(int i = 0; i < n-1; i++)
			if(a[i] > a[i+1])
				res += a[i] - a[i+1];
		return res;
	}
	
	public static int second(int[] a)
	{
		int rate = 0;
		
		int n = a.length, res = 0;
		for(int i = 0; i < n-1; i++)
			if(rate < (a[i] - a[i+1]))
				rate = a[i] - a[i+1];
		
		for(int i = 0; i < n-1; i++)
			res += Math.min(a[i], rate);
		
		return res;
		
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
		

		
		int n, res1, res2;
		
		for(int i = 0; i < t; i++)
		{ 	
			System.out.println("Case #" + (i+1));
			
			n = s.nextInt();
			
			int[] a = new int[n];
			
			for(int j = 0; j < n; j++)
				a[j] = s.nextInt();
			
			res1 = first(a);
			res2 = second(a);
			
			try {
				out.write("Case #"+(i+1)+": "+ res1 +" "+ res2 + "\n");
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
