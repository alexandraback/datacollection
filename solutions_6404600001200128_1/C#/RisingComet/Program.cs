using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Delicious_Fruit_Eurobeat_Remix
{
    class Program
    {
        static int T;
        static int curtest = 0;

        static void Main(string[] args)
        {
            StreamReader inputreader;
            StreamWriter outputwriter;
            String[] read;

            int N = 0;
            int min1 = 0;
            int min2 = 0;
            int mindif = 0;
            int[] mus;

            int loop;

            inputreader = new StreamReader("../../input.txt");
            outputwriter = new StreamWriter("../../output.txt");

            read = inputreader.ReadLine().Split(' ');

            T = Convert.ToInt32(read[0]);

            while (curtest < T)
            {
                read = inputreader.ReadLine().Split(' ');

                N = Convert.ToInt32(read[0]);
                mus = new int[N];

                read = inputreader.ReadLine().Split(' ');
                loop = 0;

                while (loop < N) { mus[loop] = Convert.ToInt32(read[loop]); loop += 1; }

                min1 = 0; min2 = 0; mindif = 0;

                loop = 1;
                while (loop < N) { if (mus[loop] < mus[loop - 1]) { min1 += (mus[loop - 1] - mus[loop]); if ((mus[loop-1] - mus[loop]) > mindif) { mindif = (mus[loop-1] - mus[loop]); } } loop += 1; }
                loop = 0;
                while (loop < N - 1) { if (mus[loop] >= mindif) { min2 += mindif; } else { min2 += mus[loop]; } loop += 1; }

                outputwriter.WriteLine(String.Format("Case #{0}: {1} {2}", curtest + 1, min1, min2));

                curtest++;
            }

            inputreader.Close();
            outputwriter.Close();
        }
    }
}
