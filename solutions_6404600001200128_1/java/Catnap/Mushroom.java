import java.util.*;
import java.io.*;

public class Mushroom
{
	public static int n;
	
	public static void main(String[] args) throws IOException
	{
		Scanner sc = new Scanner(new File("Mushroom.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Mushroom.out")));
		
		n = sc.nextInt();
		for (int i = 0; i < n; i++)
		{
			int size = sc.nextInt();
			ArrayList<Integer> plate = new ArrayList<Integer>();
			for (int j = 0; j < size; j++)
			{
				plate.add(sc.nextInt());
			}
			String ans = runTest(plate);
			out.println("Case #" + (i+1) + ": " + ans);
		}
		
		out.close();
		System.exit(0);
	}
	
	public static String runTest(ArrayList<Integer> plate)
	{
		//get the first number and the max diff
		int num1 = 0;
		int max = 0;
		for (int i = 0; i < plate.size() - 1; i++)
		{
			int med = plate.get(i) - plate.get(i+1);
			if (med > 0) num1 += med;
			if (med > max) max = med;
		}
		
		//she eats at max per 10 seconds
		
		//get the second number
		int num2 = 0;
		for (int i = 0; i < plate.size() - 1; i++)
		{
			num2 += Math.min(plate.get(i), max);
		}
		
		return "" + num1 + " " + num2;
	}
}