using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2015CodeJam1A
{
    public class B
    {
        public static string Process(int n, int[] min, int caseNo)
        {
            var lcm = LCM(min);
            var a = 0;
            for (int i = 0; i < min.Length; i ++)
            {
                a += lcm/min[i];
            }
            n = (n-min.Length)%a+min.Length;

            var remainingTime = new int[min.Length];
            var barbarForN = 1;

            for(int i=1; i<= n; i++)
            {
                var smallestRemainingTime = remainingTime[0];
                var nextBarbar = 0;
                var foundBarbar = false;
                for (int j = 0; j < remainingTime.Length; j++)
                {
                    if (remainingTime[j] == 0)
                    {
                        remainingTime[j] = min[j];
                        foundBarbar = true;
                        nextBarbar = j;
                        break;
                    }
                    
                    if (remainingTime[j] < smallestRemainingTime)
                    {
                        smallestRemainingTime = remainingTime[j];
                        nextBarbar = j;
                    }
                }
 
                if (i == n)
                {
                    barbarForN = nextBarbar+1;
                    break;
                }

                // every barbar is busy
                if (!foundBarbar)
                {
                    remainingTime = remainingTime.Select(x => x - smallestRemainingTime).ToArray();
                    remainingTime[nextBarbar] = min[nextBarbar];
                }
            }

            return string.Format("Case #{0}: {1}", caseNo, barbarForN);
            
        }

        static int LCM(int[] numbers)
        {
            return numbers.Aggregate(LCM);
        }

        static int LCM(int a, int b)
        {
            return a*b/GCD(a, b);
        }

        static int GCD(int a, int b)
        {
            return b == 0 ? a : GCD(b, a % b);
        }


    }
}
