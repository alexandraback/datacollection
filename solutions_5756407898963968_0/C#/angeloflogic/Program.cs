using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MagicTrick
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = Convert.ToInt32(Console.ReadLine());
            for (int t = 1; t <= T; ++t)
            {
                var n1 = Convert.ToInt32(Console.ReadLine());
                var row1 = Enumerable.Range(0, 4).Select(n => Console.ReadLine()).ToList()[n1 - 1].Split(' ').ToList();
                var n2 = Convert.ToInt32(Console.ReadLine());
                var row2 = Enumerable.Range(0, 4).Select(n => Console.ReadLine()).ToList()[n2 - 1].Split(' ').ToList();
                var common = row1.Intersect(row2).ToList();
                Console.Write("Case #{0}: ", t);
                if (common.Count == 0)
                    Console.WriteLine("Volunteer cheated!");
                else if (common.Count == 1)
                    Console.WriteLine(common[0]);
                else
                    Console.WriteLine("Bad magician!");
            }
        }
    }
}
