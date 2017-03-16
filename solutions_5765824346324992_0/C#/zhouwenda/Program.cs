using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using Priority_Queue;

// using priority queue library from https://bitbucket.org/BlueRaja/high-speed-priority-queue-for-c/wiki/Home

namespace GCJ_1A
{
    class Program
    {
        static void Main(string[] args) {
            List<ProblemInstance> problems;

            using (var f = File.Open(args[0], FileMode.Open))
            using (var tr = new StreamReader(f)) {
                problems = ParseProblems(tr);
            }

            var results = problems.Select(x => x.ComputeResult());

            PrintResult(results);
        }

        private static List<ProblemInstance> ParseProblems(TextReader reader) {
            int count = int.Parse(reader.ReadLine());

            var result = new List<ProblemInstance>(count);

            for (int i = 0; i < count; i++) {
                int[] parameters = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();

                int n = parameters[1];

                int[] barberLengths = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();

                result.Add(new ProblemInstance(n, barberLengths));
            }

            return result;
        }

        static void PrintResult(IEnumerable<int> results) {
            int counter = 1;
            foreach (var result in results) {
                Console.WriteLine("Case #{0}: {1}", counter++, result);
            }
        }
    }

    class BarberTime : PriorityQueueNode
    {
        public BarberTime(int id, int endTime) {
            this.BarberId = id;
            this.EndTime = endTime;
        }

        public int  BarberId { get; private set; }
        public int EndTime { get; set; }

        public double ComputePriority() {
            return EndTime + BarberId/1e6;
        }
    }

    class ProblemInstance {
        private readonly int n;
        private readonly int[] barberLengths;

        public ProblemInstance(int n, int[] barberLengths) {
            this.n = n;
            this.barberLengths = barberLengths;
        }

        public int ComputeResult() {
            int cycleTime = barberLengths.Aggregate(1, (x, y) => x*y/(int) BigInteger.GreatestCommonDivisor(x, y));
            int cycleCount = barberLengths.Select(x => cycleTime/x).Sum();

            int remainder = n%cycleCount;

            if (remainder == 0) {
                remainder = cycleCount;
            }

            HeapPriorityQueue<BarberTime> queue = new HeapPriorityQueue<BarberTime>(barberLengths.Length);

            for (int i = 0; i < barberLengths.Length; i++) {
                var node = new BarberTime(i, 0);
                queue.Enqueue(node, node.ComputePriority());
            }

            for (int i = 0; i < remainder - 1; i++) {
                var currentBarber = queue.Dequeue();
                currentBarber.EndTime += barberLengths[currentBarber.BarberId];
                queue.Enqueue(currentBarber, currentBarber.ComputePriority());
            }

            return queue.Dequeue().BarberId + 1;
        }
    }
}
