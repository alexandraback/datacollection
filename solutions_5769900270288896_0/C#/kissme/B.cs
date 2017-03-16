using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2015CodeJam1B
{
    public class B
    {
        public static string Process(int r, int c, int n, int caseNo)
        {
            var min = 0;
            var combo = new int[r*c];

            for (int i = 0; i < n; i ++)
            {
                combo[i] = 1;
            }

            min = CountNoise(r, c, combo);

            while (!Done(combo, n))
            {
                var mark = 0;
                var countOnes = 0;
                for (int i = 0; i < combo.Length-1; i++)
                {
                    if (combo[i] == 1)
                    {
                        countOnes++;
                    }

                    if (combo[i] == 1 && combo[i + 1] == 0)
                    {
                        mark = i - 1;
                        combo[i + 1] = 1;
                        combo[i] = 0;
                        countOnes = countOnes - 1;
                        break;
                    }
                }

                for (int i = 0; i <= mark; i++)
                {
                    if (i < countOnes)
                    {
                        combo[i] = 1;
                    }
                    else
                    {
                        combo[i] = 0;
                    }
                }

                min = Math.Min(min, CountNoise(r, c, combo));
            }
            

                return string.Format("Case #{0}: {1}", caseNo, min);
        }

        public static bool Done(int[] combo, int n)
        {
            for (int i = 0; i < combo.Length; i++)
            {
                if (i < combo.Length - n && combo[i] != 0)
                    return false;
            }

            return true;
        }

        public static int CountNoise(int r, int c, int[] combo)
        {
            var count = 0;
            for (int i = 0; i < r*c; i++)
            {
                if (combo[i] == 1)
                {
                    var x = i/c;
                    var y = i%c;

                    if (x - 1 >= 0 && combo[(x-1)*c + y] == 1 )
                    {
                        count++;
                    }

                    if (x + 1 < r && combo[(x+1)*c + y] == 1)
                    {
                        count++;
                    }

                    if (y - 1 >= 0 && combo[x*c +(y-1)] == 1)
                    {
                        count++;
                    }

                    if (y + 1 < c && combo[x*c+y+1] == 1)
                    {
                        count++;
                    }
                }
            }

            return count/2;
        }
    }
}
