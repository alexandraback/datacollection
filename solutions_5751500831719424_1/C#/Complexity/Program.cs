using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Repeater
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader s = new StreamReader(@"C:\Users\Tim\Desktop\input.in");
            StreamWriter w = new StreamWriter(@"C:\Users\Tim\Desktop\output.txt");
            int t = Convert.ToInt32(s.ReadLine());
            for (int i = 1; i < t + 1; i++)
            {
                int q = Convert.ToInt32(s.ReadLine());
                List<string> strings = new List<string>();
                for (int x = 0; x < q; x++)
                    strings.Add(s.ReadLine());

                bool possible=true;
                foreach (string str in strings)
                {
                    if(chars(str).Count!=chars(strings[0]).Count)
                        possible=false;
                    else{
                        for(int x=0; x<chars(str).Count;x++)
                        {
                            if(chars(str)[x]!=chars(strings[0])[x])
                                possible=false;
                        }
                    }                    
                }
                if (!possible)
                    w.WriteLine("Case #" + i + ": Fegla Won");
                else
                {
                    List<List<int>> lengths = new List<List<int>>();
                    for (int x = 0; x < strings.Count; x++)
                    {
                        lengths.Add(new List<int>());
                        int length = 1;
                        for (int y = 1; y < strings[x].Length; y++)
                        {
                            if (strings[x][y] == strings[x][y - 1])
                                length++;
                            else
                            {
                                lengths[x].Add(length);
                                length = 1;
                            }
                        }
                        lengths[x].Add(length);
                    }

                    List<int> minList = new List<int>();
                    for (int x = 0; x < lengths[0].Count; x++)
                    {
                        int min = Int32.MaxValue;
                        for (int y = 0; y < lengths.Count; y++)
                        {
                            if (lengths[y][x] < min)
                                min = lengths[y][x];
                        }
                        minList.Add(min);
                    }

                    for (int x = 0; x < minList.Count; x++)
                    {
                        List<int> newMin = new List<int>();
                        for(int y=0;y<minList.Count;y++)
                            newMin.Add(minList[y]);
                        while (true)
                        {
                            newMin[x] = newMin[x] + 1;
                            if (moves(strings, lengths, newMin) >= moves(strings, lengths, minList))
                                break;
                            else
                                minList[x] = newMin[x];
                        }

                    }                    

                    w.WriteLine("Case #" + i + ": " + moves(strings, lengths, minList));
                }
            }
            s.Close();
            w.Close();
        }

        static List<char> chars(string s)
        {
            List<char> returnChars = new List<char>();
            returnChars.Add(s[0]);
            for (int i = 1; i < s.Length; i++)
            {
                if (s[i] != s[i - 1])
                    returnChars.Add(s[i]);
            }
            return returnChars;
        }

        static int moves(List<string> strings, List<List<int>> lengths, List<int> minList)
        {
            int moves = 0;

            for (int y = 0; y < strings.Count; y++)
            {
                for (int z = 0; z < lengths[y].Count; z++)
                {
                    moves += Math.Abs(lengths[y][z] - minList[z]);
                }
            }

            return moves;
        }
    }
}
