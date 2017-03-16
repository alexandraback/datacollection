using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ_2015_Round1B
{
    public class B
    {
        private void Run()
        {
            // small only
            int T = int.Parse(Console.ReadLine().Trim());
            for (int testcase = 1; testcase <= T; ++testcase)
            {
                var input = Console.ReadLine().Trim().Split();
                int r = int.Parse(input[0]);
                int c = int.Parse(input[1]);
                int n = int.Parse(input[2]);

                var grid = Enumerable.Range(0, r).Select(_ => new bool[c]).ToArray();

                int res = int.MaxValue;
                foreach (var bits in SpecifiedSizeSubsetBits(r * c, n))
                {
                    for (int y = 0; y < r; y++)
                    {
                        for (int x = 0; x < c; x++)
                        {
                            grid[y][x] = ((bits & (1 << (y * c + x))) != 0);
                        }
                    }
                    int temp = 0;
                    for (int y = 0; y < r; y++)
                    {
                        for (int x = 0; x < c; x++)
                        {
                            if (y > 0 && grid[y][x] && grid[y - 1][x]) { temp += 1; }
                            if (x > 0 && grid[y][x] && grid[y][x - 1]) { temp += 1; }
                        }
                    }
                    res = Math.Min(res, temp);
                }

                Console.Write("Case #{0}: ", testcase);
                Console.WriteLine(res);
            }
        }

        public static IEnumerable<int> SpecifiedSizeSubsetBits(int n, int k)
        {
            if (k == 0)
            {
                yield return 0;
            }
            else
            {
                int comb = (1 << k) - 1;
                while (comb < (1 << n))
                {
                    yield return comb;
                    int x = (comb & -comb);
                    int y = comb + x;
                    int z = comb & ~y;
                    comb = ((z / x) >> 1) | y;
                }
            }
        }

        private static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new B().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}
