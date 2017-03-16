using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        private static int[] howmany(int[] line2)
        {
            int sum = 0;
            int max = 0;
            for (int i = 0; i < line2.Length-1; i++)
            {
                if (line2[i] - line2[i + 1] > 0)
                {
                    sum += line2[i] - line2[i + 1];
                }
                if (line2[i] - line2[i + 1] > max) max = line2[i] - line2[i+1];
            }
            int cucc=0;
            for (int i = 0; i < line2.Length-1; i++)
            {
                if (line2[i] < max)
                {
                    cucc += line2[i];
                }
                else cucc += max;
            }
            return new int[] { sum,cucc };
        }


        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("A-small-attempt0.in");
            StreamWriter sw = new StreamWriter("A-small-attempt0.out");
         //   StreamReader sr = new StreamReader("A.in");
        //    StreamWriter sw = new StreamWriter("A.out");
            int T = Int32.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                int N = Int32.Parse(sr.ReadLine());
                string[] line = sr.ReadLine().Split(' ');
                int[] line2 = new int[line.Length];
                for (int j = 0; j < line.Length; j++)
                {
                    line2[j] = Int32.Parse(line[j]);
                }
                int[] time = howmany(line2);
                sw.WriteLine("Case #{0}: {1} {2}", i+1,time[0], time[1]);
            }
            sr.Close();
            sw.Flush();
            sw.Close();
        }

    }
}
