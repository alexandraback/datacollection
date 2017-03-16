using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Code_Jam_Round_1a___B
{
    class ProgramB
    {
        static long gcd(long a, long b)
        {
            while (b != 0)
            {
                long temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }

        static long lcm(long a, long b)
        {
            return (a / gcd(a, b)) * b;
        }


        static void Main(string[] args)
        {
            string filename = "b-small-attempt3.in";
            string filenameout = "b-small-attempt3.out";
            string[] lines = System.IO.File.ReadAllLines(@"C:\users\jake.linenthal\documents\code jam\" + filename);
            string res = "";
            long t = Int32.Parse(lines[0]);

            for (int i = 0; i < t; i++)
            {
                String[] arr = lines[2 * i + 1].Split(' ');
                int b = Int32.Parse(arr[0]);
                int n = Int32.Parse(arr[1]);

                int[] btimes = new int[b];
                String [] arr2 = lines[2*i + 2].Split(' ');
                for(int k=0 ; k < arr2.Length; k++) {
                    btimes[k] = Int32.Parse(arr2[k]);
                }
                
                long lcmB = 1;
                if (b == 1) lcmB = btimes[1];
                else
                {
                    for (int k = 1; k < btimes.Length; k++)
                    {
                        if (k == 1) lcmB = lcm(btimes[0], btimes[1]);
                        else lcmB = lcm(lcmB, btimes[k]);
                    }
                }
                

                long peoplePerCycle = 0;
                for (int k = 0; k < btimes.Length; k++)
                {
                    peoplePerCycle += lcmB / btimes[k];
                }
                
                long placeToCalc = (n-1) % peoplePerCycle;

                bool done = false;
                int step = -1;
                int resn = -1;
                if (placeToCalc == 0) { resn = 1; done = true; }

                for (int k = 0; k < btimes.Length; k++)
                {
                    step++;
                    if (step == placeToCalc)
                    {
                        done = true;
                        resn = k + 1;
                    }
                }
                while (!done)
                {
                                    int minTime = 100000000;
                    int minPos = -1;
                    for (int k = 0; k < btimes.Length; k++)
                    {
                        if (btimes[k] < minTime) { minTime = btimes[k]; minPos = k; }
                    }
                    for (int k = 0; k < btimes.Length; k++)
                    {
                        if (btimes[k] - minTime == 0)
                        {
                            step++;
                            if (step == placeToCalc)
                            {
                                done = true;
                                resn = k + 1;
                            }
                            btimes[k] = Int32.Parse(arr2[k]);
                        }
                        else
                        {
                            btimes[k] -= minTime;
                        }
                    }
                    if (done) break;

                }
                res += "Case #" + (i + 1) + ": " + resn + "\n";
                //res += "lcm: " + lcmB + " percycle: " + peoplePerCycle + "\n";
            }
            using (System.IO.StreamWriter file = new System.IO.StreamWriter(@"C:\users\jake.linenthal\documents\code jam\" + filenameout))
            {
                //write solution
                file.Write(res);
            }
        }
    }
}
