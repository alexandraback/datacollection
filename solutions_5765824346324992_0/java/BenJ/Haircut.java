package src;
import java.io.BufferedReader;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;


public class Haircut
{
	public static void main(String [] args) throws IOException
	{
		List<String> text = readTextFile("Round1A/B-small-attempt2.in");
		
		int numCases = Integer.parseInt(text.remove(0));
		
		for(int i =  1; i <= numCases; i++)
		{
			String[] BN = text.remove(0).split(" ");
			String[] M  = text.remove(0).split(" ");
			
			// Print solution
			System.out.println("Case #" + i + ": " + H(BN, M));
		}
	}
	
	public static String H(String[] BN, String[] M)
	{
		int b = Integer.parseInt(BN[0]);
		int n = Integer.parseInt(BN[1]);
		
		int[] times = new int[M.length];
		for(int i = 0; i < times.length; i++)
			times[i] = Integer.parseInt(M[i]);
		
		int lcm = lcm(times);
		
		int sum = 0;		
		for(int i = 0; i < times.length; i++)
			sum += lcm / times[i];
		
		n = n % sum + sum;
		
		int time = 0;
		while(n > 0)
		{
			for(int barber = 0; barber < times.length; barber++)
			{
				if(time % times[barber] == 0)
					n--;
				if(n == 0)
					return "" + (barber+1);
			}
			time++;
		}
		return null;
	}
	
	public static int gcd(int a, int b)
	{
		while(b > 0)
		{
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}
	
	public static int lcm(int a, int b)
	{
		return a * b / gcd(a, b);
	}
	
	public static int lcm(int[] args)
	{
		int result = lcm(args[0], args[1]);
		for(int i = 2; i < args.length; i++)
		{
			result = lcm(result, args[i]);
		}
		return result;
	}

	final static Charset ENCODING = StandardCharsets.UTF_8;
	
	static List<String> readTextFile(String filename) throws IOException
	{
		List<String> list = new ArrayList<>();
		
		Path path = Paths.get(filename);
		try (BufferedReader reader = Files.newBufferedReader(path, ENCODING)) {
			String line;
			while((line = reader.readLine()) != null) {
				list.add(line);
			}
		}
		return list;
	}
}
