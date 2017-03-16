using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

namespace CodeJam2014
{
    class MagicTrick
    {
        public void solution(string filename)
        {
            StreamWriter sw = new StreamWriter("Magic.txt");

            StreamReader sr = new StreamReader(filename);
            string strSize = sr.ReadLine();
            int iSize = Int32.Parse(strSize);

            for (int caseIndex = 0; caseIndex < iSize; caseIndex++)
            {
                string lineA = "", lineB = "";
                int RowA =Int32.Parse(sr.ReadLine());
                for (int i = 1; i <= 4; i++)
                {
                    if (i == RowA)
                        lineA = sr.ReadLine();
                    else
                        sr.ReadLine();
                }
                int RowB = Int32.Parse(sr.ReadLine());
                for (int i = 1; i <= 4; i++)
                {
                    if (i == RowB)
                        lineB = sr.ReadLine();
                    else
                        sr.ReadLine();
                }
                List<string> intersec = IntersectString(lineA, lineB);
                if (intersec.Count == 1)
                {
                    Console.WriteLine("Case #{0}: {1}", caseIndex + 1, intersec[0]);
                    sw.WriteLine("Case #{0}: {1}", caseIndex + 1, intersec[0]);
                }
                else if (intersec.Count == 0)
                {
                    Console.WriteLine("Case #{0}: {1}", caseIndex + 1, "Volunteer cheated!");
                    sw.WriteLine("Case #{0}: {1}", caseIndex + 1, "Volunteer cheated!");
                }
                else
                {
                    Console.WriteLine("Case #{0}: {1}", caseIndex + 1, "Bad magician!");
                    sw.WriteLine("Case #{0}: {1}", caseIndex + 1, "Bad magician!");
                }

            }
            sw.Close();
 
        }

        private List<string> IntersectString(string lineA, string lineB)
        {
            List<string> res = new List<string>();
            HashSet<string> setA = new HashSet<string>(lineA.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries));
            string[] arrayB = lineB.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            foreach (string sb in arrayB)
            {
                if (setA.Contains(sb))
                    res.Add(sb);

                if (res.Count > 1)
                    return res;
            }
            return res;
        }
        
          
    }
}
