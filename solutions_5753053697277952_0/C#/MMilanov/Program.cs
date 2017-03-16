//C# Console Application, .NET v4.6.1

using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

namespace Gcj
{
	class Program
	{
		static void Main(string[] args)
		{
			var inputFile = args[0];

			var input = File.ReadAllLines(inputFile).Where(l => !string.IsNullOrWhiteSpace(l)).Select(l => l.Trim()).ToArray();
			var count = int.Parse(input.First(), NumberFormatInfo.InvariantInfo);
			input = input.Skip(1).ToArray();
			if (count * 2 != input.Length)
				throw new ArgumentException();

			var result = new StringBuilder();

			for (var i = 0; i < count; i++)
			{
				var n = int.Parse(input[i*2], NumberStyles.Integer, NumberFormatInfo.InvariantInfo);
				var ps = input[i*2 + 1].Trim().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select((s, ix) => new KeyValuePair<int, int>(ix, int.Parse(s, NumberStyles.Integer, NumberFormatInfo.InvariantInfo))).ToList();
				if (n != ps.Count)
					throw new ArgumentException();

				ps = ps.Where(p => p.Value > 0).ToList();

				var solution = "";
				while (ps.Any())
				{
					var max = ps.First(p => p.Value == ps.Max(p1 => p1.Value));
					if (max.Value > 1)
						ps[ps.IndexOf(max)] = new KeyValuePair<int, int>(max.Key, max.Value - 1);
					else
						ps.Remove(max);
					solution += (solution != "" ? " " : "") + (char) ('A' + max.Key);

					var max2 = ps.First(p => p.Value == ps.Max(p1 => p1.Value));
					if (max2.Key != max.Key)
					{
						var rest = ps.Where(p => p.Key != max2.Key).Sum(p => p.Value);
						if (max2.Value > rest)
						{
							if (max2.Value > 1)
								ps[ps.IndexOf(max2)] = new KeyValuePair<int, int>(max2.Key, max2.Value - 1);
							else
								ps.Remove(max2);
							solution += (char)('A' + max2.Key);
						}
					}
				}

				result.AppendLine("Case #" + (i + 1).ToString(NumberFormatInfo.InvariantInfo) + ": " + solution);
			}

			File.WriteAllText(Path.ChangeExtension(inputFile, ".out"), result.ToString());

#if DEBUG
			Console.WriteLine("Done");
			Console.ReadKey();
#endif
		}
	}
}
