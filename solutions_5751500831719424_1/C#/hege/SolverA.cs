using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;

namespace A
{
    class SolverA
    {
        private List<char> _letters;
        private int[,] _charCnt;

        public string SolveOne(TextReader input)
        {
            string strings = input.ReadLine();
            int numStrings = int.Parse(strings);
            string word = input.ReadLine();
            _letters = new List<char>();
            _letters.Add(word[0]);
            int letterIdx = 0;
            for (int j = 0; j < word.Length; ++j)
            {
                if (word[j] != _letters[letterIdx])
                {
                    _letters.Add(word[j]);
                    letterIdx++;
                }
            }
            _charCnt = new int[numStrings,_letters.Count];
            int linesRead = 1;
            try
            {
                ParseWord(word, 0);
                for (int i = 1; i < numStrings; ++i)
                {
                    word = input.ReadLine();
                    linesRead++;
                    ParseWord(word, i);
                }
            }
            catch (FormatException)
            {
                for (int i = linesRead; i < numStrings; ++i)
                {
                    input.ReadLine();
                }
                return "Fegla Won";
            }
            int total = 0;
            for (int i = 0; i < _letters.Count; ++i)
            {
                int min = 101*numStrings;
                for (int trg = 1; trg <= 100; ++trg)
                {
                    int sum = 0;
                    for (int j = 0; j < numStrings; ++j)
                    {
                        Debug.Assert(_charCnt[j, i] != 0);
                        sum += Math.Abs(_charCnt[j, i] - trg);
                    }
                    if (sum < min)
                    {
                        min = sum;
                    }

                }
                total += min;

            }
            return total.ToString(CultureInfo.InvariantCulture);
        }

        private void ParseWord(string word, int wordIdx)
        {
            int letterIdx = 0;
            bool bad = false;
            for (int j = 0; j < word.Length; ++j)
            {
                if (word[j] != _letters[letterIdx])
                {
                    if (j == 0 || ++letterIdx == _letters.Count || word[j] != _letters[letterIdx])
                    {
                        throw new FormatException();
                    }
                }
                ++_charCnt[wordIdx, letterIdx];
            }
            if (letterIdx != _letters.Count - 1)
            {
                throw new FormatException();
            }
        }
    }
}