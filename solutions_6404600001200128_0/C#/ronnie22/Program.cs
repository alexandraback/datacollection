using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1
{
    class Program
    {
        static char[] delim = { ' ' };

        static void Main(string[] args)
        {
            TextReader input = File.OpenText("../../input.in");
            TextWriter output = File.CreateText("../../output.out");
            int n_case = int.Parse(input.ReadLine());

            for (int caso = 1; caso <= n_case; caso++)
            {
                int n_time = int.Parse(input.ReadLine());
                string[] line = input.ReadLine().Split(delim);
                int[] mush = new int[n_time];
                int ris1 = 0;
                int ris2 = 0;
                for (int i = 0; i < n_time; i++) 
                {
                    mush[i] = int.Parse(line[i]);
                }

                //compute ris1
                for (int i = 0; i < n_time - 1; i++)
                {
                    ris1 += Math.Max(mush[i] - mush[i+1], 0);
                }

                //compute ris2
                int max = -1;
                for (int i = 0; i < n_time - 1; i++)
                {
                    max = Math.Max(mush[i] - mush[i+1], max);
                }

                for (int i = 0; i < n_time - 1; i++)
                {
                    ris2 += Math.Min(mush[i], max);
                }

                output.WriteLine("Case #" + caso + ": " + ris1 + " " + ris2);
            }
            input.Close();
            output.Close();
        }
    }
}
