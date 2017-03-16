using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Accord.Statistics.Kernels;

namespace Google.CodeJam
{
    public static class NoisyNeighbors
    {
        private static int bitCount(int x)
        {
            int count = 0;
            while (x != 0)
            {
                count++;
                x &= (x - 1);
            }
            return count;
        }
        private static int RunTestCase(int a, int b, int n)
        {
            int ret = int.MaxValue;
            for (int i = 0; i < 1<<a*b; i++)
            {
                if (bitCount(i) == n)
                {
                    int temp = 0;
                    for (int l = 0; l < a; l++)
                    {
                        for (int m = 0; m < b; m++)
                        {
                            if ((i >> (l* b + m) & 1) == 1)
                            {

                                if (m!=b-1 && (i >> (l * b + m + 1) & 1) == 1)
                                    temp++;
                                if (l!=a-1 && (i >> ((l+1) * (b) + m) & 1) == 1)
                                    temp++;
                            }
                        }
                    }
                    ret = Math.Min(ret, temp);
                }
            }
            return ret;
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
                    var parameters = reader.ReadLine().Split(" ".ToCharArray()).Select(int.Parse).ToArray();
                    answers.Add(RunTestCase(parameters[0], parameters[1], parameters[2]));
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
    }
}
