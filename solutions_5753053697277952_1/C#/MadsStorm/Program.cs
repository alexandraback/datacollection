using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.ExceptionServices;
using System.Runtime.Remoting.Channels;
using System.Text;


namespace carrots
{
    class Program
    {
        private static void Main(string[] args)
        {

            StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
            string input = reader.ReadToEnd();

            var lines = input.Split(new[] {"\r\n", "\n"}, StringSplitOptions.None);
            var validLines = lines.Take(lines.Count() - 1).ToArray();


            int linecount = 0;
            int testcases = int.Parse(validLines[linecount++]);


            foreach (var zzz in Enumerable.Range(1, testcases))
            {
                int numParties = int.Parse(validLines[linecount++]);
                string counts = validLines[linecount++];

                List<int> partyCount =
                    counts.Split(new[] {" "}, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToList();

                int totalCount = partyCount.Sum();

                List<string> results = new List<string>();

                while (totalCount > 0)
                {
                    var max = partyCount.Max();
                    var first = partyCount.IndexOf(max);
                    partyCount[first]--;
                    totalCount--;

                    if (totalCount == 0)
                    {
                        var x = (char) (first + (int) 'A');
                        results.Add(x.ToString());
                    }
                    else
                    {
                        max = partyCount.Max();
                        var second = partyCount.IndexOf(max);
                        partyCount[second]--;
                        totalCount--;

                        var x1 = (char)(first + (int)'A');
                        var x2 = (char)(second + (int)'A');
                        results.Add(x1.ToString() + x2.ToString());
                    }

                }

                var steps = results.Count;
                if (results.Last().Length == 1)
                {
                    var temp = results[steps - 2];
                    results[steps - 2] = results[steps - 1];
                    results[steps - 1] = temp;
                }

                Console.WriteLine("Case #" + zzz + ": " + string.Join(" ", results));

            }
        }
    }
}

