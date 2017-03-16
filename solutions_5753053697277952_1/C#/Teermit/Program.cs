using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class Program
    {
        class TData
        {
            public int tn;
            public int n;
            public int[] counts;
            public List<string> result = new List<string>(); 
        }
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            var cases = Enumerable.Range(1, t)
                .Select(
                    x =>
                        new TData
                        {
                            tn = x,
                            n = int.Parse(Console.ReadLine()),
                            counts = Console.ReadLine().Split(' ').Select(int.Parse).ToArray()
                        })
                .ToArray();
            Parallel.ForEach(cases, cs =>
            {
                while (cs.counts.Any(x => x > 0))
                {
                    var temp = cs.counts.Select((x, i) => new {index = i, value = x}).OrderByDescending(x => x.value).ToArray();
                    var left = cs.counts.Count(x => x > 0);
                    var first = temp[0].index;
                    var second = temp[0].value - 1 >= temp[1].value ? temp[0].index : temp[1].index;
                    if (left == 3 && cs.counts[first] == 1 && cs.counts[second] == 1)
                    {
                        cs.counts[first]--;
                        cs.result.Add(((char) ('A' + first)).ToString());
                    }
                    else
                    {
                        cs.counts[first]--;
                        cs.counts[second]--;
                        cs.result.Add(string.Join("",((char)('A' + first)).ToString(),((char)('A' + second)).ToString()));
                    }
                }
            });
            foreach (var cs in cases.OrderBy(c => c.tn))
                Console.WriteLine(string.Format("Case #{0}: {1}", cs.tn, string.Join(" ", cs.result)));
        }
    }
}
