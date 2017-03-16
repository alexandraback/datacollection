using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2014_Qualification_A
{
    class Program
    {
        static void Main(string[] args)
        {
//            string fileName = "input";
            string fileName = "A-small-attempt2";

            int counter = 0;
            string line;

            // Read the file and display it line by line.
            System.IO.StreamReader file =
               new System.IO.StreamReader(fileName + ".in");

            System.IO.StreamWriter file2 = new System.IO.StreamWriter(fileName + ".out");
                        

            line = file.ReadLine();
            
            int testcases; 
            bool success = int.TryParse(line, out testcases);

            for (int i = 0; i < testcases; i++)
            {
                solveSingleTestcase(file, file2, i + 1);
            }

            file.Close();
            file2.Close();

            // Suspend the screen.
            Console.ReadLine();
        }

        private static void solveSingleTestcase(System.IO.StreamReader file, System.IO.StreamWriter file2, int testcaseNumber)
        {
            // answer 1
            string line = file.ReadLine();
            int answer1;
            int.TryParse(line, out answer1);

            // ignore other lines
            for (int i = 0; i < answer1 - 1; i++)
            {
                file.ReadLine();
            }

            // read answered line
            line = file.ReadLine();
            string[] possibleAnswersString1 = line.Split(' ');
            int[] possibleAnswers1 = new int[4];
            for (int i = 0; i < 4; i++)
            {
                int.TryParse(possibleAnswersString1[i], out possibleAnswers1[i]);
            }

            // ignore remaining lines
            for (int i = answer1; i < 4; i++)
            {
                file.ReadLine();
            }

            // answer 2
            line = file.ReadLine();
            int answer2;
            int.TryParse(line, out answer2);

            // ignore other lines
            for (int i = 0; i < answer2 - 1; i++)
            {
                file.ReadLine();
            }

            // read answered line
            line = file.ReadLine();
            string[] possibleAnswersString2 = line.Split(' ');
            int[] possibleAnswers2 = new int[4];
            for (int i = 0; i < 4; i++)
            {
                int.TryParse(possibleAnswersString2[i], out possibleAnswers2[i]);
            }

            // ignore remaining lines
            for (int i = answer2; i < 4; i++)
            {
                file.ReadLine();
            }

            HashSet<int> answers1 = new HashSet<int>(possibleAnswers1);
            HashSet<int> answers2 = new HashSet<int>(possibleAnswers2);

          //  Console.WriteLine(possibleAnswers1[0] + " " + possibleAnswers1[1] + " " + possibleAnswers1[2] + " " + possibleAnswers1[3]);
          //  Console.WriteLine(possibleAnswers2[0] + " " + possibleAnswers2[1] + " " + possibleAnswers2[2] + " " + possibleAnswers2[3]);

            HashSet<int> answers = new HashSet<int>(answers1.Intersect(answers2));

            Console.Write("Case #" + testcaseNumber + ": ");
            file2.Write("Case #" + testcaseNumber + ": ");
            switch (answers.Count)
            {
                case 0: 
                    Console.WriteLine("Volunteer cheated!");
                    file2.WriteLine("Volunteer cheated!");
                    break;
                case 1:
                    Console.WriteLine(answers.ToArray()[0]);
                    file2.WriteLine(answers.ToArray()[0]);
                    break;
                default:
                    Console.WriteLine("Bad magician!");
                    file2.WriteLine("Bad magician!");
                    break;
            }
        }
    }
}
