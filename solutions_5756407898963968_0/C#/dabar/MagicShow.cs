using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace MagicShow
{
    enum Result
    {
        Answer,
        BadMagician,
        Cheat,
    }
    class TestCase
    {
        int number;                
        int[] xitems;
        int[] yitems;

        int chosenCard;
        Result? result;


        public string GetResult()
        {
            if (result == null)
                Calc();

            return string.Format("Case #{0}: {1}", number, (result == Result.Answer ? chosenCard.ToString() : (result == Result.BadMagician ? "Bad magician!" : "Volunteer cheated!")));
        }

        public TestCase(int _number, int[] _xitems, int[] _yitems)
        {
            number = _number;                        
            xitems = _xitems;
            yitems = _yitems;
        }

        private void Calc()
        {
            int matches = 0;
            //var xsort = xitems.OrderBy(x=>x).ToArray();
            //var ysort = yitems.OrderBy(x => x).ToArray();
            //for (int i = 0; i < noItems; i++)
            //    results += xsort[i] * ysort[i];
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (xitems[i] == yitems[j])
                    {
                        chosenCard = xitems[i];
                        matches++;
                    }
                }
            }
            if (matches == 0)
                result = Result.Cheat;
            else if (matches == 1)
                result = Result.Answer;
            else
                result = Result.BadMagician;
        }

    }
    class MagicShow
    {
        static void Main(string[] args)
        {
            try
            {
                using (StreamReader sr = new StreamReader(string.Format("c:\\codejam\\{0}", args[0])))
                {
                    System.IO.StreamWriter file = new System.IO.StreamWriter(string.Format("c:\\codejam\\out_{0}", args[0]));
                    int numberOfTest = Int32.Parse(sr.ReadLine());
                    int firstRow;
                    int[] xitems;
                    int[] yitems;
                    TestCase test;                    
                    Console.WriteLine(string.Format("{0} Test cases", numberOfTest));
                    for (int i = 0; i < numberOfTest; i++)
                    {
                        xitems = ReadLayout(sr);
                        yitems = ReadLayout(sr);
                        
                        //could check prices.Count() == noItems;
                        test = new TestCase(i + 1, xitems, yitems);
                        file.WriteLine(test.GetResult());
                        if (i % 10 == 0)
                            Console.WriteLine(string.Format("wrote test {0}", i + 1));
                    }
                    file.Close();
                    Console.WriteLine(string.Format("Done {0} Tests", numberOfTest));

                }
            }
            catch (Exception e)
            {
                Console.WriteLine("Something bad:");
                Console.WriteLine(e.Message);
                return;
            }
        }

        private static int[] ReadLayout(StreamReader sr)
        {            
            int row = int.Parse(sr.ReadLine());
            int[] xitems = new int[row];
            for (int j = 0; j < 4; j++)
            {
                if (j == (row - 1))
                    xitems = sr.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                else
                    sr.ReadLine();

            }
            return xitems;
        }
    }
}
