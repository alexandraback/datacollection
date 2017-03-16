using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round_Q_Task_1
{
    class Program
    {
        const string ResultBadMagician = "Bad magician!";
        const string ResultVolunteerCheated = "Volunteer cheated!";

        static void Main(string[] args)
        {
            int numberOfCases = int.Parse(Console.ReadLine());

            for (int i = 1; i <= numberOfCases; ++i)
            {
                // prepare input for the case
                int answer1 = int.Parse(Console.ReadLine());
                int[] chosenRow1 = ReadCardsArrangementFromInput(answer1 - 1);

                int answer2 = int.Parse(Console.ReadLine());
                int[] chosenRow2 = ReadCardsArrangementFromInput(answer2 - 1);

                // solve the case
                string caseOutput = string.Format("Case #{0}: {1}", i, SolveTaskCase(answer1, answer2, chosenRow1, chosenRow2));

                // print output
                Console.WriteLine(caseOutput);
            }
        }

        private static int[] ReadCardsArrangementFromInput(int chosenRowIndex)
        {
            int[] chosenRow = new int[4];
            for (int r = 0; r < 4; ++r)
            {
                string row = Console.ReadLine();

                if (r == chosenRowIndex)
                {
                    string[] rowSplit = row.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                    if (rowSplit.Length != 4)
                    {
                        throw new FormatException("Invalid input format");
                    }

                    for (int c = 0; c < 4; ++c)
                    {
                        chosenRow[c] = int.Parse(rowSplit[c]);
                    }
                }
            }

            return chosenRow;
        }

        private static string SolveTaskCase(int answer1, int answer2, int[] chosenRow1, int[] chosenRow2)
        {
            int numberFound = -1;

            // each number from the chosen row should be in a different row in the second arrangement
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    if (chosenRow1[i] == chosenRow2[j])
                    {
                        if (numberFound == -1)
                        {
                            numberFound = chosenRow1[i];
                            break;
                        }
                        else
                        {
                            return ResultBadMagician;
                        }
                    }
                }
            }

            if (numberFound == -1)
            {
                return ResultVolunteerCheated;
            }

            return numberFound.ToString();
        }
    }
}
