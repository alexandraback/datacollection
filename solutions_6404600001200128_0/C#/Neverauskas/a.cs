using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "A-small-attempt2";

		private static void Main()
		{
			Console.SetIn(new StreamReader(string.Format(@"C:\GoogleCodeJam\{0}.in", fileName)));
			Console.SetOut(new StreamWriter(string.Format(@"C:\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
			var t = cin.NextInt();
			for (var c = 1; c <= t; c++)
			{
				Console.Write("Case #{0}: ", c);
				Solve();
			}
		}

		private static void Solve()
		{
			var n = cin.NextInt();
			var m = new List<int>();
			for (var i = 0; i < n; i++)
			{
				m.Add(cin.NextInt());
			}
			var min = 0;
			var diff = 0;
			for (var i = 1; i < n; i++)
			{
				if (m[i] < m[i - 1])
				{
					min += m[i - 1] - m[i];
					if (m[i - 1] - m[i] > diff)
					{
						diff = m[i - 1] - m[i];
					}
				}
			}
			Console.Write(min);
			min = 0;
			for (var i = 1; i < n; i++)
			{
				if (m[i - 1] <= diff)
				{
					min += m[i - 1];
				}
				else
				{
					min += diff;
				}
			}
			Console.WriteLine(" " + min);
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