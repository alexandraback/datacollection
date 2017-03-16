using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());

            for (int tc = 1; tc <= T; tc++)
            {
                Console.WriteLine("Case #" + tc + ": " + Solve());
            }
        }

        private static string Solve()
        {
            var ar = Console.ReadLine().Split();
            long B = long.Parse(ar[0]);
            long N = long.Parse(ar[1]);
            long[] M = new long[B];
            ar = Console.ReadLine().Split();
            long lcm = 1;
            long gcd = M[0];
            for (long i = 0; i < B; i++)
            {
                M[i] = long.Parse(ar[i]);
                lcm *= M[i];
                gcd = GCD(gcd, M[i]);
            }
            lcm /= gcd;

            long s = 0;
            for (long i = 0; i < B; i++)
            {
                s += lcm / M[i];
            }

            N %= s;

            if (N == 0)
            {
                N += s;
            }

            long[] remaining = new long[B];
            long c = 0;
            while (true)
            {
                for (int i = 0; i < B; i++)
                {
                    if (remaining[i] == 0)
                    {
                        remaining[i] = M[i] - 1;
                        c++;
                        if (c == N)
                            return (i+1).ToString();
                    }
                    else
                    {
                        remaining[i]--;
                    }
                }
            }
        }

        private static long GCD(long a, long b)
        {
            if (a == 0) return b;
            return GCD(b % a, a);
        }
    }
}
