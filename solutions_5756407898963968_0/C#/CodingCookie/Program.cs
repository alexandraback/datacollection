using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCode
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader(@"C:\Temp\GoogleCode\GoogleCode\bin\Debug\a.txt");
            StreamWriter writer = new StreamWriter(@"C:\Temp\GoogleCode\GoogleCode\bin\Debug\b.txt", false);

            int numCases = int.Parse(reader.ReadLine());
            for (int c = 1; c <= numCases; c++)
            {
                int choice1 = int.Parse(reader.ReadLine());
                int[][] board = new int[4][];
                for (int i = 0; i < 4; i++)
                {
                    board[i] = reader.ReadLine().Split(' ').Select(p => int.Parse(p)).ToArray();
                }

                int[] possibleValues = board[choice1-1];

                int choice2 = int.Parse(reader.ReadLine());
                int[][] board2 = new int[4][];
                for (int i = 0; i < 4; i++)
                {
                    board2[i] = reader.ReadLine().Split(' ').Select(p => int.Parse(p)).ToArray();
                }

                int[] possibleValues2 = board2[choice2 - 1];

                int[] newValues = possibleValues.Intersect(possibleValues2).ToArray();

                if (newValues.Count() == 1)
                {
                    writer.WriteLine(string.Format("Case #{0}: {1}", c, newValues[0]));
                }

                if (newValues.Count() >= 2)
                {
                    writer.WriteLine(string.Format("Case #{0}: Bad magician!", c));
                }

                if (newValues.Count() == 0)
                {
                    writer.WriteLine(string.Format("Case #{0}: Volunteer cheated!", c));
                }
            }

            writer.Flush();
            writer.Close();            
        }
    }

}
