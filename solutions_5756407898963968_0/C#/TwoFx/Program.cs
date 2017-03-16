using System;
using System.Linq;
using System.IO;

namespace _20140_Magic_Trick
{
    class Program
    {
        private const bool DEBUG = false;
        static void debug()
        {

        }

        static string solveCase(Func<string> readLine)
        {
            int[] guesses = new int[2];
            int[][][] rows = new int[2][][];

            for (int r = 0; r < 2; r++)
            {
                guesses[r] = int.Parse(readLine()) - 1;
                rows[r] = new int[4][];
                for (int s = 0; s < 4; s++)
                {
                    rows[r][s] = readLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                }
            }
            int[] nums = Enumerable.Range(1, 16).Where(n => rows[0][guesses[0]].Contains(n) && rows[1][guesses[1]].Contains(n)).ToArray();
            if (nums.Length == 0)
            {
                return "Volunteer cheated!";
            }
            else if (nums.Length == 1)
            {
                return nums[0].ToString();
            }
            else
            {
                return "Bad magician!";
            }
        }

        static void Main(string[] args)
        {
            if (DEBUG)
            {
                debug();
            }
            else
            {
                GCJ.Initialize();
                GCJ.SolveAll(solveCase);
            }
            Console.ReadKey();
        }
    }

    static class GCJ
    {
        private static StreamReader inf;
        private static StreamWriter outf;

        private delegate void o(string format, params object[] args);
        private static o Output;

        public static void Initialize()
        {
            Console.Write("Input file: ");
            inf = new StreamReader(Console.ReadLine());
            Console.Write("Output file: ");
            outf = new StreamWriter(Console.ReadLine());
            Output = Console.WriteLine;
            Output += outf.WriteLine;
        }

        public static void SolveAll(Func<Func<string>, string> calc)
        {
            int cases = int.Parse(inf.ReadLine());
            for (int @case = 1; @case <= cases; @case++)
            {
                Output("Case #{0}: {1}", @case, calc(inf.ReadLine));
            }
            inf.Close();
            outf.Close();
            Console.WriteLine("Eureka!");
        }
    }
}
