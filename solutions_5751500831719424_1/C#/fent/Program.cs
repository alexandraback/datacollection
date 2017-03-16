using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _14_1B
{
    class Program
    {
        static void Main(string[] args)
        {
            int T;

            string str;
            string[] strs;
            str = Console.ReadLine();
            T = int.Parse(str);

            for (int caseNumber = 1; caseNumber <= T; caseNumber++)
            {
                int N;
                string[] problem;
                str = Console.ReadLine();
                N = int.Parse(str);
                problem = new string[N];

                for (int i = 0; i < N; i++)
                {
                    problem[i] = Console.ReadLine();
                }

                List<char> ch = new List<char>();
                ch.Add(problem[0][0]);
                for (int i = 1; i < problem[0].Length; i++)
                {
                    if (problem[0][i] != problem[0][i - 1])
                    {
                        ch.Add(problem[0][i]);
                    }
                }

                int[][] data = new int[N][];
                for (int i = 0; i < N; i++)
                {
                    data[i] = new int[ch.Count];

                    int cp = 0;
                    data[i][0]++;
                    if (problem[i][0] != ch[cp])
                    {
                        Console.WriteLine("Case #" + caseNumber + ": Fegla Won");
                        goto next;
                    }

                    for (int j = 1; j < problem[i].Length; j++)
                    {
                        if (problem[i][j] != ch[cp])
                        {
                            cp++;
                            if (cp == ch.Count)
                            {
                                Console.WriteLine("Case #" + caseNumber + ": Fegla Won");
                                goto next;
                            }
                            if (problem[i][j] != ch[cp])
                            {
                                Console.WriteLine("Case #" + caseNumber + ": Fegla Won");
                                goto next;
                            }
                        }
                        data[i][cp]++;
                    }

                    if (cp != ch.Count - 1)
                    {
                        Console.WriteLine("Case #" + caseNumber + ": Fegla Won");
                        goto next;

                    }
                }


                int time = 0;

                for (int i = 0; i < ch.Count; i++)
                {
                    int cmin = int.MaxValue;
                    for (int j = 1; j < 101; j++)
                    {
                        int temp = 0;
                        for (int k = 0; k < N; k++)
                        {
                            temp += Math.Abs(data[k][i] - j);
                        }
                        if (temp < cmin)
                        {
                            cmin = temp;
                        }
                    }
                    time += cmin;
                }


                Console.WriteLine("Case #" + caseNumber + ": " + time);
            next:
                continue;

            }

            Console.Error.WriteLine("fin");

            Console.ReadLine();


        }
    }
}
