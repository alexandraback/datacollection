using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace codejam
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = Convert.ToInt32(Console.In.ReadLine());
            int[] raw1 = new int[4], raw2 = new int[4];
            string[] rawtemp = new string[4];

            for (int t = 1; t <= T; t++)
            {
                int temp = Convert.ToInt32(Console.In.ReadLine());
                for (int i = 1; i <= 4; i++)
                {
                    if (i == temp) rawtemp = Console.In.ReadLine().Split(' ');
                    else Console.In.ReadLine();
                }
                for (int i = 0; i < 4; i++)
                {
                    raw1[i] = Convert.ToInt32(rawtemp[i]);
                }

                temp = Convert.ToInt32(Console.In.ReadLine());
                for (int i = 1; i <= 4; i++)
                {
                    if (i == temp) rawtemp = Console.In.ReadLine().Split(' ');
                    else Console.In.ReadLine();
                }
                for (int i = 0; i < 4; i++)
                {
                    raw2[i] = Convert.ToInt32(rawtemp[i]);
                }

                Console.Out.WriteLine(Solver.solve(t, raw1, raw2));
            }

        }
    }

    public class Solver
    {
        public static string solve(int number, int[] raw1, int[] raw2)
        {
            bool[] possible =new bool[17];
            int index = 0;
            for (int i = 0; i < 4; i++)
            {
                possible[raw1[i]] = true;
            }
            for (int i = 0; i < 4; i++)
            {
                if (possible[raw2[i]])
                    if(index==0) index = raw2[i];
                    else index=-1;
            }
            string solution = "Case #" + number + ": ";
            if (index == 0) solution += "Volunteer cheated!";
            else if (index == -1) solution+="Bad magician!";
            else solution+=index;
            return solution;
        }
    }
}
