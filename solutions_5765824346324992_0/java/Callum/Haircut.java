import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Haircut
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader("B-small.in"));
		PrintWriter pw = new PrintWriter("B-small.out");

		int t = Integer.parseInt(br.readLine());

		for (int test = 0; test < t; test++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int b = Integer.parseInt(st.nextToken());
			int n = Integer.parseInt(st.nextToken());

			int[] m = new int[b];
			st = new StringTokenizer(br.readLine());
			long gcd = -1;
			long nps = 0;
			for (int i = 0; i < b; i++)
			{
				m[i] = Integer.parseInt(st.nextToken());
				if (gcd == -1)
				{
					gcd = m[i];
				}
				else
				{
					gcd = gcd(gcd, m[i]);
				}
			}
			long lcm = m[0];
			for (int i = 1; i < b; i++)
			{
				long ol = lcm;
				lcm *= m[i];
				lcm /= gcd(ol, m[i]);
			}
			for (int i = 0; i < b; i++)
			{
				nps += lcm / m[i];
			}
			int ans = 0;
			long time = Math.max(0, (n / nps) * lcm);
			long cut = Math.max(0, (n / nps) * nps);
			if (n % nps != 0)
			{
				while (true)
				{
					for (int i = 0; i < b; i++)
					{
						if (time % m[i] == 0)
						{
							cut++;
							if (cut == n)
							{
								ans = i + 1;
								break;
							}
						}
					}
					if (ans != 0)
					{
						break;
					}
					time += gcd;
				}
			}
			else
			{
				long minoio = Long.MAX_VALUE;
				long mini = 0;
				for (int q = 0; q < b; q++)
				{
					if (m[q] <= minoio)
					{
						minoio = m[q];
						mini = q;
					}
				}
				ans = (int) (mini + 1);
			}

			pw.printf("Case #%d: %d%n", test + 1, ans);
		}
		br.close();
		pw.close();
	}

	private static long gcd(long a, long b)
	{
		long r = a % b;
		while (r != 0)
		{
			a = b;
			b = r;
			r = a % b;
		}
		return b;
	}
}