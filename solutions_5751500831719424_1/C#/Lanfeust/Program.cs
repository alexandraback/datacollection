using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamCS
{
    class Program
    {
        const string _downloadDir = @"C:\Users\Jean-Jacques\Downloads\";
        const string _workingDir = @"C:\Users\Jean-Jacques\Documents\Visual Studio 2013\Projects\CodeJamCS\";

        static string[] GetInputRaw(string file)
        {
            file = file + ".in";
            var fileName = _workingDir + file;
            if (!File.Exists(fileName))
                File.Move(_downloadDir + file, fileName);
            return File.ReadAllLines(fileName);
        }

        static IEnumerable<T> GetInputVar<T>(string file, Func<string[], Tuple<T, int>> f)
        {
            var allLines = GetInputRaw(file);
            int nbInput = int.Parse(allLines[0]);
            int curLine = 1;
            for (int i = 0; i < nbInput; i++)
            {
                string[] tmp = new string[allLines.Length - curLine];
                Array.Copy(allLines, curLine, tmp, 0, allLines.Length - curLine);
                var read = f(tmp);
                curLine += read.Item2;
                yield return read.Item1;
            }
        }

        static IEnumerable<T> GetInput<T>(string file, int nbLines, Func<string[], T> f)
        {
            return GetInputVar(file, a => Tuple.Create(f(a), nbLines));
        }

        static void GenOutput(string file, IEnumerable<string> results)
        {
            string fileName = _workingDir + file + ".out";
            if (File.Exists(fileName))
                File.Delete(fileName);
            int i = 0;
            using (var stream = new StreamWriter(File.OpenWrite(fileName)))
            {
                foreach (string s in results)
                    stream.WriteLine("Case #" + (++i) + ": " + s);
            }
        }

        static Tuple<List<string>, int> Parse(string[] input)
        {
            var n = int.Parse(input[0]);
            return Tuple.Create(new List<string>(input.Skip(1).Take(n)), n + 1);
        }

        static List<Tuple<char, int>> CountChars(string s)
        {
            char cur = ' ';
            var res = new List<Tuple<char, int>>();
            int n = 0;
            foreach (char c in s)
            {
                if (c == cur)
                {
                    n++;
                    continue;
                }
                if (n != 0)
                    res.Add(Tuple.Create(cur, n));
                n = 1;
                cur = c;
            }
            if (n != 0)
                res.Add(Tuple.Create(cur, n));
            return res;
        }

        static bool AreEqual(List<char> l1, List<char> l2)
        {
            if (l1.Count != l2.Count)
                return false;
            for (int i = 0; i < l1.Count; i++)
                if (l1[i] != l2[i])
                    return false;
            return true;
        }

        static string Solve(List<string> pb)
        {
            var l = pb.Select(CountChars).ToList();
            var letters = l[0].Select(t => t.Item1).ToList();
            if (!l.TrueForAll(s => AreEqual(letters, s.Select(t => t.Item1).ToList())))
                return "Fegla Won";

            int nbMoves = 0;
            for (int i = 0; i < letters.Count; i++)
            {
                nbMoves += Minimize(l.Select(c => c[i].Item2));
            }
            return string.Format("{0}", nbMoves);
        }

        static int Minimize(IEnumerable<int> counts)
        {
            var allCounts = counts.ToList();
            var min = allCounts.Min();
            var max = allCounts.Max();
            var best = max * allCounts.Count;
            for (int i = min; i <= max; i++)
            {
                var candidate = allCounts.Select(c => Math.Abs(c - i)).Sum();
                if (candidate < best)
                    best = candidate;
            }
            return best;
        }

        static void Main(string[] args)
        {
            var file = "A-large";
            GenOutput(file, GetInputVar(file, Parse).Select(p => Solve(p)));
        }
    }
}
