using System;

using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

namespace CodeJamApp._20160508.A
{
    public class Program
    {
        const string INPUT_FILE = "..\\..\\20160508\\A\\A-large.in";

        public void Solve()
        {
            var t = Scanner.ReadInt();
            int caseNo = 1;
            while (caseNo <= t)
            {
                var n = Scanner.ReadInt();
                string output = string.Empty;
                
                Dictionary<char, int> pp = new Dictionary<char, int>();
                int[] party = new int[n];
                for(int p=0;p<n;p++)
                {
                    int count= Scanner.ReadInt(); ;
                    //party[p]
                    char letter = 'A';
                    if (p > 0) letter += (char)p;
                    pp.Add(letter, count);
                }

                int total = pp.Sum(x=>x.Value);
                while(total>0)
                {
                    int max1 = pp.Max(x => x.Value);
                    var result1 = pp.First(x => x.Value == max1);

                    int max2=0;
                    KeyValuePair<char, int> result2 = new KeyValuePair<char, int>();
                    if (pp.Where(x => x.Key != result1.Key) !=null)
                    { 
                        max2 = pp.Where(x=>x.Key!= result1.Key).Max(x => x.Value);
                        result2 = pp.Where(x => x.Key != result1.Key).First(x => x.Value == max2);
                    }

                    if (max2>0 && IsOk(pp,n,result1.Key, result2.Key) )
                    {
                        pp[result1.Key] = pp[result1.Key] - 1;
                        pp[result2.Key] = pp[result2.Key] - 1;
                        output = output + result1.Key + result2.Key + " ";
                    }
                    else
                    {
                        pp[result1.Key] = pp[result1.Key] - 1;
                        output = output + result1.Key + " ";
                    }
                    
                    total = pp.Sum(x => x.Value);
                }
                output = output.TrimEnd();

                Scanner.Writer.WriteLine("Case #{0}: {1}", caseNo++, output);
            }
        }

        bool IsOk(Dictionary<char, int>pp,int n, char a, char b)
        {
            int total = pp.Sum(x => x.Value);
            if (a != '0') total--;
            if (b != '0') total--;
            for (int p=0; p<n;p++)
            {
                char letter = 'A';
                if (p > 0) letter += (char)p;

                int value = pp[letter];
                if (letter == a || letter == b) value--;
                if (value>(total/2)) return false;
            }
            return true;
        }

        static void Main()
        {
            var type = typeof(Program);
            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            TextReader reader;
            TextWriter writer;

            Console.WriteLine($"[{type.Namespace} Started at {DateTime.Now:u}]");

            //reader = new StreamReader(Console.OpenStandardInput());
            reader = new StreamReader(INPUT_FILE);

            //writer = new StreamWriter(Console.OpenStandardOutput());
            writer = new StreamWriter(INPUT_FILE.Replace(".in", ".out"));

            Scanner.SetReaderAndWriter(reader, writer);
            new Program().Solve();

            reader.Close();
            writer.Close();

            sw.Stop();
            Console.WriteLine($"[{type.Namespace} Ended. Took {sw.Elapsed}]");
            //Console.WriteLine("Press any key to continue");
            //Console.ReadKey();
        }
    }

    static class Scanner
    {
        public static TextReader Reader { get; set; }
        public static TextWriter Writer { get; set; }

        private static Queue<string> _currentLineTokens = new Queue<string>();
        private static string[] ReadAndSplitLine() { return Reader.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries); }

        public static void SetReaderAndWriter(TextReader reader, TextWriter writer) { Reader = reader; Writer = writer; }
        public static string ReadToken() { while (_currentLineTokens.Count == 0) _currentLineTokens = new Queue<string>(ReadAndSplitLine()); return _currentLineTokens.Dequeue(); }
        public static int ReadInt() { return int.Parse(ReadToken()); }
        public static long ReadLong() { return long.Parse(ReadToken()); }
        public static double ReadDouble() { return double.Parse(ReadToken(), CultureInfo.InvariantCulture); }
        public static int[] ReadIntArray() { return ReadAndSplitLine().Select(int.Parse).ToArray(); }
        public static long[] ReadLongArray() { return ReadAndSplitLine().Select(long.Parse).ToArray(); }
        public static double[] ReadDoubleArray() { return ReadAndSplitLine().Select(s => double.Parse(s, CultureInfo.InvariantCulture)).ToArray(); }
        public static string[] ReadLines(int quantity) { string[] lines = new string[quantity]; for (int i = 0; i < quantity; i++) lines[i] = Reader.ReadLine().Trim(); return lines; }
        public static void WriteArray<T>(IEnumerable<T> array) { Writer.WriteLine(string.Join(" ", array)); }
        public static void Write(params object[] array) { WriteArray(array); }
        public static void WriteLines<T>(IEnumerable<T> array) { foreach (var a in array) Writer.WriteLine(a); }
    }
}
