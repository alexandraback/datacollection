using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ProblemB
{
    public static class _
    {
        public static T[] Times<T>(this int count, Func<T> f) { return Enumerable.Repeat(0, count).Select(x => f()).ToArray(); }
    }

    public class ProblemB
    {
        Queue<Queue<string>> chunks = new Queue<Queue<string>>();
        void ReadChunks(TextReader tr) { string l; while ((l = tr.ReadLine()) != null) chunks.Enqueue(new Queue<string>(l.Split(' '))); }
        string rc() { var q = chunks.Peek(); if (q.Count == 1) chunks.Dequeue(); return q.Dequeue(); }
        int ri() { return int.Parse(rc()); }
        long rlong() { return long.Parse(rc()); }

        static void Main(string[] args) { new ProblemB().Run(); }

        void Run()
        {
            using (var sr = new StreamReader("B-small-attempt0.in"))
            using (var sw = new StreamWriter("out.txt"))
            {
                ReadChunks(sr);

                var tCase = ri();

                for (var tiCase = 1; tiCase <= tCase; ++tiCase)
                {
                    sw.WriteLine("Case #{0}: {1}", tiCase, Solve());
                }
            }
        }

        private int[] m;
        long Processed(long minute)
        {
            long res = 0;
            for (int i = 0; i < m.Length; i++)
            {
                var b = m[i];
                res += minute/b + 1L;
            }
            return res;
        }

        private string Solve()
        {
            int B = ri();
            int N = ri();
            m = B.Times(ri);

            long max = N*100000L;

            long lower = 0;
            long upper = max;

            while (lower < upper)
            {
                long mid = (lower + upper)/2L;
                long processed = Processed(mid);
                if (processed >= N)
                    upper = mid;
                if (processed < N)
                    lower = mid + 1L;
            }

            long res = 0;
            long minute = lower;
            List<int> avail = new List<int>();
            for (int i = 0; i < m.Length; i++)
            {
                var b = m[i];
                res += minute / b + 1L;
                if (minute % b == 0)
                    avail.Add(i+1);
            }

            for (int i = avail.Count - 1; i >= 0; i--)
            {
                if (N == res - (avail.Count - i - 1))
                    return avail[i].ToString();
            }

            throw new InvalidOperationException();
        }
    }
}
