using System;
using System.Collections.Generic;
using System.Linq;

class B
{
    long Solve(long N, long[] M)
    {
        long min = 0;
        long max = (long)11e14;
        long t = 0;
        long n = 0;
        while (max - min > 1)
        {
            t = (max + min) / 2;
            n = M.Sum(m => 1 + t / m);

            if (N - 2000 < n && n < N-1) break;
            else if (n < N-1) min = t;
            else max = t;
        }

        if (n >= N - 1) { n = 0; t = 0; }
        var list = M.Select(m => m - (t % m)).ToList();

        for (N = N - n; ; )
        {
            long m = list.Min();
            int ret = -1;
            for (int i = 0; i < list.Count; i++)
            {
                list[i] -= m;
                if (list[i] == 0)
                {
                    N--;
                    if (N == 0) return i + 1;
                    list[i] = M[i];
                }
            }
        }
        throw new Exception();
    }

    static long BinarySearch(long min, long max, Predicate<long> predicate)
    {
        while (max - min > 1)
        {
            long mid = (max + min) / 2;
            if (predicate(mid)) max = mid;
            else min = mid;
        }
        return max;
    }

    static IEnumerable<string> Output()
    {
        yield return new B().Solve(long.Parse(Console.ReadLine().Split(' ')[1]), Console.ReadLine().Split(' ').Select(long.Parse).ToArray()).ToString();
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}