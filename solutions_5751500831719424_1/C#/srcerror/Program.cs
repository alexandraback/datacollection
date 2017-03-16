using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace BaseApp
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = @"d:\Work\CodeJam\02\A-large.in";
            string output = @"d:\Work\CodeJam\02\A-large.out";

            using (var sin = new StreamReader(input))
            {
                using (var sout = new StreamWriter(output, false))
                {
                    var s = sin.ReadLine();
                    var N = long.Parse(s);
                    for (long i = 1; i <= N; i++)
                    {
                        string result = Task1(sin);
                        //string result = Task2(sin);
                        //string result = Task3(sin);
                        //string result = Task4(sin);
                        sout.WriteLine("Case #{0}: {1}", i, result);
                    }
                }
            }
        }

        private static string Task3(StreamReader sin)
        {

            return "";
        }



        private static string Task2(StreamReader sin)
        {

            return "";
        }

        public class Item
        {
            public char C { get; set; }
            public int Count { get; set; }

            public override string ToString()
            {
                return string.Format("[{0}:{1}]", C, Count);
            }
        }

        public static string ConvMask(List<Item> l)
        {
            var s = new string(l.Select(t => t.C).ToArray());
            return s;
        }

        private static string Task1(StreamReader sin)
        {
            var N = int.Parse(sin.ReadLine());
            var All = new List<List<Item>>();
            for (int i = 0; i < N; i++)
            {
                var s = sin.ReadLine();

                Item c = new Item();
                var st = s;
                var mask = new List<Item>();
                c.C = st[0];
                c.Count = 1;
                int j = 1;
                mask.Add(c);
                while (j < st.Length)
                {
                    if (st[j] != c.C)
                    {
                        c = new Item() { C = st[j], Count = 1 };
                        mask.Add(c);
                    }
                    else
                    {
                        c.Count++;
                    }
                    j++;
                }
                //for (int k = 0; k < mask.Count; k++)
                //{
                //    Console.WriteLine(s +" " +mask[k]);
                //}
                All.Add(mask);
            }

            var lost = "Fegla won";

            var sss = ConvMask(All[0]);
            bool Fecla = All.All(t => ConvMask(t) == sss);
            if (!Fecla)
            {
                //Console.WriteLine(sss + " " + "lost");
                return lost;
            }

            /// masks are the same
            /// 

            int moves = 0;
            for (int i = 0; i < sss.Length; i++)
            {
                var items = All.Select(t => t[i]).ToList();
                int min = items.Min(t => t.Count);
                int max = items.Max(t => t.Count);
                int minmoves = int.MaxValue;
                for (int j = min; j <= max; j++)
                {
                    int m = items.Sum(t => Math.Abs(t.Count - j));
                    if (m < minmoves) minmoves = m;
                }
                moves += minmoves;
            }
            
            

            return moves.ToString();
        }

    }
}
