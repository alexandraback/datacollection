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
        string inFilePath, outFilePath;
        
        static void Main(string[] args)
        {
            Program p;
            DateTime begin;

            p = new Program("C:\\gcj\\A-small-attempt0.in", "C:\\gcj\\A-small-attempt0.out");
            begin = DateTime.Now;
            p.Solve();
            Console.WriteLine("Solved sample input in {0:F4} seconds.", (DateTime.Now - begin).TotalSeconds);

            Console.WriteLine("{0}Press any key to exit.", Environment.NewLine);
            Console.ReadLine();
        }

        public Program (string inFilePath, string outFilePath)
        {
            this.inFilePath = inFilePath;
            this.outFilePath = outFilePath;
        }

        public void Solve()
        {
            using (StreamReader inStream = new StreamReader(inFilePath))
            using (StreamWriter outStream = new StreamWriter(outFilePath))
            {
                int numProblems = int.Parse(inStream.ReadLine());

                for (int i = 0; i < numProblems; i++)
                {
                    int answerOne = int.Parse(inStream.ReadLine()) - 1;
                    int[] answerOneArray = parseAnswerRowFromGrid(inStream, answerOne);

                    int answerTwo = int.Parse(inStream.ReadLine()) - 1;
                    int[] answerTwoArray = parseAnswerRowFromGrid(inStream, answerTwo);

                    outStream.WriteLine("Case #{0}: {1}", (i + 1), compareAnswerArrays(answerOneArray, answerTwoArray));
                }
            }
        }

        private string compareAnswerArrays(int[] answerOneArray, int[] answerTwoArray)
        {
            var intersection = answerOneArray.Intersect(answerTwoArray);

            var count = intersection.Count();

            if (count == 0)
                return "Volunteer cheated!";
            if (count == 1)
                return intersection.First().ToString();

            return "Bad magician!";
        }

        private int[] parseAnswerRowFromGrid(StreamReader inStream, int answerRow)
        {
            int[] answerRowArray = new int[4];

            for (int j = 0; j < 4; j++)
            {
                string rowString = inStream.ReadLine();

                if (j == answerRow)
                {
                    string[] rowStringArray = rowString.Split(' ');

                    for (int k = 0; k < rowStringArray.Length; k++)
                    {
                        answerRowArray[k] = int.Parse(rowStringArray[k]);
                    }
                }
            }
            return answerRowArray;
        }
        
    }
}
