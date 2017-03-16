using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2014.RoundQ
{
    class R0A_MagicTrick
    {
        bool logEnabled = false;
        static string baseFileName = "A-small-attempt0";
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
        private List<int> First { get; set; }
        private List<int> Second { get; set; }

        private void ReadInput()
        {
            char[] sep = { ' ' };
            int chosenRow;

            chosenRow = Int32.Parse(reader.ReadLine());
            for (int row = 1; row <= 4; row++)
            {
                string s = reader.ReadLine();
                if (row == chosenRow)
                {
                    First = s.Split(sep).Select(num => Int32.Parse(num)).ToList();
                }
            }

            chosenRow = Int32.Parse(reader.ReadLine());
            for (int row = 1; row <= 4; row++)
            {
                string s = reader.ReadLine();
                if (row == chosenRow)
                {
                    Second = s.Split(sep).Select(num => Int32.Parse(num)).ToList();
                }
            }
        }

        private void Solve()
        {
            var intersection = First.Intersect(Second).ToList();
            if (intersection.Count == 1)
            {
                Result = intersection[0].ToString();
            }
            else if (intersection.Count == 0)
            {
                Result = "Volunteer cheated!";
            }
            else
            {
                Result = "Bad magician!";
            }
        }

        public R0A_MagicTrick()
        {
            reader = new StreamReader(inputFile);
            writer = new StreamWriter(outputFile);
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
            new R0A_MagicTrick();
        }
    }
}
