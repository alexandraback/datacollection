using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Solver : ISolver
    {
        private class BarberAvailable
        {
            public long BarberId { get; set; }
            public long Time{ get; set; }
        }
        public string Solve(System.IO.StreamReader v_Reader)
        {
            long[] line = v_Reader.ReadLine().Split().Select(s => long.Parse(s)).ToArray();

            long barbers = line[0];
            long position = line[1];

            long[] speeds = v_Reader.ReadLine().Split().Select(s => long.Parse(s)).ToArray();
            long lcm = LCM(speeds);

            List<BarberAvailable> Schedule = new List<BarberAvailable>();
            for (int barberId = 1; barberId<=speeds.Length; barberId++)
            {
                for (int i = 0; i * speeds[barberId - 1] < lcm ; i++)
                {
                    Schedule.Add(new BarberAvailable() { BarberId = barberId, Time = i * speeds[barberId - 1] });
                }
            }

            position = position % (Schedule.Count());
            
            Schedule = Schedule.OrderBy(b => b.Time).ThenBy(b => b.BarberId).ToList();
            if(position == 0)
                return Schedule.Last().BarberId.ToString();
            return Schedule[(int)(position - 1)].BarberId.ToString();
        }

        static long LCM(long[] numbers)
        {
            return numbers.Aggregate(lcm);
        }

        static long lcm(long a, long b)
        {
            return Math.Abs(a * b) / GCD(a, b);
        }

        static long GCD(long a, long b)
        {
            return b == 0 ? a : GCD(b, a % b);
        }
    }
}
