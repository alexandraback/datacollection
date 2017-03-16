

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
    using System.Collections.Generic;
    using System.Linq;

    public class ProblemA : IProblem
    {
        public string SolveOneCase(InputParser input)
        {
            int A1 = input.GetInt()-1;
            int[,] arr = new int[4, 4];
            int[,] arr2 = new int[4, 4];

            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                {
                    arr[i, j] = input.GetInt();
                }

            int A2 = input.GetInt()-1;

            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                {
                    arr2[i, j] = input.GetInt();
                }

            List<int> set1 = new List<int>() { arr[A1, 0], arr[A1, 1], arr[A1, 2], arr[A1, 3] };
            List<int> set2 = new List<int>() { arr2[A2, 0], arr2[A2, 1], arr2[A2, 2], arr2[A2, 3] };

            var intersect = set1.Intersect(set2);

            if (intersect.Count() == 1)
                return intersect.First().ToString();

            if (intersect.Count() > 1)
                return "Bad magician!";

            if (intersect.Count() < 1)
                return "Volunteer cheated!";
            


            return "";
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