using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace CodeJam1
{
    public class TestCase
    {
        private const string cheatString = "Volunteer cheated!";
        private const string badMagician = "Bad magician!";

        public TestCase(TextReader stream)
        {
            Round1 = new ChoiceRound(stream);
            Round2 = new ChoiceRound(stream);
        }

        public string Evaluate()
        {
            var choice1 = Round1.GetPossibilities();
            var choice2 = Round2.GetPossibilities();
            var result = choice1.Intersect(choice2);
            switch (result.Count())
            {
                case 0:
                    return cheatString;
                case 1:
                    return result.First().ToString();
                default:
                    return badMagician;
            }
        }

        public ChoiceRound Round1 { get; private set; }
        public ChoiceRound Round2 { get; private set; }
    }
}
