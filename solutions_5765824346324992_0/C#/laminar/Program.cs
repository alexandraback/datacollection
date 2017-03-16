using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplicationB
{
    class TestCase
    {
        public int id;
        public int B;
        public int N;
        public List<int> minutes;

        public int Gcd(int a, int b)
        {
            if (b == 0)
            {
                return a;
            }
            else
            {
                return Gcd(b, a % b);
            }
        }

        public int Lcm(int a, int b)
        {
            return (a * b) / Gcd(a, b);
        }

        public void reduce()
        {
            int curLcm = 1;
            int haircuts = 0;

            minutes.ForEach(m => {
                curLcm = Lcm(curLcm, m);
            });

            minutes.ForEach(m =>
            {
                haircuts += curLcm / m;
            });

            N = N % haircuts;
            if (N == 0)
            {
                N = haircuts;
            }
        }

        public int solve()
        {
            reduce();
            List<int> minutesLeft = new List<int>();
            int result = 0;
            int tilAvail = int.MaxValue;

            minutesLeft = Enumerable.Repeat(0, minutes.Count).ToList();

            while (N > 0)
            {
                tilAvail = int.MaxValue;
                minutesLeft.ForEach(m => {
                    if (m < tilAvail)
                    {
                        tilAvail = m;
                    }
                });

                for (int i = 0; i < minutes.Count; i++)
                {
                    if (minutesLeft[i] <= tilAvail)
                    {
                        minutesLeft[i] = minutes[i];
                        N--;
                        if(N == 0){
                            result = i+1;
                        }
                    }
                    else
                    {
                        minutesLeft[i] = minutesLeft[i] - tilAvail;
                    }
                }

            }

            return result;
        }

        public TestCase()
        {
            minutes = new List<int>();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<TestCase> testCases = new List<TestCase>();
            int nTestCases;

            using (StreamWriter sw = new StreamWriter(@"C:\Users\Fred\documents\visual studio 2013\Projects\GCJ20151A\ConsoleApplicationB\ConsoleApplicationB\result.out", false))
            //using (StreamReader sr = new StreamReader(@"C:\Users\Fred\documents\visual studio 2013\Projects\GCJ20151A\ConsoleApplicationB\ConsoleApplicationB\B-practice.in"))
            using (StreamReader sr = new StreamReader(@"C:\Users\Fred\documents\visual studio 2013\Projects\GCJ20151A\ConsoleApplicationB\ConsoleApplicationB\B-small-attempt2.in"))
            //using (StreamReader sr = new StreamReader(@"C:\Users\Fred\documents\visual studio 2013\Projects\GCJ20151A\ConsoleApplicationB\ConsoleApplicationB\B-large.in"))
            {
                string line = sr.ReadLine();
                //Console.WriteLine(line);
                nTestCases = int.Parse(line);

                for (int i = 0; i < nTestCases; i++)
                {
                    TestCase tempTestCase = new TestCase();

                    tempTestCase.id = i + 1;
                    List<int> temp = sr.ReadLine().Split(' ').ToList().ConvertAll(s => int.Parse(s));

                    tempTestCase.B = temp[0];
                    tempTestCase.N = temp[1];

                    tempTestCase.minutes = sr.ReadLine().Split(' ').ToList().ConvertAll(s => int.Parse(s));

                    int result = tempTestCase.solve();

                    Console.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, result));
                    //Console.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, tempTestCase.multiplyOut()));
                    sw.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, result));
                }

                Console.ReadLine();
            }
        }

    }
}
