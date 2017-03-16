using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016
{
    class Prob1C1
    {
        internal void Run()
        {
            var lines = File.ReadAllLines("A-large.in");

            var t = int.Parse(lines[0]);

            int i = 1;
            using (var sw = File.CreateText("CA1.out"))
                while (i < lines.Length)
                {
                    var n = int.Parse(lines[i++]);
                    var ps = lines[i++].Split(' ').Select(p => int.Parse(p)).ToList();

                    var sol = new StringBuilder();
                    if (n == 2)
                    {
                        if (ps[0] != ps[1]) throw new Exception();
                        for (int j = 0; j < ps[0]; j++)
                            sol.Append("AB ");
                    }
                    else
                        while (true)
                        {
                            int min = int.MaxValue, minIndex = -1;
                            int max = 0, maxIndex = -1;
                            double total = ps.Sum();

                            if (total == 2)
                            {
                                for (int k = 0; k < n; k++)
                                    if (ps[k] == 1)
                                        sol.Append((char)('A' + k));
                                break;
                            }
                            else
                            {
                                for (int p = 0; p < ps.Count; p++)
                                {
                                    if (min > ps[p])
                                    {
                                        min = ps[p];
                                        minIndex = p;
                                    }

                                    if (max < ps[p])
                                    {
                                        max = ps[p];
                                        maxIndex = p;
                                    }

                                    if (ps[p] / total > 0.5) throw new Exception();
                                }

                                if (min == 0 && max == 0) break;

                                sol.Append((char)('A' + maxIndex) + " ");
                                ps[maxIndex]--;
                            }
                        }

                    sw.WriteLine("Case #{0}: {1}", i /2, sol.ToString().Trim());
                }
        }
    }
}
