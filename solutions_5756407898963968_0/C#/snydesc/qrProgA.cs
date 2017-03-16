using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace qr2014ProgA
{
    class qrProgA
    {
        public const string cInputFile = "C:\\Dev\\2014\\qrA\\A-small-attempt0.in";
        public const string cOutputFile         = "C:\\Dev\\2014\\qrA\\out.txt";
        public const string cExampleAnswerFile  = "C:\\Dev\\2014\\qrA\\ea.txt";

        static void Main(string[] args)
        {
            try
            {
                using (StreamWriter writer = new StreamWriter(cOutputFile))
                {
                    using (StreamReader reader = new StreamReader(cInputFile))
                    {
                        int numberOfTestCases = int.Parse(reader.ReadLine());

                        for (int testCaseNum = 0; testCaseNum < numberOfTestCases; testCaseNum++)
                        {

                            int firstRowSelected = int.Parse(reader.ReadLine());
                            List<string[]> hand1 = new List<string[]>();
                            hand1.Add( reader.ReadLine().Split(' ') );
                            hand1.Add( reader.ReadLine().Split(' ') );
                            hand1.Add( reader.ReadLine().Split(' ') );
                            hand1.Add( reader.ReadLine().Split(' ') );

                            int secondRowSelected = int.Parse(reader.ReadLine());
                            List<string[]> hand2 = new List<string[]>();
                            hand2.Add( reader.ReadLine().Split(' ') );
                            hand2.Add( reader.ReadLine().Split(' ') );
                            hand2.Add( reader.ReadLine().Split(' ') );
                            hand2.Add( reader.ReadLine().Split(' ') );

                            List<string> commonNumbers = new List<string>();
                            foreach (string h1 in hand1.ElementAt(firstRowSelected - 1))
                            {
                                foreach (string h2 in hand2.ElementAt(secondRowSelected - 1))
                                {
                                    if (h1 == h2)
                                    {
                                        commonNumbers.Add(h1);
                                    }
                                }
                            }
                            string outputString = "";
                            if (commonNumbers.Count == 1)
                            {
                                outputString = commonNumbers.ElementAt(0);
                            }
                            else if (commonNumbers.Count > 1)
                            {
                                outputString = "Bad magician!";
                            }
                            else
                            {
                                outputString = "Volunteer cheated!";
                            }


                            //Output testcase 
                            string outputLine = "Case #" + (testCaseNum + 1).ToString() + ": " + outputString;

                            Console.WriteLine(outputLine);
                            writer.WriteLine(outputLine);
                        }
                    }
                }
            }
            catch (Exception exc)
            {
                Console.WriteLine(exc);
            }
            ///CompareResultWithExample();
        }
    }
}
