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
            int[] mushrooms = v_Reader.ReadLine().Split().Select(s => int.Parse(s)).ToArray();

            int maxDif = 0;                        
            int accumulatedDif = 0;
            
            int previous = mushrooms[0];
            for (int i = 1; i < mushrooms.Length; i++)
            {
                int dif =  previous - mushrooms[i];
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
            int sameRatioTotal =0;
            for (int i = 1; i < mushrooms.Length; i++)
            {
                sameRatioTotal += Math.Min(maxDif, previous);
                previous = mushrooms[i];
            }

            return String.Format("{0} {1}", accumulatedDif, sameRatioTotal);
        }
    }
}
