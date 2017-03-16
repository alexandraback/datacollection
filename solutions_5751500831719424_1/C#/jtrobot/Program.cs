using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Threading;
using System.Numerics;

namespace CodeJam
{
    class Program
    {
        private static List<KeyValuePair<char, int>> LetterFrequency(string word)
        {
            List<KeyValuePair<char, int>> letterFrequency = new List<KeyValuePair<char, int>>();
            char lastLetter = word[0];
            for (int j = 1; j < word.Length; j++)
            {
                int letterCount = 1;
                while (word[j] == word[j - 1])
                {
                    letterCount++;
                    j++;
                    if (j == word.Length) break;
                }
                letterFrequency.Add(new KeyValuePair<char, int>(word[j - 1], letterCount));
            }
            if (word.Length != 1)
            {
                if (word[word.Length - 1] != word[word.Length - 2])
                    letterFrequency.Add(new KeyValuePair<char, int>(word[word.Length - 1], 1));
            }
            else
                letterFrequency.Add(new KeyValuePair<char, int>(word[0], 1));
            return letterFrequency;
        }


        private static string CodeJam(List<string> words)
        {
            List<List<KeyValuePair<char, int>>> letterFrequencies = new List<List<KeyValuePair<char,int>>>();
            int lastLettersCount = 0;
            for (int i = 0; i < words.Count; i++)
            {
                List<KeyValuePair<char, int>> letterFrequency = LetterFrequency(words[i]);
                letterFrequencies.Add(letterFrequency);
            }
            //Validation
            for (int i = 1; i < words.Count; i++)
            {
                if (letterFrequencies[0].Count != letterFrequencies[i].Count) return "Fegla Won";
                for (int j = 0; j < letterFrequencies[0].Count; j++)
                    if (letterFrequencies[0][j].Key != letterFrequencies[i][j].Key) return "Fegla Won";
            }
            //Move count
            int moveCount = 0;
            for (int i = 0; i < letterFrequencies[0].Count; i++)
            {
                List<int> counts = new List<int>();
                for (int j = 0; j < words.Count; j++)
                {
                    counts.Add(letterFrequencies[j][i].Value);
                }
                int meetAt = counts.Max();
                int bestDistance = int.MaxValue;
                for (int k = 0; k < counts.Count; k++)
                {
                    List<int> distances = new List<int>();
                    int dist = 0;
                    for (int l = 0; l < counts.Count; l++)
                    {
                        distances.Add(Math.Abs(counts[k] - counts[l]));
                        dist += Math.Abs(counts[k] - counts[l]);
                    }
                    //if (distances.Sum() < bestDistance)
                    if (dist < bestDistance)
                    {
                        bestDistance = dist;// distances.Sum();
                        meetAt = counts[k];
                    }
                }
                int distance = 0;
                for (int l = 0; l < counts.Count; l++)
                {
                    distance += Math.Abs(counts[l] - meetAt);
                }
                moveCount += distance;
            }
            return moveCount.ToString();
        }


        static void Main(string[] args)
        {
            string fileIn = "..\\..\\..\\A-large.in";
            string fileOut = "..\\..\\..\\fileOut.txt";
            using (StreamReader sr = new StreamReader(fileIn))
            using (StreamWriter sw = new StreamWriter(fileOut))
            {
                string theAnswer = string.Empty;
                int cases = int.Parse(sr.ReadLine());
                for (int i = 1; i <= cases; i++)
                {
                    int line1 = int.Parse(sr.ReadLine());

                    List<string> words = new List<string>();
                    for (int j = 0; j < line1; j++)
                        words.Add(sr.ReadLine());

                    string answer = "Case #" + i + ": " + CodeJam(words);
                    sw.WriteLine(answer);
                    Console.WriteLine(answer);
                }
            }
            Console.WriteLine("\r\nProcess Complete! Press any key to exit.");
            Console.ReadLine();
        }
    }
}
