using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Jam4
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var file = File.CreateText("output.txt"))
            {
                var cases = int.Parse(Console.ReadLine());

                for (int i = 0; i < cases; i++)
                {
                    DoACase(file, i);
                }
            }
        }

        private static void DoACase(StreamWriter file, int i)
        {
            file.Write("Case #" + (i + 1) + ": ");

            var numStrings = int.Parse(Console.ReadLine());
            string charSeq = "";
            List<int[]> allLengths = new List<int[]>();
            bool fegla = false;

            for (int j = 0; j < numStrings; j++)
            {
                var str = Console.ReadLine();
                if (!fegla)
                {
                    if (j == 0)
                    {
                        charSeq = GetStr(str);
                    }

                    List<int> curLengths = new List<int>();

                    char lastChar = str[0];
                    int count = 0;
                    int seqNum = 0;

                    foreach (char c in str)
                    {
                        if (c == lastChar)
                            count++;
                        else
                        {
                            curLengths.Add(count);
                            seqNum++;
                            count = 1;
                            lastChar = c;
                        }

                        if (seqNum > charSeq.Length || (seqNum != charSeq.Length && charSeq[seqNum] != c))
                        {
                            file.WriteLine("Fegla Won");
                            fegla = true;
                            break;
                        }
                    }

                    if (count > 0)
                        curLengths.Add(count);

                    if (fegla) continue;
                    if (seqNum != charSeq.Length-1)
                    {
                        file.WriteLine("Fegla Won");
                        fegla = true;
                    }
                    if (fegla) continue;

                    allLengths.Add(curLengths.ToArray());
                }
            }

            if (!fegla)
            {
                int score = 0;

                for (int letter = 0; letter < allLengths[0].Length; letter++)
                {
                    int best = Int32.MaxValue;

                    var vals = allLengths.Select(a => a[letter]);
                    int max = vals.Max();
                    for (int test = 1; test <= max; test++)
                    {
                        int curScore = 0;
                        foreach (int otherVal in vals)
                            curScore += Math.Abs(otherVal - test);
                        if (curScore < best)
                        {
                            best = curScore;
                        }
                    }

                    score += best;
                }

                file.WriteLine(score);
            }
        }

        private static string GetStr(string str)
        {
            string myString = "" + str[0];
            foreach (char c in str)
            {
                if (c != myString.Last())
                    myString += c;
            }
            return myString;
        }
    }
}
