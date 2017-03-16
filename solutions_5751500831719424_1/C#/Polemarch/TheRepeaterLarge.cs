using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class TheRepeaterLarge
    {
        public static void Run(CodeJamHelper helper)
        {
            var numTestCases = helper.ReadLineInt32();
            foreach (var c in Enumerable.Range(1, numTestCases))
            {
                var numStrings = helper.ReadLineInt32();
                var strings = helper.ReadLines(numStrings);
                var answer = Solve(strings);
                helper.OutputCase(answer == -1 ? "Fegla Won" : answer.ToString());
            }
        }
        
        public static int Solve(string[] strings)
        {
            var parsed = strings.Select(Parse).ToList();
            var first = parsed[0];
            var firstChars = first.Select(x => x.Item1);
            //Check if the sequence of any of these don't match
            if (parsed.Skip(1).Any(p => !firstChars.SequenceEqual(p.Select(x => x.Item1))))
                return -1;

            var rv = 0;
            //Now find the optimal length of each
            for (int i = 0; i < first.Count; ++i)
            {
                var counts = parsed.Select(p => p[i].Item2).ToArray();
                rv += MinOperations(counts);
            }
            return rv;
        }

        public static int MinOperations(int[] counts)
        {
            var median = Median(counts);
            return counts.Sum(c => Math.Abs(median - c));
        }

        public static int Median(int[] a)
        {
            Array.Sort(a);
            return a[a.Length / 2];
        }

        public static List<Tuple<char, int>> Parse(string s)
        {
            int count = 0;
            var rv = new List<Tuple<char, int>>();
            for (int i = 0; i < s.Length; ++i)
            {
                if (i == 0)
                {
                    count = 1;
                }
                else if (s[i] == s[i - 1])
                {
                    count += 1;
                }
                else
                {
                    rv.Add(Tuple.Create(s[i - 1], count));
                    count = 0;
                }
            }
            rv.Add(Tuple.Create(s[s.Length - 1], count));
            return rv;
        }
    }
}
