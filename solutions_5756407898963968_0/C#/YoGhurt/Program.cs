using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJamA
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Filename:");
            string filename = Console.ReadLine();
            string[] linesArray = File.ReadAllLines(@"F:\DL\" + filename);

            List<string> linesList = linesArray.ToList();

            int testCases = Int32.Parse(linesList[0]);
            using (StreamWriter file = new StreamWriter(@"F:\DL\SolveA.txt"))
            {
                for (int i = 1; i <= testCases; i++)
                {
                    List<string> testCase = new List<string>();
                    for (int j = (((i - 1) * 10) + 1); j <= (((i - 1) * 10) + 10); j++)
                    {
                        testCase.Add(linesList[j]);
                    }
                    file.WriteLine("Case #" + i.ToString() + ": " + SolveTest(testCase));
                }
            }
        }

        private static string SolveTest(List<string> testCase)
        {
            int firstLine = Int32.Parse(testCase[0]);
            int secondLine = Int32.Parse(testCase[5]);
            string firstLinestr = testCase[firstLine];
            string secondLinestr = testCase[secondLine+5];
            string[] splittedFirst = firstLinestr.Split(' ');
            string[] splittedSecond = secondLinestr.Split(' ');
            List<int> firstNumbers = new List<int>();
            List<int> secondNumbers = new List<int>();
            for (int i = 0; i < splittedFirst.Length; i++)
            {
                firstNumbers.Add(Int32.Parse(splittedFirst[i]));
                secondNumbers.Add(Int32.Parse(splittedSecond[i]));
            }
            var intersect = firstNumbers.Intersect(secondNumbers);
            if (intersect.Count() == 0) return "Volunteer cheated!";
            if (intersect.Count() > 1) return "Bad magician!";
            return intersect.First().ToString();
        }
    }
}
