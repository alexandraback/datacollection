using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NoisyNeighbours
{
    class Program
    {
        static void Main(string[] args)
        {
            string inputFilePath = args[0];
            string outputFilePath = Path.GetFileNameWithoutExtension(inputFilePath) + ".out";
            using (StreamReader reader = new StreamReader(inputFilePath))
            {
                using (StreamWriter writer = new StreamWriter(outputFilePath))
                {
                    int T = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= T; i++)
                    {
                        int[] data = reader.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                        int R = data[0];
                        int C = data[1];
                        int N = data[2];

                        writer.WriteLine(string.Format("Case #{0}: {1}", i, GetMinimumUnhappiness(C, R, N)));
                    }
                }
            }
        }

        static int GetMinimumUnhappiness(int width, int height, int N)
        {
            int minimumUnhappiness = int.MaxValue;

            bool[,] appartments = new bool[width, height];

            for (int i = 0; i <= 65536; i++)
            {
                string b = GetBinaryString(i).Substring(0, width * height);

                if (b.Count(c => c == '1') == N)
                {
                    int j = 0;
                    for (int y = 0; y < height; y++)
                    {
                        for (int x = 0; x < width; x++)
                        {
                            appartments[x, y] = b[j++] == '1';
                        }
                    }

                    int unhappiness = 0;

                    // "vertical" walls
                    for (int y = 0; y < height; y++)
                    {
                        for (int x = 0; x < width - 1; x++)
                        {
                            if (appartments[x, y] && appartments[x + 1, y])
                            {
                                unhappiness++;
                            }
                        }
                    }

                    // "horizontal" walls
                    for (int x = 0; x < width; x++)
                    {
                        for (int y = 0; y < height - 1; y++)
                        {
                            if (appartments[x, y] && appartments[x, y + 1])
                            {
                                unhappiness++;
                            }
                        }
                    }

                    if (unhappiness < minimumUnhappiness)
                    {
                        minimumUnhappiness = unhappiness;
                    }
                }
            }

            return minimumUnhappiness;
        }

        static string GetBinaryString(int i)
        {
            StringBuilder b = new StringBuilder();

            while (i > 0)
            {
                b.Append(i % 2 == 1 ? "1" : "0");

                i /= 2;
            }

            return b.ToString().PadRight(16, '0');
        }
    }
}