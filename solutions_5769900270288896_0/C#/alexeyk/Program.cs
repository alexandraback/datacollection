using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RoundB_B
{
    class Program
    {

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());

            for (int t = 0; t < T; t++)
            {
                var splitted = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

                int R = splitted[0];
                int C = splitted[1];
                int N = splitted[2];

                int res = 0;

                if (N > 1)
                {
                    bool[] occupation = new bool[R * C];

                    List<int> pointers = new List<int>();
                    for (int i = 0; i < N; i++)
                    {
                        pointers.Add(i);
                        occupation[i] = true;
                    }

                    int lastIndex = R * C - 1;
                    res = GetHappiness(occupation, R, C, pointers);

                    bool areDone = false;

                    while (!areDone)
                    {
                        if (pointers[N - 1] != lastIndex)
                        {
                            MovePointer(pointers, N - 1, pointers[N - 1] + 1, occupation);

                            res = Math.Min(res, GetHappiness(occupation, R, C, pointers));
                        }
                        else
                        {
                            int toMoveIndex = N - 1;
                            while (toMoveIndex >= 0 && (pointers[toMoveIndex] == R * C - 1 || occupation[pointers[toMoveIndex] + 1] == true))
                            {
                                toMoveIndex--;
                            }
                            if (toMoveIndex < 0)
                            {
                                areDone = true;
                                break;
                            }

                            MovePointer(pointers, toMoveIndex, pointers[toMoveIndex] + 1, occupation);
                            for (int i = toMoveIndex + 1; i < N; i++)
                            {
                                MovePointer(pointers, i, pointers[toMoveIndex] + (i - toMoveIndex), occupation);
                            }

                            res = Math.Min(res, GetHappiness(occupation, R, C, pointers));
                        }
                    }

                }


                Console.WriteLine("Case #{0}: {1}", t + 1, res);
            }
        }

        private static void MovePointer(List<int> pointers, int pIndex, int toPos, bool[] occupation)
        {
            occupation[pointers[pIndex]] = false;
            pointers[pIndex] = toPos;
            occupation[pointers[pIndex]] = true;

        }

        private static int GetHappiness(bool[] occupation, int R, int C, List<int> pointers)
        {
            int hap = 0;
            for (int i = 0; i < pointers.Count() - 1; i++)
            {
                if (pointers[i + 1] == pointers[i] + 1 && pointers[i + 1] / R == pointers[i] / R)
                {
                    hap++;
                }

                int nextRowNeighbor = pointers[i] + R;
                if (nextRowNeighbor < R * C && occupation[nextRowNeighbor] == true)
                {
                    hap++;
                }
            }

            return hap;
        }
    }
}
