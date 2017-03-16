using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class TheRepeater
    {
        public void Go()
        {
            var file = File.ReadAllLines("input.txt");
            var outFile = File.CreateText("output.txt");
            int numCases = int.Parse(file[0]);
            int fileI = 1;
            for (int i = 0; i < numCases; i++)
            {
                int numStrings = int.Parse(file[fileI++]);
                string[] strings = new string[numStrings];
                for (int j = 0; j < numStrings; j++)
                {
                    strings[j] = file[fileI++];
                }

                //string[] minStrings = new string[numStrin];
                bool felgaWon = false;
                string minString = null;
                foreach(string s in strings) {
                    string minStr = "";
                    char? oldC = null;
                    foreach(char c in s) {
                        if(oldC.HasValue && c == oldC.Value) continue;
                        oldC = c;
                        minStr += c;
                    }
                    if(minString != null && minStr != minString) {
                        felgaWon = true;
                        break;
                    }
                    minString = minStr;
                }
                if(felgaWon) {
                    outFile.WriteLine("Case #" + (i + 1)  + ": Fegla Won");
                    continue;
                }

                int totalMoves = 0;
                for (int j = 0; j < minString.Length; j++)
                {
                    int[] numLetters = new int[numStrings];
                    char current = minString[j];
                    for (int k = 0; k < numStrings; k++)
                    {
                        numLetters[k] = strings[k].TakeWhile(c => c == current).Count();
                        strings[k] = strings[k].Substring(numLetters[k]);
                    }
                    int minMoves = int.MaxValue;
                    for (int k = 0; k < 101; k++)
                    {
                        int moves = numLetters.Select(l => Math.Abs(k - l)).Sum();
                        //if (minMoves < moves) break;
                        minMoves = Math.Min(moves, minMoves);
                    }
                    totalMoves += minMoves;
                }

                outFile.WriteLine("Case #" + (i + 1) + ": " + totalMoves);

            }
            outFile.Close();
        }

        static void Main(string[] args)
        {
            new TheRepeater().Go();
            
        }
    }
}
