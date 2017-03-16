using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P1
{
    class Program
    {
        /*
4
2
2 2
3
3 2 2
3
1 1 2
3
2 3 1

Case #1: AB BA
Case #2: AA BC C BA
Case #3: C C AB
Case #4: BA BB CA
             */
        private static string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        static void Main(string[] args)
        {
            //System.Diagnostics.Debugger.Launch();

            var e1 = int.Parse(Console.ReadLine());
            for (int e2 = 1; e2 <= e1; e2++)
            {
                var parties = int.Parse(Console.ReadLine());
                var counts = Console.ReadLine().Split(' ').Select(str => int.Parse(str)).ToArray();

                System.Diagnostics.Debug.Assert(counts.Length == parties);

                var total = counts.Sum();
                var sb = new StringBuilder();

                while (total > 0)
                {
                    int maxA, maxB;

                    findMax(counts, out maxA, out maxB);

                    sb.Append(letters[maxA]);
                    total--;
                    counts[maxA]--;

                    if(total == 2)
                    {
                        sb.Append(" ");
                        continue;
                    }
                    if(maxB >= 0 && counts[maxB] > counts[maxA])
                    {
                        sb.Append(letters[maxB]);
                        total--;
                        counts[maxB]--;
                    }
                    else if(counts[maxA] > 0)
                    {
                        sb.Append(letters[maxA]);
                        total--;
                        counts[maxA]--;
                    }

                    sb.Append(" ");
                }
                
                Console.WriteLine("Case #{0}: {1}", e2, sb.ToString());
            }
        }

        private static void findMax(int[] counts, out int maxA, out int maxB)
        {
            maxA = maxB = -1;
            int maxValA = 0;
            int maxValB = 0;

            for (int i=0; i < counts.Length; i++)
            {
                if(counts[i]>maxValA)
                {
                    if(maxValA>0)
                    {
                        maxValB = maxValA;
                        maxB = maxA;
                    }

                    maxValA = counts[i];
                    maxA = i;
                    
                }
                else if(counts[i]>maxValB)
                {
                    maxValB = counts[i];
                    maxB = i;
                }
            }
        }

        private static void Check(int[] numbers, Dictionary<char, int> letters, char v1, int v2, string v3)
        {
            if (letters.ContainsKey(v1) && letters[v1] > 0)
            {
                int count = letters[v1];

                numbers[v2] = count;

                foreach(char c in v3)
                {
                    letters[c] -= count;
                }
            }
        }
    }
}
