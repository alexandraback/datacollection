using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace MagicTrick
{
    class MagicTrick
    {
        static void Main(string[] args)
        {
            using (var rd = File.OpenText(args[0]))
            using (var wr = File.CreateText(args[1]))
            {
                int t = int.Parse(rd.ReadLine()); // test cases

                for (int i = 1; i <= t; i++)
                {
                    Console.WriteLine("Processing case #{0}", i);

                    // First arrangement
                    int a1 = int.Parse(rd.ReadLine());
                    int[] n1 = null;
                    for (int r = 1; r <= 4; r++)
                    {
                        var thisRow = rd.ReadLine().Split(' ').Select(n => Convert.ToInt32(n)).ToArray();
                        if (r == a1) n1 = thisRow;
                    }

                    // Second arrangement
                    int a2 = int.Parse(rd.ReadLine());
                    int[] n2 = null;
                    for (int r = 1; r <= 4; r++)
                    {
                        var thisRow = rd.ReadLine().Split(' ').Select(n => Convert.ToInt32(n)).ToArray();
                        if (r == a2) n2 = thisRow;
                    }

                    // Count number of possible answers
                    int m = 0;
                    int found = -1;
                    foreach (int t1 in n1) 
                        foreach (int t2 in n2) {
                            if (t1 == t2)
                            {
                                found = t1;
                                m++;
                            }
                        }

                    // Determine answer
                    string y;
                    if (m == 1) y = found.ToString();
                    else if (m > 1) y = "Bad magician!";
                    else y = "Volunteer cheated!";
                    wr.WriteLine("Case #{0}: {1}", i, y);
                }
            }
        }
    }
}
