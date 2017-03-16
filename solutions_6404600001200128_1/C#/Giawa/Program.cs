using System;
using System.Collections.Generic;
using System.IO;

namespace RoundA_A
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader stream = new StreamReader("C:/Users/Montana/Desktop/A-large.in"))
            using (StreamWriter output = new StreamWriter("C:/Users/Montana/Desktop/A-large.out"))
            {
                int cases = int.Parse(stream.ReadLine());

                for (int i = 0; i < cases; i++)
                {
                    int count = int.Parse(stream.ReadLine());

                    string[] split = stream.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    int[] mushrooms = new int[split.Length];

                    int a = 0;
                    int maxdiff = 0;
                    for (int j = 0; j < split.Length; j++)
                    {
                        mushrooms[j] = int.Parse(split[j]);

                        if (j > 0)
                        {
                            int diff = mushrooms[j - 1] - mushrooms[j];
                            if (diff > maxdiff) maxdiff = diff;
                            a += Math.Max(0, diff);
                        }
                    }

                    int mushroomsPerTenSeconds = maxdiff;
                    int b = 0;
                    int onPlate = mushrooms[0];

                    for (int j = 1; j < mushrooms.Length; j++)
                    {
                        if (onPlate > mushroomsPerTenSeconds)
                        {
                            onPlate -= mushroomsPerTenSeconds;
                            b += mushroomsPerTenSeconds;
                        }
                        else
                        {
                            b += onPlate;
                            onPlate = 0;
                        }

                        onPlate = mushrooms[j];
                    }

                    output.WriteLine("Case #{0}: {1} {2}", i + 1, a, b);
                }
            }
        }
    }
}
