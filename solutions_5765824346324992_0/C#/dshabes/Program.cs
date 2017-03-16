using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2015_1A_B
{
    class Program
    {
        static long gcd(long a, long b)
        {
            if (b == 0)
                return a;
            return gcd(b, a % b);
        }

        static long lcm(long a, long b)
        {
            return (a * b) / gcd(a, b);
        }

        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var parts = Console.ReadLine().Split().Select(long.Parse).ToArray();
                var B = parts[0];
                var N = parts[1];
                var periods = Console.ReadLine().Split().Select(long.Parse).ToArray();
                var totalLcm = periods.Aggregate(1L, (acc, n) => lcm(acc, n));
                var totalPeriod = periods.Sum(n => totalLcm / n);
                N = ((N - 1) % totalPeriod) + 1;
                if (N > B)
                {
                    var queues = periods.ToArray();
                    N -= B;
                    while (true)
                    {
                        var step = long.MaxValue;
                        var index = 0;
                        for (int i = 0; i < queues.Length; i++)
                        {
                            if (queues[i] < step)
                            {
                                step = queues[i];
                                index = i;
                            }
                        }
                        for (int i = 0; i < queues.Length; i++)
                        {
                            queues[i] -= step;
                        }
                        queues[index] = periods[index];
                        N--;
                        if (N == 0)
                        {
                            N = index + 1;
                            break;
                        }
                    }
                }
                Console.WriteLine("Case #{0}: {1}", testN, N);
            }
        }
    }
}
