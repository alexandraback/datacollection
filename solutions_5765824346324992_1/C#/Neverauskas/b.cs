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
		private const string fileName = "B-large";

		private static void Main()
		{
			Console.SetIn(new StreamReader(string.Format(@"C:\GoogleCodeJam\{0}.in", fileName)));
			Console.SetOut(new StreamWriter(string.Format(@"C:\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
			var t = cin.NextInt();
			for (var c = 1; c <= t; c++)
			{
				Debug.WriteLine(c);
				Console.Write("Case #{0}: ", c);
				Solve();
			}
		}

		private static void Solve()
		{
			var b = cin.NextLong();
			var n = cin.NextLong();
			var m = new List<long>();
			for (var i = 0; i < b; i++)
			{
				m.Add(cin.NextLong());
			}
			if (b == 1)
			{
				Console.WriteLine(1);
				return;
			}
			//var lcm = Lcm(m[0], m[1]);
			//for (var i = 2; i < b; i++)
			//{
			//	lcm = Lcm(lcm, m[i]);
			//}
			//var total = 0L;
			//for (var i = 0; i < m.Count; i++)
			//{
			//	total += lcm/m[i];
			//}
			//var nn = n;
			//n = n%total;
			//if (n == 0)
			//{
			//	n = total;
			//}
			//var take =
			var bb = new long[b];
			if (n > 10000)
			{
				var min = m.Min();
				var cnt = 0.0;
				for (var i = 0; i < b; i++)
				{
					cnt += min*1.0/m[i];
				}

				//var avg = m.Average();
				var one = min/cnt; //avg/m.Count;
				var minutes = one*(n - 25000);
				var perB = (long)Math.Floor(minutes/*/b*/);
				var totalP = 0L;
				var max = long.MinValue;
				for (var i = 0; i < b; i++)
				{
					//var people = perB/m[i];
					//totalP += people;
					var left = perB%m[i];
					//bb[i] = left;
					max = Math.Max(left, max);
				}
				perB -= max;
				for (var i = 0; i < b; i++)
				{
					var people = perB/m[i];
					if (perB%m[i] > 0)
					{
						people++;
					}
					bb[i] = m[i]*people - perB;
					totalP += people;
				}
				n -= totalP;
			}

			
			for (var i = 0; i < n - 1; i++)
			{
				var minIdx = 0;
				var minValue = bb[0];
				for (var j = 1; j < b; j++)
				{
					if (bb[j] < minValue)
					{
						minIdx = j;
						minValue = bb[j];
					}
				}
				for (var j = 0; j < b; j++)
				{
					bb[j] -= minValue;
				}
				bb[minIdx] += m[minIdx];
			}
			{
				var minIdx = 0;
				var minValue = bb[0];
				for (var j = 1; j < b; j++)
				{
					if (bb[j] < minValue)
					{
						minIdx = j;
						minValue = bb[j];
					}
				}
				Console.WriteLine(minIdx + 1);
			}
		}

		static long Gcd(long a, long b)
		{
			return b == 0 ? a : Gcd(b, a % b);
		}

		static long Lcm(long a, long b)
		{
			return a/Gcd(a, b)*b;
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