using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemA
{
    class Program
    {
        public static void Main()
        {
            int T = ReadInt();
            int[,,] Cards = new int[2, 4, 4];
            for (int t = 1; t <= T; t++)
            {
                int Row1 = ReadInt();
                for (int i = 0; i < 4; i++)
                {
                    int[] line = ReadInts();
                    Cards[0, i, 0] = line[0];
                    Cards[0, i, 1] = line[1];
                    Cards[0, i, 2] = line[2];
                    Cards[0, i, 3] = line[3];
                }
                int Row2 = ReadInt();
                for (int i = 0; i < 4; i++)
                {
                    int[] line = ReadInts();
                    Cards[1, i, 0] = line[0];
                    Cards[1, i, 1] = line[1];
                    Cards[1, i, 2] = line[2];
                    Cards[1, i, 3] = line[3];
                }

                int result = CheckTable(Cards, Row1, Row2);

                if (result > 0)
                    Console.WriteLine("Case #{0}: {1}", t, result.ToString());
                else if (result == 0)
                    Console.WriteLine("Case #{0}: {1}", t, "Bad magician!");
                else if (result == -1)
                    Console.WriteLine("Case #{0}: {1}", t, "Volunteer cheated!");
                else if (result == -2)
                    Console.WriteLine("Case #{0}: {1}", t, "Error!");
            }
        }

        public static int CheckTable(int[,,] Cards, int Row1, int Row2)
        {
            int C11 = Cards[0, Row1 - 1, 0];
            int C12 = Cards[0, Row1 - 1, 1];
            int C13 = Cards[0, Row1 - 1, 2];
            int C14 = Cards[0, Row1 - 1, 3];

            int C21 = Cards[1, Row2 - 1, 0];
            int C22 = Cards[1, Row2 - 1, 1];
            int C23 = Cards[1, Row2 - 1, 2];
            int C24 = Cards[1, Row2 - 1, 3];

            int Check1 = Convert.ToInt32(C11 == C21) + Convert.ToInt32(C11 == C22) + Convert.ToInt32(C11 == C23) + Convert.ToInt32(C11 == C24);
            int Check2 = Convert.ToInt32(C12 == C21) + Convert.ToInt32(C12 == C22) + Convert.ToInt32(C12 == C23) + Convert.ToInt32(C12 == C24);
            int Check3 = Convert.ToInt32(C13 == C21) + Convert.ToInt32(C13 == C22) + Convert.ToInt32(C13 == C23) + Convert.ToInt32(C13 == C24);
            int Check4 = Convert.ToInt32(C14 == C21) + Convert.ToInt32(C14 == C22) + Convert.ToInt32(C14 == C23) + Convert.ToInt32(C14 == C24);

            // Volunteer cheated!
            //if ((Check1 != 1) || (Check2 != 1) || (Check3 != 1) || (Check4 != 1))
            if (Check1 + Check2 + Check3 + Check4 < 1)
                return -1;

            // Bad magician!
            //if (Check1 + Check2 + Check2 + Check2 < 4)
            if (Check1 + Check2 + Check3 + Check4 > 1)
                return 0;

            // Number
            if ((C11 == C21) || (C11 == C22) || (C11 == C23) || (C11 == C24))
                return C11;
            else if ((C12 == C21) || (C12 == C22) || (C12 == C23) || (C12 == C24))
                return C12;
            else if ((C13 == C21) || (C13 == C22) || (C13 == C23) || (C13 == C24))
                return C13;
            else if ((C14 == C21) || (C14 == C22) || (C14 == C23) || (C14 == C24))
                return C14;

            return -2; // -1

            /*string t = t_orig.Replace('T', 'X');

            // check rows
            if (((t[0] == 'X') && (t[1] == 'X') && (t[2] == 'X') && (t[3] == 'X')) ||
                ((t[4] == 'X') && (t[5] == 'X') && (t[6] == 'X') && (t[7] == 'X')) ||
                ((t[8] == 'X') && (t[9] == 'X') && (t[10] == 'X') && (t[11] == 'X')) ||
                ((t[12] == 'X') && (t[13] == 'X') && (t[14] == 'X') && (t[15] == 'X')))
                return 0;

            // check columns
            if (((t[0] == 'X') && (t[4] == 'X') && (t[8] == 'X') && (t[12] == 'X')) ||
                ((t[1] == 'X') && (t[5] == 'X') && (t[9] == 'X') && (t[13] == 'X')) ||
                ((t[2] == 'X') && (t[6] == 'X') && (t[10] == 'X') && (t[14] == 'X')) ||
                ((t[3] == 'X') && (t[7] == 'X') && (t[11] == 'X') && (t[15] == 'X')))
                return 0;
               
            // check diag
            if (((t[0] == 'X') && (t[5] == 'X') && (t[10] == 'X') && (t[15] == 'X')) ||
                ((t[3] == 'X') && (t[6] == 'X') && (t[9] == 'X') && (t[12] == 'X')))
                    return 0;

            // O
            t = t_orig.Replace('T', 'O');

            // check rows
            if (((t[0] == 'O') && (t[1] == 'O') && (t[2] == 'O') && (t[3] == 'O')) ||
                ((t[4] == 'O') && (t[5] == 'O') && (t[6] == 'O') && (t[7] == 'O')) ||
                ((t[8] == 'O') && (t[9] == 'O') && (t[10] == 'O') && (t[11] == 'O')) ||
                ((t[12] == 'O') && (t[13] == 'O') && (t[14] == 'O') && (t[15] == 'O')))
                return 1;

            // check columns
            if (((t[0] == 'O') && (t[4] == 'O') && (t[8] == 'O') && (t[12] == 'O')) ||
                ((t[1] == 'O') && (t[5] == 'O') && (t[9] == 'O') && (t[13] == 'O')) ||
                ((t[2] == 'O') && (t[6] == 'O') && (t[10] == 'O') && (t[14] == 'O')) ||
                ((t[3] == 'O') && (t[7] == 'O') && (t[11] == 'O') && (t[15] == 'O')))
                return 1;

            // check diag
            if (((t[0] == 'O') && (t[5] == 'O') && (t[10] == 'O') && (t[15] == 'O')) ||
                ((t[3] == 'O') && (t[6] == 'O') && (t[9] == 'O') && (t[12] == 'O')))
                return 1;

            if (!t.Contains('.'))
                return 2;

            return 3;*/
        }

        #region Library

        static string ReadLine()
        {
            return Console.ReadLine();
        }

        static string[] ReadWords()
        {
            return ReadLine().Split();
        }

        static int ReadInt()
        {
            return int.Parse(ReadLine());
        }

        static long ReadLong()
        {
            return Int64.Parse(ReadLine());
        }

        static int[] ReadInts()
        {
            return Array.ConvertAll(ReadWords(), int.Parse);
        }

        static long[] ReadLongs()
        {
            return Array.ConvertAll(ReadWords(), Int64.Parse);
        }

        static double ReadDouble()
        {
            return Double.Parse(ReadLine(), System.Globalization.NumberStyles.AllowExponent | System.Globalization.NumberStyles.Number);
        }

        static double[] ReadDoubles()
        {
            return Array.ConvertAll(ReadWords(), double.Parse);
        }

        #endregion
    }
}
