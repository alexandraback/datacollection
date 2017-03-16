using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ14
{
    using System.Globalization;

    public class A_MagicTrick
    {
        public string[] Solve(string[] lines)
        {
            int cases = int.Parse(lines[0]);
            string[] res = new string[cases];
            for (int i = 0; i < cases; i++)
            {
                int firstAnswer = int.Parse(lines[1 + i * 10]);
                var firstLine = lines[1 + i * 10 + firstAnswer].Split(' ').Select(s => int.Parse(s));
                int secondAnswer = int.Parse(lines[1 + i * 10+5]);
                var secondLine = lines[1 + i * 10 + 5 + secondAnswer].Split(' ').Select(s => int.Parse(s));
                var common = firstLine.Intersect(secondLine).ToList();
                if (common.Count == 0)
                {
                    res[i] = string.Format("Case #{0}: Volunteer cheated!", (i+1).ToString(CultureInfo.InvariantCulture));
                }
                else if (common.Count == 1)
                {
                    res[i] = string.Format("Case #{0}: {1}", (i+1).ToString(CultureInfo.InvariantCulture), common[0].ToString(CultureInfo.InvariantCulture));                    
                }
                else
                {
                    res[i] = string.Format("Case #{0}: Bad magician!", (i+1).ToString(CultureInfo.InvariantCulture));                                        
                }
            }
            return res;
        }
    }
}
