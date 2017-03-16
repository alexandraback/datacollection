using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam1b
{
    class Problem2
    {
        public static void Main()
        {
            new Problem2().Start();
        }

        void Start()
        {
            var fileName = "B-small-attempt0";
            using (var input = new System.IO.StreamReader("../../IO/" + fileName + ".in"))
            using (var output = new System.IO.StreamWriter("../../IO/" + fileName + ".out"))
            {
                var TC = int.Parse(input.ReadLine());
                for (var testCase = 1; testCase <= TC; testCase++)
                {
                    Console.WriteLine("Case #" + testCase);

                    var line = input.ReadLine().Split(' ').Select(int.Parse).ToArray();
                    var R = line[0];
                    var C = line[1];
                    var N = line[2];
                    sizeX = Math.Min(R, C);
                    sizeY = Math.Max(R, C);
                    var res = DP(0, 0, N, new string(Enumerable.Repeat(' ', sizeX).ToArray()));

                    output.WriteLine("Case #" + testCase + ": " + res);

                    memo.Clear();
                }
            }
        }

        static int sizeX;
        static int sizeY;
        static Dictionary<Tuple<int, int, int, string>, int> memo = new Dictionary<Tuple<int, int, int, string>, int>();

        static int DP(int x, int y, int toPlace, string prev)
        {
            var key = new Tuple<int, int, int, string>(x, y, toPlace, prev);
            if (memo.ContainsKey(key))
                return memo[key];
            if (x == sizeX)
            {
                return memo[key] = DP(0, y + 1, toPlace, prev);
            }
            if (toPlace == 0)
            {
                return memo[key] = 0;
            }
            if (y == sizeY)
            {
                return memo[key] = 10000;
            }
            
            var unhappy = 0;
            if (prev[prev.Length - 1] != ' ' && x > 0)
            {
                unhappy++;
            }
            if (prev[0] != ' ' && y > 0)
            {
                unhappy++;
            }
            var min = DP(x + 1, y, toPlace, prev.Substring(1) + " ");
            min = Math.Min(min, DP(x + 1, y, toPlace - 1, prev.Substring(1) + ".") + unhappy);
            return memo[key] = min;
        }
    }
}
