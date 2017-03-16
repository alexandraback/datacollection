using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ_2014_1B_A
{
    class Program
    {
        static object SolveCase(Reader rl)
        {
            int n = int.Parse(rl());
            List<string> words = new List<string>();
            for (int i = 0; i < n; i++)
            {
                words.Add(rl());
            }

            if (valid(words))
            {
                int counter = 0;
                List<List<int>> Commonnesses = new List<List<int>>();
                string profile = allLetters(words[0]);
                for (int i = 0; i < words.Count; i++)
                {
                    Commonnesses.Add(letterCommonness(words[i]));
                }
                for (int i = 0; i < profile.Length; i++)
                {
                    List<int> temp = new List<int>();
                    for (int j = 0; j < n; j++)
                    {
                        temp.Add(Commonnesses[j][i]);
                    }
                    if (profile.Length % 2 != 0)
                    {
                        int mid = middleNumber1(temp);
                        for (int j = 0; j < n; j++)
                        {
                            counter += Math.Abs(mid - temp[j]);
                        }
                    }
                    else
                    {
                        int mid1 = middleNumber1(temp);
                        int mid2 = middleNumber1(temp);
                        int counter1 = 0;
                        int counter2 = 0;
                        for (int j = 0; j < n; j++)
                        {
                            counter1 += Math.Abs(mid1 - temp[j]);
                            counter2 += Math.Abs(mid2 - temp[j]);
                        }
                        counter += Math.Min(counter1, counter2);
                    }
                }
                return counter;
            }
            else
            {
                return "Fegla Won";
            }
        }

        static List<int> letterCommonness(string word)
        {
            List<int> Commonness = new List<int>();
            int counter = 1;
            for (int i = 1; i < word.Length; i++)
            {
                if (word[i - 1] == word[i])
                {
                    counter++;
                }
                else
                {
                    Commonness.Add(counter);
                    counter = 1;
                }
            }
            Commonness.Add(counter);
            return Commonness;
        }

        static bool valid(List<string> s)
        {
            for (int i = 1; i < s.Count; i++)
            { 
                if(allLetters(s[i-1])!=allLetters(s[i]))
                {
                    return false;
                }
            }
            return true;
        }
        static string allLetters(string s)
        {
            string res = s[0].ToString();
            for (int i = 1; i < s.Length; i++)
            {
                if (res[res.Length-1]!=s[i])
                {
                    res += s[i];
                }
            }
            return res;
        }

        static int middleNumber1(List<int> temp)
        {
            temp.Sort();
            return temp[temp.Count / 2];
        }

        static int middleNumber2(List<int> temp)
        {
            temp.Sort();
            return temp[temp.Count / 2 + 1];
        }

        struct Settings
        {
            public const bool DEBUG = false;
            public const bool EXAMPLE = false;
            public const bool SMALL = false;
            public const char PROBLEM_LETTER = 'A';
            public const int ATTEMPT_NUMBER = 0;
            public const bool PRACTICE = false;
        }

        static void Debug()
        {
        }

        static void outp(List<int> a)
        {
            foreach (int i in a)
            {
                Console.WriteLine(i);
            }
        }

        #region Pattern
        static void Main(string[] args)
        {
            if (Settings.DEBUG)
            {
                Debug();
            }
            else
            {
                SolveAll(CreateInfPath(Settings.EXAMPLE, Settings.SMALL, Settings.PROBLEM_LETTER, Settings.ATTEMPT_NUMBER, Settings.PRACTICE));
            }
            Console.ReadKey();
        }
        delegate string Reader();
        static void SolveAll(string infPath)
        {
            StreamReader inf = new StreamReader(infPath);
            Reader rl = inf.ReadLine;
            StreamWriter outf = new StreamWriter(@"C:\Users\Jakob\Desktop\outf.txt");

            int cases = int.Parse(rl());

            DateTime start;
            Console.Title = "Google Code Jam";

            for (int currentCase = 1; currentCase <= cases; currentCase++)
            {
                start = DateTime.Now;
                outf.WriteLine("Case #{0}: {1}", currentCase, SolveCase(rl));
                Console.WriteLine("Case {0} / {1} : {2}ms", currentCase, cases, (DateTime.Now - start).Milliseconds);
            }

            inf.Close();
            outf.Close();

            Console.WriteLine("END!");
            Console.Beep(300, 500);
        }
        static string CreateInfPath(bool example, bool small, char problemLetter, int attemptNumber, bool practice)
        {
            string infPath;
            if (example)
            {
                infPath = @"C:\Users\Jakob\Desktop\ex.txt";
            }
            else
            {
                infPath = @"C:\Users\Jakob\Downloads\" + problemLetter.ToString() + "-";
                if (small)
                {
                    infPath += "small";
                }
                else
                {
                    infPath += "large";
                }
                if (practice)
                {
                    infPath += "-practice";
                }
                else if (small)
                {
                    infPath += "-attempt" + attemptNumber.ToString();
                }
                infPath += ".in";
            }
            return infPath;
        }
        #endregion
    }
}
