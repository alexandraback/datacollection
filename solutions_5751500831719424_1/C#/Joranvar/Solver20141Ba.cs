namespace GoogleCodeJam
{
    using System;
    using System.Collections.Generic;
    using System.IO;
    using System.Linq;

    public class Solver20141Ba
    {
        private IList<string> strings;

        private int NumStrings;

        public Solver20141Ba(TextReader @in)
        {
            this.NumStrings = int.Parse(@in.ReadLine());
            this.strings = Enumerable.Range(0, this.NumStrings).Select(i => @in.ReadLine()).ToList();
        }

        public Solver20141Ba(IList<string> strings)
        {
            this.strings = strings;
            this.NumStrings = strings.Count;
        }

        public ISolution Solve()
        {
            if (strings.Skip(1).All(s => s == strings[0]))
            {
                return new Solution(0);
            }

            List<List<CharCount>> cnt = new List<List<CharCount>>();
            foreach (var str in strings)
            {
                List<CharCount> chars = new List<CharCount> { new CharCount() { C = str[0], Count = 1 } };
                foreach (char c in str.Skip(1))
                {
                    if (chars.Last().C == c)
                    {
                        chars.Last().Count ++;
                    }
                    else
                    {
                        chars.Add(new CharCount() { C = c, Count = 1 });
                    }
                }

                cnt.Add(chars);
            }

            foreach (var c in cnt.Skip(1))
            {
                if (c.Count != cnt[0].Count)
                {
                    return Solution.Unsolvable;
                }
                if (c.Select((count, i) => new { count, i }).Any(charCount => cnt[0][charCount.i].C != charCount.count.C))
                {
                    return Solution.Unsolvable;
                }
            }

            int moves = 0;

            foreach (int i in Enumerable.Range(0, cnt[0].Count))
            {
                int i1 = i;
                var counts = cnt.Select(list => list[i1].Count).OrderBy(i2 => i2).ToArray();
                var medianLength = counts[NumStrings / 2];
                moves += counts.Sum(i2 => Math.Abs(medianLength - i2));
            }

            return new Solution(moves);
        }

        public class CharCount
        {
            public int Count;

            public char C;
        }

        public class Solution : ISolution
        {
            private readonly string show;

            private readonly int numMoves;

            public Solution(int numMoves)
            {
                this.numMoves = numMoves;
            }

            public static readonly ISolution Unsolvable = new Solution("Fegla Won");

            private Solution(string show)
            {
                this.show = show;
            }

            public override string ToString()
            {
                return " " + (string.IsNullOrWhiteSpace(show) ? numMoves.ToString() : show);
            }
        }
    }
}