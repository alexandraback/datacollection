using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ._2015._1B
{
    class b
    {
        static void Main(string[] args)
        {
            var T = int.Parse(System.Console.ReadLine().Trim());
            for (int i = 0; i < T; ++i)
            {
                var line = System.Console.ReadLine().Trim();
                var inp = line.Split(' ');
                var R = int.Parse(inp[0]);
                var C = int.Parse(inp[1]);
                var N = int.Parse(inp[2]);
                Console.WriteLine("Case #{0:D}: {1:D}", i + 1, solve(R, C, N));
            }
        }

        private static int solve(int R, int C, int N)
        {
            if ((R * C + 1) / 2 >= N || R * C == 1)
            {
                return 0;
            }
            int d = N - (R * C + 1) / 2;
            if (R * C % 2 == 0)
            {
                if (R == 1 || C == 1)
                {
                    if (d <= 1)
                    {
                        return 1;
                    }
                    else
                    {
                        return 1 + (d - 1) * 2;
                    }
                }
                else
                {
                    if (d <= 2)
                    {
                        return d * 2;
                    }
                    int side = R + C - 2;
                    if (d <= side)
                    {
                        return 4 + (d - 2) * 3;
                    }
                    else
                    {
                        return 4 + (side - 2) * 3 + (d - side) * 4;
                    }
                }
            }
            else
            {
                if (R == 1 || C == 1)
                {
                    return d * 2;
                }
                else
                {
                    int side = (R / 2) * 2 + (C / 2) * 2;
                    if (d <= side)
                    {
                        return d * 3;
                    }
                    else
                    {
                        return side * 3 + (d - side) * 4;
                    }
                }
            }
        }
    }
}
