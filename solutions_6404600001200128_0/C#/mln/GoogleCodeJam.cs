using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Google.CodeJam
{
    public static class GoogleCodeJam
    {
        private static Tuple<int, int> RunTestCase(int[] mushrooms)
        {
            var dx = mushrooms.Zip(mushrooms.Skip(1), (a, b) => a - b);
            int ret1 = dx.Where(x => x > 0).Sum();
            
            var speed = dx.Max();
            var ret2 = mushrooms.Take(mushrooms.Length - 1).Sum(x => Math.Min(x, speed));
            return Tuple.Create(ret1, ret2);
        }
        static void Main(string[] args)
        {
            int testCases;
            List<Tuple<int,int>> answers = new List<Tuple<int,int>>();
            using (var reader = File.OpenText("e:\\input.in"))
            {
                testCases = int.Parse(reader.ReadLine());
                for (int i = 0; i < testCases; i++)
                {
                    int N = int.Parse(reader.ReadLine());
                    int[] mushrooms= reader.ReadLine()
                        .Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)
                        .Select(int.Parse).ToArray();
                    answers.Add(RunTestCase(mushrooms));
                }
            }

            using (var writer = File.CreateText("e:\\output.out"))
            {
                for (int i = 0; i < answers.Count; i++)
                {
                    writer.WriteLine("Case #{0}: {1} {2}", i + 1, answers[i].Item1, answers[i].Item2);
                }
                writer.Flush();
            }
        }
    }
}
