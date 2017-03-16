using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "A-small-attempt0";

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
			var list1 = new List<int>();
			var list2 = new List<int>();
			var a = cin.NextInt();
			for (var i = 1; i <= 4; i++)
			{
				if (i == a)
				{
					for (var j = 0; j < 4; j++)
					{
						list1.Add(cin.NextInt());
					}
				}
				else
				{
					Console.ReadLine();
				}
			}
			a = cin.NextInt();
			for (var i = 1; i <= 4; i++)
			{
				if (i == a)
				{
					for (var j = 0; j < 4; j++)
					{
						list2.Add(cin.NextInt());
					}
				}
				else
				{
					Console.ReadLine();
				}
			}
			var intersection = list1.Intersect(list2).ToList();
			if (intersection.Count > 1)
			{
				Console.WriteLine("Bad magician!");
			}
			else if (intersection.Count == 1)
			{
				Console.WriteLine(intersection.Single());
			}
			else
			{
				Console.WriteLine("Volunteer cheated!");
			}
		}
	}

	internal class Scanner
	{
		private string[] s = new string[0];
		private int i;
		private readonly char[] cs = { ' ' };

		public string Next()
		{
			if (i < s.Length) return s[i++];
			var line = Console.ReadLine() ?? string.Empty;
			if (line == string.Empty)
			{
				return Next();
			}
			s = line.Split(cs, StringSplitOptions.RemoveEmptyEntries);
			i = 1;
			return s.First();
		}

		public double NextDouble()
		{
			return double.Parse(Next());
		}

		public int NextInt()
		{
			return int.Parse(Next());
		}

		public long NextLong()
		{
			return long.Parse(Next());
		}
	}
}