using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace a
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamWriter w = new StreamWriter(@"output-small.txt"))
            {
                using (StreamReader r = new StreamReader(@"A-small-attempt0.in"))
                {
                    int t = int.Parse(r.ReadLine());
                    for (int i = 0; i < t; i++)
                    {
                        int n = int.Parse(r.ReadLine());
                        string[] mstr = r.ReadLine().Split(' ');
                        int[] m = new int[n];
                        for (int j = 0; j < n; j++)
                        {
                            m[j] = int.Parse(mstr[j]);
                        }
                        int[] ans = new int[2];

                        for (int j = 1; j < n; j++)
                        {
                            if (m[j - 1] - m[j] > 0)
                            {
                                ans[0] += m[j - 1] - m[j];
                            }
                        }
                        int rate = 0;
                        for (int j = 1; j < n; j++)
                        {
                            rate = Math.Max(rate, m[j - 1] - m[j]);                      
                        }
                        for (int j = 0; j < n - 1; j++)
                        {
                            ans[1] += Math.Min(m[j], rate);
                        }
                        
                        w.WriteLine("Case #{0}: {1} {2}", i + 1, ans[0], ans[1]);
                    }
                }
            }
        }
    }
}
