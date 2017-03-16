using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Globalization;
using System.Threading;

class B
{

    class Order : IComparable<Order>
    {
        public int barber;
        public long end;

        public Order(int barber, long end)
        {
            this.barber = barber;
            this.end = end;
        }

        public int CompareTo(Order other)
        {
            if (end == other.end)
            {
                return barber - other.barber;
            }
            else
            {
                if (end - other.end < 0)
                    return -1;
                else
                    return 1;
            }
        }
    }

    static long gcd(long a, long b)
    {
        while (b != 0)
        {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static long lcm(long a, long b)
    {
        return (a / gcd(a, b)) * b;
    }

    static int Solve(int B, long N, int[] M)
    {
        long mul = 1;
        for (int i = 0; i < B; ++i)
        {
            mul = lcm(mul, M[i]);
            if (mul > N)
            {
                mul = 0;
                break;
            }
        }
        if (mul > 0)
        {
            long customers = 0;
            for (int i = 0; i < B; ++i)
            {
                customers += mul / M[i];
            }
            N = N % customers;
            if (N == 0)
                N = customers;
        }

        long time = 0;
        SortedSet<Order> orders = new SortedSet<Order>();
        for (int i = 0; i < B; ++i)
        {
            orders.Add(new Order(i, time));
        }
        Order min = null;
        for (int i = 0; i < N; ++i)
        {
            min = orders.Min;
            orders.Remove(min);
            time = min.end;
            min.end = time + M[min.barber];
            orders.Add(min);
        }
        return min.barber + 1;

    }

    static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
        int T = ReadInt();
        for (int t = 1; t <= T; ++t)
        {
            int[] I = ReadInts();
            int[] M = ReadInts();
            Console.WriteLine("Case #{0}: {1}", t, Solve(I[0], I[1], M));
        }
    }

    // INPUT READING
    static string ReadLine()
    {
        return Console.ReadLine();
    }

    static string[] ReadWords()
    {
        return ReadLine().Split();
    }

    static string[] ReadWords(char separator)
    {
        return ReadLine().Split(separator);
    }

    static int ReadInt()
    {
        return int.Parse(ReadLine());
    }

    static long ReadLong()
    {
        return long.Parse(ReadLine());
    }

    static double ReadDouble()
    {
        return double.Parse(ReadLine());
    }

    static int[] ReadInts()
    {
        return Array.ConvertAll(ReadWords(), int.Parse);
    }

    static int[] ReadInts(char separator)
    {
        return Array.ConvertAll(ReadWords(separator), int.Parse);
    }

    static long[] ReadLongs()
    {
        return Array.ConvertAll(ReadWords(), long.Parse);
    }

    static long[] ReadLongs(char separator)
    {
        return Array.ConvertAll(ReadWords(separator), long.Parse);
    }

    static double[] ReadDoubles()
    {
        return Array.ConvertAll(ReadWords(), double.Parse);
    }

    static double[] ReadDoubles(char separator)
    {
        return Array.ConvertAll(ReadWords(separator), double.Parse);
    }

    static void WriteList<T>(List<T> col)
    {
        int count = col.Count;
        for (int i = 0; i < count; i++)
            Console.Write(col[i] + (i < count - 1 ? " " : "\n"));
    }

    static void WriteArray<T>(T[] col)
    {
        int count = col.Length;
        for (int i = 0; i < count; i++)
            Console.Write(col[i] + (i < count - 1 ? " " : "\n"));
    }
}
