using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

class Problem
{
    private static StreamReader reader;

    static string Solve()
    {
        int first = int.Parse(reader.ReadLine());
        List<int> row = Enumerable.Range(0, 4).Select(
                x => reader.ReadLine().Split().Select(y => int.Parse(y)).ToList()
                ).ToArray()[first - 1];

        int second = int.Parse(reader.ReadLine());
        HashSet<int> q = new HashSet<int> (row);

        List<int> res = Enumerable.Range(0, 4).Select(
                x => reader.ReadLine().Split().Select(y => int.Parse(y)).Where(z => q.Contains(z)).ToList()
                ).ToArray()[second - 1];
        if (res.Count == 0)
            return "Volunteer cheated!";
        if (res.Count >= 2)
            return "Bad magician!";
        return res[0].ToString();
    }

    public static void Main ()
    {
        var bs = new BufferedStream(Console.OpenStandardInput());
        reader = new StreamReader(bs);

        foreach (int i in Enumerable.Range(1, int.Parse(reader.ReadLine())))
            Console.WriteLine("Case #{0}: {1}", i, Solve());
    }
}
