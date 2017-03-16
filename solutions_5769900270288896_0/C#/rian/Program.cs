using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

namespace Solver
{
    class Program
    {
        const int M = 1000000007;
        static void Main()
        {
//            var sw = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
            string textFile = @"C:\Users\Rikuto\Downloads\B-small-attempt0.in";
            string filePath = @"C:\Users\Rikuto\Downloads\out.txt";
            Encoding enc = Encoding.GetEncoding("shift_jis");
            string[] lines = File.ReadAllLines(textFile, enc);
            int t = int.Parse(lines[0]);
            var ans = new string[t];
            for (int i = 0; i < t; i++)
            {
                int[] a = lines[i + 1].Split().Select(int.Parse).ToArray();
                int r = a[0], c = a[1], n = a[2];
                ans[i] = "Case #" + (i + 1) + ": ";
                if (n == 0)
                {
                    ans[i] += "0";
                    continue;
                }
                if (n == r * c)
                {
                    ans[i] += (r * c * 2 - r - c);
                    continue;
                }
                int min = r * c * 2 - r - c;
                for (int j = 0; j < (1 << (r * c)); ++j)
                {
                    var exi = new bool[r, c];
                    int count = 0;
                    for (int k = 0; k < r * c; ++k)
                    {
                        if ((j >> k) % 2 == 1)
                        {
                            exi[k / c, k % c] = true;
                            ++count;
                        }
                    }
                    if (count != n)
                        continue;

                    int sum = 0;
                    for (int k = 0; k < r; k++)
                    {
                        for (int l = 0; l < c; l++)
                        {
                            if (k < r - 1 && exi[k, l] && exi[k + 1, l])
                                ++sum;
                            if (l < c - 1 && exi[k, l] && exi[k, l + 1])
                                ++sum;
                        }
                    }
                    min = Math.Min(min, sum);
                    if (min == 0)
                        break;
                }
                ans[i] += min;
            }
            
            File.WriteAllLines(filePath, ans, enc);

        }
    }
    class Scan
    {
        public int Int { get { return int.Parse(Console.ReadLine().Trim()); } }
        public long Long { get { return long.Parse(Console.ReadLine().Trim()); } }
        public string Str { get { return Console.ReadLine().Trim(); } }
        public int[] IntArr { get { return Console.ReadLine().Trim().Split().Select(int.Parse).ToArray(); } }
        public long[] LongArr { get { return Console.ReadLine().Trim().Split().Select(long.Parse).ToArray(); } }
        public double[] DoubleArr { get { return Console.ReadLine().Split().Select(double.Parse).ToArray(); } }
        public string[] StrArr { get { return Console.ReadLine().Trim().Split(); } }
        public List<int> IntList { get { return Console.ReadLine().Trim().Split().Select(int.Parse).ToList(); } }
        public List<long> LongList { get { return Console.ReadLine().Trim().Split().Select(long.Parse).ToList(); } }
        public void Multi(out int a, out int b) { var arr = IntArr; a = arr[0]; b = arr[1]; }
        public void Multi(out int a, out int b, out int c) { var arr = IntArr; a = arr[0]; b = arr[1]; c = arr[2]; }
        public void Multi(out int a, out int b, out int c, out int d) { var arr = IntArr; a = arr[0]; b = arr[1]; c = arr[2]; d = arr[3]; }
        public void Multi(out int a, out int b, out int c, out int d, out int e) { var arr = IntArr; a = arr[0]; b = arr[1]; c = arr[2]; d = arr[3]; e = arr[4]; }
        public void Multi(out long a, out long b) { var arr = LongArr; a = arr[0]; b = arr[1]; }
        public void Multi(out long a, out long b, out long c) { var arr = LongArr; a = arr[0]; b = arr[1]; c = arr[2]; }
        public void Multi(out long a, out long b, out long c, out long d) { var arr = LongArr; a = arr[0]; b = arr[1]; c = arr[2]; d = arr[3]; }
        public void Multi(out long a, out long b, out long c, out long d, out long e) { var arr = LongArr; a = arr[0]; b = arr[1]; c = arr[2]; d = arr[3]; e = arr[4]; }
        public void Multi(out string a, out string b) { var arr = StrArr; a = arr[0]; b = arr[1]; }
        public void Multi(out long a, out double b, out double c) { var arr = DoubleArr; a = (long)arr[0]; b = arr[1]; c = arr[2]; }
    }
}