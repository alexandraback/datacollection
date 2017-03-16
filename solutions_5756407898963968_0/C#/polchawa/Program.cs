using System;
using System.Collections.Generic;
using System.Linq;

namespace GCJMagicTrick
{
    class Program
    {
        private static class InputParser
        {
            private static string ReadLine()
            {
                var lineStr = Console.ReadLine();
                if (string.IsNullOrEmpty(lineStr))
                    throw new Exception("Missing line");
                return lineStr;
            }

            private static int ParseIntFromLineStr(string lineStr)
            {
                int result;
                if (!int.TryParse(lineStr, out result))
                    throw new Exception(string.Format("Invalid line: {0}", lineStr));
                return result;
            }

            public static int ReadLineInt()
            {
                var lineStr = ReadLine();

                return ParseIntFromLineStr(lineStr);
            }

            private static IEnumerable<string> ReadLineFragments()
            {
                return ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            }

            public static IEnumerable<int> ReadLineInts()
            {
                return ReadLineFragments().Select(ParseIntFromLineStr);
            }
        }

        private static int[] ReadAnswerCards()
        {
            int[] answerCards = null;

            var answer = InputParser.ReadLineInt();
            for (var row = 1; row <= 4; ++row)
            {
                var cards = InputParser.ReadLineInts();

                if (row == answer)
                    answerCards = cards.ToArray();
            }
            if (answerCards == null)
                throw new Exception("Answer is incorrect (limits!)");
            return answerCards;
        }

        private static object Solve(int[] firstAnswerCards, int[] secondAnswerCards)
        {
            var common = firstAnswerCards.Intersect(secondAnswerCards).ToArray();

            if (common.Length == 0)
                return "Volunteer cheated!";
            if (common.Length > 1)
                return "Bad magician!";
            return common[0];
        }

        static void Main(string[] args)
        {
            var testCases = InputParser.ReadLineInt();

            for (var test = 1; test <= testCases; ++test)
            {
                var firstAnswerCards = ReadAnswerCards();
                var secondAnswerCards = ReadAnswerCards();

                var solution = Solve(firstAnswerCards, secondAnswerCards);

                Console.WriteLine("Case #{0}: {1}", test, solution);
            }
        }
    }
}
