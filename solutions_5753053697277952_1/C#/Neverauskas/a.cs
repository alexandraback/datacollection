using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
    internal class Template
    {
        private static readonly Scanner cin = new Scanner();
        private const string fileName = "A-large";

        private static void Main()
        {
            Console.SetIn(new StreamReader(string.Format(@"D:\Contests\GoogleCodeJam\{0}.in", fileName)));
            Console.SetOut(new StreamWriter(string.Format(@"D:\Contests\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
            var t = cin.NextInt();
            for (var c = 1; c <= t; c++)
            {
                Console.Write("Case #{0}: ", c);
                Solve();
            }
        }

        private static void Solve()
        {
            var n = cin.NextInt();
            var p = new Party[n];
            for (var i = 0; i < p.Length; i++)
            {
                p[i].Letter = (char) ('A' + i);
                p[i].Count = cin.NextInt();
            }
            p = p.OrderByDescending(x => x.Count).ToArray();
            var evac = new List<string>();
            while (p[0].Count > p[1].Count)
            {
                evac.Add(p[0].Letter + "");
                p[0].Count--;
            }
            for (var i = 2; i < p.Length; i++)
            {
                for (var j = 0; j < p[i].Count; j++)
                {
                    evac.Add(p[i].Letter + "");
                }
            }
            for (var i = 0; i < p[0].Count; i++)
            {
                evac.Add(p[0].Letter + "" + p[1].Letter);
            }
            var result = string.Join(" ", evac);
            Console.WriteLine(result);
        }

        public struct Party
        {
            public char Letter { get; set; }
            public int Count { get; set; }

            public Party(char letter, int count) : this()
            {
                Letter = letter;
                Count = count;
            }
        }
    }

    internal class Scanner
    {
        private string[] s = new string[0];
        private int i;
        private readonly char[] cs = { ' ' };

        public string NextString()
        {
            if (i < s.Length) return s[i++];
            var line = Console.ReadLine() ?? string.Empty;
            if (line == string.Empty)
            {
                return NextString();
            }
            s = line.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 1;
            return s.First();
        }

        public double NextDouble()
        {
            return double.Parse(NextString());
        }

        public int NextInt()
        {
            return int.Parse(NextString());
        }

        public long NextLong()
        {
            return long.Parse(NextString());
        }
    }
}