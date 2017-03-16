using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ20161C
{
	public class Program
	{
		public static void Main(string[] args)
		{
			string[] input = File.ReadAllLines(@"input.in");
			File.WriteAllLines(@"../../lib/output.out", ProblemA(input));
			Console.ReadKey();
		}

		public static string[] ProblemA(string[] input)
		{
			int t = int.Parse(input[0]);
			string[] output = new string[t];
			for (int i = 1; i <= t; i++)
			{
				output[i - 1] = $"Case #{i}: {ProblemA(input[(i * 2) - 1], input[i * 2])}";
				Console.WriteLine(output[i - 1]);
			}

			return output;
		}

		public static string ProblemA(string n, string input)
		{
			string[] ns = input.Split(' ');
			int[] pi = new int[ns.Length];

			for (int i = 0; i < ns.Length; i++)
			{
				pi[i] = int.Parse(ns[i]);
			}

			int min;
			int[] excess = ProblemAExcess(pi, out min);

			List<char> result = new List<char>();

			int pos = ProblemAGetMax(excess);
			while (pos > -1)
			{
				result.Add(ProblemAGetChar(pos));
				excess[pos]--;
				pos = ProblemAGetMax(excess);
			}

			for (int i = 0; i < min; i++)
			{
				for (int j = 0; j < ns.Length; j++)
				{
					result.Add(ProblemAGetChar(j));
				}
			}

			string output = "";

			for (int i = 0; i < result.Count; i++)
			{
				output += result[i];
				if (i <= result.Count - 3)
				{
					if (i % 2 != result.Count % 2)
					{
						output += " ";
					}
				}
			}

			return $"{output}";
		}

		public static int[] ProblemAExcess(int[] pi, out int min)
		{
			int[] result = new int[pi.Length];

			min = int.MaxValue;

			for (int i = 0; i < pi.Length; i++)
			{
				if (min > pi[i])
				{
					min = pi[i];
				}
			}

			for (int i = 0; i < pi.Length; i++)
			{
				result[i] = pi[i] - min;
			}

			return result;
		}

		public static int ProblemAGetMax(int[] excess)
		{
			int pos = -1;
			int max = int.MinValue;

			for (int i = 0; i < excess.Length; i++)
			{
				if (excess[i] > max && excess[i] > 0)
				{
					pos = i;
					max = excess[i];
				}
			}

			return pos;
		}

		public static char ProblemAGetChar(int i)
		{
			return (char)(i + (int)'A');
		}
	}
}
