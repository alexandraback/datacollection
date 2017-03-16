using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2014.RoundQ
{
    class R1BA_TheRepeater
    {
        bool logEnabled = false;
        static string baseFileName = "A-large";
        string inputFile = baseFileName + ".in";
        string outputFile = baseFileName + ".out";
        string logFile = baseFileName + ".log";
        StreamReader reader;
        StreamWriter writer;
        StreamWriter logWriter;
        private void Log(string message)
        {
            if (!logEnabled) return;
            logWriter.WriteLine(message);
        }

        private string Result { get; set; }

        private int N { get; set; }
        private int P { get; set; }
        private string[] Inputs { get; set; }
        private char[] Pattern { get; set; }
        private int[][] Lengths { get; set; }

        private void Init()
        {
            Inputs = new string[100];
            Pattern = new char[100];
            Lengths = new int[100][];
            for (int i = 0; i < 100; i++)
            {
                Lengths[i] = new int[100];
            }
        }

        private void ReadInput()
        {
            N = Int32.Parse(reader.ReadLine());

            for (int i = 0; i < N; i++) 
                Inputs[i] = reader.ReadLine();
        }

        private void Solve()
        {
            string s = Inputs[0];
            P = 0;
            Pattern[P] = s[0];
            Lengths[0][P] = 1;
            for (int j = 1; j < s.Length; j++)
            {
                if (s[j] == Pattern[P])
                {
                    Lengths[0][P]++;
                }
                else
                {
                    Pattern[++P] = s[j];
                    Lengths[0][P] = 1;
                }
            }
            P++;

            for (int i = 1; i < N; i++)
            {
                int p;
                for (p = 0; p < P; p++)
                {
                    Lengths[i][p] = 0;
                }
                s = Inputs[i];
                p = 0;
                for (int j = 0; j < s.Length; j++)
                {
                    if (s[j] == Pattern[p])
                    {
                        Lengths[i][p]++;
                    }
                    else 
                    {
                        if (Lengths[i][p] == 0 || p == P-1)
                        {
                            Result = "Fegla Won";
                            return;
                        }
                        j--;
                        p++;
                    }
                }
                if (Lengths[i][P - 1] == 0)
                {
                    Result = "Fegla Won";
                    return;
                }
            }

            var nums = new List<int>();
            int moves = 0;
            for (int p = 0; p < P; p++)
            {
                nums.Clear();
                for (int i = 0; i < N; i++)
                {
                    nums.Add(Lengths[i][p]);
                }
                nums.Sort();
                int median = nums[N / 2];
                for (int i = 0; i < N; i++)
                {
                    moves += Math.Abs(median - nums[i]);
                }
            }

            Result = moves.ToString();
        }

        public R1BA_TheRepeater()
        {
            reader = new StreamReader(inputFile);
            writer = new StreamWriter(outputFile);
            Init();
            if (logEnabled)
                logWriter = new StreamWriter(logFile);
            try
            {
                string s = reader.ReadLine();
                int T = Int32.Parse(s);
                for (int t = 1; t <= T; t++)
                {
                    Log("Start Case #" + t);
                    ReadInput();
                    Solve();
                    writer.WriteLine(String.Format("Case #{0}: {1}", t, Result));
                    Log("End Case #" + t);
                }
            }
            finally
            {
                reader.Close();
                writer.Close();
                if (logEnabled)
                    logWriter.Close();
            }
        }
        static void Main(string[] args)
        {
            new R1BA_TheRepeater();
        }
    }
}
