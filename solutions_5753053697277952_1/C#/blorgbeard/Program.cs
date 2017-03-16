using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace senate
{
    class Program
    {
        class Senate
        {
            public Dictionary<char, int> PartyMembers { get; set; }

            private int TotalPeople { get; set; }

            public Senate(string line)
            {
                PartyMembers = new Dictionary<char, int>();
                var counts = line.Split().Select(int.Parse);
                char p = 'A';
                foreach (var count in counts)
                {
                    PartyMembers[p++] = count;
                    TotalPeople += count;
                }
            }

            public bool MajorityExists()
            {
                int threshold = TotalPeople / 2;
                return PartyMembers.Any(t => t.Value > threshold);
            }
        }

        static List<Senate> GetInput()
        {
            var cases = int.Parse(Console.ReadLine());
            var input = new List<Senate>(cases);
            for (int i = 0; i < cases; i++)
            {
                var partyCount = Console.ReadLine();
                input.Add(new Senate(Console.ReadLine()));
            }
            return input;
        }

        private static IEnumerable<string> Evacuate(char party, int count)
        {
            foreach (var step in Enumerable.Repeat(new string(party, 2), count / 2))
            {
                yield return step;
            }
            if (count % 2 == 1)
            {
                yield return new string(party, 1);
            }
        } 

        private static IEnumerable<string> Solve(Senate senate)
        {
            if (senate.PartyMembers.Count == 1)
            {
                // there's only one party!
                var count = senate.PartyMembers['A'];
                foreach (var step in Evacuate('A', count))
                    yield return step;
                yield break;
            }

            // get the largest party, bring it down to the level of the next largest.
            var senateBySize = senate.PartyMembers.OrderByDescending(t => t.Value);
            var largest = senateBySize.First();
            var second = senateBySize.Skip(1).First();
            var diff = largest.Value - second.Value;
            foreach (var step in Evacuate(largest.Key, diff))
                yield return step;

            // then evacuate everyone else
            foreach (var party in senateBySize.Skip(2))
            {
                foreach (var step in Evacuate(party.Key, party.Value))
                    yield return step;
            }

            // then evacuate the only two remaining parties two by two.
            // there can never be a majority.
            foreach (var step in Enumerable.Repeat(new string(new[] {largest.Key, second.Key}), second.Value))
            {
                yield return step;
            }

        }
        static void Main(string[] args)
        {
            var cases = GetInput();

            int i = 1;
            foreach (var senate in cases)
            {
                Console.WriteLine("Case #{0}: {1}", i++, string.Join(" ", Solve(senate)));
            }

            try { Console.ReadKey(); }
            catch { }
        }
    }
}
