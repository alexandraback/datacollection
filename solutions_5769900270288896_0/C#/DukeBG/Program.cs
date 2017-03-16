using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace codejam_1b_2
{
    class Program
    {
        struct liv
        {
            public bool occupied;
            public byte neigh;
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(args.Length > 0 ? args[0] : "in");
            FileStream fsOut = new FileStream("out.txt", FileMode.Create);
            StreamWriter sw = new StreamWriter(fsOut);
            sw.AutoFlush = true;
            int testCount = int.Parse(sr.ReadLine());
            for (int i = 0; i < testCount; i++)
            {
                sw.Write(string.Format("Case #{0}: ", i + 1));
                string[] data = sr.ReadLine().Split(' ');
                int r = int.Parse(data[0]);
                int c = int.Parse(data[1]);
                int n = int.Parse(data[2]);
                if (r > c) { int t = r; r = c; c = t; }
                if (n <= 1)
                {
                    sw.WriteLine(0);
                    continue;
                }

                //int maxn = r * c - r - c;
                liv[,] x = new liv[r, c];
                for(int j1 = 0; j1 < r; j1++)
                    for (int j2 = 0; j2 < c; j2++)
                        x[j1, j2] = new liv { occupied = false, neigh = 0 };

                //reset_x(r, c, x);

                for (int t = 0; t < n; t++ )
                {
                    //int nt = noise(r, c, x);
                    //liv[,] x1 = new liv[r, c];
                    int jx = -1; int jy = -1; int m = 5;
                    for (int j1 = 0; j1 < r; j1++)
                        for (int j2 = 0; j2 < c; j2++)
                        {
                            if (x[j1, j2].occupied) continue;
                            int nei = 0;
                            if (j1 > 0 && x[j1 - 1, j2].occupied) nei++;
                            if (j1 < r - 1 && x[j1 + 1, j2].occupied) nei++;
                            if (j2 > 0 && x[j1, j2 - 1].occupied) nei++;
                            if (j2 < c - 1 && x[j1, j2 + 1].occupied) nei++;
                            if (nei < m)
                            {
                                m = nei;
                                jx = j1; jy = j2;
                            }
                        }
                    x[jx, jy].occupied = true;
                    //reset_x(r, c, x);
                }
                int res1 = noise(r, c, x);

                for (int j1 = 0; j1 < r; j1++)
                    for (int j2 = 0; j2 < c; j2++)
                        x[j1, j2] = new liv { occupied = true, neigh = 0 };
                reset_x(r, c, x);

                for (int t = r * c; t > n; t--)
                {
                    int m = -1; int jx = -1; int jy = -1;
                    for (int j1 = 0; j1 < r; j1++)
                        for (int j2 = 0; j2 < c; j2++)
                        {
                            if (x[j1, j2].neigh > m)
                            {
                                m = x[j1, j2].neigh;
                                jx = j1; jy = j2;
                            }
                        }
                    x[jx, jy] = new liv { occupied = false, neigh = 0 };
                    reset_x(r, c, x);
                }
                int res2 = noise(r, c, x);

                sw.WriteLine(Math.Min(res1, res2));
            }
            fsOut.Close();
        }

        private static int noise(int r, int c, liv[,] x)
        {
            int res = 0;
            for (int j1 = 0; j1 < r; j1++)
            {
                for (int j2 = 0; j2 < c; j2++)
                {
                    if (!x[j1, j2].occupied) { continue; }
                    if (j1 < r - 1 && x[j1 + 1, j2].occupied) res++;
                    if (j2 < c - 1 && x[j1, j2 + 1].occupied) res++;
                }
            }
            return res;
        }

        private static void reset_x(int r, int c, liv[,] x)
        {
            for (int j1 = 0; j1 < r; j1++)
            {
                for (int j2 = 0; j2 < c; j2++)
                {
                    x[j1, j2].neigh = 0;
                    if (!x[j1, j2].occupied) { continue; }
                    if (j1 > 0 && x[j1 - 1, j2].occupied) x[j1, j2].neigh++;
                    if (j1 < r - 1 && x[j1 + 1, j2].occupied) x[j1, j2].neigh++;
                    if (j2 > 0 && x[j1, j2 - 1].occupied) x[j1, j2].neigh++;
                    if (j2 < c - 1 && x[j1, j2 + 1].occupied) x[j1, j2].neigh++;
                }
            }
        }

    }
}
