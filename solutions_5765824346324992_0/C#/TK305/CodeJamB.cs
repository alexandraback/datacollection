using System;
using System.IO;
namespace CodeJamB
{
    class Program
    {
        static int GCF(int a, int b)
        {
            while (b != 0)
            {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }

        static int LCM(int a, int b)
        {
            return (a *b) / GCF(a, b);
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(new FileStream("B-small-attempt2.in", FileMode.Open));
            StreamWriter sw = new StreamWriter(new FileStream("B_small.out", FileMode.Create));
            string temp = sr.ReadLine();

            int test_num = int.Parse(temp);

            for (int i = 1; i < test_num + 1; i++)
            {
                
                temp = sr.ReadLine();
                string[] data = temp.Split(' ');

                int B = int.Parse(data[0]);
                int N = int.Parse(data[1]);
                int answer = 0;

                temp = sr.ReadLine();
                string[] M_k = temp.Split(' ');
                
                if (B >= N)
                    answer = N;
                else
                {
                    int[,] sol = new int[2, B + 1];
                    int[] B_time = new int[B + 1];
                    int min = 100000;
                    int lcm = 1;

                    for (int j = 1; j <= B; j++)
                    {
                        sol[0, j] = int.Parse(M_k[j - 1]);
                        B_time[j] = sol[0, j];
                        lcm = LCM(lcm, B_time[j]);
                        sol[1, j] = j;
                        if (min > sol[0, j])
                            min = sol[0, j];
                    }

                    int time = 0;
                    int customer = B + 1;
                    int[] N_B = new int[lcm*customer];
                    int loop_count = 0;

                    while (customer <= N)
                    {
                        loop_count++;
                        int new_min = 100000;
                        time += min;

                        if (time == lcm)
                        {
                            if (loop_count == 1)
                                N_B[customer - 1] = B;
                            break;
                        }

                        for (int j = 1; j <= B; j++)
                        {
                            sol[0, j] -= min;
                            if (sol[0, j] == 0)
                            {
                                sol[1, j] = customer;
                                N_B[customer] = j;
                                customer++;
                                if (customer > N)
                                {
                                    answer = j;
                                    break;
                                }
                                sol[0, j] += B_time[j];
                            }
                            
                            if (new_min > sol[0, j])
                                new_min = sol[0, j];
                        }
                        min = new_min;
                    }
                    if (customer <= N)
                    {
                        int repeat = customer - 1;
                        customer = (N % (repeat));
                        if (customer == 0)
                            answer = N_B[repeat];                        
                        else if (customer <= B)
                            answer = customer;
                        else
                            answer = N_B[customer];
                    }
                }
                sw.WriteLine("Case #{0}: {1}", i, answer);
            }
            sw.Close();
            sr.Close();
        }
    }
}
