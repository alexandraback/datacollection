using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace GoogleCoceJam2016
{
    class A
    {
        public const string ProblemCode = "A";

        public static void Solve(string file)
        {
            using (var sr = new StreamReader(file + ".in"))
            {
                using (var sw = new StreamWriter(file + ".out"))
                {
                    string line = sr.ReadLine();
                    var cases = int.Parse(line);

                    for (int i = 1; i <= cases; i++)
                    {
                        line = sr.ReadLine();
                        var n = int.Parse(line);
                        line = sr.ReadLine();

                        var p = line.Split(' ').Select(x => int.Parse(x)).ToArray();

                        string restText = Solve(p);
                        Console.WriteLine("Case #{0}: {1}", i, restText);

                        sw.WriteLine("Case #{0}: {1}", i, restText);
                    }

                }
            }

            Console.WriteLine();
            Console.WriteLine("FINITO");
            Console.WriteLine();
            Console.ReadKey();
        }

        private static string[] alpha = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
        private static string Solve(int[] p)
        {
            StringBuilder sb = new StringBuilder();
            while (p.Sum() > 0)
            {
                int notzero = 0;
                int sum = 0;
                List<int> maxindex = new List<int> { };
                int maxvalue = 0;
                for (int i = 0; i < p.Length; i++)
                {
                    if (p[i] > 0) notzero++;
                    sum += p[i];
                    if (p[i] >= maxvalue && p[i] > 0)
                    {
                        if (p[i] == maxvalue) { maxindex.Add(i); }
                        if (p[i] > maxvalue)
                        {
                            maxindex = new List<int> { i };
                            maxvalue = p[i];
                        }
                    }

                }

                p[maxindex[0]]--;
                sb.Append(alpha[maxindex[0]]);
                sum--;
                if (sum == 2)
                {
                    sb.Append(" ");
                    continue;
                }

                if (maxindex.Count > 1)
                {
                    p[maxindex[1]]--;
                    sb.Append(alpha[maxindex[1]]);
                }
                else
                {
                    p[maxindex[0]]--;
                    sb.Append(alpha[maxindex[0]]);
                }
                sum--;

                if (sum > 0) sb.Append(" ");

            }

            return sb.ToString();
        }

        public static void SolveLarge()
        {
            Solve(ProblemCode + "-large");
        }

        public static void SolveSample()
        {
            Solve(ProblemCode + "-sample");
        }


        public static void SolveSmall()
        {
            Solve(ProblemCode + "-small");
        }


    }
}
