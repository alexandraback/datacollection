using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ_2016_Round1C
{
    public class A
    {
        private void Run()
        {
            int T = int.Parse(Console.ReadLine().Trim());
            for (int testcase = 1; testcase <= T; ++testcase)
            {
                var N = int.Parse(Console.ReadLine().Trim());
                var P = Console.ReadLine().Trim().Split().Select(int.Parse).ToArray();

                var queue = new PriorityQueue<Tuple<int, char>>();
                for (int i = 0; i < P.Length; i++)
                {
                    queue.Push(Tuple.Create(-P[i], (char)('A' + i)));
                }

                var list = new List<string>();
                while (queue.Count > 0)
                {
                    var a = queue.Pop();
                    if (queue.Count > 0 && a.Item1 + 1 <= queue.Peek().Item1)
                    {
                        list.Add("" + a.Item2 + a.Item2);
                        if (a.Item1 < -2)
                        {
                            queue.Push(Tuple.Create(a.Item1 + 2, a.Item2));
                        }
                    }
                    else if (a.Item1 == -1 && queue.Count == 2 && queue.Peek().Item1 == -1)
                    {
                        list.Add("" + a.Item2);
                    }
                    else
                    {
                        var b = queue.Pop();
                        list.Add("" + a.Item2 + b.Item2);
                        if (a.Item1 != -1)
                        {
                            queue.Push(Tuple.Create(a.Item1 + 1, a.Item2));
                        }
                        if (b.Item1 != -1)
                        {
                            queue.Push(Tuple.Create(b.Item1 + 1, b.Item2));
                        }
                    }
                }

                Console.Write("Case #{0}: ", testcase);
                Console.WriteLine(string.Join(" ", list));
            }
        }

        private static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new A().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }

        public class PriorityQueue<T>
        {
            public PriorityQueue() : this(Comparer<T>.Default) { }
            public PriorityQueue(IComparer<T> compare)
            {
                this.m_buffer = new List<T>();
                this.m_comparer = compare;
            }

            public void Push(T elem)
            {
                int n = this.m_buffer.Count;
                this.m_buffer.Add(elem);
                while (n != 0)
                {
                    int i = (n - 1) / 2;
                    if (this.m_comparer.Compare(this.m_buffer[i], this.m_buffer[n]) > 0)
                    {
                        T temp = this.m_buffer[i];
                        this.m_buffer[i] = this.m_buffer[n];
                        this.m_buffer[n] = temp;
                    }
                    n = i;
                }
            }
            public T Pop()
            {
                int n = this.m_buffer.Count - 1;
                var res = this.m_buffer[0];
                this.m_buffer[0] = this.m_buffer[n];
                this.m_buffer.RemoveAt(n);
                int i = 0, j;
                while (true)
                {
                    j = 2 * i + 1;
                    if (j >= n) { break; }
                    if (j < n - 1 && this.m_comparer.Compare(this.m_buffer[j], this.m_buffer[j + 1]) > 0) { ++j; }
                    if (this.m_comparer.Compare(this.m_buffer[i], this.m_buffer[j]) > 0)
                    {
                        T temp = this.m_buffer[i];
                        this.m_buffer[i] = this.m_buffer[j];
                        this.m_buffer[j] = temp;
                    }
                    i = j;
                }
                return res;
            }
            public T Peek() { return this.m_buffer[0]; }
            public int Count { get { return this.m_buffer.Count; } }
            public void Clear() { this.m_buffer.Clear(); }

            private readonly List<T> m_buffer;
            private readonly IComparer<T> m_comparer;
        }
    }
}
