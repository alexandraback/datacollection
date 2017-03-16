using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Numerics;

namespace A
{
    class Program
    {
        static int[,] arrangement1 = new int[4, 4];
        static int[,] arrangement2 = new int[4, 4];
        static int answer1, answer2;

        static string Solve()
        {
            List<int> possible1 = new List<int>();
            List<int> possible2 = new List<int>();

            for (int j = 0; j < 4; j++)
                possible1.Add(arrangement1[answer1 - 1, j]);
            for (int j = 0; j < 4; j++)
                possible2.Add(arrangement2[answer2 - 1, j]);

            var intersection = possible1.Intersect(possible2).ToArray();

            switch (intersection.Length)
            {
                case 0:
                    return "Volunteer cheated!";

                case 1:
                    return intersection.First().ToString();

                default:
                    return "Bad magician!";
            }
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                answer1 = int.Parse(Console.ReadLine());
                for (int i = 0; i < 4; i++)
                {
                    string[] line = Console.ReadLine().Split();
                    for (int j = 0; j < 4; j++)
                        arrangement1[i, j] = int.Parse(line[j]);
                }

                answer2 = int.Parse(Console.ReadLine());
                for (int i = 0; i < 4; i++)
                {
                    string[] line = Console.ReadLine().Split();
                    for (int j = 0; j < 4; j++)
                        arrangement2[i, j] = int.Parse(line[j]);
                }

                Console.WriteLine("Case #{0}: {1}", t, Solve());
            }
        }
    }
}
