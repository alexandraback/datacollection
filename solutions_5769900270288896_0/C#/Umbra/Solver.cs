using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

namespace ReadWriteTemplate
{
    public class Solver
    {
        public static int bestNoise;
        public static bool[,] map;
        public static bool[,] bestMap;

        private static void SolveCase(int caseNumber)
        {
            var r = ReadInt();
            var c = ReadInt();
            var n = ReadInt();

            bestNoise = int.MaxValue;
            map = new bool[r, c];
            StartBT(0, n, r, c);
            Writer.WriteLine("Case #{0}: {1}", caseNumber, bestNoise);
        }

        private static void StartBT(int pos, int t, int r, int c)
        {
            if (t == 0)
            {
                int noise = 0;
                for (int i = 0; i < r; i++)
                {
                    for (int j = 0; j < c; j++)
                    {
                        if (map[i, j])
                        {
                            if (i + 1 < r && map[i + 1, j])
                            {
                                noise++;
                            }
                            if (j + 1 < c && map[i, j + 1])
                            {
                                noise++;
                            }
                        }
                    }
                }
                if (noise < bestNoise)
                {
                    bestNoise = noise;
                }
                return;
            }

            if (r * c - pos < t)
            {
                return;
            }

            StartBT(pos + 1, t, r, c);
            map[pos / c, pos % c] = true;
            StartBT(pos + 1, t - 1, r, c);
            map[pos / c, pos % c] = false;
        }

        public static void Solve()
        {
            var n = ReadInt();
            for (int i = 0; i < n; i++)
            {
                SolveCase(i + 1);
            }
        }

        public static void Main()
        {
            //Reader = Console.In; Writer = Console.Out;
            Reader = File.OpenText("input.txt"); Writer = File.CreateText("output.txt");

            Solve();

            Reader.Close();
            Writer.Close();
        }

        #region Read/Write

        private static TextReader Reader;

        private static TextWriter Writer;

        private static Queue<string> CurrentLineTokens = new Queue<string>();

        private static string[] ReadAndSplitLine()
        {
            return Reader.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
        }

        public static string ReadToken()
        {
            while (CurrentLineTokens.Count == 0)
                CurrentLineTokens = new Queue<string>(ReadAndSplitLine());
            return CurrentLineTokens.Dequeue();
        }

        public static int ReadInt()
        {
            return int.Parse(ReadToken());
        }

        public static long ReadLong()
        {
            return long.Parse(ReadToken());
        }

        public static double ReadDouble()
        {
            return double.Parse(ReadToken(), CultureInfo.InvariantCulture);
        }

        public static int[] ReadIntArray()
        {
            return ReadAndSplitLine().Select(int.Parse).ToArray();
        }

        public static long[] ReadLongArray()
        {
            return ReadAndSplitLine().Select(long.Parse).ToArray();
        }

        public static double[] ReadDoubleArray()
        {
            return ReadAndSplitLine().Select(s => double.Parse(s, CultureInfo.InvariantCulture)).ToArray();
        }

        public static int[][] ReadIntMatrix(int numberOfRows)
        {
            int[][] matrix = new int[numberOfRows][];
            for (int i = 0; i < numberOfRows; i++)
                matrix[i] = ReadIntArray();
            return matrix;
        }

        public static string[] ReadLines(int quantity)
        {
            string[] lines = new string[quantity];
            for (int i = 0; i < quantity; i++)
                lines[i] = Reader.ReadLine().Trim();
            return lines;
        }

        public static void WriteArray<T>(IEnumerable<T> array)
        {
            Writer.WriteLine(string.Join(" ", array));
        }

        #endregion
    }
}
