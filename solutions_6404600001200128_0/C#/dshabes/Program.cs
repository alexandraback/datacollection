using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2015_1A_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var snapshotsCount = int.Parse(Console.ReadLine());
                var parts = Console.ReadLine().Split().Select(int.Parse).ToArray();
                var arbitrary = 0;
                var minSpeed = 0;
                for (int i = 0; i < snapshotsCount - 1; i++)
                {
                    var speed = parts[i] - parts[i + 1];
                    if (speed > 0)
                        arbitrary += speed;
                    if (speed > minSpeed)
                        minSpeed = speed;
                }
                var constRated = 0;
                for (int i = 0; i < snapshotsCount - 1; i++)
                {
                    constRated += Math.Min(minSpeed, parts[i]);
                }
                Console.WriteLine("Case #{0}: {1} {2}", testN, arbitrary, constRated);
            }
        }
    }
}
