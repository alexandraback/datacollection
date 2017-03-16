using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ConsoleApplication1
{
    public class Program
    {
        private static Queue<Queue<string>> chunks = new Queue<Queue<string>>();
        private static void ReadChunks(TextReader tr) { string l; while ((l = tr.ReadLine()) != null) chunks.Enqueue(new Queue<string>(l.Split(' '))); }
        private static string rc() { var q = chunks.Peek(); if (q.Count == 1) chunks.Dequeue(); return q.Dequeue(); }
        private static int ri() { return int.Parse(rc()); }
        private static string rl() { return string.Join(" ", chunks.Dequeue()); }
        private static void swap<T>(ref T a, ref T b) { var x = a; a = b; b = x; }

        public static void Main()
        {
            using (var sr = new StreamReader("A-small-attempt0.in"))
            using (var sw = new StreamWriter("out.txt"))
            {
                ReadChunks(sr);

                var t = ri();

                for (var ti = 1; ti <= t; ++ti)
                {
                    var a = ri();

                    var row = Enumerable.Range(1, 4).Select(i => new[] {ri(), ri(), ri(), ri()}).ToArray()[a - 1];

                    a = ri();

                    row = row.Intersect(Enumerable.Range(1, 4).Select(i => new[] { ri(), ri(), ri(), ri() }).ToArray()[a - 1]).ToArray();

                    var answer =
                        row.Length == 1
                            ? row[0].ToString()
                            : row.Length == 0
                                ? "Volunteer cheated!"
                                : "Bad magician!";
                    sw.WriteLine("Case #{0}: {1}", ti, answer);
                }

            }
        }
    }
}