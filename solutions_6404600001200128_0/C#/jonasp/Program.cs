using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam.Round1A
{
    class Program
    {
        private static StreamReader _reader;
        private static StreamWriter _writer;

        static Program()
        {
            _reader = new StreamReader(@"C:\CodeJam.Round1A\data\input.txt");
            _writer = new StreamWriter(@"C:\CodeJam.Round1A\data\output.txt", false);
            _writer.AutoFlush = true;
        }

        static void Main(string[] args)
        {
            var testCount = int.Parse(_reader.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                _reader.ReadLine();
                var mushrooms = _reader.ReadLine().Split().Select(Int32.Parse).ToArray();

                var firstMethodAmount = 0;
                var secondMethodAmount = 0;
                var maxRate = 0;

                for (var i = 1; i < mushrooms.Length; i++)
                {
                    var hasToEatThisTurn = Math.Max(0, mushrooms[i-1] - mushrooms[i]);
                    firstMethodAmount += hasToEatThisTurn;
                    maxRate = Math.Max(maxRate, hasToEatThisTurn);
                }

                for (var i = 1; i < mushrooms.Length; i++)
                {
                    secondMethodAmount += Math.Min(mushrooms[i-1], maxRate);
                }

                _writer.WriteLine("Case #{0}: {1} {2}", testN, firstMethodAmount, secondMethodAmount);
            }
        }
    }
}