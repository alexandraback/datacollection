using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam.Algorithms
{
    public class MagicTrickAlgorithm : Algorithm
    {
        public int LinesNeeded
        {
            get { return 10; }
        }

        public object Solve(string[] input)
        {
            var firstRowGuess = int.Parse(input[0]);
            IEnumerable<int> firstPossibleNumbers = GetPossibleNumbers(input[firstRowGuess]);
            var secondRowGuess = int.Parse(input[5]);
            IEnumerable<int> secondPossibleNumbers = GetPossibleNumbers(input[secondRowGuess + 5]);
            IEnumerable<int> intersection = firstPossibleNumbers.Intersect(secondPossibleNumbers);
            if (intersection.Count() == 1)
            {
                return intersection.Single();
            }
            else if (!intersection.Any())
            {
                return "Volunteer cheated!";
            }
            else
            {
                return "Bad magician!";
            }
        }

        private IEnumerable<int> GetPossibleNumbers(string row)
        {
            return row.Split(' ').Select(num => int.Parse(num));
        }
    }
}
