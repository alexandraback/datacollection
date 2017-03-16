using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleCodeJam
{
    internal class A : CodeJamBase
    {
        private readonly List<Word> strs = new List<Word>();
        private int N;

        public override bool ExecuteAsynchronus
        {
            get { return false; }
        }

        public override void LoadInput(StreamReader input)
        {
            N = input.ReadNumber();
            for (int i = 0; i < N; i++)
            {
                strs.Add(new Word(input.ReadLine()));
            }
        }

        public override string Process()
        {
            int changes = 0;
            int index = 0;
            var sb = new StringBuilder();
            var ch = ' ';
            var g = strs[0].String;
            foreach (var t in g)
            {
                if (ch != t)
                {
                    sb.Append(ch = t);
                }
            }
            g = sb.ToString();
            sb = null;
            bool newChar = true;
            while (true)
            {
                if (g.Length == index)
                {
                    return "Fegla Won";
                }
                int count = strs.Where(str => g[index] == str.Char).Count();

                if (count == 0)
                {
                    if (newChar)
                    {
                        return "Fegla Won";
                    }
                    index++;
                    newChar = true;
                    continue;
                }
                if (count == N)
                {
                    foreach (var word in strs)
                    {
                        word.Index++;
                    }
                    newChar = false;
                }
                else
                {
                    if (newChar)
                    {
                        return "Fegla Won";
                    }
                    foreach (var word in strs.Where(word => word.Char == g[index]))
                    {
                        word.Index++;
                    }
                    changes += Math.Min(count, N - count);
                }

                if (strs.All(word => word.Char == ' '))
                {
                    return changes.ToString();
                }
            }
        }

        private class Word
        {
            public readonly string String;
            public int Index;

            public Word(string s)
            {
                String = s;
            }

            public char Char
            {
                get { return Index == String.Length ? ' ' : String[Index]; }
            }
        }
    }
}