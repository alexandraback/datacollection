using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj14qr
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines(@"C:\GCJ\A.in");
            int idx = 0;
            int t = int.Parse(lines[idx++]);
            TextWriter tw = new StreamWriter(@"C:\GCJ\A.out");
            for (int a = 0; a < t; a++)
            {
                int row = int.Parse(lines[idx++]);
                string[] line1 = null, line2 = null;
                for (int b = 0; b < 4; b++)
                {
                    if (b + 1 == row)
                    {
                         line1 = lines[idx].Split(' ');
                    }
                    idx++;
                }
                int row2 = int.Parse(lines[idx++]);
                for (int b = 0; b < 4; b++)
                {
                    if (b + 1 == row2)
                    {
                        line2 = lines[idx].Split(' ');
                    }
                    idx++;
                }
                List<string> choices = line1.ToList().Intersect(line2.ToList()).ToList();
                string ans;
                if (choices.Count == 0)
                {
                    ans = "Volunteer cheated!";
                }
                else if (choices.Count == 1)
                {
                    ans = choices[0];
                }
                else
                {
                    ans = "Bad magician!";
                }
                tw.WriteLine("Case #{0}: {1}", a + 1, ans);
            }
            tw.Close();
        }
    }
}
