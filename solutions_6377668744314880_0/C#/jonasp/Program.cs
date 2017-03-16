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
                _writer.WriteLine("Case #{0}:", testN);

                var numTrees  = Int32.Parse(_reader.ReadLine());

                var trees = new List<Tuple<int, int>>();
                for (var i = 0; i < numTrees; i++)
                {
                    var coordinates = _reader.ReadLine().Split().Select(Int32.Parse).ToArray();
                    trees.Add(new Tuple<int, int>(coordinates[0], coordinates[1]));
                }

                foreach (var rootTree in trees)
                {
                    if (trees.Count <= 3)
                    {
                        _writer.WriteLine(0);
                        continue;
                    }

                    var minCuts = trees.Count;
                    foreach (var relTree in trees)
                    {
                        var newTrees = new List<Tuple<int, int>>(trees);
                        newTrees.Remove(rootTree);
                        newTrees.Remove(relTree);
                        minCuts = Math.Min(minCuts, GetNumToCutDown(rootTree.Item1, rootTree.Item2, relTree.Item1, relTree.Item2, trees));
                    }
                    _writer.WriteLine(minCuts);
                }
            }
        }

        private static int GetNumToCutDown(int rootx, int rooty, int relx, int rely, List<Tuple<int,int>> trees)
        {
            if (rootx == relx)
            {
                return Math.Min(trees.Count(t => t.Item1 < rootx), trees.Count(t => t.Item1 > rootx));
            }

            var upCount = 0;
            var downCount = 0;

            var deltax = relx - rootx;
            var deltay = rely - rooty;

            foreach (var tree in trees)
            {
                var deltaxCurrent = tree.Item1 - rootx;

                int boundaryY;
                bool exact = false;
                if (deltaxCurrent%deltax == 0)
                {
                    exact = true;
                    boundaryY = rooty + (deltaxCurrent/deltax)*deltay;
                }
                else
                {
                    boundaryY = rooty + (int) Math.Floor((deltaxCurrent*1.0/deltax)*deltay);
                }

                if (exact && boundaryY == tree.Item2) continue;
                if (tree.Item2 < boundaryY || (tree.Item2 <= boundaryY && !exact))
                {
                    downCount++;
                }
                else
                {
                    upCount++;
                }
            }

            return Math.Min(upCount, downCount);
        }
    }
}