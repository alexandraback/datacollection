//#define ONLINE_JUDGE
//#define DEBUG

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;

class Program
{

    static int tests = 3;

#if (ONLINE_JUDGE)
    static TextReader r = Console.In;
    static TextWriter w = Console.Out;
#else
    static string path = @"C:\Y\Prog\_СпортивноеПрограммирование\GoogleCodeJam\2016\1C\1\";
    static string answerFile = "0{0}Answer.txt";
    static string resultFile = "0{0}Result.txt";
    static string sourceFile = "0{0}Source.txt";
    
    static TextReader r;
    static TextWriter w;
#endif

    static void Main(string[] args)
    {
        //long cur = 123466789234;
        //Console.WriteLine( Convert.ToString(cur) ); 

        for (int i = 1; i <= tests; i++)
        {
#if (!ONLINE_JUDGE)
            r = new StreamReader(string.Format(path + sourceFile, i));
            w = new StreamWriter(string.Format(path + resultFile, i), false);
#endif
            string s = r.ReadLine();
            int cases = Convert.ToInt32(s);
            for (int j = 0; j < cases; j++)
                solve(j+1);
#if (!ONLINE_JUDGE)
            w.Flush(); w.Close();
            Console.WriteLine("CASE: {0}", i);
            string answer = File.ReadAllText(string.Format(path + answerFile, i));
            string result = File.ReadAllText(string.Format(path + resultFile, i));
            if (answer != result)
            {
                Console.WriteLine("FAIL:");
                Console.WriteLine("Result" + Environment.NewLine + result);
                Console.WriteLine("Answer" + Environment.NewLine + answer);
            }
            else
                Console.WriteLine("OK");
#endif
        }
    }

    class Party : IComparable<Party>
    {
        public char c;
        public int n;

        int IComparable<Party>.CompareTo(Party other)
        {
            if (this.n < other.n) return -1;
            if (this.n > other.n) return 1;
            if (this.c < other.c) return -1;
            if (this.c > other.c) return 1;            
            return 0;
        }
    }

    public static void solve(int c)
    {
        int n = Convert.ToInt32(r.ReadLine());
        Party[] p = new Party[n];        
        string[] b = r.ReadLine().Split(' ');
        for (int i = 0; i < n; i++)
        {
            Party pp = new Party { c = (char)((int)'A' + i), n = Convert.ToInt32(b[i]) };
            p[i] = pp;
        }
        Array.Sort(p);
        Array.Reverse(p);
        int other = 0;
        for (int i = 1; i < n; i++)
            other += p[i].n;

        StringBuilder sb = new StringBuilder();

        while (p[0].n > 0)
        { 
            if (other >= (p[0].n + 1))
            {
                for (int i = 1; i < n; i++)
                {
                    if (p[i].n > 0)
                    {
                        sb.Append(p[i].c.ToString() + " ");
                        other -= 1;
                        p[i].n -= 1;
                        break;
                    }
                }
                continue;
            }
            if (other == p[0].n)
            {
                for (int i = 1; i < n; i++)
                {
                    if (p[i].n > 0)
                    {
                        sb.Append((p[0].c.ToString()) + ((string)p[i].c.ToString()) + " ");
                        other -= 1;
                        p[0].n -= 1;
                        p[i].n -= 1;
                        break;
                    }
                }
                continue;
            }
        }


        w.WriteLine("Case #{0}: {1}", c, sb.ToString());        
    }
}
