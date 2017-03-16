using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ProblemA
{
    class Program
    {
        private static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Invalid input parameters!");
                return;
            }

            string inputFile = args[0];
            string outputFile = args[1];

            using (var reader = new StreamReader(inputFile))
            using (var writer = new StreamWriter(outputFile))
            {
                int testCases = int.Parse(reader.ReadLine());
                for (int caseNumber = 1; caseNumber <= testCases; caseNumber++)
                {
                    int initialRow = int.Parse(reader.ReadLine());
                    var initialArrangement = new List<List<int>>
                    {
                        reader.ReadLine().Split().Select(int.Parse).ToList(),
                        reader.ReadLine().Split().Select(int.Parse).ToList(),
                        reader.ReadLine().Split().Select(int.Parse).ToList(),
                        reader.ReadLine().Split().Select(int.Parse).ToList()
                    };

                    int finalRow = int.Parse(reader.ReadLine());
                    var finalArrangement = new List<List<int>>
                    {
                        reader.ReadLine().Split().Select(int.Parse).ToList(),
                        reader.ReadLine().Split().Select(int.Parse).ToList(),
                        reader.ReadLine().Split().Select(int.Parse).ToList(),
                        reader.ReadLine().Split().Select(int.Parse).ToList()
                    };

                    var result = finalArrangement[finalRow-1].Where(item => initialArrangement[initialRow-1].Contains(item)).Select(item=>item).ToList();
                    if (!result.Any())
                    {
                        Console.WriteLine("Case #{0}: Volunteer cheated!", caseNumber);
                        writer.WriteLine("Case #{0}: Volunteer cheated!", caseNumber);
                    }
                    else if (result.Count() > 1)
                    {
                        Console.WriteLine("Case #{0}: Bad magician!", caseNumber);
                        writer.WriteLine("Case #{0}: Bad magician!", caseNumber);
                    }
                    else
                    {
                        Console.WriteLine("Case #{0}: {1}", caseNumber, result.Single());
                        writer.WriteLine("Case #{0}: {1}", caseNumber, result.Single());
                    }
                }
            }
        }
    }
}
