namespace ZTGCJ2014.Qualification_Round
{
    using System.Collections.Generic;
    using System.Linq;
    using ZTCommon;
    using ZTCommon.ContestCommon;

    internal class MagicTrick : SolverBase
    {
        public MagicTrick()
            : base(@"Qualification Round\A-small-attempt0")
        {
        }

        public override void Solve(InputHelper input)
        {
            var res = ReadMatrix(input, input.ReadInt()).ToArray().
                Intersect(ReadMatrix(input, input.ReadInt())).ToArray();

            this.SetResult(res.Count() == 1 ? res[0].ToString() : res.Count() == 0 ? "Volunteer cheated!" : "Bad magician!");
        }

        private static IEnumerable<int> ReadMatrix(InputHelper input, int row)
        {
            for (int i = 1; i <= 4; ++i)
            {
                for (int j = 1; j <= 4; ++j)
                {
                    int x = input.ReadInt();

                    if (row == i)
                    {
                        yield return x;
                    }
                }
            }
        }
    }
}
