using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplicationA
{
    class TestCase
    {
        public int id;
        public List<Int64> mushrooms;

        public Int64 solveY()
        {
            Int64 result = 0;
            Int64 last = 0;

            mushrooms.ForEach(m =>
            {
                if (m < last)
                {
                    result += last - m;
                }
                last = m;
            });

            return result;
        }

        public Int64 solveZ()
        {
            Int64 delta = 0;
            Int64 last = 0;

            mushrooms.ForEach(m =>
            {
                if (delta < last - m)
                {
                    delta = last - m;
                }
                last = m;
            });

            Int64 result = 0;

            for(int i = 0; i < mushrooms.Count -1; i++){
                Int64 m = mushrooms[i];
                result += Math.Min(delta, m);
            }

            return result;
        }

        public TestCase()
        {
            mushrooms = new List<Int64>();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<TestCase> testCases = new List<TestCase>();
            int nTestCases;

            using (StreamWriter sw = new StreamWriter(@"C:\Users\Fred\documents\visual studio 2013\Projects\GCJ20151A\ConsoleApplicationA\ConsoleApplicationA\result.out", false))
            //using (StreamReader sr = new StreamReader(@"C:\Users\Fred\documents\visual studio 2013\Projects\GCJ20151A\ConsoleApplicationA\ConsoleApplicationA\A-practice.in"))
            using (StreamReader sr = new StreamReader(@"C:\Users\Fred\documents\visual studio 2013\Projects\GCJ20151A\ConsoleApplicationA\ConsoleApplicationA\A-small-attempt0.in"))
            //using (StreamReader sr = new StreamReader(@"C:\Users\Fred\documents\visual studio 2013\Projects\GCJ20151A\ConsoleApplicationA\ConsoleApplicationA\A-large.in"))
            {
                string line = sr.ReadLine();
                //Console.WriteLine(line);
                nTestCases = int.Parse(line);

                for (int i = 0; i < nTestCases; i++)
                {
                    TestCase tempTestCase = new TestCase();

                    tempTestCase.id = i + 1;
                    sr.ReadLine();

                    tempTestCase.mushrooms = sr.ReadLine().Split(' ').ToList().ConvertAll(s => Int64.Parse(s));

                    Int64 result1 = tempTestCase.solveY();
                    Int64 result2 = tempTestCase.solveZ();

                    Console.WriteLine(String.Format("Case #{0}: {1} {2}", tempTestCase.id, result1, result2));
                    //Console.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, tempTestCase.multiplyOut()));
                    sw.WriteLine(String.Format("Case #{0}: {1} {2}", tempTestCase.id, result1, result2));
                }

                Console.ReadLine();
            }
        }

    }
}
