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

        static List<Int64> ReadInt64List(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => Int64.Parse(x)).ToList();
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

        static Int64 GCD(List<Int64> numbers)
        {
            return numbers.Aggregate(GCD);
        }

        static Int64 LCM(List<Int64> numbers)
        {
            return numbers.Aggregate(LCM);
        }

        static Int64 GCD(Int64 a, Int64 b)
        {
            return b == 0 ? a : GCD(b, a % b);
        }

        static Int64 LCM(Int64 a, Int64 b)
        {
            return (a * b) / GCD(a, b);
        }

        static void Main(string[] args)
        {
            System.IO.StreamReader reader = System.IO.File.OpenText("input.in");
            System.IO.StreamWriter writer = System.IO.File.CreateText("output.out");

            int T = ReadInt(reader);

            for (int i = 1; i <= T; i++)
            {
                int[] data = ReadIntData(reader);
                int B = data[0];
                Int64 N = data[1];
                List<Int64> M = ReadInt64List(reader);

                Int64 lcm = LCM(M);

                Int64 cf = 0;
                for (int j = 0; j < M.Count; j++)
                { 
                    cf += lcm/M[j];
                }

                if (cf < N && cf != 0)
                    N = N % cf;
                if (N == 0)
                    N = cf;
                
                Int64[] cData = new Int64[M.Count];
                M.CopyTo(cData);
                List<Int64> currentStatus = cData.ToList();

                Int64 result = 0;
                if (N <= B)
                    result = N;
                else
                {
                    //for (int j = 0; j < M.Count; j++) 
                    //{
                    //    currentStatus[j] = M[j];
                    //}
                    int currentNumber = B;
                    while (currentNumber < N)
                    {
                        Int64 min = currentStatus.Min();
                        for (int k = 0; k < currentStatus.Count; k++)
                        {
                            currentStatus[k] = currentStatus[k] - min;
                        }

                        for (int k = 0; k < currentStatus.Count; k++)
                        {
                            if (currentStatus[k] == 0)
                            {
                                currentNumber++;
                                currentStatus[k] = M[k];
                                if (currentNumber == N)
                                {
                                    result = k + 1;
                                    break;
                                }
                            }
                        }
                    }
                }

                Console.WriteLine("Case #" + i + ": " + result);
                writer.WriteLine("Case #" + i + ": " + result);
            }

            reader.Dispose();
            writer.Dispose();
        }
    }
}
