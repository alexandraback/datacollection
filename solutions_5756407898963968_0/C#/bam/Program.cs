using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qualif1
{
    class Program
    {
        static void Main(string[] args)
        {
            var file = new StreamReader(@"C:\Users\Administrator\Documents\CodeJam\first2.txt");
            var outFile = new StreamWriter(@"C:\Users\Administrator\Documents\CodeJam\firstOut2.txt");
            var total = long.Parse(file.ReadLine());
            for (long i = 1; i <= total; i++)
            {
                var set1 = ReadChoises(file);
                var set2 = ReadChoises(file);

                var result = set1.Intersect(set2);
                int count = result.Count();
                if (count == 0)
                    outFile.WriteLine(string.Format("Case #{0}: Volunteer cheated!", i));
                if (count > 1)
                    outFile.WriteLine(string.Format("Case #{0}: Bad magician!", i));
                if (count == 1)
                    outFile.WriteLine(string.Format("Case #{0}: {1}", i, result.First()));

            }

            file.Close();
            outFile.Close();
        }

        private static HashSet<byte> ReadChoises(StreamReader file)
        {
            int choise = int.Parse(file.ReadLine());
            var set = new HashSet<byte>();
            for (int j = 1; j <= 4; j++)
            {
                var line = file.ReadLine();
                if (j == choise)
                {
                    Array.ForEach(line.Split(' '), x => set.Add(byte.Parse(x)));
                }
            }
            return set;
        }
    }
}
