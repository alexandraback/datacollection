using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ._2015._1A
{
    class a
    {
        static void Main(string[] args)
        {
            var T = int.Parse(System.Console.ReadLine().Trim());
            for (int i = 0; i < T; ++i)
            {
                var line = System.Console.ReadLine().Trim();
                var inp1 = line.Split(' ');
                var B = int.Parse(inp1[0]);
                var N = long.Parse(inp1[1]);
                line = System.Console.ReadLine().Trim();
                var inp2 = line.Split(' ');
                var m = new int[B];
                for (var j = 0; j < B; ++j)
                {
                    m[j] = int.Parse(inp2[j]);
                }
                Console.WriteLine("Case #{0:D}: {1:D}", i + 1, solve(B, N, ref m));
            }
        }

        private static int solve(int B, long N, ref int[] m)
        {

            var first_N = N;
            var lc = m[0];
            for (int i = 1; i < B; ++i)
            {
                lc = lcm(lc, m[i]);
            }
            var list = new long[B];
            while (true)
            {
                long min = lc + 1;
                var k = B;
                for (var i = 0; i < B; ++i)
                {
                    if (list[i] < min)
                    {
                        min = list[i];
                        k = i;
                    }
                }
                if (N == 1)
                {
                    return k + 1;
                }
                if (min == lc)
                {
                    var roop = first_N - N;
                    N %= roop;
                    list = new long[B];
                    if (N == 0)
                    {
                        N = roop;
                    }
                }
                else
                {
                    list[k] += m[k];
                    --N;
                }
            }
        }

        private static int lcm(int m, int n)
        {
            return m * n / gcd(m, n);
        }

        private static int gcd(int m, int n)
        {
            while (m != n)
            {
                if (m > n)
                {
                    m -= n;
                }
                else
                {
                    n -= m;
                }
            }
            return m;
        }
    }
}
