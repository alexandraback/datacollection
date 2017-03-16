using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.IO;
using System.Xml;

namespace Facebook
{
    static class Program
    {
        static void Solve()
        {
            var s = sr.ReadLine().Split(' ');
            int n = int.Parse(s[0]);
            var list = new List<string>();
            for(int i = 0; i<n; i++)
                list.Add(sr.ReadLine());
            var t = list[0];
            int k = 1;
            int[,] m = new int[150,150];
            char[] c = new char[150];
            m[0, 0] = 1;
            c[0] = t[0];
            for (int i = 1; i < t.Length; i++)
            {
                if (t[i] == t[i - 1])
                {
                    m[0, k - 1]++;
                }
                else
                {
                    m[0, k] = 1;
                    c[k] = t[i];
                    k++;
                }
            }
            for (int j = 1; j < n; j++)
            {
                t = list[j];
                if (t[0] != c[0])
                {
                    Print("Fegla Won");
                    return;
                }
                m[j, 0] = 1;
                int cur = 0;
                for (int i = 1; i < t.Length; i++)
                {
                    if (t[i] == t[i - 1])
                    {
                        m[j, cur]++;
                    }
                    else
                    {
                        cur++;
                        if (t[i] != c[cur])
                        {
                            Print("Fegla Won");
                            return;
                        }
                        m[j, cur] = 1;
                        
                        
                    }
                }
                if (cur + 1 != k)
                {
                    Print("Fegla Won");
                    return;
                }
            }
            int res = 0;
            for (int i = 0; i < k; i++)
            {
                int min = 1000000000;
                for (int x = 1; x < 102; x++)
                {
                    int r = 0;
                    for (int j = 0; j < n; j++)
                    {
                        r += Math.Abs(m[j, i] - x);

                    }
                    if (r < min) min = r;
                }
                res += min;
            }
            Print(res.ToString());
        }

        static void PreCalc()
        {
        }

        #region Main
        static int testNum = 1;
        static StreamReader sr;
        static StreamWriter sw;
        static void Print(string s)
        {
            sw.WriteLine("Case #{0}: {1}", testNum, s);
            testNum++;
        }
        static void Main(string[] args)
        {
            PreCalc();
            sr = new StreamReader(@"..\..\in.txt");
            sw = new StreamWriter(@"..\..\out.txt");
            int t = int.Parse(sr.ReadLine());
            for (int i = 0; i < t; i++)
            {
                Solve();
            }
            sr.Dispose();
            sw.Dispose();
        }
        #endregion
    }
}
