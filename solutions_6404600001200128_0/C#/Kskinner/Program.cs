using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());

            for (int tc = 1; tc <= T; tc++)
            {
                Console.WriteLine("Case #" + tc + ": " + Solve());                
            }
        }

        private static string Solve()
        {
            int N = int.Parse(Console.ReadLine());
            var ar = Console.ReadLine().Split();
            int min1 = 0;
            
            int min_rate = 0;
            int mlast = int.Parse(ar[0]);
            for (int i = 1; i < N; i++)
            {
                int mi = int.Parse(ar[i]);
                if (mi < mlast)
                {
                    min1 += mlast - mi;
                    min_rate = Math.Max(min_rate, mlast - mi);
                }
                mlast = mi;
            }

            mlast = int.Parse(ar[0]);
            int min2 = 0;
            for (int i = 0; i < N-1; i++)
            {
                int mi = int.Parse(ar[i]);
                min2 += Math.Min(min_rate, mi);
            }

            return min1 + " " + min2;
        }
    }
}
