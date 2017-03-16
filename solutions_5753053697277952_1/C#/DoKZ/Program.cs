using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main()
        {
            File.Delete("output.txt");

            int t;
            using (var sr = new StreamReader(File.OpenRead("input.txt")))
            using (var sw = new StreamWriter(new FileStream("output.txt", FileMode.CreateNew)))
            {
                t = int.Parse(sr.ReadLine());

                for (int tRun = 0; tRun < t; tRun++)
                {
                    RunTest(tRun, sr, sw);
                }
            }
        }

        static void RunTest(int run, StreamReader reader, StreamWriter writer)
        {
            writer.Write("Case #{0}: ", run + 1);

            int n = int.Parse(reader.ReadLine());
            int[] parties = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();

            if (n == 2)
            {
                while (parties[0] != parties[1])
                {
                    if (parties[0] > parties[1])
                    {
                        writer.Write("A ");
                        parties[0]--;
                    }
                    else
                    {
                        writer.Write("B ");
                        parties[1]--;
                    }
                }

                while (parties[0] > 0)
                {
                    writer.Write("AB ");
                    parties[0]--;
                    parties[1]--;
                }
            }

            while (parties.Sum() > 2)
            {
                int maxParty = 0;
                for (int i = 1; i < n; i++)
                {
                    if (parties[i] > parties[maxParty])
                        maxParty = i;
                }

                parties[maxParty]--;
                writer.Write((char)('A' + maxParty) + " ");
            }

            for (int i = 0; i < n; i++)
            {
                while (parties[i] > 0)
                {
                    writer.Write((char)('A' + i));
                    parties[i]--;
                }
            }

            writer.WriteLine();
        }
    }
}
