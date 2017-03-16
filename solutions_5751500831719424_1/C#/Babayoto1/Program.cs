using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

namespace TheRepeater
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args[0] == null)
            {
                Console.WriteLine("Input file path");
                return;
            }

            int testsCount;
            var inputDescks = FileReader.GetProblems(args[0], out testsCount);
            var resultString = string.Empty;
            for (var index = 0; index < inputDescks.Count; index++)
            {
                var inputDesck = inputDescks[index];
                var result = ProcessProblem(inputDesck);

                if (!string.IsNullOrEmpty(resultString))
                    resultString += "\r\n";
                if (result > -1)
                {
                    resultString += string.Format(CultureInfo.InvariantCulture, "Case #{0}: {1}", index + 1, result);
                }
                else
                {
                    resultString += string.Format(CultureInfo.InvariantCulture, "Case #{0}: Fegla Won", index + 1);
                }
               
            }
            Console.WriteLine(resultString);
            File.WriteAllText(args[1], resultString);
            Console.ReadKey();
        }

        static int ProcessProblem(Problem problem)
        {
            var result = -1;

            var occurrences = new List<List<Occurrences>>();

            
            foreach (var s in problem.Strings)
            {
                var currentChar = '#';
                var currentDictionary = new List<Occurrences>();
                for (int i = 0; i < s.Length; i++)
                {
                    if (s[i] != currentChar)
                    {
                        currentChar = s[i];
                        currentDictionary.Add(new Occurrences { Char = currentChar, Count = 1 });
                    }
                    else
                    {
                        currentDictionary.Last().Count++;
                    }
                }
                occurrences.Add(currentDictionary);
            }

            var count = occurrences[0].Count;
            if (occurrences.Any(o =>
            {
                if (count != o.Count)
                    return true;
                for (int i = 0; i < o.Count; i++)
                {
                    if (o[i].Char != occurrences[0][i].Char)
                        return true;
                }
                return false;
            }))
                return -1;

            result = 0;

            for (int i = 0; i < count; i++)
            {
                var counts = new List<int>();
                for (int j = 0; j < occurrences.Count; j++)
                {
                    counts.Add(occurrences[j][i].Count);
                }

                counts = counts.OrderBy(c => c).ToList();
                var median = counts[counts.Count/2];
                foreach (var count1 in counts)
                {
                    result += Math.Abs(median - count1);
                }
            }

            return result;
        }

        internal class Occurrences
        {
            public char Char { get; set; }
            public int Count { get; set; }
        }

        internal class Problem
        {
            public List<string> Strings { get; set; }
        }

        internal class FileReader
        {
            public static List<Problem> GetProblems(string filename, out int problemsCount)
            {
                var file = new StreamReader(filename);
                var line = file.ReadLine();
                int.TryParse(line, out problemsCount);

                var result = new List<Problem>();

                Problem currentProblem;
                while ((currentProblem = GetProblem(file)) != null)
                {
                    result.Add(currentProblem);
                }

                file.Close();
                return result;
            }

            private static Problem GetProblem(StreamReader file)
            {
                var currentProblem = new Problem();
                currentProblem.Strings = new List<string>();

                var firstLine = file.ReadLine();
                if (string.IsNullOrEmpty(firstLine))
                    return null;

                int stringsCount;
                int.TryParse(firstLine, out stringsCount);
                for (int i = 0; i < stringsCount; i++)
                {
                    currentProblem.Strings.Add(file.ReadLine());
                }
                return currentProblem;
            }
        }
    }
}
