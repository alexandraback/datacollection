
#define TRACE

using System;
using System.Text;
using System.Diagnostics;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Problem
    {
        public int ansR1;
        public List<int> shuffle1 = new List<int>();

        public int ansR2;
        public List<int> shuffle2 = new List<int>();        
    }

    class MainClass
    {
        static int Solve(Problem m)
        {
            List<int> picked1 = new List<int>();

            for(int i = 4*(m.ansR1-1); i < 4*(m.ansR1-1) + 4; ++i)
            {
                picked1.Add(m.shuffle1[i]);
            }

            List<int> picked2 = new List<int>();
            for (int i = 4 * (m.ansR2 - 1); i < 4 * (m.ansR2 - 1) + 4; ++i)
            {
                picked2.Add(m.shuffle2[i]);
            }

            var isect = picked1.Intersect(picked2);

            if(isect.Count() == 1)
            {
                return isect.First();
            }
            else if (isect.Count() > 1)
            {
                return -1;
            }

            return -2;
        }

        static List<Problem> ReadProblems(string file)
        {
            List<Problem> problems = new List<Problem>();

            string[] lines = System.IO.File.ReadAllLines(file);

            int nProbs = int.Parse(lines[0]);
            for (int i = 1; i < lines.Length;)
            {
                Problem problem = new Problem();

                problem.ansR1 = int.Parse(lines[i]);
                ++i;

                for (int j = 0; j < 4; ++j)
                {
                    string[] cards = lines[i].Split(' ');
                    foreach (string card in cards)
                    {
                        problem.shuffle1.Add(int.Parse(card));
                    }
                    ++i;
                }

                problem.ansR2 = int.Parse(lines[i]);
                ++i;

                for (int j = 0; j < 4; ++j)
                {
                    string[] cards = lines[i].Split(' ');
                    foreach (string card in cards)
                    {
                        problem.shuffle2.Add(int.Parse(card));
                    }
                    ++i;
                }

                problems.Add(problem);
            }

            // Trace.Assert (nProbs == problems.Count);

            return problems;
        }

        public static void Main(string[] args)
        {
            Trace.Listeners.Add(new ConsoleTraceListener());

            //string filename = "../../tiny.in";
            string filename = "../../A-small-attempt0.in";

            List<Problem> problems = ReadProblems(filename);

            int i = 0;
            StringBuilder sb = new StringBuilder();
            foreach (var problem in problems)
            {
                int res = Solve(problem);

                string sRes;

                if(res > 0)
                {
                    sRes = res.ToString();
                }
                else if (res == -1)
                {
                    sRes = "Bad magician!";
                }
                else
                {
                    sRes = "Volunteer cheated!";
                }

                string s = string.Format("Case #{0}: {1}", i+1, sRes);

                Console.WriteLine(s);
                sb.Append(s);
                sb.Append("\n");

                ++i;
            }

            System.IO.File.WriteAllText(filename.Replace(".in", ".out"), sb.ToString());
        }
    }
}
