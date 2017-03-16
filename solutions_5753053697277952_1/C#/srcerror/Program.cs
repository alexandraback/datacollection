using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var filenameIn = @"c:\Projects\test\CodeJamApp\Tasks\A-large.in ";
            var filenameOut = @"c:\Projects\test\CodeJamApp\Tasks\A-large.in.out";
            var fileIn = File.ReadAllLines(filenameIn);
            using (var fout = new StreamWriter(filenameOut))
            {
                var L = int.Parse(fileIn[0]);
                for (int i = 0; i < L; i++)
                {
                    var res = Task1(fileIn[2*i+1], fileIn[2*i + 2]);
                    fout.WriteLine("Case #{0}: {1}", i+1, res);
                }
            }
        }

        public class Party
        {
            public int Index { get; set; }
            public char Name { get { return Alphabet[Index]; } }
            public int Count { get; set; }
        }
        static char[] Alphabet = new char[] { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
        static string Task1(string sN, string parties)
        {
            var N = int.Parse(sN);
            int cnt = 0;
            var pp = parties.Split(' ').Select(x => new Party() { Index = cnt++, Count = int.Parse(x) }).ToList();

            // step #1. Sort
            var sorted = pp.OrderByDescending(x => x.Count).ToList();
            // step #2. reduce top

            var sb = new StringBuilder();
            var p2 = sorted[1].Count;
            while (sorted[0].Count > p2)
            {
                var p1 = sorted[0];
                p1.Count--;
                sb.AppendFormat("{0} ", p1.Name);

            }
            for (int i = sorted.Count-1; i > 1; i--)
            {
                while (sorted[i].Count > 0)
                {
                    var pi = sorted[i];
                    pi.Count--;
                    sb.AppendFormat("{0} ", pi.Name);
                }
            }
            // last step 2 parties
            for (int i = 0; i < sorted[0].Count; i++)
            {
                sb.AppendFormat("{0}{1} ", sorted[0].Name, sorted[1].Name);
            }


            return sb.ToString().TrimEnd();
        }
    }
}
