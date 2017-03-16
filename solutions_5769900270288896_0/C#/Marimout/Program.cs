using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace _1B_2
{
    class Program
    {
        public static int R;
        public static int C;
        public static int N;
        public static int[,] a;
        public static int minUnhappy = Int32.MaxValue;
        public static int count;
        static void Main(string[] args)
        {
            const string inputFilename = @"D:\Projects\GoogleCodeJam2015\1B-2\input\B-small-attempt0.in";
            string outputFilename = Path.Combine(Path.GetDirectoryName(inputFilename), Path.GetFileNameWithoutExtension(inputFilename) + ".out");

            using (var output = new StreamWriter(outputFilename))
            {
                using (var input = new StreamReader(inputFilename))
                {
                    int T = Convert.ToInt32(input.ReadLine());
                    for (int i = 1; i <= T; i++)
                    {
                        string[] s = input.ReadLine().Split(' ');

                        R = int.Parse(s[0]);
                        C = int.Parse(s[1]);
                        N = int.Parse(s[2]);

                        a = new int[R, C];
                        count = 0;
                        minUnhappy = Int32.MaxValue;

                        TryPut(0, 0);

                        output.WriteLine("Case #{0}: {1}", i, minUnhappy);
                    }
                }
            }
        }

        public static int Solve(int R, int C, int N)
        {
            int[,] a = new int[R, C];
            int count = 0;
            int minUnhappy = int.MaxValue;
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    for (int k = 0; k < 2; k++)
                    {
                        a[i, j] = k;
                        count += k;

                        if (i == R - 1 && j == C - 1 && k == N)
                        {
                        }

                        count -= k;
                    }

                    if (minUnhappy == 0)
                        break;
                }

                if (minUnhappy == 0)
                    break;
            }

            return minUnhappy;
        }

        public static void TryPut(int i, int j)
        {
            if (minUnhappy == 0)
                return;

            for (int k = 0; k < 2; k++)
            {
                a[i, j] = k;
                count += k;

                if (count <= N)
                {
                    if (i == R - 1 && j == C - 1)
                    {
                        if (count == N)
                        {
                            int u = CountUnhappy();
                            if (u < minUnhappy)
                            {
                                minUnhappy = u;
                            }
                        }
                    }
                    else
                    {
                        if (j < C - 1)
                        {
                            TryPut(i, j + 1);
                        }
                        else
                        {
                            TryPut(i + 1, 0);
                        }
                    }
                }
                count -= k;
            }
        }

        public static int CountUnhappy()
        {
            int c = 0;
            for (int i = 0; i < R - 1; i++)
            {
                for (int j = 0; j < C - 1; j++)
                {
                    // Voisin droit
                    if (a[i, j] == 1 && a[i, j + 1] == 1)
                        c++;
                    // Voisin en bas
                    if (a[i, j] == 1 && a[i + 1, j] == 1)
                        c++;
                }

                // Voisin en bas
                if (a[i, C - 1] == 1 && a[i + 1, C - 1] == 1)
                    c++;
            }

            for (int j = 0; j < C - 1; j++)
            {
                if (a[R - 1, j] == 1 && a[R - 1, j + 1] == 1)
                    c++;
            }

            return c;
        }
    }
}
