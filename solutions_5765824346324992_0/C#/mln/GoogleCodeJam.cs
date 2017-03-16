using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Google.CodeJam
{
    public static class GoogleCodeJam
    {
        private static int RunTestCase(int pos, int[] bSpeed)
        {
            int k = bSpeed.Aggregate((a, b) => (int)lcm(a, b));
            int range = bSpeed.Sum(x => k/x);
            List<int> arr = new List<int>();
            int[] bState = new int[bSpeed.Length];
            for (int i = 0; i < Math.Min(range,pos); i++)
            {
                int min = bState.Min();
                int idx = Array.IndexOf(bState, min);
                arr.Add(idx);
                bState[idx] += bSpeed[idx];
            }
            return arr[(pos - 1)%range]+1;
        }
        static void Main(string[] args)
        {
            int testCases;
            List<int> answers = new List<int>();
            using (var reader = File.OpenText("e:\\input.in"))
            {
                testCases = int.Parse(reader.ReadLine());
                for (int i = 0; i < testCases; i++)
                {
                    var temp = reader.ReadLine()
                            .Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)
                            .Select(int.Parse)
                            .ToArray();
                    int barbers = temp.First();
                    int myPlace = temp.Last();

                    int[] speed = reader.ReadLine()
                        .Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)
                        .Select(int.Parse).ToArray();
                    answers.Add(RunTestCase(myPlace,speed));
                }
            }

            using (var writer = File.CreateText("e:\\output.out"))
            {
                for (int i = 0; i < answers.Count; i++)
                {
                    writer.WriteLine("Case #{0}: {1}", i + 1, answers[i]);
                }
                writer.Flush();
            }
        }

        static long gcd(long a, long b)
        {
            return b == 0 ? a : gcd(b, a%b);
        }

        static long lcm(long a, long b)
        {
            return a*b/gcd(a, b);
        }
    }
}
