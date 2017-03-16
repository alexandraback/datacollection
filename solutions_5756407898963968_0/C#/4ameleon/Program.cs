using System;
using System.Collections.Generic;
using System.IO;

namespace Test
{
	public class Program
	{
		private static void Main()
		{
			Solve(Console.In, Console.Out);
		}

		public static void Solve(TextReader input, TextWriter output)
		{
			int t = Convert.ToInt32(input.ReadLine());

			for (int z = 1; z <= t; z++)
			{
				int a1 = Convert.ToInt32(input.ReadLine());
				bool[] index = new bool[17];

				for (int r = 1; r <= 4; r++)
				{
					string[] data = input.ReadLine().Split(' ');

					if (r == a1)
					{
						for (int j = 0; j < 4; j++)
							index[Convert.ToInt32(data[j])] = true;
					}
				}

				int a2 = Convert.ToInt32(input.ReadLine());
				int n = 0;

				for (int r = 1; r <= 4; r++)
				{
					string[] data = input.ReadLine().Split(' ');

					if (r == a2)
					{
						for (int j = 0; j < 4; j++)
						{
							int k = Convert.ToInt32(data[j]);

							if (index[k])
								n = (n == 0) ? k : -1;
						}
					}
				}

				if (n > 0)
				{
					output.WriteLine("Case #{0}: {1}", z, n);
				}
				else if (n == 0)
				{
					output.WriteLine("Case #{0}: Volunteer cheated!", z);
				}
				else
				{
					output.WriteLine("Case #{0}: Bad magician!", z);
				}
			}
		}
	}
}