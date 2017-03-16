using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeChallenge_2015_1A_A
{
    class Program
    {
        static void Main(string[] args)
        {
            //create new parser
            InputParse parser = new InputParse(args[0], Program.DetermineCaseLength);

            //create case receiver
            string[] case_results = new string[parser.CaseCount];

            //loop through test cases, in parallel if in release mode
#if DEBUG
            for (int i = 0; i < case_results.Length; i++)
            {
                case_results[i] = ProcessCase(parser.GetNextCase());
            }
#else
            Parallel.For(0, parser.CaseCount, (int i) =>
            {
                int cc = 0;
                string result = ProcessCase(parser.GetNextCase(out cc));
                case_results[cc - 1] = result;
            });
#endif


            //loop through and print results
#if DEBUG
            //print results to console
            for (int i = 0; i < case_results.Length; i++)
            {
                Console.WriteLine(String.Format("Case #{0}: {1}", i + 1, case_results[i]));
            }

            //wait for input, to hold open console
            Console.ReadKey();
#else
            //print results to file
            StreamWriter file = new StreamWriter(args.Length > 1 ? args[1] : "output.txt");

            //loop through and print lines
            for (int i = 0; i < case_results.Length; i++)
            {
                file.WriteLine(String.Format("Case #{0}: {1}", i + 1, case_results[i]));
            }

            //close file
            file.Close();
#endif
        }

        //function that determines that how many lines in a case
        private static int DetermineCaseLength(StreamReader sr, ref List<string> read_lines)
        {
            return 2;
        }

        //function to receive *all* data for a single test case, return answer as string
        private static string ProcessCase(string[] caseData)
        {
            //parse input
            int[] mplate = MatrixInput<int>.To1DMatrix(caseData[1]);

            //process input for differential
            int eaten_diff = 0;
            int eaten_rate = 0;
            int max_rate = 0;
            for (int i = 0; i < mplate.Length - 1; i++)
            {
                if (mplate[i] > mplate[i + 1]) eaten_diff += mplate[i] - mplate[i + 1];
                int diff = (mplate[i] - mplate[i + 1]);
                if (max_rate < diff && diff > 0) max_rate = diff;
            }
            for (int i = 0; i < mplate.Length - 1; i++)
            {
                if (mplate[i] < max_rate)
                {
                    eaten_rate += mplate[i];
                }
                else
                {
                    eaten_rate += max_rate;
                }
            }

            //return output
            return String.Format("{0} {1}", eaten_diff, eaten_rate);
        }
    }


    //make a generic input class
    class InputParse : IDisposable
    {
        //fields
        public delegate int TestCaseLength(StreamReader sr, ref List<string> read_lines);
        private StreamReader sr;
        private TestCaseLength test_case_length;

        //parameters
        public int CaseCount { get; private set; }
        public int CurrentCase { get; private set; }

        //constructor
        public InputParse(string textfile, TestCaseLength test_case_length)
        {
            this.sr = new StreamReader(textfile);
            this.test_case_length = test_case_length;

            //read first line and parse the number of test cases
            this.CaseCount = Int32.Parse(this.sr.ReadLine());
            this.CurrentCase = 0;
        }

        //dispose
        public void Dispose()
        {
            if (this.sr != null) this.sr.Dispose();
            this.sr = null;
        }


        //read file from case
        public string[] GetNextCase()
        {
            int cc = 0;
            return GetNextCase(out cc);
        }
        public string[] GetNextCase(out int current_case)
        {
            lock (this.sr)
            {
                //read the first line in
                List<string> read_lines = new List<string>();

                //get the number of lines in the test case
                int len = test_case_length(this.sr, ref read_lines);

                //create case matrix
                string[] tcase = new string[len];

                //save lines
                for (int i = 0; i < tcase.Length && !this.sr.EndOfStream; i++)
                {
                    if (i < read_lines.Count)
                    {
                        tcase[i] = read_lines[i];
                    }
                    else
                    {
                        tcase[i] = this.sr.ReadLine();
                    }
                }

                //increment case count
                this.CurrentCase++;

                //return current case
                current_case = this.CurrentCase;

                //return case
                return tcase;
            }
        }
    }

    static class MatrixInput<T>
    {
        //default delimiters
        public static char line_delim = '\n';
        public static char col_delim = ' ';

        //to generic 2d matrix
        public static T[,] To2DMatrix(string str)
        {
            //split string into lines
            String[] lines = str.Split(line_delim);

            //return matrix
            return To2DMatrix(lines, 0, lines.Length);
        }
        public static T[,] To2DMatrix(string[] lines)
        {
            //return matrix
            return To2DMatrix(lines, 0, lines.Length);
        }
        public static T[,] To2DMatrix(string[] lines, int start, int count)
        {
            //get height/length of first line
            int h = count;
            int w = lines[start].Count(x => x == col_delim) + 1;

            //create result matrix
            T[,] result = new T[h, w];

            //loop through each line and place
            for (int i = 0; i < h; i++)
            {
                //split line into cols
                String[] cols = lines[start + i].Split(col_delim);
                for (int j = 0; j < w; j++)
                {
                    result[i, j] = (T)Convert.ChangeType(cols[j], typeof(T));
                }
            }

            //return result
            return result;
        }

        //to generic 1d matrix
        public static T[] To1DMatrix(string str)
        {
            //split line into cols
            String[] cols = str.Split(col_delim);

            //create result matrix
            T[] result = new T[cols.Length];

            //convert and save each
            for (int j = 0; j < result.Length; j++)
            {
                result[j] = (T)Convert.ChangeType(cols[j], typeof(T));
            }

            //return result
            return result;
        }
    }
}
