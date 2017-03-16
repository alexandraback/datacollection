using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Problem_B
{
    class Program
    {
        static void Main(string[] args)
        {
            // Num of cases:
            int T = Int32.Parse(Console.ReadLine());

            for (int i = 1; i <= T; i++)
            {
                string temp = Console.ReadLine();
                string[] temp2 = temp.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                int R = Int32.Parse(temp2[0]);
                int C = Int32.Parse(temp2[1]);
                int N = Int32.Parse(temp2[2]);
                

                HandleCase(i, R, C, N);
            }
        }


        static void HandleCase(int case_num, int R, int C, int N)
        {
            bool[][] arr = new bool[R][];
            for (int i = 0; i < R; i++)
            {
                arr[i] = new bool[C];
            }

            int total = FillArray(arr, 0, 0, N);

            Console.WriteLine("Case #" + case_num.ToString() + ": " + total.ToString());
        }


        static int FillArray(bool[][] arr, int i, int j, int N)
        {
            if (N == 0)
                return ComputeUnhappiness(arr);

            if ((i >= arr.Length) || (j >= arr[i].Length))
                return -1;
            
            int next_i = i;
            int next_j = j + 1;
            if (next_j == arr[i].Length)
            {
                next_i++;
                next_j = 0;
            }

            bool[][] temp = CloneArray(arr);
            temp[i][j] = true;
            int res_use = FillArray(temp, next_i, next_j, N - 1);
            int res_dont_use = FillArray(arr, next_i, next_j, N);

            if ((res_use == -1) && (res_dont_use == -1))
                return -1;
            else if (res_use == -1)
                return res_dont_use;
            else if (res_dont_use == -1)
                return res_use;
            else
                return Math.Min(res_use, res_dont_use);
        }


        static bool[][] CloneArray(bool[][] arr)
        {
            bool[][] arr2 = new bool[arr.Length][];

            for (int i = 0; i < arr.Length; i++)
            {
                arr2[i] = new bool[arr[i].Length];

                for (int j = 0; j < arr[i].Length; j++)
                {
                    arr2[i][j] = arr[i][j];
                }
            }

            return arr2;
        }

        static int ComputeUnhappiness(bool[][] arr)
        {
            int total = 0;

            for (int i = 0; i < arr.Length; i++)
            {
                for (int j = 0; j < arr[i].Length; j++)
                {
                    for (int orientation = 0; orientation < 2; orientation++)       // 0 = horizontal, 1 = vertical
                    {
                        // if valid:
                        if ((i == 0) && (orientation == 0))
                            continue;
                        if ((j == 0) && (orientation == 1))
                            continue;

                        if (orientation == 0)
                        {
                            if (arr[i - 1][j] && arr[i][j])
                                total++;
                        }
                        else if (orientation == 1)
                        {
                            if (arr[i][j-1] && arr[i][j])
                                total++;
                        }
                    }
                }
            }

            return total;
        }
    }
}
