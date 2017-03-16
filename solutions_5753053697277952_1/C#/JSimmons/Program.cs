using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static string IN = "in.txt";
        static string OUT = "out.txt";

        
        static void Main(string[] args)
        {
            if (File.Exists(OUT)) File.Delete(OUT);
            string[] lines = File.ReadAllText("in.txt").Split('\n');

            string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

            int f = 0;

            foreach (string line in lines)
            {
                if (f++ == 0 || line.Trim() == "" || f % 2 == 0) continue;

                string[] senas = line.Split(' ');
                int[] sens = new int[senas.Length];
                for (int s = 0; s < sens.Length; s++)
                {
                    sens[s] = Convert.ToInt32(senas[s]);
                }

                string output = "";

                while (left(sens) > 0)
                {
                    int next = max(sens);
                    output += alpha[next];
                    sens[next]--;

                    if (left(sens) != 2 && left(sens) > 0)
                    {
                        next = max(sens);
                        output += alpha[max(sens)];
                        sens[next]--;
                    }

                    output += " ";
                }


                write(output.Trim());
            }


            //write(currMax.ToString());


        }

        private static int left(int[] sens)
        {
            int total = 0;
            foreach(int i in sens)
            {
                total += i;
            }

            return total;
        }

        private static int max(int[] sens)
        {
            int max = 0;
            for (int i = 1; i < sens.Length; i ++)
            {
                if (sens[i] > sens[max]) max = i;
            }

            return max;
        }

        static int lineNo = 1;
        private static void write(string line)
        {
            File.AppendAllText(OUT, $"Case #{lineNo++}: {line.Trim()}\r\n");
        }
    }
}
