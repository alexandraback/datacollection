using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Reflection;

namespace QRProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            String path = Path.GetDirectoryName(Assembly.GetExecutingAssembly().
                GetModules()[0].FullyQualifiedName);

            String inputPath = path + Path.DirectorySeparatorChar + "A-small-attempt0.in";
            String outputPath = path + Path.DirectorySeparatorChar + "A-small-attempt0.in.txt";

            StreamReader reader = new StreamReader(inputPath);
            StreamWriter writer = new StreamWriter(outputPath);

            int caseNumber = 0;
            string line = reader.ReadLine();
            caseNumber = Convert.ToInt32(line);

            for (int i = 0; i < caseNumber; ++i)
            {
                DoOneCase(i + 1, reader, writer);
            }
            reader.Close();
            writer.Close();
        }

        public static void DoOneCase(int caseNumber, StreamReader reader, StreamWriter writer)
        {
            // read row1
            string line = reader.ReadLine();

            int row1 = Convert.ToInt32(line) - 1;

            // read grid1
            int[,] grid1 = new int[4, 4];
            for (int i = 0; i < 4; ++i)
            {
                line = reader.ReadLine();
                string[] word = line.Split(new char[] { ' ' });
                for (int j = 0; j < 4; ++j)
                {
                    grid1[i, j] = Convert.ToInt32(word[j]);
                }
            }
            // read row2
            line = reader.ReadLine();
            int row2 = Convert.ToInt32(line) - 1;

            // read grid2
            int[,] grid2 = new int[4, 4];
            for (int i = 0; i < 4; ++i)
            {
                line = reader.ReadLine();
                string[] word = line.Split(new char[] { ' ' });
                for (int j = 0; j < 4; ++j)
                {
                    grid2[i, j] = Convert.ToInt32(word[j]);
                }
            }

            // judge
            int count = 0;
            int num = -1;
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    if (grid1[row1, i] == grid2[row2, j])
                    {
                        num = grid1[row1, i];
                        count++;
                        break;
                    }
                }
            }
            string result = "";
            if (num == -1)
            {
                result = "Volunteer cheated!";
            }
            else
            {
                if (count > 1)
                {
                    result = "Bad magician!";
                }
                else
                {
                    result = "" + num;
                }
            }

            writer.WriteLine("Case #" + caseNumber + ": " + result);
        }
    }
}
