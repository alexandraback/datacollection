using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Magic_Trick
{
    class Program
    {
        static void Main(string[] args)
        {
            int T;
            List<string> possibles = new List<string>();

            int.TryParse(Console.ReadLine(), out T);

            for (int i = 0; i < T; i++)
            {
                possibles.Clear();

                int userChoice;
                string[] row1 = new string[4];
                string[] row2 = new string[4];
                string[] trash;

                int.TryParse(Console.ReadLine(), out userChoice);

                for (int j = 0; j < 4; j++)
                {
                    if (userChoice - 1 == j)    // On the right row
                        row1 = Console.ReadLine().Split();
                    else
                        trash = Console.ReadLine().Split();
                }

                int.TryParse(Console.ReadLine(), out userChoice);

                for (int j = 0; j < 4; j++)
                {
                    if (userChoice - 1 == j)    // On the right row
                        row2 = Console.ReadLine().Split();
                    else
                        trash = Console.ReadLine().Split();
                }

                // Check for the numbers that overlap
                for (int j = 0; j < 4; j++)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        if (row1[j] == row2[k])
                        {
                            possibles.Add(row1[j]);
                        }
                    }
                }

                if (possibles.Count == 1)
                    Console.WriteLine("Case #" + (i + 1) + ": " + possibles[0]);
                else if (possibles.Count == 0)
                    Console.WriteLine("Case #" + (i + 1) + ": " + "Volunteer cheated!");
                else
                    Console.WriteLine("Case #" + (i + 1) + ": " + "Bad magician!");
            }
        }
    }
}
