using System;
using System.Globalization;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam
{
	class ProblemA
	{
		static void Main(string[] args)
		{
			//string inFilePath = "C:\\Users\\Pablo\\Desktop\\input.txt";
			Console.Out.Write("enter input file path:");
			string inFilePath = Console.In.ReadLine();
			string outFilePath = Path.Combine(Path.GetDirectoryName(inFilePath),
			Path.GetFileNameWithoutExtension(inFilePath) + "_out");
			outFilePath = Path.ChangeExtension(outFilePath, Path.GetExtension(inFilePath));
			Console.Out.Write("Input file: " + inFilePath + "\nOutput file: " + outFilePath + "\n");
			StreamReader inputFile = new StreamReader(inFilePath, Encoding.ASCII);
			StreamWriter outputFile = new StreamWriter(outFilePath, false, Encoding.ASCII);
			string line = inputFile.ReadLine();
			uint caseCount = uint.Parse(line);
			for(uint caseNumber = 1; caseNumber <= caseCount; ++caseNumber) {
				var result = ResolveCase(inputFile);
				string output = string.Format("Case #{0}: {1}", caseNumber, result);
				outputFile.WriteLine(output);
				Console.Out.WriteLine(output);
			}
			inputFile.Close();
			outputFile.Close();
		}

		//-------------------------------------------------------------------------------------------------
		static string ResolveCase(StreamReader input)
		{
			// Reading input
			int first = int.Parse(input.ReadLine()) - 1;
			int[][] firstArrangement = new int[4][];
			for (int i = 0; i < 4; i++) {
				firstArrangement[i] = input.ReadLine().Split(' ').Select(num => int.Parse(num)).ToArray();
			}
			int second = int.Parse(input.ReadLine()) - 1;
			int[][] secondArrangement = new int[4][];
			for(int i = 0; i < 4; i++) {
				secondArrangement[i] = input.ReadLine().Split(' ').Select(num => int.Parse(num)).ToArray();
			}

			string retVal = "Volunteer cheated!";
			bool hasMatch = false;
			foreach(int i in firstArrangement[first]) {
				foreach(int j in secondArrangement[second]) {
					if (i == j) {
						if(hasMatch) return "Bad magician!";
						hasMatch = true;
						retVal = i.ToString();
					}
				}
			}
			return retVal;
		}
	}
}
