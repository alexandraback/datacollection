using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Q1A_MushroomMonster_2
{
    class Program
    {
        static void Main(string[] args)
        {
            var inFilename = args[0];
            var inFile = new StreamReader(inFilename);
            var outFile = new StreamWriter("output.txt");
            string line = inFile.ReadLine();
            var numTestCases = Int32.Parse(line);
            int testCase = 0;
            while ((line = inFile.ReadLine()) != null)
            {
                var numIntervals = Int32.Parse(line);
                int[] intList = inFile.ReadLine().Split(' ').Select(s => Int32.Parse(s)).ToArray();
                var y = min1(numIntervals, intList);
                var z = min2(numIntervals, intList);
                outFile.WriteLine("Case #{0}: {1} {2}", testCase + 1, y, z);
                ++testCase;
            }
            outFile.Close();
            inFile.Close();
        }

        public static int min1(int numIntervals, int[] intList)
        {
            var sum = 0;
            var diff = 0;
            for(var i=0;i<numIntervals-1;++i)
            {
                diff = intList[i] - intList[i+1];
                if (diff > 0) sum += diff;
            }

            return sum;
        }

        public static int min2(int numIntervals, int[] intList)
        {
            var maxDif = 0;
            var diff = 0;
            for(var i=0;i<numIntervals-1;++i)
            {
                diff = intList[i] - intList[i+1];
                if (diff > maxDif) maxDif = diff;
            }

            var numEaten = 0;
            for(var i=0;i<numIntervals-1;++i)
            {
                if (intList[i] <= maxDif)
                {
                    numEaten += intList[i];
                }
                else
                {
                    numEaten += maxDif;
                }
            }
            return numEaten;
        }
    }
}
