using GoogleCodeJam.Algorithms;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam
{
    class Program
    {
        private static string _inputFilename;
        private static string _outputFilename;
        private static readonly Algorithm _algorithm = new MagicTrickAlgorithm();

        static void Main(string[] args)
        {
            Console.WriteLine("Enter input filename:");
            _inputFilename = Console.ReadLine();
            _outputFilename = string.Format("{0}\\{1}.out", Path.GetDirectoryName(_inputFilename), Path.GetFileNameWithoutExtension(_inputFilename));
            Console.WriteLine(string.Format("Solving {0}...", _inputFilename));

            try
            {
                Solve();
                Console.WriteLine("Solved. Output file at {0}", _outputFilename);
            }
            catch (Exception e)
            {
                Console.WriteLine("Error: " + e.Message);
            }
            Console.Read();
        }

        static void Solve()
        {

            if (!File.Exists(_inputFilename))
                throw new Exception("Input file does not exist.");
            using (FileStream fs = File.OpenRead(_inputFilename))
            {
                using (var sr = new StreamReader(fs))
                {
                    using (var sw = new StreamWriter(_outputFilename))
                    {
                        string s = sr.ReadLine();
                        int numCases;
                        if (!int.TryParse(s, out numCases))
                            throw new Exception("Cannot parse number of cases.");
                        Console.WriteLine(numCases + " cases");
                        for (int i = 0; i < numCases; i++)
                        {
                            var lines = GetInputLines(sr).ToArray();
                            var answer = _algorithm.Solve(lines);
                            Console.WriteLine("Case #{0}: {1}", i + 1, answer);
                            sw.WriteLine("Case #{0}: {1}", i + 1, answer);
                        }
                    }
                }
            }
        }

        static IEnumerable<string> GetInputLines(StreamReader sr)
        {
            for (int i = 0; i < _algorithm.LinesNeeded; i++)
            {
                yield return sr.ReadLine();
            }
        }
    }
}
