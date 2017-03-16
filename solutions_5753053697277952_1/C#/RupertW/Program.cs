using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
  class Program
  {
    static void Main(string[] args)
    {
      string inputFile = (args.Length > 0) ? args[0] : @"..\..\test.in";
      using (var f = new StreamReader(inputFile))
      {
        int nncases = Int32.Parse(f.ReadLine());
        for (int ncase = 1; ncase <= nncases; ++ncase)
        {
          int nparties = Int32.Parse(f.ReadLine());
          var evac = new StringBuilder();
          bool first = true;

          var s = f.ReadLine().Split().Select(pp => Int32.Parse(pp)).ToList();
          int total = s.Sum();

          while (total > 0)
          {
            int m = s.Max();
            if (m == 0)
            {
              break;
            }
            int o = s.IndexOf(m);
            total--;
            s[o]--;

            if (!first) evac.Append(" ");
            else first = false;
            evac.Append((char) ('A' + o));

            bool bad = s.Any(n => n > (total/2));

            int m2 = s.Max();
            if (m2 == 0)
            {
              break;
            }
            int o2 = s.IndexOf(m2);
            total--;
            s[o2]--;
            if (s.Any(n => n > (total/2)))
            {
              if (bad)
              {
                evac = new StringBuilder("IMPOSSIBLE");
                break;
              }
              ++s[o2];
              ++total;
            }
            else
            {
              evac.Append((char) ('A' + o2));
            }
          }

          Console.WriteLine("Case #{0}: {1}", ncase, evac);
        }
      }
    }
  }
}
