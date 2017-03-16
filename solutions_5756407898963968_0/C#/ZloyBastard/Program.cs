using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace AA
{    

    public class Solver
    {
        public int firstRow, secondRow;
        public HashSet<int> mySet = new HashSet<int>();
        public int TotalRows = 4;
        public string answer;

        public void Run()
        {
            using (FileStream input = new FileStream("A-small-attempt0.in", FileMode.Open))
            using (FileStream output = new FileStream("output.txt", FileMode.Create))
            using (StreamReader reader = new StreamReader(input))
            using (StreamWriter writer = new StreamWriter(output))
            {
                int test = Int32.Parse(reader.ReadLine());
                for (int tt = 0;tt < test; tt++)
                {
                    ReadInput(reader);
                    //SolveTask();
                    WriteOutput(writer, tt+1);
                }
            }

        }

        private void WriteOutput(StreamWriter writer, int testNum)
        {
            writer.WriteLine(string.Format("Case #{0}: {1}", testNum, answer));
        }

        private void ReadInput(StreamReader reader)
        {
            mySet.Clear();
            firstRow = Int32.Parse(reader.ReadLine());
            for (int i = 0; i < TotalRows; i++)
            {
                string str = reader.ReadLine();
                if (i+1 == firstRow)
                {
                    string[] strNums = str.Split(' ');
                    foreach (string sNum in strNums)
                    {
                        int num = Int32.Parse(sNum);
                        mySet.Add(num);
                    }
                }
            }
            answer = "Volunteer cheated!";
            bool hasAnswer = false;
            secondRow = Int32.Parse(reader.ReadLine());
            for (int i = 0; i < TotalRows; i++)
            {
                string str = reader.ReadLine();
                if (i + 1 == secondRow)
                {
                    string[] strNums = str.Split(' ');
                    foreach (string sNum in strNums)
                    {
                        int num = Int32.Parse(sNum);
                        if (mySet.Contains(num))
                        {
                            if (!hasAnswer)
                            {
                                answer = num.ToString();
                                hasAnswer = true;
                            }
                            else
                            {
                                answer = "Bad magician!";
                                break;
                            }
                        }
                    }
                }
            }
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            (new Solver()).Run();
        }

    }
}
