using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2014_MagicTrick
{
    class Program
    {
        static TextReader input = Console.In;
        static TextWriter output = Console.Out;
        static void Main(string[] args)
        {
            if (args.Any())
            {
                var path = args[0];
                if (File.Exists(path))
                {
                    input = File.OpenText(path);
                }
                path.Remove(path.LastIndexOf('.'));
                path += ".out";
                output = File.CreateText(path);
            }

            int totalCases = int.Parse(input.ReadLine());
            for (int currentCase = 1; currentCase <= totalCases; currentCase++)
            {
                string caseOutput = HandleCase(input);
                output.WriteLine(string.Format("Case #{0}: {1}", currentCase, caseOutput));
            }
            output.Flush();
        }

        private static string HandleCase(TextReader input)
        {
            int lineOne = int.Parse(input.ReadLine()) - 1;
            List<int[]> linesFirst = new List<int[]>();
            for (int i = 0; i < 4; i++)
            {
                linesFirst.Add(input.ReadLine().Split(' ').Select(int.Parse).ToArray());
            }

            int lineTwo = int.Parse(input.ReadLine()) - 1;
            List<int[]> linesSecond = new List<int[]>();
            for (int i = 0; i < 4; i++)
            {
                linesSecond.Add(input.ReadLine().Split(' ').Select(int.Parse).ToArray());
            }

            var doubles = linesFirst[lineOne].Where(number => linesSecond[lineTwo].Contains(number));
            if (doubles.Count() > 1)
            {
                // multiple possibilities => bad magician
                return "Bad magician!";
            }
            else if (doubles.Count() == 1)
            {
                // exactly one possibility => correct
                return doubles.First().ToString();
            }
            else
            {
                // no possibilities => bad volunteer
                return "Volunteer cheated!";
            }
        }
    }
}
