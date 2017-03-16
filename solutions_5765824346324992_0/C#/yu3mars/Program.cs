using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace b
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamWriter w = new StreamWriter(@"output-small1-0.txt"))
            {
                using (StreamReader r = new StreamReader(@"B-small-attempt1.in"))
                {
                    long t = int.Parse(r.ReadLine());
                    for (long i = 0; i < t; i++)
                    {
                        long ans = 0;
                        string[] bn = r.ReadLine().Split(' ');
                        long b = long.Parse(bn[0]);
                        long n = long.Parse(bn[1]);
                        string[] mstr = r.ReadLine().Split(' ');
                        long[] m = new long[b];
                        long inter = 1;
                        long lastb = 0;
                        long lastval = long.MaxValue;
                        for (long j = 0; j < b; j++)
                        {
                            m[j] = long.Parse(mstr[j]);
                            inter = Lcm(inter, m[j]);
                            if (lastval >= m[j])
                            {
                                lastval = m[j];
                                lastb = j;
                            }
                        }
                        long intercnt = 0;
                        for (long j = 0; j < b; j++)
                        {
                            intercnt += inter / m[j];
                        }
                        bool done = false;
                        long cnt = 0;

                        cnt += (n / intercnt) * intercnt;
                        if (cnt == n)
                        {
                            ans = lastb + 1;
                            w.WriteLine("Case #{0}: {1}", i + 1, ans);
                            continue;
                        }

                        for (long j = 0; j < inter; j++)
                        {
                            for (long k = 0; k < b; k++)
                            {
                                if (j % m[k] == 0)
                                {
                                    cnt += 1;
                                    if (cnt == n)
                                    {
                                        ans = k + 1;
                                        done = true;
                                        //w.WriteLine("Case #{0}: {1}", i + 1, ans);
                                        continue;
                                    }
                                }
                            }
                            if (done == true) break;
                        }
                        w.WriteLine("Case #{0}: {1}", i + 1, ans);
                        //w.WriteLine("Error");
                    }
                }
            }
        }
        static long Gcd(long a, long b)
        {
            if (b == 0) return a;
            return Gcd(b, a % b);
        }

        static long Lcm(long a, long b)
        {
            return (long)a / Gcd(a, b) * b;
        }
    }
}
