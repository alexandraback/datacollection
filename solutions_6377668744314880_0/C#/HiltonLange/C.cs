using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class C : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                int N = int.Parse(Console.ReadLine());
                List<Point> Ps = new List<Point>();
                for (int i = 0; i < N; i++)
                {
                    string[] sp = Console.ReadLine().Split();
                    Point p = new Point();
                    p.x = int.Parse(sp[0]);
                    p.y = int.Parse(sp[1]);
                    Ps.Add(p);
                }

                string[] sOut = this.ProcessMulti(Ps);
                Console.WriteLine("Case #{0}:", iCase);
                System.Diagnostics.Debug.WriteLine("Case #{0}:", iCase);
                for (int j = 0; j < sOut.Length; j++) {
                    Console.WriteLine(sOut[j]);
                    System.Diagnostics.Debug.WriteLine(sOut[j]);
                }
            }

            if (bManual) Console.ReadKey();
        }

        private string[] ProcessMulti(List<Point> Ps)
        {
            List<string> ret = new List<string>();
            for (int i = 0; i < Ps.Count; i++)
            {
                int minCut = Ps.Count - 1;
                for (int j = 0; j < Ps.Count; j++)
                {
                    if (j != i)
                    {
                        int online = 0;
                        int negline = 0;
                        int posline = 0;
                        for (int k = 0; k < Ps.Count; k++)
                        {
                            long x1 = Ps[j].x - Ps[i].x;
                            long x2 = Ps[k].x - Ps[i].x;
                            long y1 = Ps[j].y - Ps[i].y;
                            long y2 = Ps[k].y - Ps[i].y;
                            long xp = x1 * y2 - y1 * x2;
                            if (xp > 0) posline++;
                            if (xp < 0) negline++;
                            if (xp == 0) online++;
                        }
                        minCut = Math.Min(minCut, Math.Min(posline, negline));
                    }
                }
                ret.Add(minCut.ToString());
            }
            return ret.ToArray();
        }

        private class Point
        {
            public long x;
            public long y;
        }

    }
}
