using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

namespace CodeJam.Round1B
{
	public class ProblemB
	{
		public static void Main(string[] args)
		{
			using (var input = new StreamReader(File.OpenRead("../../Input.txt")))
			{
				using (var output = new StreamWriter(File.OpenWrite("../../Output.txt")))
				{
					int cases = int.Parse(input.ReadLine());

					for (int i = 0; i < cases; i++)
					{
						var result = GetResult(input);

						Console.WriteLine("Case #" + (i + 1) + ": " + result);
						output.WriteLine("Case #" + (i + 1) + ": " + result);
					}
				}
			}
		}

		public class Node : IComparable
		{
			public int Entries;
			public int Unhappiness;

			public int X;
			public int Y;

			public Node Previous;

			public int CompareTo(object other)
			{
				var o = (Node)other;

				int result = o.Entries + o.Unhappiness - Entries - Unhappiness;

				if (result == 0)
				{
					// Try to move as far from the center as possible
					result = X + Y - o.X - o.Y;
				}
				return result;
			}
		}

		public static string GetResult(StreamReader input)
		{
			var line = input.ReadLine();

			var splits = line.Split(' ');

			int R = int.Parse(splits[0]), C = int.Parse(splits[1]), N = int.Parse(splits[2]);

			List<Node> options = new List<Node>();

			for (int i = 0; i < R; i++)
			{
				for (int j = 0; j < C; j++)
				{
					int unhappiness = 0;
					if(i > 0)
					{
						unhappiness--;
					}
					if(j > 0)
					{
						unhappiness--;
					}
					if(i < R - 1)
					{
						unhappiness--;
					}
					if(j < C - 1)
					{
						unhappiness--;
					}
					options.Add(new Node(){ Entries = R * C - 1, Unhappiness = (R - 1) * C + R * (C - 1) + unhappiness, X = i, Y = j });
				}
			}

			options.Sort();

			//special case
			if (R % 2 == 1 && C % 2 == 1)
			{
				if (N <= (R + 1) / 2 + (C + 1) / 2 + R / 2 + C / 2)
				{
					return "0";
				}
			}

			Node current = null;
			Node prev = null;
			int entries = R * C;
			int minUnhappy = (R - 1) * C + R * (C - 1);
			while(entries > N)
			{	
				List<Node> newOptions = new List<Node>();
				//while(true)
				//{
					prev = current;
					current = options[options.Count - 1];
					options.RemoveAt(options.Count - 1);

					if (current.Unhappiness > minUnhappy)
					{
						break;
					}
					minUnhappy = current.Unhappiness;

					entries = current.Entries;

					var grid = BuildGrid(current, R, C);

					for (int i = 0; i < R; i++)
					{
						for (int j = 0; j < C; j++)
						{
							if (grid[i, j])
							{
								continue;
							}

							int unhappiness = 0;
							if (i > 0 && !grid[i - 1, j])
							{
								unhappiness--;
							}
							if (j > 0 && !grid[i, j - 1])
							{
								unhappiness--;
							}
							if (i < R - 1 && !grid[i + 1, j])
							{
								unhappiness--;
							}
							if (j < C - 1 && !grid[i, j + 1])
							{
								unhappiness--;
							}

							newOptions.Add(new Node(){ Entries = current.Entries - 1, Unhappiness = current.Unhappiness + unhappiness, X = i, Y = j, Previous = current });
						}
					}
				//}

				options.AddRange(newOptions);
				options.Sort();
			}

			bool[,] grid2 = null;
			if (current != null)
			{
				grid2 = BuildGrid(current, R, C);
			}
			for (int i = 0; i < R; i++)
			{
				for (int j = 0; j < C; j++)
				{
					if (grid2 != null && grid2[i, j])
					{
						Console.Write("| . ");
					}
					else
					{
						Console.Write("| X ");
					}

				}
				Console.Write("|\n");
				for (int j = 0; j < C; j++)
				{
					Console.Write("----");
				}
				Console.Write("|\n");
			}
		

			return minUnhappy.ToString();
		}

		public static bool[,] BuildGrid(Node node, int r, int c)
		{
			bool[,] result = new bool[r,c];

			do
			{
				result[node.X, node.Y] = true;
				node = node.Previous;
			}
			while (node != null);

			return result;
		}
	}
}

