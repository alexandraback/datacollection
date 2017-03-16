using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2014_QualA
{
    #region TestCase
    struct TestCaseMember
    {
        private object[] values;
        public object this[int index]
        {
            get { return values[index]; }
        }

        public int Count { get { return values.Length; } }

        public TestCaseMember(params object[] values)
        {
            this.values = values;
        }
    }

    struct TestCase
    {
        private TestCaseMember[] member;
        public TestCaseMember this[int index] { get { return member[index]; } }

        public int Count { get { return member.Length; } }

        public TestCase(TestCaseMember[] member)
        {
            this.member = member;
        }
    }
    #endregion

    class Program
    {
        #region Constant
        public static void PrintFile(TestCase[] cases)
        {
            using (Stream s = File.Create(InputFileName + "_output.out"))
            {
                using (StreamWriter sw = new StreamWriter(s))
                {
                    for (int i = 0; i < cases.Length; i++)
                    {
                        string result = "Case #" + (i + 1) + ": " + RunCase(cases[i]);
                        Console.WriteLine(result);
                        sw.WriteLine(result);
                    }

                    sw.Flush();
                }
            }
        }

        public static TestCase[] ReadFile()
        {
            TestCase[] result;
            using (Stream s = File.OpenRead(InputFileName + ".in"))
            {
                using (StreamReader sr = new StreamReader(s))
                {
                    int numTestCases = int.Parse(sr.ReadLine());
                    result = new TestCase[numTestCases];

                    for (int currCase = 0; currCase < numTestCases; currCase++)
                    {
                        int caseLength = (linesPerCase != -1) ? linesPerCase : int.Parse(sr.ReadLine());

                        CreateCase(result, sr, currCase, caseLength);
                    }
                }
            }

            return result;
        }
        
        static void Main(string[] args)
        {
            TestCase[] cases = ReadFile();
            
            PrintFile(cases);

            Console.WriteLine("Done!");
            Console.ReadLine();
        }

        public static void CreateCase(TestCase[] result, StreamReader sr, int currCase, int caseLength)
        {
            TestCaseMember[] member = new TestCaseMember[caseLength];
            for (int i = 0; i < caseLength; i++)
            {
                string[] line = sr.ReadLine().Split(' ');
                object[] parameter = new object[line.Length];
                for (int j = 0; j < line.Length; j++)
                {
                    if (parameterIsString)
                        parameter[j] = line[j];
                    else
                        parameter[j] = int.Parse(line[j]);
                }

                member[i] = new TestCaseMember(parameter);
            }

            result[currCase] = new TestCase(member);
        }
        #endregion

        private const string InputFileName = @"C:\Users\mihai_000\Downloads\" + "A-small-attempt0";

        /// <summary>
        /// Are the test Case parameter strings or numbers
        /// </summary>
        private const bool parameterIsString = false;

        /// <summary>
        /// How many rows follow each test case
        /// </summary>
        private const int linesPerCase = 10;

        public static string RunCase(TestCase testCase)
        {
            TestCaseMember first = testCase[(int)testCase[0][0]];
            TestCaseMember second = testCase[5 + (int)testCase[5][0]];
            List<int> values = new List<int>();

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    int value = (int)first[i];
                    if (value == (int)second[j])
                    {
                        values.Add(value);
                        break;
                    }
                }
            }

            if (values.Count == 1)
                return (values[0].ToString());
            else if (values.Count == 0)
                return "Volunteer cheated!";
            else
                return "Bad magician!";
        }
    }
}