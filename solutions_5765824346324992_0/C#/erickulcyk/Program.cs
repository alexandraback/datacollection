using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ_2013
{
    class Program
    {
        static long gcd(long a, long b)
        {
            return b == 0 ? a : gcd(b, a % b);
        }

        static void Main(string[] args)
        {
            long t = long.Parse(Console.ReadLine());
            for (long i =0; i < t;i++)
            {
                string[] a = Console.ReadLine().Split();
                int b = int.Parse(a[0]);
                int n = int.Parse(a[1]);
                long[] m = new long[b];
                string [] c=  Console.ReadLine().Split();
                long gcdn = 1;
                for(int j =0; j < b;j++)
                {
                    m[j] = long.Parse(c[j]);
                    if(j==0)
                    {
                        gcdn = m[j];
                    }
                    else
                    {
                        gcdn = gcd(gcdn, m[j]);
                    }
                }



                long lcm = m[0];
                for (int j = 1; j < b; j++)
                {
                    lcm *= m[j] / gcdn;
                }

                //Console.WriteLine("GCDN: " + gcdn);
                //Console.WriteLine("lcm: " + lcm);

                long num = 0;
                for (int j = 0; j < b; j++)
                {
                    num += lcm / m[j];
                }

                //Console.WriteLine("n, num: " + n+" "+ num);
                //num++;
                long left = (n-1) % num + 1;

                //Console.WriteLine("left: " + left);

                long[] good = new long[b];
                for (int j = 0; j < b; j++)
                {
                    good[j] = 0;
                }

                int ind = 0;
                for (long j = 0; j < left; j++ )
                {
                    long minTime = -1;
                    ind = -1;
                    for (int k = 0; k < b; k++)
                    {
                        if(minTime==-1 || good[k]<minTime)
                        {
                            minTime = good[k];
                            ind = k;
                        }
                    }

                    good[ind] += m[ind];
                }

                Console.WriteLine("Case #" + (i + 1) + ": " + (ind+1));
            }
        }
    }
}
