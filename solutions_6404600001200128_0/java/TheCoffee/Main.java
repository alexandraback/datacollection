import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
		
		int cases = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < cases; i++)
		{
			System.out.print("Case #" + (i+1) + ": ");
			
			int periods = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int[] mushrooms = new int[periods];
			for(int j = 0; j < periods; j++)
			{
				mushrooms[j] = Integer.parseInt(st.nextToken());
			}
			
			process(mushrooms);
		}
	}
	
	public static void process(int[] mushrooms)
	{	
		method1(mushrooms);
		method2(mushrooms);
	}
	
	public static void method1(int[] mushrooms)
	{
		//System.out.println(Arrays.toString(mushrooms));
		
		int eaten = 0;
		int prev = mushrooms[0];
		for(int i = 1; i < mushrooms.length; i++)
		{
			if(mushrooms[i] < prev)
			{
				eaten += prev - mushrooms[i];
			}
			prev = mushrooms[i];
		}
		
		System.out.print("" + eaten);
	}
	
	public static void method2(int[] mushrooms)
	{
		int maxInPeriod = 0;
		int prev = mushrooms[0];
		for(int i = 1; i < mushrooms.length; i++)
		{
			if((prev - mushrooms[i]) > maxInPeriod)
			{
				maxInPeriod = prev - mushrooms[i];
			}
			prev = mushrooms[i];
		}
		
		int eaten = 0;
		prev = mushrooms[0];
		for(int i = 1; i < mushrooms.length; i++)
		{
			int potentiallyEaten = mushrooms[i] - prev;
			if(prev < maxInPeriod)
			{
				eaten += prev;
			}
			else
			{
				eaten += maxInPeriod;
			}
			
			prev = mushrooms[i];
		}
		
		int answer = maxInPeriod * (mushrooms.length-1);
		System.out.println(" " + eaten);
	}

}	
