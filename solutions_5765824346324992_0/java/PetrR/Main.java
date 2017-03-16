
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.PriorityQueue;

public class Main
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader br = Files.newBufferedReader(Paths.get("B-small-attempt0.in", args), Charset.defaultCharset());
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.setOut(new PrintStream(Files.newOutputStream(Paths.get("output.out"))));

		final int CASES = Integer.parseInt(br.readLine());
		String line;

		for (int cs = 0; cs < CASES; cs++)
		{
			line = br.readLine();
			final int space = line.indexOf(' ');
			final int B = Integer.parseInt(line.substring(0, space));
			final int N = Integer.parseInt(line.substring(space + 1));

			final int[] barbers = new int[B];
			parseIntArray(br.readLine().toCharArray(), barbers);

			printStatus(cs + 1, barbers, N);
			//br.readLine();
		}
	}

	private static void printStatus(int dataCase, int[] barbers, int N)
	{
		N--;
		// find LCM
		BigInteger bi = BigInteger.ONE;
		for (int i = 0; i < barbers.length; i++) {
			BigInteger val = BigInteger.valueOf(barbers[i]);
			bi = bi.multiply(val).divide(bi.gcd(val));
		}
		
		int lcm = bi.intValue();
		
		int len = 0;
		for(int i : barbers)
			len += lcm / i;
//		System.err.println("len "+len);
		
		N = N % len;
//		System.err.println("N" +N);
		
		PriorityQueue<Barber> pq = new PriorityQueue<>();
		
		for(int i = 0; i < barbers.length;i++)
			pq.add(new Barber(0, i));
		
		int current = 0;
		while(N != -1) {
			Barber b = pq.remove();
			current = b.index;
//			System.err.println("b "+b.index+ " at "+b.time);
			pq.add(new Barber(b.time+barbers[current],current));
			N--;
		}
		printMessage(dataCase, Integer.toString(current + 1));
	}

	public static void printMessage(int dataCase, String message)
	{
		System.out.println("Case #" + dataCase + ": " + message);
	}

	public static int parseIntArray(char[] line, int[] target)
	{
		// ignore the first character!!

		int j = 0;
		int accumulator = -1;
		boolean sign = true; // can be surely done without this
		for (char ch : line)
			if (ch == '-')
			{
				accumulator = 0;
				sign = false;
			}
			else if (ch < '0' || ch > '9')
			{
				if (accumulator != -1)
				{
					target[j] = sign ? accumulator : -accumulator;
					accumulator = -1;
					sign = true;
					j++;
				} // we found a new digit
			}
			else
				accumulator = accumulator == -1
					? (ch - '0')
					: accumulator * 10 + (ch - '0');
		if (accumulator != -1)
			target[j++] = sign ? accumulator : -accumulator;
		return j;
	}
	
	static class Barber implements Comparable<Barber> {
		int time;
		int index;

		public Barber(int time, int index)
		{
			this.time = time;
			this.index = index;
		}

		@Override
		public int compareTo(Barber o)
		{
			if(time != o.time)
				return Integer.compare(time, o.time);
			return Integer.compare(index, o.index);
		}
		
		
	}
}
