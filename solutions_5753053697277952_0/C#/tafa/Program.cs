using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round1CQ1
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine().Trim());

            for (int i = 0; i < t; i++)
                SolveProblem(i + 1);
        }

        private static void SolveProblem(int testNum)
        {
            int N = int.Parse(Console.ReadLine().Trim());
            List<int> p = Console.ReadLine().Split(' ').Select(x => int.Parse(x.Trim())).ToList();


            int positiveCount = N;

            List<string> result = new List<string>();



            while (positiveCount > 0)
            {
                int max1 = int.MinValue;
                int max1Index = -1;
                int max2 = int.MinValue;
                int max2Index = -1;

                int sum = 0;

                for (int i = 0; i < N; i++)
                {
                    sum += p[i];

                    if (p[i] > max1)
                    {
                        if (max1 > max2)
                        {
                            max2Index = max1Index;
                            max2 = max1;
                        }

                        max1 = p[i];
                        max1Index = i;
                    }
                    else if (p[i] > max2)
                    {
                        max2 = p[i];
                        max2Index = i;
                    }
                }

                if (sum == 3)
                {
                    // must remove just 1
                    p[max1Index] -= 1;
                    if (p[max1Index] == 0)
                        positiveCount -= 1;
                    result.Add(((char)('A' + max1Index)).ToString());
                }
                else if (sum == 2)
                {
                    string val = ((char)('A' + max1Index)).ToString() + ((char)('A' + max2Index)).ToString();
                    result.Add(val);
                    break;
                }
                else
                {
                    p[max1Index] -= 1;
                    if (p[max1Index] == 0)
                        positiveCount -= 1;
                    p[max2Index] -= 1;
                    if (p[max2Index] == 0)
                        positiveCount -= 1;

                    string val = ((char)('A' + max1Index)).ToString() + ((char)('A' + max2Index)).ToString();
                    result.Add(val);
                }
            }

            Console.WriteLine("Case #{0}: {1}", testNum, string.Join(" ", result));

        }
    }
}
