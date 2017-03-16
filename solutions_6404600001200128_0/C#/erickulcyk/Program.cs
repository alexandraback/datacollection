using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ_2013
{
    class Program
    {

        static void Main(string[] args)
        {
            long t = long.Parse(Console.ReadLine());
            for (long i =0; i < t;i++)
            {
                int a = int.Parse(Console.ReadLine());
                string[] b = Console.ReadLine().Split();
                int[] c = new int[b.Count()];
                for (int j = 0; j < a;j++)
                {
                    c[j] = int.Parse(b[j]);
                }

                int d = 0;
                int e = 0;
                for (int j = 0; j < a - 1; j++)
                {
                    e = Math.Max(e, c[j] - c[j + 1]);
                    d += Math.Max(0, c[j] - c[j + 1]);
                }

                int f = 0;
                for (int j = 0; j < a - 1; j++)
                {
                    f += Math.Min(e, c[j]);
                }

                Console.WriteLine("Case #" + (i + 1) + ": " + d + " " + f);
            }
        }
    }
}
