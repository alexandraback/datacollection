using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Magic_Trick
{
    class Program
    {
        static void Main(string[] args)
        {
            //string filename = @"sample.in.txt";
            string filename = @"A-small-attempt2.in.txt";
            

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (var reader = new StreamReader(filename))
            {
                using (var writer = new StreamWriter(filename.Replace(".in.", ".out."), false))
                {
                    int n = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= n; i++)
                    {
                        Console.Write("N=" + i + " Time=");
                        Process(i, reader, writer);
                        Console.WriteLine((DateTime.Now - current).ToString().Substring(4));
                        current = DateTime.Now;
                    }
                }
            }

            Console.WriteLine("Time=" + (DateTime.Now - begin));
            Console.ReadLine();
        }

        private static void Process(int C, TextReader reader, TextWriter writer)
        {
            int row = int.Parse(reader.ReadLine());
            Hashtable h = new Hashtable();

            for (int i = 1; i < 5; i++)
            {
                string line = reader.ReadLine();
                if (i==row)
                {
                    string[] ll = line.Split(' ');
                    foreach (var s in ll)
                    {
                        h[s] = 1;
                    }
                }
            }

            row = int.Parse(reader.ReadLine());
            for (int i = 1; i < 5; i++)
            {
                string line = reader.ReadLine();
                if (i == row)
                {
                    string[] ll = line.Split(' ');
                    foreach (var s in ll)
                    {
                        if (h[s] != null)
                         h[s] = 2;
                    }
                }
            }

            int count = 0;
            string last = "";
            foreach (DictionaryEntry dictionaryEntry in h)
            {
                if ((int)dictionaryEntry.Value == 2)
                {
                    count++;
                    last = (string)dictionaryEntry.Key;
                }
            }

            if (count==0)
            {
                Console.WriteLine("Case #{0}: {1}", C, "Volunteer cheated!");
                writer.WriteLine("Case #{0}: {1}", C, "Volunteer cheated!");
            }
            else if (count==1)
            {
                Console.WriteLine("Case #{0}: {1}", C, last);
                writer.WriteLine("Case #{0}: {1}", C, last);
            }
            else
            {
                Console.WriteLine("Case #{0}: {1}", C, "Bad magician!");
                writer.WriteLine("Case #{0}: {1}", C, "Bad magician!");
            }
        }
    }
}
