namespace ZTGCJ2014.Round_1B
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using ZTCommon;
    using ZTCommon.ContestCommon;

    internal class TheRepeater : SolverBase
    {
        public TheRepeater()
            : base(@"Round 1B\A-large")
            //: base(@"Round 1B\A-small-attempt1")
            //: base(@"Round 1B\sample")
        {
        }

        public override void Solve(InputHelper input)
        {
            int N = input.ReadInt();

            var lst = Parse(input.ReadString()).Select(pr => Tuple.Create(pr.Item1, new List<int>(new int[] { pr.Item2 }))).ToArray();

            bool fail = false;

            for (int i = 1; i < N; ++i)
            {
                var index = 0;
                Parse(input.ReadString()).All(pr =>
                    {
                        if (index >= lst.Length || pr.Item1 != lst[index].Item1)
                        {
                            fail = true;
                            return false;
                        }
                        else
                        {
                            lst[index++].Item2.Add(pr.Item2);
                            return true;
                        }
                    });
                if (index < lst.Length)
                {
                    fail = true;
                }
            }

            if (fail)
            {
                this.SetResult("Fegla Won");
            }
            else
            {
                this.SetResult(lst.Sum(pr =>
                    {
                        var items = pr.Item2;
                        items.Sort();
                        return items.Sum(x => Math.Abs(x - items[N / 2]));
                    }));
            }
        }

        private static IEnumerable<Tuple<char, int>> Parse(string s)
        {
            char cur = '\0';
            int cnt = -1;
            foreach (var c in s)
            {
                if (c == cur)
                {
                    ++cnt;
                }
                else
                {
                    if (cnt > 0)
                    {
                        yield return Tuple.Create(cur, cnt);
                    }

                    cur = c;
                    cnt = 1;
                }
            }

            if (cnt > 0)
            {
                yield return Tuple.Create(cur, cnt);
            }
        }
    }
}
