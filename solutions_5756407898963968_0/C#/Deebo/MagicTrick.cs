using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dfs.GoogleCodeJam.CodeJam2014.QualificationRound
{
    [ProblemInfo(ContestNames.CodeJam2014, RoundNames.QualificationRound, ProblemIdentifiers.A)]
    internal class MagicTrick : ProblemBase
    {
        protected override ProblemCaseBase ParseCase(TextReader reader)
        {
            return new MagicTrickCase(reader);
        }

        private class MagicTrickCase : ProblemCaseBase
        {
            public MagicTrickCase(TextReader reader)
            {
                firstChoice = int.Parse(reader.ReadLine());
                firstArrangement = parseArrangement(reader);
                secondChoice = int.Parse(reader.ReadLine());
                secondArrangement = parseArrangement(reader);
            }

            public override string Solve()
            {
                var intersection = firstArrangement[firstChoice - 1].Intersect(secondArrangement[secondChoice - 1]);
                switch (intersection.Count())
                {
                    case 0: return "Volunteer cheated!";
                    case 1: return intersection.Single().ToString();
                    default: return "Bad magician!";
                }
            }

            private int[][] parseArrangement(TextReader reader)
            {
                int[][] result = new int[4][];
                for (int i = 0; i < 4; i++)
                    result[i] = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
                return result;
            }

            private readonly int firstChoice;
            private readonly int[][] firstArrangement;
            private readonly int secondChoice;
            private readonly int[][] secondArrangement;
        }
    }
}
