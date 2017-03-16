using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ14Q1
{
  class Program
  {
    static IEnumerable<int> readRow(StreamReader sr)
    {
      int row1 = int.Parse(sr.ReadLine());
      IEnumerable<int> result = null;
      for (int i = 1; i <= 4; ++i)
      {
        string line = sr.ReadLine().Trim();
        if (i == row1)
        {
          result =  line.Split(' ').Select(s => int.Parse(s));
        }
      }
      return result;
    }

    static void Main(string[] args)
    {
      //args = new string[] {"..\\..\\sample.in"};
      using (var sr = new StreamReader(args[0]))
      {
        int nCases = int.Parse(sr.ReadLine());

        for (int nCase = 1; nCase <= nCases; ++nCase)
        {
          var overlap = readRow(sr).Intersect(readRow(sr)).ToList();
          if (overlap.Count == 0)
          {
            Console.WriteLine("Case #{0}: Volunteer cheated!", nCase);
          }
          else if (overlap.Count == 1)
          {
            Console.WriteLine("Case #{0}: {1}", nCase, overlap[0]);
          }
          else
          {
            Console.WriteLine("Case #{0}: Bad magician!", nCase);
          }
        }
      }
    }
  }
}
