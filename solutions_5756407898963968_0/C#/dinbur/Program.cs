using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QualificationRound
{


    class Program
    {
        static void Main(string[] args)
        {
            magicTrick mt = new magicTrick();
            mt.solve();
        }
    }




    class magicTrick
    {
        public void solve()
        {
            string result = string.Empty;
            string inputFile = @"C:\Users\dante\Desktop\Google CodeJam 2014\QualificationRound\QualificationRound\input.txt";


            string[] lines = File.ReadAllLines(inputFile);
            int totalRowCounter = 0;

            int testCases = Int32.Parse(lines[totalRowCounter++]);

            for (int i = 0; i < testCases; i++)
            {
                int row1 = Int32.Parse(lines[totalRowCounter]);
                List<string> firstRow = lines[totalRowCounter + row1].Split(' ').ToList();

                int row2 = Int32.Parse(lines[totalRowCounter + 5]);
                List<string> secondRow = lines[totalRowCounter + 5 + row2].Split(' ').ToList();

                string msg = getMessage(firstRow, secondRow);

                result += String.Format("Case #{0}: {1}\n", i + 1, msg);

                totalRowCounter += 10;
            }


            string outputFile = @"C:\Users\dante\Desktop\Google CodeJam 2014\QualificationRound\QualificationRound\output.txt";
            File.WriteAllText(outputFile, result);

            Console.WriteLine("Success!");
            Console.Read();
        }

        public static string getMessage(List<string> row1, List<string> row2)
        {
            int occurances = 0;
            string magicNumber = "";
            foreach (string s in row1)
            {
                if (row2.Contains(s))
                {
                    magicNumber= s;
                    occurances++;
                }
            }

            if (occurances == 0)
                return "Volunteer cheated!";
            else if (occurances == 1)
                return magicNumber;
            else
                return "Bad magician!";
        }
    }
}
