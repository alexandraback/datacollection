
using System;
using System.Linq;
using System.IO;
using System.Collections.Generic;

namespace _151BB
{
    class Program
    {
        private const bool DEBUG = false;
        static void debug()
        {

        }

        static string solveCase()
        {
            int[] rcn = readMany<int>();
            int r = rcn[0];
            int c = rcn[1];
            bool?[][] v = new bool?[r][];
            for (int i = 0; i < r; i++)
            {
                v[i] = new bool?[c];
                for (int j = 0; j < c; j++)
                {
                    v[i][j] = null;
                }
            }
            return solve(r, c, v, rcn[2]).ToString();
        }

        static int solve(int r, int c, bool?[][] src, int more)
        {
            for (int cr = 0; cr < r; cr++)
            {
                for (int cc = 0; cc < c; cc++)
                {
                    if (!src[cr][cc].HasValue)
                    {
                        src[cr][cc] = true;
                        int a = solve(r, c, src, more - 1);
                        src[cr][cc] = false;
                        int b = solve(r, c, src, more);
                        src[cr][cc] = null;
                        return Math.Min(a, b);
                    }
                }
            }
            if (more == 0)
            {
                return score(r, c, src);
            }
            return int.MaxValue;
        }

        static int score(int r, int c, bool?[][] rooms)
        {
            int res = 0;
            for (int cr = 0; cr < r; cr++)
            {
                for (int cc = 0; cc < c; cc++)
                {
                    if (cc != c - 1 && rooms[cr][cc].Value && rooms[cr][cc + 1].Value) res++;
                    if (cr != r - 1 && rooms[cr][cc].Value && rooms[cr + 1][cc].Value) res++;
                }
            }
            return res;
        }

        static void Main(string[] args)
        {
            if (DEBUG)
            {
                debug();
            }
            else
            {
                Initialize();
                SolveAll(solveCase);
            }
            Console.ReadKey();
        }

        private static StreamReader inf;
        private static StreamWriter outf;

        private delegate void o(string format, params object[] args);
        private static o Output;

        private static T read<T>()
        {
            return (T)Convert.ChangeType(inf.ReadLine(), typeof(T));
        }

        private static string read()
        {
            return inf.ReadLine();
        }

        private static T[] readMany<T>()
        {
            return readMany<T>(' ');
        }

        private static _[] readMany<_>(params char[] ___)
        {
            return read().Split(___).Select(__ => (_)Convert.ChangeType(__, typeof(_))).ToArray();
        }

        private static string[] readMany()
        {
            return readMany<string>();
        }

        private static T[][] readField<T>(int height, Func<char, T> map)
        {
            T[][] res = new T[height][];
            for (int _ = 0; _ < height; _++)
            {
                res[_] = read().Select(c => map(c)).ToArray();
            }
            return res;
        }

        private static char[][] readField(int height)
        {
            return readField(height, c => c);
        }

        private static T[][] readField<T>(int height, Dictionary<char, T> dic)
        {
            return readField(height, c => dic[c]);
        }

        public static void Initialize()
        {
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write("Input file: ");
            inf = new StreamReader(Console.ReadLine());
            Console.Write("Output file: ");
            outf = new StreamWriter(Console.ReadLine());
            Console.ForegroundColor = ConsoleColor.White;
            Output = highlightedPrint;
            Output += outf.WriteLine;
        }

        private static void highlightedPrint(string format, params object[] args)
        {
            ConsoleColor prev = Console.ForegroundColor;
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine(format, args);
            Console.ForegroundColor = prev;
        }

        public static void SolveAll(Func<string> calc)
        {
            int cases = int.Parse(inf.ReadLine());
            for (int _ = 1; _ <= cases; _++)
            {
                Output("Case #{0}: {1}", _, calc());
            }
            inf.Close();
            outf.Close();
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine("Eureka!");
        }
    }
}