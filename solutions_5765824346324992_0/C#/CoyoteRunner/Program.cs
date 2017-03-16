using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Numerics;
using System.Threading.Tasks;

namespace google_code_jam
{
    class Haircut
    {
        long gcd(long m, long n)
        {
            if (n > m)
            {
                return gcd(n, m);
            }

            if (n == 0)
            {
                return m;
            }

            return gcd(n, m % n);
        }

        long lcm(long a, long b)
        {
            return a * b / gcd(a, b);
        }

        public string solve(string s1, string s2)
        {
            long B = int.Parse(s1.Split(' ')[0]);
            long N = int.Parse(s1.Split(' ')[1]);

            var M = new List<long>();

            foreach (var t in s2.Split(' '))
            {
                M.Add(int.Parse(t));
            }

            long L = M[0];

            for (int i = 1; i < M.Count; i++)
            {
                L = lcm(L, M[i]);
            }

            long sum = 0;

            for (int i = 0; i < M.Count; i++)
            {
                sum += L / M[i];
            }

            long d = N % sum;

            if (d == 0)
            {
                d = sum;
            }

            if (d <= B)
            {
                return d.ToString();
            }

            d -= B;

            long max = M.Max();
            var b = new long[B];

            for (long i = 0; ; i++)
            {
                for (int j = 0; j < B; j++)
                {
                    b[j]++;

                    if (b[j] == M[j])
                    {
                        b[j] = 0;

                        d--;

                        if (d == 0)
                        {
                            return (j + 1).ToString();
                        }
                    }
                }
            }

            return "";
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            string folder = @"D:\tmp\";
            string input = "input.in";

            StreamReader reader = new StreamReader(folder + input, Encoding.ASCII);
            StreamWriter writer = new StreamWriter(folder + "out.txt");
            string s = reader.ReadLine();

            int T = int.Parse(s);

            for (int i = 0; i < T; i++)
            {
                //reader.ReadLine();
                var x = reader.ReadLine();
                var y = reader.ReadLine();

                string r = "Case #" + (i + 1).ToString() + ":" + " " + new Haircut().solve(x, y);

                writer.WriteLine(r);
                Console.WriteLine(r);
            }
            reader.Close();
            writer.Close();
        }
    }
}
