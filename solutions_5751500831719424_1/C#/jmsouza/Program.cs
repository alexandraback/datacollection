using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Program
    {
        

        static void Main(string[] args)
        {
            string fileName = args.Length == 0 ? "input.txt" : args[0];

            List<string> inputData = new List<string>();

            using (StreamReader sr = new StreamReader(fileName))
            {
                while (sr.Peek() >= 0)
                    inputData.Add(sr.ReadLine());
            }

            int cases = Convert.ToInt32(inputData[0]);
            int caseNumber = 1;

            int startCasePosition = 1;

            using (StreamWriter sw = new StreamWriter("output.txt"))
            {
                while (caseNumber <= cases)
                {
                    int N = Convert.ToInt32(inputData[startCasePosition]);

                    List<string[]> caseList = new List<string[]>();

                    string[] lettersCount;
                    string lettersSequence = GetSequence(inputData[startCasePosition + 1], out lettersCount);
                    caseList.Add(lettersCount);
                    bool FeglaWon = false;

                    for (int i = 2; i <= N; i++)
                    {
                        if (lettersSequence != GetSequence(inputData[startCasePosition + i], out lettersCount))
                        {
                            FeglaWon = true;
                            break;
                        }
                        else
                        {
                            caseList.Add(lettersCount);
                        }
                    }

                    if (FeglaWon)
                    {
                        sw.WriteLine("Case #" + caseNumber.ToString() + ": Fegla Won");
                    }
                    else
                    {

                        int totalCount = 0;

                        int lettersGroupCount = caseList[0].Count();

                        for (int i = 0; i < lettersGroupCount; i++)
                        {
                            List<int> LettersCountOrder = new List<int>();
                            for (int j = 0; j < caseList.Count; j++)
                            {
                                LettersCountOrder.Add(Convert.ToInt32(caseList[j][i]));
                            }
                            LettersCountOrder.Sort();

                            int CenterPosition = LettersCountOrder[LettersCountOrder.Count / 2];

                            for (int x = 0; x < LettersCountOrder.Count; x++)
                            {
                                if (LettersCountOrder[x] != CenterPosition)
                                    totalCount += Math.Abs(CenterPosition - LettersCountOrder[x]);
                            }

                        }

                        sw.WriteLine("Case #" + caseNumber.ToString() + ": " + totalCount.ToString());
                    }

                    startCasePosition += N + 1;
                    caseNumber++;
                }
            }
        }

        private static string GetSequence(string line, out string[] lettersCountResult)
        {
            string lettersSequenceResult = line[0].ToString();
            string lastLetter = line[0].ToString();
            int letterCount = 1;
            string lettersCount = "";

            for (int i = 1; i < line.Length; i++)
            {
                if (lastLetter == line[i].ToString())
                {
                    letterCount++;
                }
                else
                {
                    lettersSequenceResult += line[i].ToString();
                    lastLetter= line[i].ToString();
                    lettersCount += letterCount.ToString() + ",";
                    letterCount = 1;
                }
            }

            lettersCount += letterCount.ToString();
            lettersCountResult = lettersCount.Split(',');

            return lettersSequenceResult;
        }

      

    }
}
