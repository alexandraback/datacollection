using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;

namespace Google.CodeJam
{
    class Program
    {
        private static int[][] ReadSquare(TextReader reader)
        {
            return new[]
            {
                reader.ReadLine().Split(' ').Select(int.Parse).ToArray(),
                reader.ReadLine().Split(' ').Select(int.Parse).ToArray(),
                reader.ReadLine().Split(' ').Select(int.Parse).ToArray(),
                reader.ReadLine().Split(' ').Select(int.Parse).ToArray()
            };
        }

        private static void Solve(int id, TextReader reader, TextWriter writer)
        {
            int firstAnswer = int.Parse(reader.ReadLine());
            var firstSquare = ReadSquare(reader);
            var firstRow = firstSquare[firstAnswer - 1];

            int secondAnswer = int.Parse(reader.ReadLine());
            var secondSquare = ReadSquare(reader);
            var secondRow = secondSquare[secondAnswer - 1];

            var possibleCards = firstRow.Where(secondRow.Contains).ToArray();

            if (possibleCards.Length == 0)
            {
                writer.WriteLine("Case #{0}: {1}", id, "Volunteer cheated!");
            }
            else if (possibleCards.Length > 1)
            {
                writer.WriteLine("Case #{0}: {1}", id, "Bad magician!");
            }
            else
            {
                writer.WriteLine("Case #{0}: {1}", id, possibleCards[0]);
            }
        }

        private static void Main(string[] args)
        {
            try
            {
                var inputPath = args[0];
                var outputPath = args[1];

                using (var reader = new StreamReader(inputPath))
                using (var writer = new StreamWriter(outputPath))
                {
                    int count = int.Parse(reader.ReadLine());
                    for (int i = 0; i < count; i++)
                        Solve(i + 1, reader, writer);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
        }
    }
}
