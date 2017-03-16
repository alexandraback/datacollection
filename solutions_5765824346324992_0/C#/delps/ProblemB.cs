

namespace Contest
{
    using System;
    using System.IO;

    public class Program
    {
        static void Main(string[] args)
        {
            Wrapper.Solve(new ProblemB(), Console.In, Console.Out);
        }
    }

    public class Wrapper
    {
        public static void Solve(IProblem problem, TextReader input, TextWriter output)
        {
            var parser = new InputParser(input);
            int T = parser.GetInt();

            for (int i = 0; i < T; i++)
            {
                output.WriteLine(string.Format("Case #{0}: {1}", i + 1, problem.SolveOneCase(parser)));
            }
        }
    }

    public interface IProblem
    {
        string SolveOneCase(InputParser input);
    }
}﻿





namespace Contest
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Numerics;

    public class ProblemB : IProblem
    {


        public string SolveOneCase(InputParser input)
        {
            int B = input.GetInt();
            int N = input.GetInt();

            int[] M = input.GetIntArray();

            BigInteger lcm = 1;

            for (int i = 0; i < B; i++)
            {
                lcm = GCD_Calc.LCM(lcm, M[i]);
            }

            BigInteger period = 0;
            for (int i = 0; i < B; i++)
            {
                period += lcm/M[i];
            }
            var pp = (int) period;
            var arr = new int[pp];
            var pq = new PriorityQueue<int>();
            for (int i = 0; i < B; i++)
            {
                arr[i] = i;
                pq.Enqueue(i, M[i]);
            }


            for (int i = B; i < pp; i++)
            {
                var prior = pq.PeakPriority();
                var next = pq.Dequeue();

                arr[i] = next;
                pq.Enqueue(next, prior + M[next]);
            }

            int mod =  (N-1)%pp ;
            var res = arr[mod]+1;


            return res.ToString();
        }
    }

    public class GCD_Calc
    {
        public static BigInteger GCD(BigInteger a, BigInteger b)
        {
            while (b != 0)
            {
                BigInteger t = b;
                b = a % b;
                a = t;
            }

            return a;
        }

        public static BigInteger LCM(BigInteger a, BigInteger b)
        {
            return a / GCD(a, b) * b;
        }
    }

    // Had to roll my own prioirty Queue
    // inspired by: http://stackoverflow.com/questions/102398/priority-queue-in-net
    public class PriorityQueue<T>
    {
        public int Count { get; private set; }

        private SortedDictionary<BigInteger, SortedDictionary<T, T>> dictionary;

        public PriorityQueue()
        {
            dictionary = new SortedDictionary<BigInteger, SortedDictionary<T, T>>();
        }

        public bool IsEmpty
        {
            get { return Count == 0; }
        }

        public void Enqueue(T item, BigInteger priority)
        {
            if( !dictionary.ContainsKey(priority) )
            {
                dictionary.Add(priority, new SortedDictionary<T, T>());
            }

            dictionary[priority].Add(item, item);
            Count++;
        }

        public BigInteger PeakPriority()
        {
            return dictionary.Keys.First();
        }

        public T Dequeue()
        {
            if( IsEmpty )
            {
                throw new InvalidOperationException("Cannot Dequeue.  The queue is empty.");
            }

            BigInteger key = dictionary.Keys.First();
            var sd = dictionary[key];
            
            if (sd.Count == 1)
                dictionary.Remove(key);

            Count--;
            var kk = sd.Keys.First();
            
            var val = sd[kk];
            sd.Remove(kk);
            return val;
        }
    }
}﻿

namespace Contest
{
    using System.Collections;
    using System;
    using System.IO;

    public class InputParser
    {
        private readonly TextReader _textReader;

        private IEnumerator _enumerator;

        public InputParser(TextReader textReader)
        {
            this._textReader = textReader;
            this._enumerator = (new string[0]).GetEnumerator();
        }

        public string ReadLine()
        {
            return _textReader.ReadLine();
        }

        public string[] GetStringArray()
        {
            return ReadLine().Split(new string[0], StringSplitOptions.RemoveEmptyEntries);
        }

        public int[] GetIntArray()
        {
            string[] tokens = GetStringArray();
            int length = tokens.Length;

            var values = new int[length];

            for (int i = 0; i < length; i++)
            {
                values[i] = int.Parse(tokens[i]);
            }

            return values;
        }

        public long[] GetLongArray()
        {
            string[] tokens = GetStringArray();
            int length = tokens.Length;

            var values = new long[length];

            for (int i = 0; i < length; i++)
            {
                values[i] = long.Parse(tokens[i]);
            }

            return values;
        }

        public string GetString()
        {
            while (_enumerator.MoveNext() == false)
            {
                _enumerator = GetStringArray().GetEnumerator();
            }

            return (string)_enumerator.Current;
        }

        public int GetInt()
        {
            return int.Parse(GetString());
        }

        public long GetLong()
        {
            return long.Parse(GetString());
        }
    }
}