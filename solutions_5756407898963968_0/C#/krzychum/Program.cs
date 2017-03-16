using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MagicTrick
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] data = File.ReadAllLines("data_in.txt");
            List<string> result = new List<string>();
            int nCases = int.Parse(data[0]);
            int cLine = 1;
            for (int cCase = 0; cCase < nCases;++cCase)
            {
                int answer1 = int.Parse(data[cLine])-1;
                ++cLine;
                int[] arrangement1 = ReadArrangement(data, cLine);
                cLine += 4;
                int answer2 = int.Parse(data[cLine])-1;
                ++cLine;
                int[] arrangement2 = ReadArrangement(data, cLine);
                cLine += 4;
                string res = Solve(answer1, arrangement1, answer2, arrangement2);
                result.Add("Case #" + (cCase + 1) + ": " + res);
            }
            File.WriteAllLines("data_out.txt", result);
        }

        private static string Solve(int answer1, int[] arrangement1, int answer2, int[] arrangement2)
        {
            var answer1Numbers = arrangement1.Skip(answer1 * 4).Take(4);
            var answer2Numbers = arrangement2.Skip(answer2 * 4).Take(4);
            var anAnswer = answer1Numbers.Intersect(answer2Numbers);
            if (anAnswer.Count() == 1)
                return anAnswer.First().ToString();
            if (anAnswer.Count() == 0)
                return "Volunteer cheated!";
            return "Bad magician!";
        }

        private static int[] ReadArrangement(string[] data, int cLine)
        {
            int[] res = new int[16];
            for (int c = 0; c < 4;++c)
            {
                var ints = data[cLine + c].Split(' ').Select(i => int.Parse(i)).ToList();
                for (int i = 0; i < 4; ++i)
                    res[c * 4 + i] = ints[i];
            }
            return res;
        }
    }
}
