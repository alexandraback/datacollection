using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Senate_Evacuation
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var sr = new StreamReader("input.in"))
            using (var sw = new StreamWriter("output.out"))
            {
                string line = sr.ReadLine();
                string[] words = line.Split(' ');
                int t = int.Parse(words[0]);
                int n;
                int[] p;
                List<string> plan;
                int total;
                string res;
                for (int i = 0; i < t; i++)
                {
                    plan = new List<string>();
                    total = 0;

                    line = sr.ReadLine();
                    words = line.Split(' ');
                    n = int.Parse(words[0]);

                    p = new int[n];
                    line = sr.ReadLine();
                    words = line.Split(' ');
                    for (int j = 0; j < n; j++)
                    {
                        p[j] = int.Parse(words[j]);
                        total += p[j];
                    }

                    while(total > 0)
                    {
                        List<int> maxIndexList = new List<int>();
                        maxIndexList.Add(0);
                        for (int j = 1; j < n; j++)
                        {
                            if (p[j] > p[maxIndexList[0]])
                            {
                                maxIndexList.Clear();
                                maxIndexList.Add(j);
                            }
                            else if (p[j] == p[maxIndexList[0]])
                            {
                                maxIndexList.Add(j);
                            }
                        }

                        if(maxIndexList.Count % 2 == 0)
                        {
                            plan.Add(((char)('A' + maxIndexList[0])).ToString() + ((char)('A' + maxIndexList[1])).ToString());
                            p[maxIndexList[0]]--;
                            p[maxIndexList[1]]--;
                            total -= 2;
                        }
                        else
                        {
                            plan.Add(((char)('A' + maxIndexList[0])).ToString());
                            p[maxIndexList[0]]--;
                            total--;
                        }
                    }

                    res = string.Join(" ", plan);

                    sw.WriteLine(string.Format("Case #{0}: {1}", i + 1, res));
                }
            }
        }
    }
}
