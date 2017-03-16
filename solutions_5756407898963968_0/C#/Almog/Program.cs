using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.IO;

namespace _1_MagicTrick
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream fsInput = new FileStream(args[0], FileMode.Open, FileAccess.Read);
            StreamReader reader = new StreamReader(fsInput);
            FileStream fsOutput = new FileStream(args[0] + ".out", FileMode.Create, FileAccess.Write);
            StreamWriter writer = new StreamWriter(fsOutput);


            string sCases = reader.ReadLine();

            int iCases = int.Parse(sCases);

            for (int i = 0; i < iCases; i++)
            {
                int A1 = int.Parse(reader.ReadLine());
                A1--;
                int[,] M1 = GetMatrix(reader);

                int A2 = int.Parse(reader.ReadLine());
                A2--;
                int[,] M2 = GetMatrix(reader);

                int matches = 0;
                int match = 0;
                for (int r1 = 0; r1 < 4; r1++)
                {
                    for (int r2 = 0; r2 < 4; r2++)
                    {
                        if (M1[A1,r1] == M2[A2, r2])
                        {
                            matches++;
                            match = M1[A1,r1];
                        }
                    }
                }

                string result;
                switch (matches)
                {
                    case 0:
                        result = "Volunteer cheated!";
                        break;
                    case 1:
                        result = match.ToString();
                        break;
                    default:
                        result = "Bad magician!";
                        break;
                }

                writer.WriteLine("Case #{0}: {1}", i + 1, result);
            }

            reader.Close();
            writer.Close();

        }

        private static int[,] GetMatrix(StreamReader reader)
        {
            int[,] M = new int[4, 4];
            for (int r = 0; r < 4; r++)
            {
                string sr = reader.ReadLine();
                string[] ar = sr.Split(' ');
                for (int c = 0; c < 4; c++)
                {
                    M[r, c] = int.Parse(ar[c]);
                }
            }
            return M;
        }
    }
}
