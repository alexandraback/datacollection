namespace GCJ15.R1A
{
    using System;
    using System.Linq;

    public class A
    {
        public string[] Solve(string[] lines)
        {
            int cases = int.Parse(lines[0]);
            string[] res = new string[cases];
            for (int i = 0; i < cases; i++)
            {
                var zline = lines[i*2 + 2].Split(' ').Select(s => int.Parse(s)).ToList();
                int a = 0;
                int b = 0;
                long r1 = 0;
                long r2 = 0;
                for (int q = 0; q < zline.Count-1; q++)
                {
                    a = Math.Max(0, zline[q] - zline[q+1]);
                    r1 += a;
                    b = Math.Max(b, a);
                }
                for (int q = 0; q < zline.Count - 1; q++)
                {
                    r2 += Math.Min(zline[q], b);
                }

                    res[i] = string.Format("Case #{0}: {1} {2}", (i+1), r1, r2);
                

            }
            return res;
        }

    }
}
