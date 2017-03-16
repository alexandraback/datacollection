using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Task_B
{
    class Solution
    {
        static void Main()
        {
            string inputName = "B-small-attempt0.in";
            StreamReader input = new StreamReader(inputName);
            StreamWriter output = new StreamWriter("output", false);

            int T = int.Parse(input.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] str1 = input.ReadLine().Split(' ');
                string[] str2 = input.ReadLine().Split(' ');
                int B = int.Parse(str1[0]);
                int N = int.Parse(str1[1]);
                int []bs=new int[B];
                for (int b = 0; b < B; b++) bs[b] = int.Parse(str2[b]);
                output.WriteLine("Case #{0}: {1}", t, Solve(N, B, bs));
            }

            input.Close();
            output.Close();
        }

        static int Solve(int inQueue, int count, int[] barbers)
        {
            //long[] mins = new long[count];
            //for (int i = 0; i < count; i++) mins[i] = barbers[i] * (inQueue - 1);
            if (inQueue <= count) return inQueue;
            int cycle = -1;
            int[] current = (int[])barbers.Clone();
            int currentQueue = inQueue - count;
            int pushRes = -3;
            while (currentQueue > 0)
            {
                Work(current, count);
                pushRes = Push(ref currentQueue, current, count, barbers);
                if (pushRes == -1)
                {
                    cycle = inQueue - currentQueue - 1;
                    currentQueue = inQueue % cycle - 1;
                    if (currentQueue < 0) currentQueue += cycle;
                }
            }
            if (pushRes == -1) return 1;
            return pushRes;
        }

        static int FindMinIndex(int[] array)
        {
            int len = array.Length;
            if (len == 1) return 0;
            int ans = 0;
            for (int i = 1; i < len; i++)
                if (array[i] < array[ans]) ans = i;
            return ans;
        }

        static int Push(ref int count, int[] current, int len,int[]start)
        {
            bool NonEmptyFlag = false;
            bool InsFlag = false;
            int inserted=-2;
            for (int i = 0; i < len; i++)
            {
                if (current[i] == 0)
                {
                    if (!InsFlag)
                    {
                        count--;
                        current[i] = start[i];
                        InsFlag = true;
                        inserted = i + 1;
                    }
                }
                else NonEmptyFlag = true;
                if (InsFlag && NonEmptyFlag) break;
            }
            if (InsFlag && NonEmptyFlag) return inserted;
            if (!InsFlag && NonEmptyFlag) return 0;
            return -1;
        }
        static void Work(int[] current, int len)
        {
            int min = FindMinIndex(current);
            min = current[min];
            for (int i = 0; i < len; i++) current[i] -= min;
        }
    }
}