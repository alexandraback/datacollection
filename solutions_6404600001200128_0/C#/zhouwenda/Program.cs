using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Mushroom
{
    class Program
    {
        static void Main(string[] args) {
            List<ProblemInstance> problems;

            using (var f = File.Open(args[0], FileMode.Open))
            using (var tr = new StreamReader(f)) {
                problems = ParseInstances(tr);
            }

            var results = problems.Select(x => x.ComputeResult());
            PrintResult(results);
        }

        static List<ProblemInstance> ParseInstances(TextReader reader) {
            int count = int.Parse(reader.ReadLine());
            var result = new List<ProblemInstance>(count);

            for (int i = 0; i < count; i++) {
                int elementCount = int.Parse(reader.ReadLine());

                var data = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();

                result.Add(new ProblemInstance(data));
            }

            return result;
        }

        static void PrintResult(IEnumerable<ProblemResult> results) {
            int problemCount = 1;

            foreach (var problemResult in results) {
                Console.WriteLine("Case #{0}: {1} {2}", problemCount++, problemResult.MushroomEaten, problemResult.MushroomEatenConstantRate);
            }
        }
    }

    class ProblemInstance {
        private readonly int[] mushrooms;

        public ProblemInstance(int[] mushrooms) {
            this.mushrooms = mushrooms;
        }

        public ProblemResult ComputeResult() {
            long[] pairwiseDifference = new long[mushrooms.Length - 1];

            for (int i = 0; i < pairwiseDifference.Length; i++) {
                pairwiseDifference[i] = mushrooms[i + 1] - mushrooms[i];
            }

            long mushroomEaten = -pairwiseDifference.Where(x => x < 0).DefaultIfEmpty(0).Sum();

            long maxEatRate = -pairwiseDifference.Where(x => x < 0).DefaultIfEmpty(0).Min();

            long mushroomEatenConstRate = 0;

            for (int i = 0; i < mushrooms.Length - 1; i++) {
                mushroomEatenConstRate += Math.Min(maxEatRate, mushrooms[i]);
            }

            return new ProblemResult {
                MushroomEaten = mushroomEaten,
                MushroomEatenConstantRate = mushroomEatenConstRate
            };
        }
    }

    class ProblemResult {
        public long MushroomEaten { get; set; }
        public long MushroomEatenConstantRate { get; set; }
    }
}
