using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
    public class Program
    {
        public static void Main(string[] args)
        {
            // ToDo
            var inputPath = @"C:\GCJ_TestData\A-small-attempt0.in";
            //var inputPath = @"C:\GCJ_TestData\A-large.in";

            //var inputPath = @"C:\GCJ_TestData\file.in";
            var outputPath = @"C:\GCJ_TestData\file.out";

            var solver = new SolveA();
            var solutionStrings = new List<string>();

            using (StreamReader fileReader = new StreamReader(inputPath))
            {
                var numOfProblems = MathHelper.ConvertToInt(fileReader.ReadLine());

                for (var problemNumber = 1; problemNumber <= numOfProblems; problemNumber++)
                {
                    var solution = solver.Solve(fileReader);
                    var solutionString = "Case #" + problemNumber + ": " + solution;

                    solutionStrings.Add(solutionString);
                }
            }

            using (StreamWriter fileWriter = new StreamWriter(outputPath))
            {
                foreach (var solution in solutionStrings)
                {
                    fileWriter.WriteLine(solution);
                }
            }            
        }

        private class SolveA : ISolver
        {
            string result = "";

            List<string> chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".ToCharArray().Select(c => c.ToString()).ToList();
            List<int> countOfEachParty;

            public string Solve(StreamReader fileReader)
            {
                result = "";

                var numOfParties = MathHelper.ConvertToInt(fileReader.ReadLine());
                countOfEachParty = MathHelper.ConvertToInts(fileReader.ReadLine(), ' ').ToList();

                while (true)
                {
                    var max = countOfEachParty.Max();
                    if (max == 0)
                    {
                        break;
                    }

                    var count = countOfEachParty.Where(x => x == max).Count();
                    if (count > 2)
                    {
                        var firstIndex = countOfEachParty.IndexOf(max);

                        Add(firstIndex);
                        continue;
                    }
                    else if (count == 2)
                    {
                        var firstIndex = countOfEachParty.IndexOf(max);
                        var lastIndex = countOfEachParty.LastIndexOf(max);

                        Add(firstIndex, lastIndex);
                        continue;
                    }
                    else
                    {
                        var firstIndex = countOfEachParty.IndexOf(max);

                        Add(firstIndex);
                        continue;
                    }
                }

                return result;
            }

            private void Add(int v)
            {
                countOfEachParty[v] -= 1;

                result += chars[v] + " ";
            }

            private void Add(int v, int w)
            {
                countOfEachParty[v] -= 1;
                countOfEachParty[w] -= 1;

                result += chars[v] + chars[w] + " ";
            }
        }

        private class SolveB : ISolver
        {
            public string Solve(StreamReader fileReader)
            {
                throw new NotImplementedException();
            }
        }

        private class SolveC : ISolver
        {
            public string Solve(StreamReader fileReader)
            {
                throw new NotImplementedException();
            }
        }

        private class SolveD : ISolver
        {
            public string Solve(StreamReader fileReader)
            {
                throw new NotImplementedException();
            }
        }
    }    
}
