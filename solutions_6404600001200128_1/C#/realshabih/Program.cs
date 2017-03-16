using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qualification
{
    class Program
    {
        static int ReadInt(System.IO.StreamReader reader)
        {
            return int.Parse(reader.ReadLine());
        }

        static List<int> ReadIntList(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => int.Parse(x)).ToList();
        }

        static int[] ReadIntArray(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => int.Parse(x)).ToArray();
        }

        static int[] ReadCharArray(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            int[] dataInt = new int[data.Length];
            for (int i = 0; i < data.Length; i++)
                dataInt[i] = data[i] == '.' ? -1 : 1;

            return dataInt;
        }

        static int[] ReadIntData(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => int.Parse(x)).ToArray();
        }

        static Int64[] ReadInt64Array(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => Int64.Parse(x)).ToArray();
        }

        static List<string> ReadStringList(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').ToList();
        }

        static void Main(string[] args)
        {
            System.IO.StreamReader reader = System.IO.File.OpenText("input.in");
            System.IO.StreamWriter writer = System.IO.File.CreateText("output.out");

            int T = ReadInt(reader);

            for (int i = 1; i <= T; i++)
            {
                int N = ReadInt(reader);
                List<int> M = ReadIntList(reader);
                Int64 r1 = 0;
                Int64 r2 = 0;
                int maxRate = 0;

                for (int j = 1; j < M.Count; j++)
                {
                    if (M[j] < M[j - 1])
                    { 
                        int rate = M[j - 1] - M[j];
                        r1 += rate;
                        if (rate > maxRate)
                            maxRate = rate;
                    }
                }

                for (int j = 0; j < M.Count - 1; j++)
                {
                    if (M[j] > maxRate)
                    {
                        r2 += maxRate;
                    }
                    else
                    {
                        r2 += M[j];
                    }
                }

                writer.WriteLine("Case #" + i + ": " + r1 + " " + r2);
            }

            reader.Dispose();
            writer.Dispose();
        }
    }
}
