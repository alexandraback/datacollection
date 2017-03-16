using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class MagicTrick
    {
        static StreamReader Input;
        static StreamWriter Output;

        static string name;
        static long n;

        static Random rnd = new Random();

        static void Main(string[] args)
        {
            string classname = MethodBase.GetCurrentMethod().DeclaringType.Name;
            string testcase = Console.ReadLine();

            Input = new StreamReader("input/" + classname + "-" + testcase + ".txt");
            Output = new StreamWriter("output/" + classname + "-" + testcase + ".txt");

            long testcases = Convert.ToInt32(Input.ReadLine());

            for (long tc = 1; tc <= testcases; tc++)
            {
                int[] cards = new int[16];

                int row = Convert.ToInt32(Input.ReadLine());
                for (int r = 1; r <= 4; r++)
                {
                    string[] input = Input.ReadLine().Split(' ');

                    if (r == row)
                    {
                        for (int c = 0; c < 4; c++)
                        {
                            int number = Convert.ToInt32(input[c]);
                            ++cards[number - 1];
                        }
                    }
                }

                int possibleCards = 0;
                int solution = -1;
                row = Convert.ToInt32(Input.ReadLine());
                for (int r = 1; r <= 4; r++)
                {
                    string[] input = Input.ReadLine().Split(' ');

                    if (r == row)
                    {
                        for (int c = 0; c < 4; c++)
                        {
                            int number = Convert.ToInt32(input[c]);
                            ++cards[number - 1];

                            if (cards[number - 1] == 2)
                            {
                                ++possibleCards;
                                solution = number;
                            }
                        }
                    }
                }

                if (possibleCards == 0)
                    Output.WriteLine("Case #{0}: {1}", tc, "Volunteer cheated!");
                else if (possibleCards > 1)
                    Output.WriteLine("Case #{0}: {1}", tc, "Bad magician!");
                else
                    Output.WriteLine("Case #{0}: {1}", tc, solution);
            }

            Output.Close();
        }
    }
}
