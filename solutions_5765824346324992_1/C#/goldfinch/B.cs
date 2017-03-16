namespace GCJ15.R1A
{
    using System;
    using System.Collections.Generic;
    using System.Linq;

    public class B
    {
        public string[] Solve(string[] lines)
        {
            int cases = int.Parse(lines[0]);
            string[] res = new string[cases];
            for (int test = 0, line = 1; test < cases;test++ )
            {
                    var zline = lines[line++].Split(' ').Select(s => long.Parse(s)).ToList();
                    var barbs = lines[line++].Split(' ').Select(s => long.Parse(s)).ToList();
                long n = zline[1];

                int ans = 0;
                if (n <= barbs.Count)
                    ans = (int)n;
                else
                {
                    long left = 0;
                    long right = 100000000000000000;
                    while (left<right)
                    {
                        long mid = (left + right) / 2;
                        long compl = 0;
                        long start = 0;
                        for (int i = 0; i < barbs.Count; i++)
                        {
                            compl += mid / barbs[i];
                            start += (mid) / barbs[i] + 1;
                        }
                        if (start>=n)
                        {
                            right = mid;
                        }
                        else
                        {
                            left = mid+1;
                        }
                    }
                    long v = 0;
                    for (int i = 0; i < barbs.Count; i++)
                    {
                        v += (left-1) / barbs[i] + 1;
                    }

                    for(int i = 0;i<barbs.Count;i++)
                        if (left % barbs[i] == 0)
                        {
                            v++;
                            if (v == n)
                            {
                                ans = i + 1;
                                break;
                            }
                        }
                }
                res[test] = string.Format("Case #{0}: {1}", test + 1, ans);

            }
            return res;
        }

     
    }
}
