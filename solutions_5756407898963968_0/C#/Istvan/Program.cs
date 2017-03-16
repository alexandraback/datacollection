using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Reading input file...");
            StreamReader streamReader = new StreamReader(@"D:\Work\Programming Challange\CodeJam 2014\Qualifying\Problem A\inputSmall.txt");
            StreamWriter streamWriter = new StreamWriter(@"D:\Work\Programming Challange\CodeJam 2014\Qualifying\Problem A\outputSmall.txt", false);
            
            string line = streamReader.ReadLine();
            int nrOfTests = 0;
            if(!int.TryParse(line, out nrOfTests))
            {
                Console.WriteLine("Number of tests is not an int!");
                return;
            }

            int rowSetA = 0, rowSetB = 0;
            List<int> numbersSetA = null, numbersSetB = null;

            Console.WriteLine("Number of tests: "+nrOfTests.ToString());
            for(int i=0; i<nrOfTests;i++)
            {
                rowSetA = 0; rowSetB = 0;
                numbersSetA = null; numbersSetB = null;

                int caseNR = i+1;
                Console.WriteLine("Case #"+caseNR.ToString()+": reading input");
                //reading SetA
                line = streamReader.ReadLine();
                if (!int.TryParse(line, out rowSetA))
                {
                    Console.WriteLine("Case #" + caseNR.ToString() + ": Line for SetA is not an int!");
                    return;
                }
                for(int j=1; j<=4; j++)
                {
                    line = streamReader.ReadLine();
                    if (j != rowSetA)
                    {
                        continue;
                    }
                    numbersSetA = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(t => int.Parse(t)).ToList();
                }
                //reading SetB
                line = streamReader.ReadLine();
                if (!int.TryParse(line, out rowSetB))
                {
                    Console.WriteLine("Case #" + caseNR.ToString() + ": Line for SetB is not an int!");
                    return;
                }
                for (int j = 1; j <= 4; j++)
                {
                    line = streamReader.ReadLine();
                    if (j != rowSetB)
                    {
                        continue;
                    }
                    numbersSetB = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(t => int.Parse(t)).ToList();
                }

                if(numbersSetA == null || numbersSetA.Count == 0)
                {
                    Console.WriteLine("Case #" + caseNR.ToString() + ": numbersSetA is null or empty!");
                    continue;
                }
                if(numbersSetB == null || numbersSetB.Count == 0)
                {
                    Console.WriteLine("Case #"+caseNR.ToString()+": numbersSetB is null or empty!");
                    continue;
                }

                //process it
                Console.WriteLine("Case #" + caseNR.ToString() + ": processing input");

                //try to find an identical number in the rows
                List<int> matches = numbersSetA.Where(t => numbersSetB.Contains(t)).ToList();

                string message = string.Empty;
                //evaluate the answer
                if (matches.Count == 0)
                {
                    message = "Volunteer cheated!";
                }
                if (matches.Count == 1)
                {
                    message = matches[0].ToString();
                }
                if (matches.Count > 1)
                {
                    message = "Bad magician!";
                }

                Console.WriteLine("Case #" + caseNR.ToString() + ": result is " + message);
                Console.WriteLine("Case #" + caseNR.ToString() + ": writing output");
                streamWriter.WriteLine("Case #" + caseNR + ": " + message);
            }
            streamReader.Close();
            streamWriter.Close();
            Console.ReadLine();
        }
    }
}
