using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Clear();
            TextReader r = new StreamReader("input.txt");
            using (TextWriter w = new StreamWriter("output.txt"))
            {
                int cases = int.Parse(r.ReadLine());
                for (int i = 0; i < cases; i++)
                {
                    Console.Clear();
                    Console.WriteLine(string.Format("Case {0} of {1}: {2:P1}%", i, cases, i / (double)cases));
                    var testcase = new TestCase(r);
                    w.WriteLine(string.Format("Case #{0}: {1}", i+1, testcase.Evaluate()));
                }
            }
        }
    }
}
