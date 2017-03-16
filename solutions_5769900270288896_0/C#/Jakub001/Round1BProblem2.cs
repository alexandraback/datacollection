using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeAlgorithms.Problems
{
    class Round1BProblem2 : IProblem
    {
        public void Solve(TextReader input, TextWriter output)
        {
            int tests = int.Parse(input.ReadLine());

            for (int q = 0; q < tests; q++)
            {
                var p = input.ReadLine().Split(' ').Select(int.Parse).ToArray();

                int r = p[0];
                int c = p[1];
                int n = p[2];
                int result = 0;
                int t = (int)Math.Ceiling(r * c / 2.0);

                if (n == r * c)
                {
                    var w = new bool[r, c];
                    var h = new int[r, c];

                    for (int i = 0; i < r; i++)
                        for (int j = 0; j < c; j++)
                            w[i, j] = true;

                    result = CountWalls(w, h, r, c);
                }
                else if (n > t)
                {
                    result = GetMin(r, c, n, t, false);
                    if (r % 2 != 0 && c % 2 != 0)
                    {
                        var tmp = GetMin(r, c, n, t, true);

                        if (tmp < result)
                            result = tmp;
                    }
                }

                output.WriteLine("Case #{0}: {1}", q + 1, result);
                Console.WriteLine("Case #{0}: {1}", q + 1, result);

            }



            output.WriteLine();
        }

        private static int GetMin(int r, int c, int n, int t, bool mode)
        {
            var w = new bool[r, c];
            var h = new int[r, c];
            int result = 0;
            int counter = t;

            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if ((j + i) % 2 == 0)
                        w[i, j] = true;
                }
            }

            if (mode)
            {
                w[r / 2, c / 2] = false;
                t--;
                counter--;
            }

            CountWalls(w, h, r, c);

            while (counter < n)
            {
                int min = int.MaxValue;
                int tr = 0, tc = 0;
                for (int i = 0; i < r; i++)
                {
                    for (int j = 0; j < c; j++)
                    {
                        if (w[i, j]) continue;

                        if (mode && i == r / 2 && j == c / 2)
                            continue;

                        if (h[i, j] < min)
                        {
                            min = h[i, j];
                            tr = i;
                            tc = j;
                        }
                    }
                }

                w[tr, tc] = true;
                counter++;

                result = CountWalls(w, h, r, c);
            }

            return result;
        }

        static int CountWalls(bool[,] w, int[,] h, int r, int c)
        {
            int counter = 0;
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    h[i, j] = 0;

                    if (!w[i, j])
                    {
                        if (i < r - 1 && w[i + 1, j]) h[i, j]++;
                        if (i > 0 && w[i - 1, j]) h[i, j]++;
                        if (j < c - 1 && w[i, j + 1]) h[i, j]++;
                        if (j > 0 && w[i, j - 1]) h[i, j]++;

                        continue;
                    }

                    if (i < r - 1 && w[i + 1, j]) counter++;
                    if (j < c - 1 && w[i, j + 1]) counter++;
                }
            }

            return counter;
        }

        #region Support

        public IEnumerable<Action<TextReader, TextWriter>> Solvers
        {
            get
            {
                yield return Solve;
            }
        }

        public IEnumerable<KeyValuePair<string, string>> TestData
        {
            get
            {
                yield return new KeyValuePair<string, string>(@"1
4 4 12", @"Case #1: 2");

               
                yield return new KeyValuePair<string, string>(@"10
3 3 0
3 3 1
3 3 2
3 3 3
3 3 4
3 3 5
3 3 6
3 3 7
3 3 8
3 3 9", @"Case #1: 0
Case #2: 0
Case #3: 0
Case #4: 0
Case #5: 0
Case #6: 0
Case #7: 3
Case #8: 6
Case #9: 8
Case #10: 12");
               
                
                yield return new KeyValuePair<string, string>(@"4
2 3 6
4 1 2
3 3 8
5 2 0", @"Case #1: 7
Case #2: 0
Case #3: 8
Case #4: 0");
            }
        }

       
        static void Main(string[] args)
        {
            var p = new Round1BProblem2();

            int testNumber = 2;
            string directory = @"c:\Downloads";
            string fileName = "B-small-attempt" + testNumber;

            string inputFile = Path.Combine(directory, fileName) + ".in";
            string outputFile = Path.Combine(directory, fileName) + ".out";

            using (var input = new StreamReader(inputFile))
            using (var output = new StreamWriter(outputFile))
            {
                p.Solve(input, output);
            }
        }
      

        #endregion
    }
}

