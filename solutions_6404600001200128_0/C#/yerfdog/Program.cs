using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj15r1a
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines(@"C:\GCJ\A.in");
            int idx = 0;
            int t = int.Parse(lines[idx++]);
            TextWriter tw = new StreamWriter(@"C:\GCJ\A.out");
            for (int a = 0; a < t; a++)
            {
                int N = int.Parse(lines[idx++]);
                string[] line2 = lines[idx++].Split(' ');
                int first = int.Parse(line2[0]);
                int min1 = 0;
                int max2 = 0;
                for (int b = 1; b < N; b++)
                {
                    int next = int.Parse(line2[b]);
                    if (first > next)
                    {
                        min1+= first - next;
                        if (first - next > max2)
                        {
                            max2 = first - next;
                        }
                    }
                    first = next;
                }
                int min2 = 0;
                for (int b = 0; b < N-1; b++)
                {
                    min2 += Math.Min(int.Parse(line2[b]), max2);
                }

                tw.WriteLine("Case #{0}: {1} {2}", a+1, min1, min2);
            }
            tw.Close();
        }
    }
}
