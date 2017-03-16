using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Globalization;
using System.Threading;

class A
{
    static long Solve1(int N, int[] M)
    {
        long sum = 0;
        for (int i = 1; i < N; ++i)
        {
            if (M[i - 1] > M[i])
                sum += M[i - 1] - M[i];
        }
        return sum;
    }

    static long Solve2(int N, int[] M)
    {
        int maxGap = 0;
        for (int i = 1; i < N; ++i)
        {
            if (M[i - 1] - M[i] > maxGap)
                maxGap = M[i - 1] - M[i];
        }
        long sum = 0;
        for (int i = 0; i < N-1; ++i)
        {
            sum += Math.Min(M[i], maxGap);
        }
        return sum;
    }

    static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
        int T = ReadInt();
        for (int t = 1; t <= T; ++t)
        {
            int N = ReadInt();
            int[] M = ReadInts();
            Console.WriteLine("Case #{0}: {1} {2}", t, Solve1(N, M), Solve2(N, M));
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
