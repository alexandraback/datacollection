using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Google_Jam_Q1
{
    class Program
    {
        static void Main(string[] args)
        {
            Stream s = new FileStream("input", FileMode.Open);
            StreamReader sr = new StreamReader(s);
            
            int numberOfTests = 0;
            numberOfTests = int.Parse(sr.ReadLine());
            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < numberOfTests; i++)
            {
                int firstAnswer = int.Parse(sr.ReadLine());
                int[] firstRow={0};
                for (int j = 0; j < 4; j++)
                {
                    if (j == firstAnswer - 1)
                        firstRow = ParseRow(sr.ReadLine());
                    else
                        sr.ReadLine();
                }
                int secondAnswer = int.Parse(sr.ReadLine());
                int[] secondRow = {0};
                for (int j = 0; j < 4; j++)
                {
                    if (j == secondAnswer - 1)
                        secondRow = ParseRow(sr.ReadLine());
                    else
                        sr.ReadLine();
                }

                int result = FindTheNumber(firstRow, secondRow);
                if (result == 0)
                    sb.AppendLine(string.Format("Case #{0}: Volunteer cheated!", i+1));
                else if (result == -1)
                    sb.AppendLine(string.Format("Case #{0}: Bad magician!", i+1));
                else if (result > 0)
                    sb.AppendLine(string.Format("Case #{0}: {1}", i+1, result));
            }

            sr.Dispose();
            StreamWriter sw = new StreamWriter(new FileStream("output.txt", FileMode.CreateNew));
            sw.Write(sb.ToString());
            sw.Dispose();
        }

        static int[] ParseRow(string row)
        {
            string[] splitR = row.Split(' ');
            int[] result = new int[splitR.Length];
            for (int i = 0; i < splitR.Length; i++)
            {
                result[i] = int.Parse(splitR[i]);
            }

            return result;
        }

        static int FindTheNumber(int[] first, int[] second)
        {
            int number = 0;
            bool multipleAnswers= false;
            foreach(int elem in first)
                foreach (int elem2 in second)
                {
                    if (elem == elem2 && number == 0)
                        number = elem;
                    else if (elem == elem2 && number != 0)
                        multipleAnswers = true;
                }
            if (multipleAnswers) return -1;
            else return number;
        }
    }
}
