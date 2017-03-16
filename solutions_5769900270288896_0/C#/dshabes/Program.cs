using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2015_1B_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var parts = Console.ReadLine().Split().Select(long.Parse).ToArray();
                var R = parts[0];
                var C = parts[1];
                if (R > C)
                {
                    var t = R;
                    R = C;
                    C = t;
                }
                var N = parts[2];

                var odd = R % 2 != 0 && C % 2 != 0;
                var free = (R * C + 1) / 2;
                var result = 0L;
                var excess = N - free;
                if (excess > 0)
                {
                    if (R == 1)
                    {
                        result = excess * 2;
                        if (C % 2 == 0)
                            result--;
                    }
                    else if (R == 2)
                    {
                        if (excess <= 2)
                            result = excess * 2;
                        else
                            result = excess * 3 - 2;
                    }
                    else if (R == 3)
                    {
                        if (C == 3)
                        {
                            if (excess <= 2)
                                result = excess * 3;
                            else if (excess == 3)
                                result = 8;
                            else if (excess == 4)
                                result = 12;
                        }
                        else if (C == 4)
                        {
                            if (excess <= 2)
                                result = excess * 2;
                            else if (excess <= 5)
                                result = excess * 3 - 2;
                            else
                                result = excess * 4 - 7;
                        }
                        else
                        {
                            if (excess <= 6)
                                result = excess * 3;
                            else
                                result = excess * 3 + 1;
                        }
                    }
                    else if (R == 4)
                    {
                        if (excess <= 2)
                            result = excess * 2;
                        else if (excess <= 6)
                            result = excess * 3 - 2;
                        else
                            result = excess * 4 - 8;
                    }
                }

                Console.WriteLine("Case #{0}: {1}", testN, result);
            }
        }
    }
}
