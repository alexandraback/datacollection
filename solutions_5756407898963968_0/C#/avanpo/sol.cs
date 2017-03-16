using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

class MagicTrick
{
	public int n;

	public MagicTrick()
	{
		this.n = int.Parse(Console.ReadLine());
	}

	public void Run()
	{
		for (int i = 0; i < this.n; i++)
		{
			int[][] arr = new int[2][];
			int r;
			for (int j = 0; j < 2; j++)
			{
				r = int.Parse(Console.ReadLine()) - 1;
				for (int k = 0; k < 4; k++)
				{
					if (k == r)
						arr[j] = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
					else
						Console.ReadLine();
				}
			}

			int dubs = 0;
			int ans = 0;
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					if (arr[0][j] == arr[1][k])
					{
						dubs++;
						ans = arr[0][j];
					}
				}
			}

			using (StreamWriter w = File.AppendText("out.txt"))
			{
				if (dubs == 0)
					w.WriteLine("Case #{0}: Volunteer cheated!", i + 1);
				else if (dubs == 1)
					w.WriteLine("Case #{0}: {1}", i + 1, ans);
				else
					w.WriteLine("Case #{0}: Bad magician!", i + 1);
			}
		}
	}
	
	static void Main(string[] args)
	{
		MagicTrick m = new MagicTrick();
		m.Run();
	}
}
