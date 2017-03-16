using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam1C
{
    internal class Program
    {
        private static void Main(string[] args)
        {

            int t = int.Parse(Console.ReadLine());

            for (int i = 0; i < t; i++)
            {
                var n = int.Parse(Console.ReadLine());
                var senators = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                Console.Write("Case #{0}: ", i + 1);
                var sum = senators.Sum();

                int[] s = new int[2];

                while (sum > 0)
                {
                    var lst = max(senators);
                    foreach (var ind in lst)
                    {
                        senators[ind]--;
                        Console.Write(Convert.ToChar('A'+ind));
                        sum--;
                    }
                    Console.Write(' ');

                }
                Console.WriteLine();
            }
        }

        private static List<int> max(int[] arr)
        {
            int max = int.MinValue;
            List<int> maxi = new List<int>();
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] > max)
                {
                    max = arr[i];
                    maxi.Clear();
                    maxi.Add(i);
                }
                else if (arr[i] == max) 
                {
                    maxi.Add(i);
                }
            }
            if (maxi.Count > 2) maxi = maxi.GetRange(0, 1);
            return maxi;
        }

    }
}
