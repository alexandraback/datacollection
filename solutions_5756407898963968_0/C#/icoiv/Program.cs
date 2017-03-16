using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace QualificationRound
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            string inputFilename = "A-small-attempt0.in"; //args[0];
            string outputFilename = Path.ChangeExtension(inputFilename, "out");

            using (var input = new StreamReader(File.OpenRead(inputFilename)))
            using (var output = new StreamWriter(File.OpenWrite(outputFilename)))
            {
                int T = int.Parse(input.ReadLine());

                for (int tc = 1; tc <= T; ++tc)
                {
                    IEnumerable<int> firstCandidates = Candidates(input);
                    IEnumerable<int> secondCandidates = Candidates(input);

                    IEnumerable<int> intersect =
                        firstCandidates.OrderBy(x => x).Intersect(secondCandidates.OrderBy(x => x));
                    int overlap = intersect.Count();

                    output.Write("Case #{0}: ", tc);
                    switch (overlap)
                    {
                        case 0:
                            output.WriteLine("Volunteer cheated!");
                            break;
                        case 1:
                            output.WriteLine(intersect.First());
                            break;
                        default:
                            output.WriteLine("Bad magician!");
                            break;
                    }
                }
            }
        }

        private static IEnumerable<int> Candidates(StreamReader input)
        {
            int guess = int.Parse(input.ReadLine());
            for (int i = 1; i < guess; ++i) input.ReadLine(); // skip
            IEnumerable<int> candidates = input.ReadLine().Split(' ').Select(int.Parse);
            for (int i = guess + 1; i <= 4; ++i) input.ReadLine(); // skip
            return candidates;
        }
    }
}