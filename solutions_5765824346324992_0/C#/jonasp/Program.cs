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
                var parts  = _reader.ReadLine().Split();
                var b = Int32.Parse(parts[0]);
                var n = Int32.Parse(parts[1]);

                var times = _reader.ReadLine().Split().Select(Int32.Parse).ToArray();

                var periodLength = times.Aggregate(GetLCM);
                var clientsInPeriod = times.Sum(t => periodLength/t);

                var currentPosition = n%clientsInPeriod;
                if (currentPosition == 0)
                {
                    currentPosition = clientsInPeriod;
                }

                var maxTime = currentPosition*times.Min(t => t);
                for (var minute = 0; minute <= maxTime; minute++)
                {
                    var freeBarbers = new List<int>();
                    for (var i = 0; i < b; i++)
                    {
                        if (minute%times[i] == 0)
                        {
                            freeBarbers.Add(i + 1);
                        }
                    }

                    if (freeBarbers.Count >= currentPosition)
                    {
                        _writer.WriteLine("Case #{0}: {1}", testN, freeBarbers[currentPosition-1]);
                        break;
                    }
                    currentPosition -= freeBarbers.Count;
                }
            }
        }

        public static int GetLCM(int x, int y)
        {
            int n1, n2;
            if (x > y)
            {
                n1 = x;
                n2 = y;
            }
            else
            {
                n1 = y;
                n2 = x;
            }

            for (var i = 1; i <= n2; i++)
            {
                if ((n1 * i) % n2 == 0)
                {
                    return i * n1;
                }
            }
            return n2;
        }
    }
}