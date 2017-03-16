using System;
using System.IO;
using System.Linq;
using System.Reflection;

namespace ProblemB
{
    class ProblemBProgram
    {
        static void Main(string[] args) { (Activator.CreateInstance(MethodBase.GetCurrentMethod().DeclaringType) as dynamic).Run(); }
        void Run()
        {
            //using (TextReader tr = new StreamReader(@"c:\temp\testin.txt"))
            using (TextReader tr = new StreamReader(@"c:\temp\b-small-attempt0.in"))
            //using (TextReader tr = new StreamReader(@"c:\temp\b-large.in"))
            //using (TextReader tr = Console.In)

            using (TextWriter tw = new StreamWriter(@"c:\temp\out.txt"))
            //using (TextWriter tw = Console.Out)
            {
                var tCase = int.Parse(tr.ReadLine());

                for (var tiCase = 1; tiCase <= tCase; ++tiCase)
                {
                    tw.WriteLine("Case #{0}: {1}", tiCase, Solve(tr.ReadLine));
                }
            }
        }

        string Solve(Func<string> rline)
        {
            var inp = rline().Split().Select(int.Parse).ToArray();
            int R = inp[0], C = inp[1], N = inp[2];

            var min = int.MaxValue;
            for (int i = 0; i <= 1 << R*C; i++)
            {
                if (bCount(i) != N)
                    continue;

                int sum = 0;
                for (int ci = 1; ci < C;ci++)
                    for (int ri = 0; ri < R; ri++)
                    {
                        sum += ((i & (1 << (ri*C + ci))) > 0 && (i & (1 << (ri*C + ci - 1))) > 0) ? 1 : 0;
                    }

                for (int ci = 0; ci < C; ci++)
                    for (int ri = 1; ri < R; ri++)
                    {
                        sum += ((i & (1 << (ri * C + ci))) > 0 && (i & (1 << ((ri - 1) * C + ci))) > 0) ? 1 : 0;
                    }

                min = Math.Min(min, sum);
            }
            return min.ToString();
        }

        int bCount(int x)
        {
            int count = 0;
            while (x > 0)
            {
                count += x & 1;
                x >>= 1;
            }
            return count;
        }
    }
}
