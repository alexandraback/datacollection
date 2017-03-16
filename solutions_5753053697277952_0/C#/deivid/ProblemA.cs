using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleCodeJam
{
    public class ProblemA
    {
        StreamReader _reader;
        StreamWriter _writer;

        public static void Main()
        {
            var sw = Stopwatch.StartNew();
            System.Threading.Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");

            var problem = new ProblemA(@"..\..\_data\A-small-attempt0.in");
            problem.Solve();

            sw.Stop();
            Console.WriteLine("Done in {0}", sw.Elapsed);
            Console.ReadKey();
        }

        public ProblemA(string fileName)
        {
            _reader = File.OpenText(fileName);
            _writer = File.CreateText(Path.Combine(Path.GetDirectoryName(fileName), Path.GetFileNameWithoutExtension(fileName) + ".out"));
        }

        public void Solve()
        {
            int T = ReadInt();
            for (int testCase = 1; testCase <= T; testCase++)
            {
                WriteCaseResult(testCase, SolveCase());
            }
            ProduceOutput();
        }

        private string SolveCase()
        {
            int N = ReadInt();
            var P = ReadIntIEnumerable().Select((p, i) => new Tuple<int, string>(p, char.ConvertFromUtf32(65 + i))).ToList();
            int total = P.Sum(p => p.Item1);
            var result = new StringBuilder();
            while (total > 0)
            {
                P = P.OrderByDescending(p => p.Item1).ToList();
                P[0] = new Tuple<int, string>(P[0].Item1 - 1, P[0].Item2);
                result.Append(P[0].Item2);
                total--;
                if (total > 0 && total != 2)
                {
                    if (P.Count > 1 && P[1].Item1 > P[0].Item1)
                    {
                        P[1] = new Tuple<int, string>(P[1].Item1 - 1, P[1].Item2);
                        result.Append(P[1].Item2);
                    }
                    else
                    {
                        P[0] = new Tuple<int, string>(P[0].Item1 - 1, P[0].Item2);
                        result.Append(P[0].Item2);
                    }
                    total--;
                }
                result.Append(" ");
            }
            return result.ToString().Trim();
        }

        private void WriteCaseResult(int caseNumber, string result)
        {
            _writer.Write("Case #");
            _writer.Write(caseNumber);
            _writer.Write(": ");
            _writer.WriteLine(result);
        }

        private void ProduceOutput()
        {
            _writer.Flush();
            _writer.Close();
            _writer.Dispose();
            _reader.Close();
            _reader.Dispose();
        }

        private int ReadInt() => int.Parse(_reader.ReadLine());

        private string ReadString() => _reader.ReadLine();

        private string[] ReadStringArray() => ReadString().Split();

        private IEnumerable<int> ReadIntIEnumerable() => ReadStringArray().Select(s => int.Parse(s));
    }
}
