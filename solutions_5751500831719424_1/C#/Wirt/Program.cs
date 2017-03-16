using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace A
{
	public class Program
	{
		private static readonly List<string> Tokens = new List<string>();
		private static int position;
		private const string InputFile = @"A-large.in";
		private const string OutputFile = @"A-large.out";
		private const string Folder = @"D:\DotNetProjects\GoogleCodeJam2014\";
		private static readonly StringBuilder sb = new StringBuilder();
		
		static void Main()
		{
			ReadInput();
			int taskCount = NextInt();
			for (int t = 0; t < taskCount; t++)
			{
				Solve(t + 1);
			}
			FlushOutput();
			
		}

		private static void Solve(int taskNumber)
		{
			int n = NextInt();
			var lines = new string[n];
			for (int i = 0; i < n; i++)
			{
				lines[i] = NextToken();
			}

			var codes = lines.Select(Pair.Make).ToList();

			string result = "";
			foreach (var code in codes)
			{
				if (codes[0].Count != code.Count)
					result = "Fegla Won";
			}

			if (string.IsNullOrEmpty(result))
			{
				result = Find(codes);
			}

			WriteLineFormat("Case #{0}: {1}", taskNumber, result);
		}

		private static int Median(List<int> nums)
		{
			nums.Sort();
			var count = nums.Count;
			if (count % 2 == 1)
			{
				return nums[count/2];
			}
			return (nums[count/2] + nums[count/2 - 1])/2;
		}

		private static string Find(List<List<Pair>> codes)
		{
			var result = "Fegla Won";
			int cnt = 0;
			int letCnt = codes[0].Count;
			for (int i = 0; i < letCnt; i++)
			{
				var curCh = codes[0][i].ch;
				foreach (var code in codes)
				{
					if (code[i].ch != curCh)
						return result;
				}
				int mid = Median(codes.Select(c => c[i].count).ToList());
				foreach (var code in codes)
				{
					cnt += Math.Abs(code[i].count - mid);
				}
			}
			return cnt + "";
		}

		public class Pair
		{
			public char ch;
			public int count;

			public static List<Pair> Make(string str)
			{
				var result = new List<Pair>();
				char curChar = str[0];
				int curCnt = 1;
				for (int i = 1; i < str.Length; i++)
				{
					if (str[i] == curChar)
						curCnt++;
					else
					{
						result.Add(new Pair{ch = curChar, count = curCnt});
						curCnt = 1;
						curChar = str[i];
					}
				}
				result.Add(new Pair{ch = curChar, count = curCnt});
				return result;
			}
		}
		
		private static void FlushOutput()
		{
			File.WriteAllText(Folder + OutputFile, sb.ToString());
		}

		private static void ReadInput()
		{
			var lines = File.ReadAllLines(Folder + InputFile);
			foreach (var line in lines)
			{
				var strings = line.Split(' ', '\n');
				Tokens.AddRange(strings);
			}
		}

		private static void WriteLine(string line)
		{
			sb.AppendLine(line);
		}

		private static void WriteLineFormat(string format, params object[] args)
		{
			sb.AppendLine(string.Format(format, args));
		}

		private static void Write(string str)
		{
			sb.Append(str);
		}

		private static string NextToken()
		{
			return Tokens[position++];
		}

		public static int NextInt()
		{
			return int.Parse(NextToken());
		}
		
		public static long NextLong()
		{
			return long.Parse(NextToken());
		}
	}
}
