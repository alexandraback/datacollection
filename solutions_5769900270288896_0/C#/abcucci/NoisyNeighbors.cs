using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round1B
{
    public class NoisyNeighbors
    {
        public string Run(string input)
        {
            string[] lines = input.Split(new char[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);

            string output = "";

            int T = int.Parse(lines[0]);
            for (int i = 1; i <= T; ++i)
            {
                string[] values = lines[i].Split(' ');
                int R = int.Parse(values[0]);
                int C = int.Parse(values[1]);
                int N = int.Parse(values[2]);

                int answer = this.solve(R, C, N);

                output += string.Format("Case #{0}: {1}", i, answer);
                output += Environment.NewLine;
            }

            return output;
        }

        private int solve(int R, int C, int N)
        {
#if true
            int S = R * C;
            int K = 1 << S;
            int min = int.MaxValue;
            for (int k = 0; k < K; ++k)
            {
                bool[,] tenant = new bool[R, C];
                int count = 0;
                for (int i = 0; i < S; ++ i)
                {
                    int x = (k >> i) & 0x1;
                    if (x == 0) { continue; }
                    //
                    tenant[i / C, i % C] = true;
                    ++count;
                }
                if (count != N) { continue; }

                int unhappiness = 0;
                for (int r = 0; r < R; ++r)
                {
                    for (int c = 0; c < C - 1; ++c)
                    {
                        if (tenant[r, c] && tenant[r, c + 1]) { ++unhappiness; }
                    }
                }
                for (int r = 0; r < R-1; ++r)
                {
                    for (int c = 0; c < C; ++c)
                    {
                        if (tenant[r, c] && tenant[r+1, c]) { ++unhappiness; }
                    }
                }

                min = Math.Min(min, unhappiness);
            }
            return min;

#else
            bool[,] used = new bool[R, C];
            int all = R * C;
            int remove = all - N;

            int unhappines = (R - 1) * C + R * (C - 1);

            for (int k = 0; k < 3; ++k)
            {
                for (int r = 0; r < R; ++r)
                {
                    for (int c = r & 0x1; c < C; c += 2)
                    {
                        if (remove == 0) { break; }

                        if (k == 0)
                        {
                            if (r == 0) { continue; }
                            if (c == 0) { continue; }
                            if (r == (R - 1)) { continue; }
                            if (c == (C - 1)) { continue; }
                        }
                        else if (k == 1)
                        {
                            if ((r == 0) && (c == 0)) { continue; }
                            if ((r == 0) && (c == (C - 1))) { continue; }
                            if ((r == (R - 1)) && (c == 0)) { continue; }
                            if ((r == (R - 1)) && (c == (C - 1))) { continue; }
                        }

                        if (used[r, c]) { continue; }
                        used[r, c] = true;
                        --remove;

                        if (k == 0)
                        {
                            unhappines -= 4;
                        }
                        else if (k == 1)
                        {
                            if ((R == 1) || (C == 1))
                            {
                                unhappines -= 2;
                            }
                            else
                            {
                                unhappines -= 3;
                            }
                        }
                        else if (k == 2)
                        {
                            if ((R == 1) || (C == 1))
                            {
                                unhappines--;
                            }
                            else
                            {
                                unhappines -= 2;
                            }
                        }
                    }
                }
            }
            return unhappines;
#endif
        }
    }
}
