

namespace Contest
{
    using System;
    using System.IO;

    public class Program
    {
        static void Main(string[] args)
        {
            Wrapper.Solve(new ProblemA(), Console.In, Console.Out);
        }
    }

    public class Wrapper
    {
        public static void Solve(IProblem problem, TextReader input, TextWriter output)
        {
            var parser = new InputParser(input);
            int T = parser.GetInt();

            for (int i = 0; i < T; i++)
            {
                output.WriteLine(string.Format("Case #{0}: {1}", i + 1, problem.SolveOneCase(parser)));
            }
        }
    }

    public interface IProblem
    {
        string SolveOneCase(InputParser input);
    }
}﻿



namespace Contest
{
    using System;
    using System.Collections.Generic;

    public class ProblemA : IProblem
    {
        private string _felga = "Fegla Won";

        public string SolveOneCase(InputParser input)
        {
            int N = input.GetInt();
            var strs = new string[N];

            for (int i = 0; i < N; i++)
            {
                strs[i] = input.GetString();
            }

            var let = new List<char>[N];
            var c = new List<int>[N];

            for (int i = 0; i < N; i++)
            {
                let[i] = new List<char>();
                c[i] = new List<int>();

                var str = strs[i];
                var cc = '1';
                int n = -1;
                for (int j = 0; j < str.Length ; j++)
                {
                    if (str[j] == cc)
                        c[i][n]++;
                    else
                    {
                        let[i].Add(str[j]);
                        cc = str[j];
                        n++;

                        c[i].Add(1);
                    }

                }
            }

            int m = 0;

            int L = let[0].Count;
            for (int i = 0; i < N; i++)
            {
                if (let[i].Count != L)
                    return _felga;
            }


            for (int i = 0; i < L; i++)
            {
                int best = int.MaxValue;

                char ll = let[0][i];

                for (int j = 0; j < N; j++)
                {
                    int b = 0;

                    if (let[j][i] != ll)
                        return _felga;

                    int t = c[j][i];

                    for (int k = 0; k < N; k++)
                    {
                        b += Math.Abs(t - c[k][i]);
                    }

                    if (b < best)
                        best = b;
                }
                m += best;
            }

            
//            int best = int.MaxValue;
//
//
//            if (best == int.MaxValue)
//            {
//               
//                return _felga;
//            }

            return m.ToString();
        }
    }
}﻿

namespace Contest
{
    using System.Collections;
    using System;
    using System.IO;

    public class InputParser
    {
        private readonly TextReader _textReader;

        private IEnumerator _enumerator;

        public InputParser(TextReader textReader)
        {
            this._textReader = textReader;
            this._enumerator = (new string[0]).GetEnumerator();
        }

        public string ReadLine()
        {
            return _textReader.ReadLine();
        }

        public string[] GetStringArray()
        {
            return ReadLine().Split(new string[0], StringSplitOptions.RemoveEmptyEntries);
        }

        public int[] GetIntArray()
        {
            string[] tokens = GetStringArray();
            int length = tokens.Length;

            var values = new int[length];

            for (int i = 0; i < length; i++)
            {
                values[i] = int.Parse(tokens[i]);
            }

            return values;
        }

        public long[] GetLongArray()
        {
            string[] tokens = GetStringArray();
            int length = tokens.Length;

            var values = new long[length];

            for (int i = 0; i < length; i++)
            {
                values[i] = long.Parse(tokens[i]);
            }

            return values;
        }

        public string GetString()
        {
            while (_enumerator.MoveNext() == false)
            {
                _enumerator = GetStringArray().GetEnumerator();
            }

            return (string)_enumerator.Current;
        }

        public int GetInt()
        {
            return int.Parse(GetString());
        }

        public long GetLong()
        {
            return long.Parse(GetString());
        }
    }
}