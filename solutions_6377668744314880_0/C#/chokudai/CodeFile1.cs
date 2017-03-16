using System;
using System.Collections.Generic;
using System.Linq;

class Myon
{
    public Myon() { }
    public static void Main()
    {
        new Myon().run2();
    }

    Scanner cin;
    public void run2()
    {
        init();
        cin = new Scanner();
        int T = cin.nextInt();
        for (int i = 0; i < T; i++)
        {
            Console.Write("Case #{0}: ", i + 1);

            run();
        }
    }


    void init()
    {
        
    }

    int N;
    long[] x, y;
    void run()
    {
        N = cin.nextInt();
        x = new long[N];
        y = new long[N];
        for (int i = 0; i < N; i++)
        {
            x[i] = cin.nextInt();
            y[i] = cin.nextInt();
        }

        int[] ret = new int[N];
        for (int i = 0; i < N; i++)
		{
            ret[i] = Math.Max(0, N - 3);
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                int a = 0;
                int b = 0;
                for (int k = 0; k < N; k++)
                {
                    long S = calc(i, j, k);
                    if (S < 0) a++;
                    if (S > 0) b++;
                }
                a = Math.Min(a, b);
                ret[i] = Math.Min(ret[i], a);
                ret[j] = Math.Min(ret[j], a);
            }
        }
        Console.WriteLine();
        for (int i = 0; i < N; i++)
        {
            Console.WriteLine(ret[i]);
        }
    }

    long calc(int a, int b, int c)
    {
        return calc(x[a] - x[b], x[a] - x[c], y[a] - y[b], y[a] - y[c]);
    }

    long calc(long x1, long x2, long y1, long y2)
    {
        return (x1 * y2) - (x2 * y1);
    }






}

class Scanner
{
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner()
    {
        s = new string[0];
        i = 0;
    }

    public string next()
    {
        if (i < s.Length) return s[i++];
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
        s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }

}
