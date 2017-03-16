using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2015_1A
{
    class Program
    {
        static void Main(string[] args)
        {
            int tests = ReadInt();
            for (int test = 1; test <= tests; ++test)
            {
                int sampleCount = ReadInt();
                var samples = ReadInts().ToList();

                int min = 0;
                int rate = 0;
                int last = samples[0];
                for(int i = 1; i < samples.Count; ++i)
                {
                    int s = samples[i];
                    if (s < last)
                    {
                        int drop = last - s;
                        min += drop;
                        if (drop > rate) rate = drop;
                    }
                    last = s;
                }

                int crate = 0;
                for (int i = 0; i < (samples.Count - 1); ++i)
                {
                    int s = samples[i];
                    if (s < rate)
                    {
                        crate += s;
                    }
                    else
                    {
                        crate += rate;
                    }
                }

                Console.WriteLine("Case #{0}: {1} {2}", test, min, crate);
            }
        }


        static int ReadInt()
        {
            return Convert.ToInt32(Console.ReadLine());
        }

        static IEnumerable<String> ReadStrings()
        {
            string line = Console.ReadLine();
            return line.Split((char[])null, StringSplitOptions.RemoveEmptyEntries);
        }

        static IEnumerable<int> ReadInts()
        {
            return ReadStrings().Select(s => Convert.ToInt32(s));
        }

        static IEnumerable<long> ReadLongs()
        {
            return ReadStrings().Select(s => Convert.ToInt64(s));
        }

        static int[] ReadInts(int count)
        {
            return ReadInts().Take(count).ToArray();
        }

    }
}
