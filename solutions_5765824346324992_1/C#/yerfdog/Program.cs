using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj15r1a
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines(@"C:\GCJ\B-large.in");
            int idx = 0;
            int t = int.Parse(lines[idx++]);
            TextWriter tw = new StreamWriter(@"C:\GCJ\B-large.out");
            for (int a = 0; a < t; a++)
            {
                
                string[] line2 = lines[idx++].Split(' ');
                int B = int.Parse(line2[0]);
                int N = int.Parse(line2[1]);
                string[] line3 = lines[idx++].Split(' ');
                int[] barbers = new int[B];
                long time = 0;
                for (int b = 0; b < B; b++)
                {
                    barbers[b] = int.Parse(line3[b]);
                    time = Math.Max(time, barbers[b]);

                }
                while(N > calc(barbers, time))
                {
                    time *= 2;
                }
                long ans = binS(N, barbers, time /2, time);

                tw.WriteLine("Case #{0}: {1}", a+1, ans);
            }
            tw.Close();
        }

        private static int binS(int N, int[] barbers, long min, long max)
        {
            if (min == max - 1)
            {
                return calc2(N, barbers, max);
            }
            else
            {
                long mid = (max + min) / 2;
                if (N > calc(barbers, mid))
                {
                    return binS(N, barbers, mid, max);
                }
                else if (N < calc(barbers, mid))
                {
                    return binS(N, barbers, min, mid);
                }
                else
                {
                    return calc2(N, barbers, mid);
                }
            }
        }
        private static int calc2(int N, int[] barbers, long time)
        {
            long ncut = calc(barbers, time);
            
            List<BarberSet> bs = new List<BarberSet>();
            for (int a = 0; a < barbers.Length; a++)
            {
                long n = time / barbers[a];
                long lastT = time - (n*barbers[a]);
                bs.Add(new BarberSet(a+1, lastT, barbers[a]));
            }
            for (int a = 0; a < ncut-N; a++)
            {
                bs.Sort();
                bs[0].time += bs[0].ctime;
            }
            bs.Sort();
            return bs[0].bnum;
        }

        private static long calc(int[] barbers, long time)
        {
            long ncut = 0;
            for (int a = 0; a < barbers.Length; a++)
            {
                ncut += time / barbers[a] + 1;
            }
            return ncut;
        }
        
    }
    class BarberSet : IComparable<BarberSet>
    {
        public int bnum;
        public long time;
        public long ctime;

        public BarberSet(int b, long t, long c)
        {
            bnum = b;
            time = t;
            ctime = c;
        }
        public int CompareTo(BarberSet that)
        {
            if (this.time > that.time)
            {
                return 1;
            }
            else if (this.time < that.time)
            {
                return -1;
            }
            else
            {
                return -this.bnum.CompareTo(that.bnum);
            }
            
        }
    }
}
