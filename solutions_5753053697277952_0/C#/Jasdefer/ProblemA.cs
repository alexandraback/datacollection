using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam2016.Round1C
{
    public class ProblemA
    {
        private static readonly string PATH = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Desktop), "GoogleCodeJam2016", "Round1C", "ProblemA");
        private const string INPUT_FILE = "input-small.in";
        private const string OUTPUT_FILE = "output-small.out";
        private byte T;
        private StringBuilder SB;

        public void Solve()
        {
            string[] lines = File.ReadAllLines(Path.Combine(PATH, INPUT_FILE));
            T = Convert.ToByte(lines[0]);
            SB = new StringBuilder();
            for (byte i = 1; i <= T; i++)
            {
                byte n = Convert.ToByte(lines[(i * 2 - 1)]);
                int[] p = new int[n];
                for (byte j = 0; j < n; j++)
                    p[j] = Convert.ToByte(lines[i * 2].Split(' ')[j]);

                string result = Solve(n,p);
                SB.AppendLine($"Case #{i}: {result}");
            }

            File.WriteAllText(Path.Combine(PATH, OUTPUT_FILE), SB.ToString());
        }

        private string Solve(byte n, int[] p)
        {
            string result = string.Empty;
            while (GetSum(p) > 0)
            {
                int sum = GetSum(p);
                byte max = GetMaxIndex(p);
                result += Convert.ToChar(max + 65);
                p[max] -= 1;

                if (sum > 1)
                {
                    byte maxSecond = GetMaxIndex(p);
                    p[maxSecond] -= 1;
                    if (p.Max() / (double)(sum - 2)<= 0.5)
                        result += Convert.ToChar(maxSecond + 65);
                    else
                        p[maxSecond]++;
                    
                }

                if (sum > 2)
                    result += " ";

            };

            return result;
        }

        private byte GetMaxIndex(int[] p)
        {
            int max = 0;
            byte maxIndex = Convert.ToByte(p.Length);
            for (byte i = 0; i < p.Length; i++)
            {
                if (p[i] > max)
                {
                    max = p[i];
                    maxIndex = i;
                }
            }

            return maxIndex;
        }

        private int GetSum(int[] p)
        {
            int sum = 0;
            foreach (int item in p)
                sum += item;
            return sum;
        }

    }
}
