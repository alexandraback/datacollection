using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace google_magic
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamWriter writer = new StreamWriter("result.txt");
            using (StreamReader reader = new StreamReader("A-small-attempt0.in"))
            {
                int numGames = Int32.Parse(reader.ReadLine());  // first line

                for (int i = 0; i < numGames; i++)
                {
                    // read in round 1
                    int answer1 = Int32.Parse(reader.ReadLine());
                    List<int> row1 = new List<int>();

                    for (int j = 0; j < 4; j++)
                    {
                        if (j == answer1 - 1)
                            row1 = reader.ReadLine().Split(' ').Select(Int32.Parse).ToList();
                        else
                            reader.ReadLine();
                    }

                    // read in round 2
                    int answer2 = Int32.Parse(reader.ReadLine());
                    List<int> row2 = new List<int>();

                    for (int j = 0; j < 4; j++)
                    {
                        if (j == answer2 - 1)
                            row2 = reader.ReadLine().Split(' ').Select(Int32.Parse).ToList();
                        else
                            reader.ReadLine();
                    }

                    // calculate game
                    int match = DoMagic(row1, row2);
                    string result = "Case #" + (i + 1).ToString() + ": ";

                    if (match < 0)
                        result += "Bad magician!";
                    else if (match == 0)
                        result += "Volunteer cheated!";
                    else
                        result += match.ToString();
                    writer.WriteLine(result);
                }
            }

            writer.Close();
        }

        static int DoMagic(List<int> row1, List<int> row2)
        {
            int result = 0;

            foreach (int n in row1)
            {
                if (row2.Contains(n))
                {
                    if (result != 0)
                        result = -1;
                    else
                        result = n;
                }
            }

            return result;
        }
    }
}
