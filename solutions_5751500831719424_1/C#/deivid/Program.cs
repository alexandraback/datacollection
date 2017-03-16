using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var sw = Stopwatch.StartNew();

            var problem = new ProblemA(@"..\..\_data\A-large.in");
            problem.Solve();

            sw.Stop();
            Console.WriteLine("Done in {0}", sw.Elapsed);
            Console.ReadKey();
        }
    }

    public class ProblemA
    {
        StreamReader _reader;
        StreamWriter _writer;

        public ProblemA(string fileName)
        {
            _reader = System.IO.File.OpenText(fileName);
            _writer = System.IO.File.CreateText(Path.Combine(Path.GetDirectoryName(fileName), Path.GetFileNameWithoutExtension(fileName) + ".out"));
        }


        public void Solve()
        {
            int N = ReadInt();
            for (int testCase = 1; testCase <= N; testCase++)
            {
                WriteCaseResult(testCase, SolveCase());
            }
            ProduceOutput();
        }

        private void WriteCaseResult(int caseNumber, string result)
        {
            _writer.Write("Case #");
            _writer.Write(caseNumber);
            _writer.Write(": ");
            _writer.WriteLine(result);
        }

        private void ProduceOutput()
        {
            _writer.Flush();
            _writer.Close();
            _writer.Dispose();
            _reader.Close();
            _reader.Dispose();
        }

        private int ReadInt()
        {
            return int.Parse(_reader.ReadLine());
        }

        private string ReadString()
        {
            return _reader.ReadLine();
        }

        private string[] ReadStringArray()
        {
            return ReadString().Split();
        }

        private IEnumerable<int> ReadIntIEnumerable()
        {
            return ReadStringArray().Select(s => int.Parse(s));
        }

        private string SolveCase()
        {
            int N = ReadInt();
            var words = new List<List<WordItem>>();
            bool flegaWon = false;
            for (int i = 0; i < N; i++)
            {
                words.Add(GetWord(ReadString()));
                if (i > 0)
                {
                    if (!CompareWords(words[i], words[i - 1]))
                    {
                        flegaWon = true;
                        
                    }
                }
            }
            if( flegaWon)
                return "Fegla Won";

            // Omar wons
            int moves = 0;
            for (int i = 0; i < words[0].Count; i++)
            {
                while (true)
                {
                    int min = int.MaxValue;
                    int minPos = 0;
                    int max = int.MinValue;
                    int maxPos = 0;
                    int sum = 0;
                    for (int w = 0; w < N; w++)
                    {
                        if (words[w][i].num < min)
                        {
                            min = words[w][i].num;
                            minPos = w;
                        }
                        if (words[w][i].num > max)
                        {
                            max = words[w][i].num;
                            maxPos = w;
                        }
                        sum += words[w][i].num;
                    }

                    if (min == max)
                        break;

                    var avg = (double)sum / (double)N;
                    if ((avg - (double)min) > ((double)max - avg))
                        words[minPos][i].num++;
                    else
                        words[maxPos][i].num--;
                    moves++;
                }
            }

            return moves.ToString();
        }

        private List<WordItem> GetWord(string s)
        {
            var word = new List<WordItem>();
            foreach (var c in s.ToCharArray())
            {
                if (word.Count == 0 || word.Last().c != c)
                    word.Add(new WordItem { c = c, num = 1 });
                else
                    word.Last().num++;

            }
            return word;
        }

        private bool CompareWords(List<WordItem> word1, List<WordItem> word2)
        {
            if (word1.Count != word2.Count)
                return false;

            for (int i = 0; i < word1.Count; i++)
            {
                if (word1[i].c != word2[i].c)
                    return false;
            }

            return true;
        }
    }

    class WordItem
    {
        public char c;
        public int num;
    }
}
