using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            using (TextReader input = new StreamReader("input.txt"))
            using (TextWriter output = new StreamWriter("output.txt"))
            //using (TextReader input = new StreamReader(Console.OpenStandardInput()))
            //using (TextWriter output = new StreamWriter(Console.OpenStandardOutput()))
            {
                Process(input, output);
            }
        }

        private static void Process(TextReader input, TextWriter output)
        {
            int numberOfCases = int.Parse(input.ReadLine());
            for (int currentCase = 0; currentCase < numberOfCases; currentCase++)
            {
                output.Write("Case #" + (currentCase + 1).ToString() + ": ");
                ProcessLine(input, output);
            }
        }

        private static void ProcessLine(TextReader input, TextWriter output)
        {
            int firstRow = int.Parse(input.ReadLine());
            List<int> firstSet = new List<int>(4);
            for (int row = 1; row < 5; row++)
            {
                string rowString = input.ReadLine();
                if (row == firstRow)
                {
                    string[] numbers = rowString.Split(' ');
                    for (int index = 0; index < 4; index++)
                    {
                        firstSet.Add(int.Parse(numbers[index]));
                    }
                }
            }
            int secondRow = int.Parse(input.ReadLine());
            int foundCount = 0;
            int found = 0;
            for (int row = 1; row < 5; row++)
            {
                string rowString = input.ReadLine();
                if (row == secondRow)
                {
                    string[] numbers = rowString.Split(' ');
                    for (int index = 0; index < 4; index++)
                    {
                        int current = int.Parse(numbers[index]);
                        if (firstSet.Contains(current))
                        {
                            found = current;
                            for (int subIndex = 0; subIndex < 4; subIndex++)
                            {
                                if (firstSet[subIndex] == current)
                                {
                                    foundCount++;
                                }
                            }
                        }
                    }
                }
            }
            switch (foundCount)
            {
                case 0:
                    output.WriteLine("Volunteer cheated!");
                    break;
                case 1:
                    output.WriteLine(found.ToString());
                    break;
                default:
                    output.WriteLine("Bad magician!");
                    break;
            }
        }
    }
}
