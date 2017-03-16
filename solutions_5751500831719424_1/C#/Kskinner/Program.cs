using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    public class Program
    {
        int N;
        string[] lines;

        int M;

        public void ReadData()
        {
            N = ReadInt();
            lines = new string[N];
            for (int i = 0; i < N; i++)
            {
                lines[i] = ReadLine();
            }
        }

        public string Solve()
        {
            string chars = Chars(lines[0]);
            M = chars.Length;
            foreach (var line in lines)
            {
                if (Chars(line) != chars)
                    return "Fegla Won";
            }

            var lengths = new int[N][];
            for (int i = 0; i < N; i++)
            {
                lengths[i] = Lengths(lines[i]);
            }

            int totalCost = 0;
            for (int i = 0; i < M; i++)
            {
                int median = Median(lengths, i);
                int cost = Cost(lengths, i, median);
                totalCost += cost;
            }

            return totalCost.ToString();
        }

        private int Cost(int[][] lengths, int i, int median)
        {
            int cost = 0;
            for (int j = 0; j < N; j++)
            {
                cost += Math.Abs(lengths[j][i] - median);
            }
            return cost;
        }

        private int Median(int[][] lengths, int i)
        {
            List<int> xs = new List<int>();
            for (int j = 0; j < N; j++)
            {
                xs.Add(lengths[j][i]);
            }
            xs.Sort();
            return xs[xs.Count / 2];
        }

        public string Chars(string s)
        {
            var sb = new StringBuilder();
            sb.Append(s[0]);
            for (int i = 1; i < s.Length; i++)
            {
                if (s[i] != s[i - 1])
                {
                    sb.Append(s[i]);
                }
            }
            return sb.ToString();
        }

        public int[] Lengths(string s)
        {
            var lengths = new int[M];
            lengths[0] = 1;
            int j = 0;
            for (int i = 1; i < s.Length; i++)
            {
                if (s[i] == s[i - 1])
                {
                    lengths[j]++;
                }
                else
                {
                    j++;
                    lengths[j] = 1;
                }
            }
            return lengths;
        }

        static StreamReader reader;

        static void Main(string[] args)
        {
            string filename = args.Length > 0 ? args[0] : "test.in";
            string outFileName = filename.Replace(".in", ".out");
            string expectedFileName = filename.Replace(".in", ".expected");

            using (reader = File.OpenText(filename))
            using (var outFile = File.CreateText(outFileName))
            {
                int T = ReadInt();
                Console.WriteLine("{0} test cases", T);

                for (int tc = 1; tc <= T; tc++)
                {
                    Console.WriteLine("Starting test case {0}", tc);
                    var problem = new Program();
                    problem.ReadData();
                    string solution = problem.Solve();

                    outFile.WriteLine("Case #{0}: {1}", tc, solution);
                    Console.WriteLine("Case #{0}: {1}", tc, solution);
                }
            }

            if (File.Exists(expectedFileName))
            {
                CompareOutputToExpected(outFileName, expectedFileName);
            }
        }

        private static void CompareOutputToExpected(string outFileName, string expectedFileName)
        {
            string[] expected = File.ReadAllLines(expectedFileName);
            string[] actual = File.ReadAllLines(outFileName);
            for (int i = 0; i < Math.Max(expected.Length, actual.Length); i++)
            {
                string lineActual = i < actual.Length ? actual[i] : "** missing **";
                string lineExpected = i < expected.Length ? expected[i] : "** missing **";
                if (lineActual != lineExpected)
                {
                    Console.WriteLine("{0}: Expected: {1} Actual: {2}", (i + 1), lineExpected, lineActual);
                }
            }
        }

        #region Readers

        private static string ReadWord()
        {
            StringBuilder word = new StringBuilder();
            while (reader.Peek() >= 0)
            {
                char c = (char)reader.Read();
                if (Char.IsControl(c) || Char.IsWhiteSpace(c))
                    break;
                word.Append(c);
            }
            return word.ToString();
        }

        private static string ReadLine()
        {
            return reader.ReadLine();
        }

        private static int ReadInt()
        {
            return int.Parse(ReadLine());
        }

        private static T Read<T>()
        {
            return (T)Convert.ChangeType(ReadLine(), typeof(T));
        }

        private static T[] ReadArray<T>()
        {
            return ReadLine().Split(' ').Select(v => (T)Convert.ChangeType(v, typeof(T))).ToArray();
        }

        #endregion
    }
}
