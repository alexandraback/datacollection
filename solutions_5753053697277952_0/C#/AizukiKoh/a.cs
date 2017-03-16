using System;

namespace GCJ._2016.C
{
    class a
    {
        static string[] charList = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
        static void Main(string[] args)
        {
            var T = int.Parse(System.Console.ReadLine().Trim());
            for (int i = 0; i < T; ++i)
            {
                var line = Console.ReadLine().Trim();
                Console.WriteLine("Case #{0:D}: {1}", i + 1, solve(int.Parse(line)));
            }
        }

        static string solve(int n)
        {
            var line = Console.ReadLine().Trim();
            var list = line.Split(' ');
            var nList = new int[n];
            var sum = 0;
            for (var i = 0; i < n; ++i)
            {
                nList[i] = int.Parse(list[i]);
                sum += nList[i];
            }
            var rtn = "";
            while(sum > 0)
            {
                var tmp = getMax(sum, ref nList, false);
                sum -= tmp.Length;
                rtn += tmp + " ";
            }
            return rtn.Trim();
        }

        private static string getMax(int sum, ref int[] nList, bool isSecond)
        {
            if (sum > 2)
            {
                var max = 0;
                var pos = -1;
                for (var i = 0; i < nList.Length; ++i)
                {
                    if (nList[i] > max)
                    {
                        max = nList[i];
                        pos = i;
                    }
                }
                --nList[pos];
                if (isSecond)
                {
                    return charList[pos];
                }
                else
                {
                    if (sum > 3)
                    {
                        return charList[pos] + getMax(sum, ref nList, true);
                    }
                    else
                    {
                        return charList[pos];
                    }
                }
            }
            else
            {
                var pos = -1;
                for (var i = 0; i < nList.Length; ++i)
                {
                    if (nList[i] > 0)
                    {
                        if (pos < 0)
                        {
                            pos = i;
                        }
                        else
                        {
                            return charList[pos] + charList[i];
                        }
                    }
                }
                return "";
            }
        }
    }
}
