using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj16r1c
{
    class Program
    {
        public static int largest = 0;
        public static long count;

        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"C:\GCJ\A-large.in");
            int idx = 0;
            int t = int.Parse(lines[idx++]);
            TextWriter tw = new StreamWriter(@"C:\GCJ\A-large.out");
            for (int a = 0; a < t; a++)
            {
                int N = int.Parse(lines[idx++]);
                int[] numSens = new int[N];
                string[] line = lines[idx++].Split(' ');
                for (int b = 0; b < N; b++)
                {
                    numSens[b] = int.Parse(line[b]);
                }
                tw.WriteLine("Case #{0}:{1}", a + 1, calca(N, numSens));
            }
            tw.Close();
        }

        private static string calca(int n, int[] numSens)
        {
            string ans = "";
            while (true)
            {
                int max = -1;
                List<int> tops = new List<int>();
                for (int a = 0; a < n; a++)
                {
                    if (numSens[a] > max)
                    {
                        tops = new List<int>();
                        tops.Add(a);
                        max = numSens[a];
                    }
                    else if (numSens[a] == max)
                    {
                        tops.Add(a);
                    }
                }
                if (max == 0)
                {
                    break;
                }
                int take = 2;
                if(max == 1 && tops.Count == 3)
                {
                    take = 1;
                }
                ans += " ";
                for (int a = 0; a < tops.Count && a < take; a++)
                {
                    ans += (char)('A' + tops[a]);
                    numSens[tops[a]]--;
                }
            }
            return ans;
        }

    }
}