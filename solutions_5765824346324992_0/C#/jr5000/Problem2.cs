using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam1a
{
    class Problem2
    {
        public static void Main()
        {
            new Problem2().Start();
        }

        void Start()
        {
            var fileName = "B-small-attempt1";
            using (var input = new System.IO.StreamReader("../../IO/" + fileName + ".in"))
            using (var output = new System.IO.StreamWriter("../../IO/" + fileName + ".out"))
            {
                var TC = int.Parse(input.ReadLine());
                for (var testCase = 1; testCase <= TC; testCase++)
                {
                    Console.WriteLine("Case #" + testCase);

                    var l = input.ReadLine().Split(' ').Select(int.Parse).ToArray();
                    var B = l[0];
                    var N = l[1];
                    var M = input.ReadLine().Split(' ').Select(int.Parse).ToArray();

                    var cycleTime = 0;
                    var barbs = new int[B];
                    for (int i = 1; i <= N; i++)
                    {
                        var min = int.MaxValue;
                        var minind = -1;
                        for (int j = 0; j < B; j++)
                        {
                            if (barbs[j] < min)
                            {
                                min = barbs[j];
                                minind = j;
                            }
                        }
                        if(i == N)
                        {
                            output.WriteLine("Case #" + testCase + ": " + (minind + 1));
                            break;
                        }
                        var allMatch = true;
                        for (int j = 0; j < B; j++)
                        {
                            barbs[j] -= min;
                            if (barbs[j] != M[j] && j != minind)
                                allMatch = false;
                        }
                        if (allMatch)
                        {
                            i = (N / i) * i - 1;
                        }
                        barbs[minind] = M[minind];
                    }
                }
            }
        }
    }
}
