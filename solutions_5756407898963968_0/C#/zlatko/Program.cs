using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace GoogleCodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"C:\Users\Zlatko\Desktop\ASmall.in");

            int counter;
            int value;

            int T = int.Parse(lines[0]);
            for (int i = 0; i < T; i++)
            {

                counter = 0;
                value = 0;

                int line1 = int.Parse(lines[10 * i + 1]);
                int line2 = int.Parse(lines[10 * i + 6]);

                string[] snum1 = lines[10 * i + 1 + line1].Split();
                int[] num1 = new int[4];
                for (int j = 0; j < 4; j++)
                    num1[j] = int.Parse(snum1[j]);

                string[] snum2 = lines[10 * i + 6 + line2].Split();
                int[] num2 = new int[4];
                for (int j = 0; j < 4; j++)
                    num2[j] = int.Parse(snum2[j]);

                for (int j = 0; j < 4; j++)
                    for(int k = 0; k < 4; k++)
                        if (num1[j] == num2[k])
                        {
                            counter++;
                            value = num1[j];
                        }

                string message = "";

                if (counter == 0)
                    message = "Volunteer cheated!";

                else if (counter > 1)
                    message = "Bad magician!";

                else
                    message = value.ToString();


    
                using (StreamWriter file = new StreamWriter(@"C:\Users\Zlatko\Desktop\OutputASmall.txt", true))
                {
                    file.WriteLine("Case #" + (i + 1) + ": " + message);
                }
            
            
            }
        }
    }
}
