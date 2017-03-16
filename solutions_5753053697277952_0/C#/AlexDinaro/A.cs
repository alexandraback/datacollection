using System.Collections.Generic;
using System.IO;
using System.Linq;

// ReSharper disable PossibleNullReferenceException

// ReSharper disable AssignNullToNotNullAttribute

namespace ConsoleApplication2
{
	class A
	{
		private string[] text = new[] {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
		private int[] order = new[] {0, 8, 3, 2, 4, 6, 7, 1, 9, 5};

		public void Solve()
		{
			using (var sr = new StreamReader("A.in"))
			using (var sw = new StreamWriter("A.out"))
			{
				var t = int.Parse(sr.ReadLine());
				for (var testCase = 1; testCase <= t; ++testCase)
				{
					sw.Write("Case #{0}:", testCase);
					sr.ReadLine();
					var s = sr.ReadLine().Split(' ').Select(int.Parse).ToArray();
					var sum = s.Sum();
					var ans = "";
					while (sum != 0)
					{
						var maxIndex = -1;
						var curMax = 0;
						for (var i = 0; i < s.Length; ++i)
						{
							if (s[i] > curMax)
							{
								maxIndex = i;
								curMax = s[i];
							}
						}
						ans += (char) ('A' + maxIndex);
						s[maxIndex]--;
						--sum;
						if (ans.Length == 2 || sum == 2)
						{
							sw.Write(" {0}", ans);
							ans = "";
						}
					}
					if (ans!="")
						sw.Write(" {0}", ans);
					sw.WriteLine();
				}
			}
		}
	}
}
