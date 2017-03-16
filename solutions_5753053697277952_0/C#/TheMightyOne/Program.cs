using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Serialization;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.ComponentModel;
using System.Threading;
using System.Numerics;

namespace GoogleCodeJamProject
{
    class Program
    {
        static void Main(string[] args)
        {
            Resolve();
            Console.WriteLine("Press any key to continue...");
            Console.ReadKey(true);
        }

        private static void Resolve()
        {
            int numLines = 0;
            var lines = IOHelper.OpenFileToNumbersInt(out numLines);
            Output op = new Output();
            for (int n = 0; n < lines.Count; n+=2)
            {
                var line = lines[n+1];
                op.WriteCase<string>(Solve(line));
            }
            op.Save();
        }

        private static bool IsMajor(List<int> s)
        {
            int sum = s.Sum(z => z);
            int m = (sum / 2);
            return s.Any(p => p > m);
        }

        private static string Solve(List<int> s)
        {
            List<string> a = new List<string>() { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
            string res = "";
            while (true)
            {
                int count = 0;
                for (int i = 0; i < s.Count; i++)
                {
                    var n = s[i];
                    if (n > 0)
                    {
                        s[i]--;
                        if (!IsMajor(s))
                        {
                            res += a[i] + " ";
                            count++;
                            break;
                        }
                        else
                        {
                            bool found = false;
                            bool any = false;
                            for (int k = 0; k < s.Count; k++)
                            {
                                var n2 = s[k];
                                if (s[k] > 0)
                                {
                                    any = true;
                                    s[k]--;
                                    if (!IsMajor(s))
                                    {
                                        res += a[i] + a[k] + " ";
                                        count++;
                                        found = true;
                                        break;
                                    }
                                    else
                                    {
                                        s[k]++;
                                    }
                                }
                            }
                            if (!found)
                            {
                                if (any)
                                {
                                    s[i]++;
                                }
                                else
                                {
                                    res += a[i] + " ";
                                    count++;
                                }
                            }
                        }
                    }
                }
                if (!s.Any(p => p > 0))
                    return res;
            }
        }
    }
}


namespace GoogleCodeJamProject
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;

    public class Output
    {
        public string OutputResult { get; set; }
        private int _caseCount = 1;
        public int CaseCount { get { return _caseCount; } set { _caseCount = value; } }

        public Output()
        {

        }

        public void WriteCases<T>(List<T> objects)
        {
            string currentCase = string.Empty;
            for (int i = 0; i < objects.Count; i++)
            {
                currentCase += objects[i].ToString();
                if (i < objects.Count - 1)
                    currentCase += " ";
            }
            string outCase = "Case #" + CaseCount + ": " + currentCase;
            OutputResult += outCase + "\n";
            CaseCount++;
            Console.WriteLine(outCase);
        }
        public void WriteCases<T>(T[] objects)
        {
            string currentCase = string.Empty;
            for (int i = 0; i < objects.Length; i++)
            {
                currentCase += objects[i].ToString();
                if (i < objects.Length - 1)
                    currentCase += " ";
            }
            string outCase = "Case #" + CaseCount + ": " + currentCase;
            OutputResult += outCase + "\n";
            CaseCount++;
            Console.WriteLine(outCase);
        }
        public void WriteCase<T>(T newObject)
        {
            string outCase = "Case #" + CaseCount + ": " + newObject.ToString();
            OutputResult += outCase + "\n";
            CaseCount++;
            Console.WriteLine(outCase);
        }
        public void WriteCaseMatrix<T>(List<T> objects)
        {
            string outCase = "Case #" + CaseCount + ": \n";
            OutputResult += outCase + "\n";
            CaseCount++;
            Console.WriteLine(outCase);
            for (int i = 0; i < objects.Count; i++)
            {
                Console.WriteLine(objects[i]);
            }
        }

        public void Save()
        {
            IOHelper.SaveFile(OutputResult);
        }

    }
}

namespace GoogleCodeJamProject
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.IO;
    using System.Numerics;

    public class IOHelper
    {
        public static string InputDir = @"D:\GoogleCodeJam\Input\";
        public static string OutputDir = @"D:\GoogleCodeJam\Output\";

        public static List<string> OpenFile(out int numTimes)
        {
            numTimes = 0;
            FileInfo file = GetFile();
            if (file != null)
            {
                Console.WriteLine("Loaded input file: " + file.Name);
                var lines = File.ReadAllLines(file.FullName).ToList();
                numTimes = int.Parse(lines[0]);
                lines.RemoveAt(0);
                return lines;
            }
            Console.WriteLine("Directory " + InputDir + " is empty.");
            return null;
        }

        public static List<List<BigInteger>> OpenFileToNumbersBigInt(out int numTimes, char splitChar = ' ')
        {
            numTimes = 0;
            var lines = OpenFile(out numTimes);
            List<List<BigInteger>> result = new List<List<BigInteger>>();
            foreach (var line in lines)
            {
                var stringsTokens = line.Split(splitChar);
                List<BigInteger> tTokens = new List<BigInteger>();
                foreach (var stringToken in stringsTokens)
                {
                    if (!string.IsNullOrEmpty(stringToken))
                        tTokens.Add(BigInteger.Parse(stringToken));
                }
                result.Add(tTokens);
            }
            return result;

        }
        public static List<List<double>> OpenFileToNumbersDouble(out int numTimes, char splitChar = ' ')
        {
            numTimes = 0;
            var lines = OpenFile(out numTimes);
            List<List<double>> result = new List<List<double>>();
            foreach (var line in lines)
            {
                var stringsTokens = line.Split(splitChar);
                List<double> tTokens = new List<double>();
                foreach (var stringToken in stringsTokens)
                {
                    if (!string.IsNullOrEmpty(stringToken))
                        tTokens.Add(double.Parse(stringToken));
                }
                result.Add(tTokens);
            }
            return result;
        }

        public static List<List<int>> OpenFileToNumbersInt(out int numTimes, char splitChar = ' ')
        {
            numTimes = 0;
            var lines = OpenFile(out numTimes);
            List<List<int>> result = new List<List<int>>();
            foreach (var line in lines)
            {
                var stringsTokens = line.Split(splitChar);
                List<int> tTokens = new List<int>();
                foreach (var stringToken in stringsTokens)
                {
                    if (!string.IsNullOrEmpty(stringToken))
                        tTokens.Add(int.Parse(stringToken));
                }
                result.Add(tTokens);
            }
            return result;
        }

        public static List<List<string>> OpenFileToNumbersString(out int numTimes, char splitChar = ' ')
        {
            numTimes = 0;
            var lines = OpenFile(out numTimes);
            List<List<string>> result = new List<List<string>>();
            foreach (var line in lines)
            {
                var stringsTokens = line.Split(splitChar);
                List<string> tTokens = new List<string>();
                foreach (var stringToken in stringsTokens)
                {
                    if (!string.IsNullOrEmpty(stringToken))
                        tTokens.Add(stringToken);
                }
                result.Add(tTokens);
            }
            return result;
        }

        public static List<List<double>> OpenFileToNumbersGroupped(out int numTimes, char splitChar = ' ')
        {
            numTimes = 0;
            var lines = OpenFile(out numTimes);
            int numLines = lines.Count;

            double unitRow = numLines / numTimes;
            if (unitRow % 1 != 0)
                throw new Exception("ALE Exception - Incorrect number of line");

            List<List<double>> result = new List<List<double>>();

            for (int i = 0; i < numTimes * unitRow; i += 3)
            {
                List<double> partialResult = new List<double>();
                for (int k = 0; k < unitRow; k++)
                {
                    foreach (var split in lines[i + k].Split(splitChar))
                    {
                        partialResult.Add(double.Parse(split));
                    }
                }
                result.Add(partialResult);
            }
            return result;
        }

        public static void SaveFile(string result)
        {
            string fileName = "out.txt";
            StreamWriter file = new StreamWriter(OutputDir + fileName);
            file.Write(result);
            file.Close();
        }

        private static FileInfo GetFile()
        {
            var files = new DirectoryInfo(InputDir).GetFiles();
            if (files.Length == 0) return null;
            FileInfo lastCreatedFile = files[0];
            foreach (var file in files)
            {
                var fileInfo = file;
                if (fileInfo.LastWriteTime > lastCreatedFile.LastWriteTime)
                    lastCreatedFile = fileInfo;
            }
            return lastCreatedFile;
        }
    }
}