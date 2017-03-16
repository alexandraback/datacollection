using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication
{
    public static class MyExtensions
    {
        public static bool NextPermutation<T>(this List<T> perm) where T : IComparable
        {
            int end = perm.Count() - 1;
            if (end <= 0) return false;

            int last = end;
            while (true)
            {
                int pos = last--;
                if (perm[last].CompareTo(perm[pos]) < 0)
                {
                    int i = end + 1;
                    while (perm[last].CompareTo(perm[--i]) >= 0) { }
                    var tmp = perm[last]; perm[last] = perm[i]; perm[i] = tmp;
                    perm.Reverse(pos, end - pos + 1);
                    return true;
                }
                if (last == 0)
                {
                    perm.Reverse();
                    return false;
                }
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string input = "../../A-large.in";

            using (TextReader tr = new StreamReader(input))
            using (TextWriter tw = new StreamWriter(input.Replace(".in", ".out.txt")))
            {
                int T = int.Parse(tr.ReadLine());
                for (int _c = 1; _c <= T; _c++)
                {

                    List<string> seq = new List<string>();

                    //TODO
                    int N = int.Parse(tr.ReadLine());
                    var parties = tr.ReadLine().Split(' ').Select((x, index) => new { name = ((char)('A' + index)).ToString(), num = int.Parse(x) }).OrderByDescending(z => z.num).ToList();

                    while (parties.Where(x => x.num > 0).Any())
                    {
                        if(parties.Select(x => x.num).Sum() == 3)
                        {
                            seq.Add(parties[0].name);
                            parties[0] = new { name = parties[0].name, num = parties[0].num - 1 };
                        }
                        else
                        {
                            seq.Add(parties[0].name + parties[1].name);
                            parties[0] = new { name = parties[0].name, num = parties[0].num - 1 };
                            parties[1] = new { name = parties[1].name, num = parties[1].num - 1 };
                        }
                        parties = parties.OrderByDescending(x => x.num).ToList();
                    }


                    string ans = string.Join(" ", seq);

                    Console.WriteLine($"Case #{_c}: {ans}");
                    tw.WriteLine($"Case #{_c}: {ans}");
                }
            }
        }
    }
}
