using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace Round1_2
{
    class Program
    {
        static void Main(string[] args)
        {
            var dir = new DirectoryInfo(@"C:\Users\Arnau\Downloads");
            var file = dir.EnumerateFiles("*.in").OrderByDescending(f => f.LastWriteTime).First();
            Console.WriteLine(file.Name);
            Console.ReadLine();
            var lines = File.ReadAllLines(file.FullName);
            var count = int.Parse(lines[0]);
            var results = new List<string>();
            var l = 1;
            var t = 0;
            while (t < count)
            {
                var n = int.Parse(lines[l++]);
                var senators = lines[l++].Split(' ').Select(int.Parse).ToList();
                var total = senators.Sum();
                var result = new StringBuilder();
                var goingOut = 0;
                while (total > 0)
                {
                    var index1 = senators.IndexOf(senators.Max());
                    senators[index1] = senators[index1] - 1;
                    var index2 = senators.IndexOf(senators.Max());
                    senators[index2] = senators[index2] - 1;
                    total = senators.Sum();
                    var go = Check(senators, total, goingOut);
                    if (go)
                    {
                        result.Append((char) ('A' + index1));
                        result.Append((char) ('A' + index2));
                    }
                    else
                    {
                        senators[index2] = senators[index2] + 1;
                        total = senators.Sum();
                        go = Check(senators, total, goingOut);
                        if (go)
                        {
                            result.Append((char) ('A' + index1));
                        }
                        else
                        {
                            Debugger.Break();
                        }
                    }
                    result.Append(' ');
                    total = senators.Sum();
                }

                results.Add($"Case #{t + 1}: {result}");
                t++;
            }
            File.WriteAllLines(@"..\..\output.txt", results);
        }

        private static bool Check(List<int> senators, int total, int goingOut)
        {
            if (senators.Any(s => s >= ((total/2) + 1)))
            {
                if (goingOut == 2)
                {
                    Debugger.Break();
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
    }
}