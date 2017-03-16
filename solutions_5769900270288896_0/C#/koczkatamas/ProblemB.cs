using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace ProblemB
{
    class ProblemB
    {
        static void Main(string[] args)
        {
            var outputLines = new List<string>();
            var inputLines = File.ReadAllLines("input.txt");
            var testCases = inputLines.Skip(1).Select(i => i.Split(' ').Select(int.Parse).ToArray()).ToArray();

            var testCaseId = 1;
            foreach (var testCase in testCases)
            {
                var R = testCase[0];
                var C = testCase[1];
                var N = testCase[2];

                var max = (int)Math.Pow(2, R * C);
                var bestHappiness = int.MaxValue;
                for (int i = 0; i < max; i++)
                {
                    var bitRep = Convert.ToString(i, 2).PadLeft(R * C, '0').Select(x => x == '1').ToArray();
                    if(bitRep.Count(y => y) != N)
                        continue;

                    Func<int, int, bool> getCell = (y, x) => bitRep[y * C + x];

                    var unhap = 0;
                    for(var y = 0; y < R; y++)
                        for(var x = 0; x < C - 1; x++)
                            if (getCell(y, x) && getCell(y, x + 1))
                                unhap++;

                    for (var y = 0; y < R-1; y++)
                        for (var x = 0; x < C; x++)
                            if (getCell(y, x) && getCell(y + 1, x))
                                unhap++;

                    if (unhap < bestHappiness)
                        bestHappiness = unhap;
                }

                outputLines.Add(String.Format("Case #{0}: {1}", testCaseId, bestHappiness));
                testCaseId++;
            }

            File.WriteAllLines("output.txt", outputLines);
        }
    }
}
