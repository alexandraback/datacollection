using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2015CodeJam1A
{
    public class A
    {
        public static string Process(int[] m, int caseNo)
        {
            return string.Format("Case #{0}: {1} {2}", caseNo, Alpha(m), Beta(m));
        }

        static int Beta(int[] m)
        {
            double rate = 0;
            double maxDelta = 0;
            for (int i = 0; i < m.Length-1; i++)
            {
                var delta = m[i] - m[i + 1];
                if (delta > maxDelta)
                {
                    maxDelta = delta;
                }
            }

            rate = maxDelta/10;

            int min = 0;
            for (int i = 0; i < m.Length-1; i++)
            {
                min += Math.Min(m[i], (int)(rate*10));
            }

            return min;
        }

        public static int Alpha(int[] m)
        {
            int min = 0;
            for (int i = 0; i < m.Length-1; i++)
            {
                var delta = m[i] - m[i + 1];
                if (delta > 0)
                {
                    min += delta;
                }
            }

            return min;
        }
    }
}
