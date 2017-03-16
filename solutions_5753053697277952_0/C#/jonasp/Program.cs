using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace CodeJam2016
{
    class Program
    {
        static void Main(string[] args)
        {
            RunSmall(A, 0);
        }

        private static void Solve(TextReader reader, TextWriter writer)
        {
            var cases = Convert.ToInt32(reader.ReadLine());

            for (var i = 1; i <= cases; i++)
            {
                reader.ReadLine();
                var input = reader.ReadLine().Split(' ').Select(s => Convert.ToInt32(s)).ToList();
                writer.WriteLine($"Case #{i}: {String.Join(" ", Evacuation(input))}");
            }
        }

        public static List<string> Evacuation(List<int> partySizes)
        {
            var evac = new List<string>();

            var partyCount = partySizes.Count(s => s > 0);

            while (partyCount > 0)
            {
                var max = partySizes.Max(s => s);

                var first = partySizes.IndexOf(max);
                var second = partySizes.IndexOf(max, first + 1);

                var str = "";
                str += (char) ('A' + first);
                partySizes[first]--;

                if (partyCount == 2)
                {
                    str += (char) ('A' + second);
                    partySizes[second]--;
                }

                evac.Add(str);

                partyCount = partySizes.Count(s => s > 0);
            }

            return evac;
        } 

        public static void RunSample()
        {
            var sample = @"4
2
2 2
3
3 2 2
3
1 1 2
3
2 3 1
";

            var reader = new StringReader(sample);
            var writer = Console.Out;

            Solve(reader, writer);
            Console.ReadKey();
        }

        public static void RunSmall(string problemLetter, int attemptNo)
        {
            SolveFile(problemLetter, "-small", "-attempt" + attemptNo);
        }

        public static void RunLarge(string problemLetter)
        {
            SolveFile(problemLetter, "-large", "");
        }

        public static void SolveFile(string problemLetter, string size, string suffix)
        {
            var dir = @"C:\Users\paulijon\Downloads";

            var fileName = problemLetter + size + suffix;

            var reader = new StreamReader(Path.Combine(dir, fileName + ".in"));
            var writer = new StreamWriter(Path.Combine(dir, fileName + ".out"));

            Solve(reader, writer);

            writer.Dispose();
        }

        public const string A = "A";
        public const string B = "B";
        public const string C = "C";
    }
}