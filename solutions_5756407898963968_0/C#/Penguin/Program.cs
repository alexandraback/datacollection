using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace MagicTrick
{
    class Program
    {
     
        static void Main(string[] args)
        {
            MagicTrick(@"C:\Users\Yulin\Downloads\A-small-attempt0.in", @"C:\Users\Yulin\Downloads\A-small-attempt0.out");
        }

        private static void MagicTrick(string inputName, string outputName)
        {

            Dictionary<int, int> dict = new Dictionary<int, int>();

            using (StreamReader sr = File.OpenText(inputName))
            {
                using (StreamWriter sw = new StreamWriter(File.OpenWrite(outputName)))
                {
                    int T = int.Parse(sr.ReadLine());

                    for (int i = 0; i < T; i ++)
                    {
                        dict.Clear();
                        int row1 = int.Parse(sr.ReadLine());
                        string parsingLine1 = "";
                        for (int j = 0; j < 4; j++)
                        {
                            string line = sr.ReadLine();
                            if (j == row1 - 1)
                                parsingLine1 = line;
                        }

                        int row2 = int.Parse(sr.ReadLine());
                        string parsingLine2 = "";
                        for (int j = 0; j < 4; j++)
                        {
                            string line = sr.ReadLine();
                            if (j == row2 - 1)
                                parsingLine2 = line;
                        }

                        string[] numbers1 = parsingLine1.Split(new char[] { ' ' });
                        string[] numbers2 = parsingLine2.Split(new char[] { ' ' });

                        foreach (string number in numbers1)
                        {
                            int n = int.Parse(number);
                            dict.Add(n, 1);
                        }

                        int counter = 0;
                        int answer = -1;
                        foreach (string number in numbers2)
                        {
                            int n = int.Parse(number);
                            if (dict.ContainsKey(n))
                            {
                                counter++;
                                answer = n;
                            }
                        }

                        if (counter == 1)
                        {
                            sw.WriteLine(String.Format("Case #{0}: {1}", i + 1, answer));
                        }
                        if (counter == 0)
                        {
                            sw.WriteLine(String.Format("Case #{0}: Volunteer cheated!", i + 1));
                        }
                        if (counter > 1)
                        {
                            sw.WriteLine(String.Format("Case #{0}: Bad magician!", i + 1));
                        }
                        
                    }
                }
            }
        }
    }
}
