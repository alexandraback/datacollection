using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    class Solver : ISolver
    {
        public string Solve(System.IO.StreamReader v_Reader)
        {
            v_Reader.ReadLine();
            long[] mushrooms = v_Reader.ReadLine().Split().Select(s => long.Parse(s)).ToArray();

            long maxDif = 0;
            long accumulatedDif = 0;

            long previous = mushrooms[0];
            for (long i = 1; i < mushrooms.Length; i++)
            {
                long dif = previous - mushrooms[i];
                if (dif >0)
                {
                    accumulatedDif += dif;
                    if (dif > maxDif)
                    {
                        maxDif = dif;
                    }
                }
                previous = mushrooms[i];
            }

            previous = mushrooms[0];
            long sameRatioTotal = 0;
            for (int i = 1; i < mushrooms.Length; i++)
            {
                sameRatioTotal += Math.Min(maxDif, previous);
                previous = mushrooms[i];
            }

            return String.Format("{0} {1}", accumulatedDif, sameRatioTotal);
        }
    }
}
