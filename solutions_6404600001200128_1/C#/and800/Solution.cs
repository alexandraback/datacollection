using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Task_A
{
    class Solution
    {
        static void Main()
        {
            string inputName = "A-large.in";
            StreamReader input = new StreamReader(inputName);
            StreamWriter output = new StreamWriter("output", false);

            int T = int.Parse(input.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                int N=int.Parse(input.ReadLine());
                string[] str = input.ReadLine().Split(' ');
                int[] m = new int[N];
                for (int i = 0; i < N; i++) m[i] = int.Parse(str[i]);
                long[] res = Solve(N, m);
                output.WriteLine("Case #{0}: {1} {2}", t, res[0], res[1]);
            }

            input.Close();
            output.Close();
        }

        static long[] Solve(int count, int[] input)
        {
            long[] res = { Unfixed(count, input), Fixed(count, input) };
            return res;
        }

        static long Unfixed(int count, int[] input)
        {
            int current = input[0];
            long res = 0;
            for (int c = 1; c < count; c++)
            {
                if (input[c] < current)
                {
                    res += (current - input[c]);

                }
                current = input[c];
            }
            return res;
        }

        static long Fixed(int count, int[] input)
        {
            int current = input[0];
            long res = 0;
            int maxRate=0;
            for (int c = 1; c < count; c++)
            {
                if (input[c] < current)
                {
                    int rate = current - input[c];
                    if (rate > maxRate) maxRate = rate;
                    
                }
                current = input[c];
            }
            for (int c = 0; c < count - 1; c++)
            {
                if (input[c] > maxRate) res += maxRate;
                else res += input[c];
            }
            return res;
        }
    }
}
