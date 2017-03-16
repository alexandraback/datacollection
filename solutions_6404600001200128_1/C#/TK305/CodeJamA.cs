using System;
using System.IO;

namespace CodeJamA
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(new FileStream("A-large.in", FileMode.Open));
            StreamWriter sw = new StreamWriter(new FileStream("A_large.out", FileMode.Create));
            string temp = sr.ReadLine();

            int test_num = int.Parse(temp);

            for (int i = 1; i < test_num + 1; i++)
            {
                temp = sr.ReadLine();
                int obs_num = int.Parse(temp);

                temp = sr.ReadLine();
                string[] obs_temp = temp.Split(' ');
                int[] obs = new int[obs_num];
                int max_diff = 0;
                int diff;
                int count1 = 0;
                int count2 = 0;
                obs[0] = int.Parse(obs_temp[0]);
                
                for (int j = 1; j < obs_num; j++)
                {
                    obs[j] = int.Parse(obs_temp[j]);
                    diff = obs[j-1] - obs[j];
                    if (diff > 0)
                    {
                        count1 += diff;
                        if (diff > max_diff)
                            max_diff = diff;
                    }
                }

                for (int j = 0; j < obs_num - 1; j++)
                {
                    if (obs[j] < max_diff)
                        count2 += obs[j];
                    else
                        count2 += max_diff;
                }

                sw.WriteLine("Case #{0}: {1} {2}", i, count1, count2);
            }
            sw.Close();
            sr.Close();
        }
    }
}
