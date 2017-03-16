using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static string ReadLine() { return Console.ReadLine(); }
    static int ReadInt() { return int.Parse(ReadLine()); }
    static int[] ReadInts() { return ReadLine().Split().Select(int.Parse).ToArray(); }
    static string[] ReadStrings() { return ReadLine().Split(); }

    class D {
        public int index;
        public int val;
    }


    static void Calc(int[] xs) {
        var ans = new List<string>();

        var ls = new List<D>();
        for (int i = 0; i < xs.Length; i++) {
            ls.Add(new D { index = i, val = xs[i] });
        }

        while (true) {
            ls.Sort((a, b) => a.val.CompareTo(b.val));
            while (ls.Count > 0 && ls[ls.Count-1].val == 0) {
                ls.RemoveAt(ls.Count-1);
            }
            if (ls.Count == 0) break;

            int sum = ls.Sum(e => e.val);

            ls[ls.Count-1].val--;
            sum--;

            bool over = false;
            for (int i = 0; i < ls.Count; i++) {
                if (ls[i].val > sum / 2.0) {
                    over = true;
                    break;
                }
            }

            if (over) {
                string a = ((char)(ls[ls.Count-1].index + 'A')).ToString();
                string b = ((char)(ls[ls.Count-2].index + 'A')).ToString();
                ls[ls.Count-2].val--;
                ans.Add(a + b);
            }
            else {
                string a = ((char)(ls[ls.Count-1].index + 'A')).ToString();
                ans.Add(a);
            }
        }

        Console.WriteLine(string.Join(" ", ans));
    }

    static void Main() {
        int t = ReadInt();
        for (int i = 0; i < t; i++) {
            ReadInt();
            var xs = ReadInts();
            Console.Write("Case #{0}: ", i+1);
            Calc(xs);
        }
    }
}
