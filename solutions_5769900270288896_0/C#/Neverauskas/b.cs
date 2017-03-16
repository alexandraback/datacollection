using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "B-small-attempt0";

		private static void Main()
		{
			var sw = Stopwatch.StartNew();
			Console.SetIn(new StreamReader(string.Format(@"C:\GoogleCodeJam\{0}.in", fileName)));
			Console.SetOut(new StreamWriter(string.Format(@"C:\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
			var t = cin.NextInt();
			for (var c = 1; c <= t; c++)
			{
				Console.Write("Case #{0}: ", c);
				Solve();
				Debug.WriteLine(sw.Elapsed);
				Debug.WriteLine(c);
			}
			var elapsed = sw.Elapsed;
			var z = 5;
		}

		private static void Solve()
		{
			var r = cin.NextInt();
			var c = cin.NextInt();
			var n = cin.NextInt();
			var rand = new Random();
			var min = int.MaxValue;
			var size = r*c;
			for (var i = 0; i < 500000; i++)
			{
				var board = new int[r, c];
				var nn = n;
				while (nn > 0)
				{
					var num = rand.Next(size);
					var rr = num/c;
					var cc = num%c;
					if (board[rr, cc] == 0)
					{
						board[rr, cc] = 1;
						nn--;
					}
				}
				var cnt = 0;
				for (var y = 0; y < c; y++)
				{
					for (var x = 1; x < r; x++)
					{
						if (board[x - 1, y] == 1 && board[x, y] == 1)
						{
							cnt++;
						}
					}
				}
				for (var x = 0; x < r; x++)
				{
					for (var y = 1; y < c; y++)
					{
						if (board[x, y - 1] == 1 && board[x, y] == 1)
						{
							cnt++;
						}
					}
				}
				min = Math.Min(min, cnt);
			}
			Console.WriteLine(min);
		}

	}
	internal class Scanner
	{
		private string[] s = new string[0];
		private int i;
		private readonly char[] cs = { ' ' };

		public string NextString()
		{
			if (i < s.Length) return s[i++];
			var line = Console.ReadLine() ?? string.Empty;
			if (line == string.Empty)
			{
				return NextString();
			}
			s = line.Split(cs, StringSplitOptions.RemoveEmptyEntries);
			i = 1;
			return s.First();
		}

		public double NextDouble()
		{
			return double.Parse(NextString());
		}

		public int NextInt()
		{
			return int.Parse(NextString());
		}

		public long NextLong()
		{
			return long.Parse(NextString());
		}
	}
}