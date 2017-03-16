using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj15r1b
{
    class Program
    {
        static void Main(string[] args)
        {
            {
                string root = @"C:\Users\Josiah\Downloads\";
                string problem = "B";
                string ptype = "small-attempt4";
                //string ptype = "Large";

                string[] lines = System.IO.File.ReadAllLines(string.Format("{0}{1}-{2}.in", root, problem, ptype));
                TextWriter tw = new StreamWriter(string.Format("{0}{1}-{2}.out", root, problem, ptype));

                int idx = 0;
                int t = int.Parse(lines[idx++]);
                for (int a = 0; a < t; a++)
                {
                    string[] line = lines[idx++].Split(' ');
                    int R = int.Parse(line[0]);
                    int C = int.Parse(line[1]);
                    int N = int.Parse(line[2]);

                    
                    tw.WriteLine("Case #{0}: {1}", a + 1, Math.Min(way1(R,C,N),way2(R,C,N)));
                }

                tw.Close();
            }
        }

        private static int way2(int R, int C, int N)
        {
            int score = 0;
            int s0 = 0;
            int s1 = 0;
            int s2 = 0;
            int s3 = 0;

            if (R == 1)
            {
                s0 = (C + 1) / 2;
                s1 = (C + 1) % 2;
                s2 = C / 2;
            }
            else if (C == 1)
            {
                s0 = (R + 1) / 2;
                s1 = (R + 1) % 2;
                s2 = R / 2;
            }
            else
            {
                s0 = (R / 2) * ((C + 1) / 2) + ((R + 1) / 2) * (C / 2);
                s2 = (R % 2 == 1 && C % 2 == 1) ? 4 : 2;

                int top = ((R + 1) / 2) - 1 - (R % 2);
                int bot = top;
                if (C % 2 == 1)
                {
                    bot = (R / 2) - ((R + 1) % 2);
                }
                int left = ((C + 1) / 2) - 1 - (C % 2);
                int right = left;
                if (R % 2 == 1)
                {
                    bot = (C / 2) - ((C + 1) % 2);
                }
                s3 = top + bot + right + left;
            }
            N -= s0;
            score += 1 * Math.Max(Math.Min(N, s1), 0);
            N -= s1;
            score += 2 * Math.Max(Math.Min(N, s2), 0);
            N -= s2;
            score += 3 * Math.Max(Math.Min(N, s3), 0);
            N -= s3;
            score += 4 * Math.Max(N, 0);

            return score;
        }

        private static int way1(int R, int C, int N)
        {
            int score = 0;
            int s0 = 0;
            int s1 = 0;
            int s2 = 0;
            int s3 = 0;

            if (R == 1)
            {
                s0 = (C + 1) / 2;
                s1 = (C + 1) % 2;
                s2 = C / 2;
            }
            else if (C == 1)
            {
                s0 = (R + 1) / 2;
                s1 = (R + 1) % 2;
                s2 = R / 2;
            }
            else
            {
                s0 = ((R+1) / 2) * ((C+1) / 2) + ((R) / 2) * ((C) / 2);
                s2 = (R % 2 == 1 && C % 2 == 1) ? 0 : 2;

                int top = ((R) / 2) - ((R+1) % 2);
                int bot = top;
                if (C % 2 == 1)
                {
                    bot = ((R+1) / 2) - 1 - ((R) % 2);
                }
                int left = ((C) / 2) - ((C+1) % 2);
                int right = left;
                if (R % 2 == 1)
                {
                    bot = ((C+1) / 2) - 1 - ((C) % 2);
                }
                s3 = top + bot + right + left;
            }
            N -= s0;
            score += 1 * Math.Max(Math.Min(N, s1), 0);
            N -= s1;
            score += 2 * Math.Max(Math.Min(N, s2), 0);
            N -= s2;
            score += 3 * Math.Max(Math.Min(N, s3), 0);
            N -= s3;
            score += 4 * Math.Max(N, 0);

            return score;
        }


    }
}
