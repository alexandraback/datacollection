using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.Threading;

namespace CodeJam
{
    class Program
    {
        static string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        static void Main(string[] args)
        {
            //string fileName = "in";
            string fileName = "A-small-attempt1.in";
            //string fileName = "A-large.in";
            Console.SetIn(new System.IO.StreamReader(@"..\..\..\" + fileName));
            Console.SetOut(new System.IO.StreamWriter(@"..\..\..\out"));

            //SetCulture();

            int testCases = ReadInt();
            for (int testCase = 1; testCase <= testCases; testCase++)
            {
                var n = NextInt();
                var p = ReadInts();
                var ind = new int[n];
                long total = 0;
                for (int i = 0; i < n; i++)
                {
                    ind[i] = i;
                    total += p[i];
                }

                Array.Sort(p, ind);
                Array.Reverse(p);
                Array.Reverse(ind);
                StringBuilder sb = new StringBuilder();
                int c = 0;
                while (total > 2)
                {
                    if (c == 2)
                    {
                        c = 0;
                        sb.Append(' ');
                    }
                    sb.Append(alph[ind[0]]);
                    c++;
                    p[0]--;
                    int j = 0;
                    while (j < n - 1 && p[j] <= p[j + 1])
                    {
                        p[j] ^= p[j + 1];
                        p[j + 1] ^= p[j];
                        p[j] ^= p[j + 1];

                        ind[j] ^= ind[j + 1];
                        ind[j + 1] ^= ind[j];
                        ind[j] ^= ind[j + 1];

                        j++;
                    }
                    total--;
                }

                if (c != 0)
                {
                    sb.Append(' ');
                }

                sb.Append(alph[ind[0]]);
                sb.Append(alph[ind[1]]);

                Console.WriteLine("Case #{0}: {1}", testCase, sb.ToString());
            }

            //Console.WriteLine(string.Format(NumberFormatInfo.InvariantInfo, "{0:F4}", res));

            Console.In.Close();
            Console.Out.Close();
        }

        private static char[] _defaultSplitter = new char[] { ' ', '\t' };

        private static void SetCulture()
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        }

        private static char[] ReadChars(int n)
        {
            char[] buffer = new char[n];
            Console.In.ReadBlock(buffer, 0, n);
            return buffer;
        }

        private static string[] ReadAll()
        {
            return Console.In.ReadToEnd().Split(new char[] { ' ', '\t', '\n', '\r' }, StringSplitOptions.RemoveEmptyEntries);
        }

        private static string[] ReadWords(char[] splitter)
        {
            return Console.ReadLine().Split(splitter, StringSplitOptions.RemoveEmptyEntries);
        }

        private static string[] ReadWords()
        {
            return ReadWords(_defaultSplitter);
        }

        private static int ReadInt()
        {
            return int.Parse(Console.ReadLine());
        }

        private static int[] ReadInts(char[] splitter)
        {
            return Console.ReadLine().Split(splitter, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToArray();
        }

        private static int[] ReadInts()
        {
            return ReadInts(_defaultSplitter);
        }

        private static long ReadLong()
        {
            return long.Parse(Console.ReadLine());
        }

        private static double ReadDouble()
        {
            return double.Parse(Console.ReadLine(), NumberFormatInfo.InvariantInfo);
        }

        private static int _pos = 0;
        private static string[] _inputLine = new string[0];

        private static void CheckInputLine()
        {
            if (_pos >= _inputLine.Length)
            {
                _inputLine = ReadWords();
                _pos = 0;
            }
        }

        private static string NextWord()
        {
            CheckInputLine();
            return _inputLine[_pos++];
        }

        private static int NextInt()
        {
            CheckInputLine();
            return int.Parse(_inputLine[_pos++]);
        }

        private static long NextLong()
        {
            CheckInputLine();
            return long.Parse(_inputLine[_pos++]);
        }
    }
}
