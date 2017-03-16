using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2008_1a
{
    class MagicTrick
    {
        static void Main(string[] args)
        {
            var me = new Numbers();
            using (var helper = new CodeJamHelper('A', ProblemType.Small, 0))
            {
                var numTestCases = helper.ReadLineInt32();
                foreach (var caseNum in Enumerable.Range(1, numTestCases))
                {
                    var answer1 = helper.ReadLineInt32();
                    var rows1 = new List<int[]>();
                    rows1.Add(helper.ReadInt32Array());
                    rows1.Add(helper.ReadInt32Array());
                    rows1.Add(helper.ReadInt32Array());
                    rows1.Add(helper.ReadInt32Array());

                    var answer2 = helper.ReadLineInt32();
                    var rows2 = new List<int[]>();
                    rows2.Add(helper.ReadInt32Array());
                    rows2.Add(helper.ReadInt32Array());
                    rows2.Add(helper.ReadInt32Array());
                    rows2.Add(helper.ReadInt32Array());

                    var possibilities = rows1[answer1 - 1].Intersect(rows2[answer2 - 1]).ToList();
                    if (possibilities.Count == 1)
                        helper.OutputCase(possibilities[0]);
                    else if (possibilities.Count == 0)
                        helper.OutputCase("Volunteer cheated!");
                    else
                        helper.OutputCase("Bad magician!");
                }
            }
        }

    }
}
