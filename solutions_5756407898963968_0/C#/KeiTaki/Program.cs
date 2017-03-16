using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Program
    {
        static string _folderPath = Directory.GetCurrentDirectory() + @"/../../Questions/";
        static string _question = "MagicTrick";
        static string _dataSize = "S";   // T, S or L

        static void Main(string[] args)
        {
            var data = File.ReadAllLines(_folderPath + _question + "_" + _dataSize + ".txt");

            using (var outFile = File.CreateText(_folderPath + _question + "_" + _dataSize + "_A.txt"))
            {
                Action<string> dualWriter = line => 
                    {
                        Console.WriteLine(line);
                        outFile.WriteLine(line);
                    };

                solve(data, dualWriter);
            }

            Console.WriteLine("Done!");
            Console.Read();
       }

        static void solve(IList<string> lines, Action<string> writeLine)
        {
            int numQs = int.Parse(lines[0]);

            int at = 1;

            for (int q = 0; q < numQs; q++)
            {
                int row1, row2;
                var grid1 = new List<List<string>>();
                var grid2 = new List<List<string>>();

                row1 = int.Parse(lines[at++]);

                grid1.Add(lines[at++].Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList());
                grid1.Add(lines[at++].Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList());
                grid1.Add(lines[at++].Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList());
                grid1.Add(lines[at++].Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList());

                row2 = int.Parse(lines[at++]);

                grid2.Add(lines[at++].Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList());
                grid2.Add(lines[at++].Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList());
                grid2.Add(lines[at++].Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList());
                grid2.Add(lines[at++].Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList());

                string answer = solve1(row1, row2, grid1, grid2);

                writeLine(string.Format("Case #{0}: {1}", q + 1, answer));
            }
        }

        static string solve1(int row1, int row2, List<List<string>> grid1, List<List<string>> grid2)
        {
            var match = new List<string>();

            for (int i = 0; i < 4; i++)
            {
                var card1 = grid1[row1 - 1][i];
                for (int j = 0; j < 4; j++)
                {
                    if (card1 == grid2[row2 - 1][j])
                    {
                        match.Add(card1);
                    }
                }
            }

            if (match.Count == 1)
            {
                return match[0];
            }
            else if (match.Count > 1)
            {
                return "Bad magician!";
            }

            return "Volunteer cheated!";
        }
    }
}
