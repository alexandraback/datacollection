using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2015_1B
{
  class Program
  {
    static void Main(string[] args)
    {
      int tests = ReadInt();
      for (int test = 1; test <= tests; ++test)
      {
        var i1 = ReadLongs().ToArray();
        long count = (int)i1[0];
        long n = i1[1];
        var times = ReadLongs().ToList();

        long b = 0;
        if (n < count)
        {
          b = n;
        }
        else
        {
          long q = (n * times[0] / count);
          long le = 0;
          long ue = q;
          n -= count;

          for (; ;)
          {
            //Console.WriteLine("Rising {0} {1}", le, ue);
            long uu = 0;
            foreach (int t in times)
            {
              uu += (ue / t);
            }
            if (uu > n) {
              //Console.WriteLine("Hit {0}", uu);
              break;
            }
            le = ue;
            ue += q;
          }

          long est = (ue + le) / 2;
          long lower = 0;
          long upper = 0;
          while (le < ue)
          {
            //Console.WriteLine("{0}-{1} {2}", le, ue, est);
            est = (ue + le) / 2;
            lower = 0;
            upper = 0;
            for (int i = 0; i < count; ++i)
            {
              lower += (est - 1) / times[i];
              upper += est / times[i];
            }
            //Console.WriteLine("lower = {0} upper = {1} n = {2}", lower, upper, n);
            if (n <= lower)
            {
              ue = est;
            }
            else if (n <= upper)
            {
              break;
            }
            else if (le == est)
            {
              le = est + 1;
            }
            else
            {
              le = est;
            }
          }

          long ofs = n - lower;
          for (int i = 0; i < count; ++i)
          {
            if ((est % times[i]) == 0)
            {
              --ofs;
              if (ofs <= 0)
              {
                b = i + 1;
                break;
              }
            }
          }
        }

        Console.WriteLine("Case #{0}: {1}", test, b);
      }
    }

    static int ReadInt()
    {
      return Convert.ToInt32(Console.ReadLine());
    }

    static IEnumerable<String> ReadStrings()
    {
      string line = Console.ReadLine();
      return line.Split((char[])null, StringSplitOptions.RemoveEmptyEntries);
    }

    static IEnumerable<int> ReadInts()
    {
      return ReadStrings().Select(s => Convert.ToInt32(s));
    }

    static IEnumerable<long> ReadLongs()
    {
      return ReadStrings().Select(s => Convert.ToInt64(s));
    }

    static int[] ReadInts(int count)
    {
      return ReadInts().Take(count).ToArray();
    }
  }
}
