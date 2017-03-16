using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace Solution {

    class Solver
    {
        #region hel
        int ReadInt()
        {
            return int.Parse(Console.ReadLine());
        }

        string ReadString()
        {
            return Console.ReadLine();
        }
        #endregion


        private int GetMin(List<string> s)
        {
            string bc="";
            List<List<int>> r = new List<List<int>>();
            for (int i = 0; i < s.Count; i++)
            {
                string c = s[i];
                string a = "";
                int k = 1;
                List<int> l = new List<int>();
                for (int j = 0; j < c.Length-1; j++)
                {
                    if (c[j] != c[j + 1])
                    {
                        a += c[j];
                        l.Add(k);
                        k = 1;
                    }
                    else
                    {
                        k++;
                    }
                }
                a += c[c.Length - 1];
                l.Add(k);
                r.Add(l);

                if (string.IsNullOrEmpty(bc))
                    bc = a;
                if (bc != a)
                    return -1;
            }

            return MCount(r);

        }

        private int MCount(List<List<int>> r)
        {
            int mm = 0;
            for (int j = 0; j < r[0].Count; j++)
            {
                List<int> cv = new List<int>();
                for (int i = 0; i < r.Count; i++)
                {
                    cv.Add(r[i][j]);
                }

                cv = cv.OrderBy(x => x).ToList();
                int m = cv[cv.Count / 2];
                foreach (int k in cv)
                {
                    mm += Math.Abs(k - m);
                }
            }
            return mm;
        }

        internal void Solve()
        {
            int T = ReadInt();
            for (int i = 1; i <= T; i++)
            {
                int N = ReadInt();
                List<string> s = new List<string>();
                for (int j = 0; j < N; j++)
                {
                    s.Add(ReadString());
                }
                var v = GetMin(s);
                Console.WriteLine("Case #{0}: {1}",i , v == -1 ? "Fegla Won" : v.ToString());
            }
        }
    }


    class Solution
    {
        static Regex catIdRegex = new Regex("(%\\d+)");
      
        static void Main(string[] args)
        {
            Solver s = new Solver();
            s.Solve();
        }
    }
}
