using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            int numberOfTestCases = int.Parse(Console.ReadLine());

            for (int i = 0; i < numberOfTestCases; i++)
            {
                Console.Write("Case #{0}: ", i + 1);
                Trial();
            }
        }

        static void Trial()
        {
            int numberOfLines = int.Parse(Console.ReadLine());
            List<string> strings = new List<string>();
            for (int i = 0; i < numberOfLines; i++)
            {
                strings.Add(Console.ReadLine());
            }

            List<List<SameChars>> patterns = new List<List<SameChars>>();

            foreach (string str in strings)
            {
                List<SameChars> pattern = new List<SameChars>();
                SameChars lastChars = null;

                for (int i = 0; i < str.Length; i++)
                {
                    if (lastChars == null || lastChars.Char != str[i])
                    {
                        lastChars = new SameChars(str[i], 1);
                        pattern.Add(lastChars);
                    }
                    else
                    {
                        lastChars.Num++;
                    }
                }
                patterns.Add(pattern);
            }

            List<SameChars> first = patterns.First();
            if (!patterns.All((x) =>
            {
                if (first.Count != x.Count)
                {
                    return false;
                }

                for (int i = 0; i < first.Count && i < x.Count; i++)
                {
                    if (first[i].Char != x[i].Char)
                    {
                        return false;
                    }
                }
                return true;
            }))
            {
                Console.WriteLine("Fegla Won");
                return;
            }

            int sum = 0;
            for (int i = 0; i < first.Count; i++)
            {
                int min = patterns.Min((x) => (x[i].Num));
                int max = patterns.Max((x) => (x[i].Num));

                if (min == max)
                {
                    continue;
                }

                int minimumActions = int.MaxValue;
                for (int j = min; j <= max; j++)
                {
                    int actions = patterns.Sum((x) => (Math.Abs(x[i].Num - j)));
                    minimumActions = Math.Min(minimumActions, actions);
                }
                sum += minimumActions;
            }

            Console.WriteLine(sum);
        }
    }

    class SameChars
    {
        public char Char { get; set; }
        public int Num { get; set; }

        public SameChars(char ch, int n)
        {
            this.Char = ch;
            this.Num = n;
        }
    }
}
