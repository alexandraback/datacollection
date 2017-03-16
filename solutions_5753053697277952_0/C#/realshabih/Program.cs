using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016
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

                List<int> P = ReadIntList(reader);

                string result = String.Empty; 
                int total = P.Sum();
                while (total > 0)
                {
                    int max = P.Max();
                    int i1 = P.IndexOf(max);
                    P[i1] = max - 1;
                    int i2 = -1;

                    if (P.Sum() > 0 && P.Sum() != 2)
                    {
                        max = P.Max();
                        i2 = P.IndexOf(max);
                        P[i2] = max - 1;
                    }

                    if (result.Equals(String.Empty))
                        result = Convert.ToChar(i1 + 65).ToString() + ((i2 == -1) ? String.Empty : Convert.ToChar(i2 + 65).ToString()).ToString();
                    else
                        result = result + " " + Convert.ToChar(i1 + 65).ToString() + ((i2 == -1) ? String.Empty : Convert.ToChar(i2 + 65).ToString()).ToString();

                    total = P.Sum();
                }

                
                writer.WriteLine("Case #" + i + ": " + result);
            }

            reader.Dispose();
            writer.Dispose();
        }
    }
}
