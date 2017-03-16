using System.IO;
using System.Linq;

namespace MagicTrick
{
	class Program
	{
		static void Main(string[] args)
		{
			var inFile = @"C:\Repository\GoogleCodeJam\Qualification2014\MagicTrick\bin\Debug\A-small-attempt0.in";
			var outFile = @"C:\Repository\GoogleCodeJam\Qualification2014\MagicTrick\bin\Debug\output.out";

			var reader = new StreamReader(inFile);
			var writer = new StreamWriter(outFile);

			var T = int.Parse(reader.ReadLine());
			for (int i = 1; i <= T; i++)
			{
				int ansA = int.Parse(reader.ReadLine());
				var rowA = new int[4];
				for (int j = 1; j <= 4; j++)
				{
					if (j == ansA)
						rowA = reader.ReadLine().Split(new[] { ' ' }).Select(n => int.Parse(n)).ToArray();
					else
						reader.ReadLine();
				}
				int ansB = int.Parse(reader.ReadLine());
				var rowB = new int[4];
				for (int j = 1; j <= 4; j++)
				{
					if (j == ansB)
						rowB = reader.ReadLine().Split(new[] { ' ' }).Select(n => int.Parse(n)).ToArray();
					else
						reader.ReadLine();
				}
				int matchCount = 0;
				int card = 0;
				for (int j = 0; j < 4; j++)
					for (int k = 0; k < 4; k++)
						if (rowA[j] == rowB[k])
						{
							card = rowA[j];
							if (++matchCount > 1)
							{
								j = 3;
								break;
							}
						}
				if (matchCount == 0)
					writer.WriteLine("Case #" + i + ": Volunteer cheated!");
				else if (matchCount == 1)
					writer.WriteLine("Case #" + i + ": " + card);
				else
					writer.WriteLine("Case #" + i + ": Bad magician!");
			}

			reader.Close();
			writer.Close();
		}
	}
}
