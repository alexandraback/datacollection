using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Numerics;
using System.Threading.Tasks;

namespace google_code_jam
{
    class MushroomMonster
    {
        public string solve(string s)
        {
            var x = new List<int>();

            foreach (var t in s.Split(' '))
            {
                x.Add(int.Parse(t));
            }

            int N = x.Count;

            int u = 0;

            for (int i = 1; i < N; i++)
            {
                int d = x[i] - x[i - 1];

                if (d < 0)
                {
                    u += -d;
                }
            }

            int v = 0;
            int max = 0;

            for (int i = 1; i < N; i++)
            {
                int d = x[i] - x[i - 1];

                if (d < 0)
                {
                    max = Math.Max(max, -d);
                }
            }

            for (int i = 0; i < N - 1; i++)
            {
                if (max > x[i])
                {
                    v += x[i];
                }
                else
                {
                    v += max;
                }
            }

            return u.ToString() + " " + v.ToString();
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
                reader.ReadLine();
                var x = reader.ReadLine();

                string r = "Case #" + (i + 1).ToString() + ":" + " " + new MushroomMonster().solve(x);

                writer.WriteLine(r);
                Console.WriteLine(r);
            }
            reader.Close();
            writer.Close();
        }
    }
}
