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
                var N = int.Parse(line);
                line = System.Console.ReadLine().Trim();
                var inp = line.Split(' ');
                var m = new int[N];
                for (var j = 0; j < N; ++j)
                {
                    m[j] = int.Parse(inp[j]);
                }
                Console.WriteLine("Case #{0:D}: {1:D} {2:D}", i + 1, s_solve(N, ref m), l_solve(N, ref m));
            }
        }
        private static long s_solve(int N, ref int[] m)
        {
            long now = m[0];
            long cnt = 0;
            for (var i = 1; i < N; ++i)
            {
                if (m[i] < now)
                {
                    cnt += now - m[i];
                }
                now = m[i];
            }
            return cnt;
        }

        private static long l_solve(int N, ref int[] m)
        {
            long cnt = 0;
            var gap = 0;
            for (var i = 0; i < N - 1; ++i)
            {
                if (m[i] - m[i + 1] > gap)
                {
                    gap = m[i] - m[i + 1];
                }
            }
            for (var i = 0; i < N - 1; ++i)
            {
                if (m[i] < gap)
                {
                    cnt += m[i];
                }
                else
                {
                    cnt += gap;
                }
            }
            return cnt;
        }
    }
}
