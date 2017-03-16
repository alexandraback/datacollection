using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Template
{
    class Program
    {
        static String runCase(StreamReader inputReader)
        {
            int firstSelectedRowNumber = Int32.Parse(inputReader.ReadLine());
            int[] firstSelectedRow = new int[4];

            for (int i = 0; i < 4; i++)
            {
                int[] numbers = inputReader.ReadLine().Split(' ').Select(n => Convert.ToInt32(n)).ToArray();
                if (i == firstSelectedRowNumber - 1)
                {
                    firstSelectedRow = numbers;
                }
            }

            int secondSelectedRowNumber = Int32.Parse(inputReader.ReadLine());
            List<int> matches = new List<int>();

            for (int i = 0; i < 4; i++)
            {
                int[] numbers = inputReader.ReadLine().Split(' ').Select(n => Convert.ToInt32(n)).ToArray();
                if (i == secondSelectedRowNumber - 1)
                {
                    foreach (int number in numbers)
                    {
                        if (firstSelectedRow.Contains(number))
                        {
                            matches.Add(number);
                        }
                    }
                }
            }
            
            if (matches.Count == 0)
            {
                return "Volunteer cheated!";
            }
            else if (matches.Count == 1)
            {
                return "" + matches[0];
            }
            else
            {
                return "Bad magician!";
            }
        }

        static String fileName = "A-small-attempt0";
        static String folderName = "2014QA";

        static String pathToFiles = "../../../../io/";
        static String inputFileName = pathToFiles + "\\" + folderName + "\\" + fileName + ".in";
        static String outputFileName = pathToFiles + "\\" + folderName + "\\" + fileName + ".out";

        static void Main(string[] args)
        {
            File.WriteAllText(outputFileName, string.Empty);
            using (StreamWriter outputFile = new StreamWriter(outputFileName))
            {
                using (StreamReader inputReader = new StreamReader(inputFileName))
                {
                    int testCaseCount = Int32.Parse(inputReader.ReadLine());
                    for (int caseIterator = 0; caseIterator < testCaseCount; caseIterator++)
                    {
                        String caseResult = runCase(inputReader);
                        String caseOutput = "Case #" + (caseIterator + 1) + ": " + caseResult;
                        outputFile.WriteLine(caseOutput);
                        Console.Out.WriteLine(caseOutput);
                    }
                }
            }

            Console.Read();
        }
    }
}
