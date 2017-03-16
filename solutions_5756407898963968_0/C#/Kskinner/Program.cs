using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    public class Problem
    {        
        public string Solve()
        {
            HashSet<int> candidates = null;

            int row1 = ReadInt();
            for (int i = 1; i <= 4; i++)
            {
                var ar = ReadArray<int>();
                if (i == row1)
                {
                    candidates = new HashSet<int>(ar);
                }
            }
            Debug.Assert(candidates != null);

            int row2 = ReadInt();
            for (int i = 1; i <= 4; i++)
            {
                var ar = ReadArray<int>();
                if (i == row2)
                {
                    candidates.IntersectWith(ar);
                }
            }

            if (candidates.Count == 0)
            {
                return "Volunteer cheated!";
            }
            if (candidates.Count > 1)
            {
                return "Bad magician!";
            }

            return candidates.First().ToString();
        }

        static StreamReader reader;

        static void Main(string[] args)
        {
            string filename = args.Length > 0 ? args[0] : "test.in";
            string outFileName = filename.Replace(".in", ".out");

            using (reader = File.OpenText(filename))
            using (var outFile = File.CreateText(outFileName))
            {
                int T = ReadInt();
                Console.WriteLine("{0} test cases", T);

                for (int tc = 1; tc <= T; tc++)
                {
                    Console.WriteLine("Starting test case {0}", tc);
                    var problem = new Problem();
                    string solution = problem.Solve();

                    outFile.WriteLine("Case #{0}: {1}", tc, solution);
                    Console.WriteLine("Case #{0}: {1}", tc, solution);
                }
            }
        }

        #region Readers

        private static string ReadLine()
        {
            return reader.ReadLine();
        }

        private static int ReadInt()
        {
            return int.Parse(ReadLine());
        }

        private static T Read<T>()
        {
            return (T)Convert.ChangeType(ReadLine(), typeof(T));
        }

        private static T[] ReadArray<T>()
        {
            return ReadLine().Split(' ').Select(v => (T)Convert.ChangeType(v, typeof(T))).ToArray();
        }

        #endregion
    }
}
