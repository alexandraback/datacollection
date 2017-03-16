

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
    using System.Text;

    public class ProblemA : IProblem
    {
        public class P : IComparable
        {
            public char let { get; set; }
            public int Sen { get; set; }
            public int CompareTo(object obj)
            {
                var p = obj as P;

                return this.Sen.CompareTo(p.Sen);
            }
        }

        public string SolveOneCase(InputParser input)
        {
            int N = input.GetInt();

            char c = 'A';

            var list = new List<P>();
            for (int i = 0; i < N; i++)
            {
                int t = input.GetInt();
                list.Add(new P(){let = c, Sen = t} ) ;
                c++;
            }
            list.Sort();
            list.Reverse();

            var sb = new StringBuilder();

            while( list[0].Sen > list[1].Sen)
            {
                sb.Append(list[0].let + " ");
                list[0].Sen--;
            }

            for (int i = 2; i < N; i++)
            {
                var val = list[i];

                for (int j = 0; j < val.Sen; j++)
                {
                    sb.Append(val.let + " ");
                }
            }

            for (int i = 0; i < list[0].Sen; i++)
            {
                sb.Append(list[0].let + "" + list[1].let + " ");
            }


            return sb.ToString();
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