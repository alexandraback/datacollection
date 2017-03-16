using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam.Round1B
{
    class B
    {
        static void Main(string[] args)
        {
            for (var r = 1; r < 16; r++)
                for (var c = 1; c < 16; c++)
                    if (r * c <= 16)
                        for (var n = 0; n <= r * c; n++)
                            Console.WriteLine("{0}x{1}, {2} = {3}", r, c, n, Solver.SolveCase(r, c, n));

            var input = @"..\..\Round1B\B-small-attempt0.in";

            var result = Solver.Solve(File.ReadAllLines(input));
            File.WriteAllLines(Path.ChangeExtension(input, "out"), result);

            Console.WriteLine("Press ENTER to finish");
            Console.ReadLine();
        }

        public class Solver
        {
            public static IEnumerable<string> Solve(IEnumerable<string> input)
            {
                var reader = new Reader(input);
                var testCount = int.Parse(reader.Next());

                for (var i = 0; i < testCount; i++)
                {
                    var value = reader.Next().Split(' ').Select(int.Parse).ToArray();
                    var r = value[0];
                    var c = value[1];
                    var n = value[2];

                    yield return string.Format("Case #{0}: {1}", i + 1, SolveCase(r, c, n));
                }
            }

            static readonly Dictionary<Tuple<int, int, int>, int> _cache = new Dictionary<Tuple<int, int, int>, int>();

            public static int SolveCase(int r, int c, int n)
            {
                var key = Tuple.Create(r, c, n);
                int value;

                if (_cache.TryGetValue(key, out value))
                    return value;

                var rooms = new bool[r][];

                for (var i = 0; i < r; i++)
                    rooms[i] = new bool[c];

                var result = Solve(rooms, n, 0, -1);

                _cache[key] = result;

                return result;
            }

            static int Solve(bool[][] rooms, int n, int parentR, int parentC)
            {
                if (n == 0)
                    return CountSharedWalls(rooms);

                var min = int.MaxValue;

                for (var r = parentR; r < rooms.Length; r++)
                    for (var c = r == parentR ? parentC + 1 : 0; c < rooms[0].Length; c++)
                    {
                        if (rooms[r][c] == false)
                        {
                            rooms[r][c] = true;
                            min = Math.Min(min, Solve(rooms, n - 1, r, c));
                            rooms[r][c] = false;
                        }
                    }

                return min;
            }

            static int CountSharedWalls(bool[][] rooms)
            {
                var counter = 0;
                for (var r = 0; r < rooms.Length; r++)
                    for (var c = 0; c < rooms[0].Length; c++)
                    {
                        if (rooms[r][c])
                        {
                            if (r > 0 && rooms[r - 1][c])
                                counter++;

                            if (r < rooms.Length - 1 && rooms[r + 1][c])
                                counter++;

                            if (c > 0 && rooms[r][c - 1])
                                counter++;

                            if (c < rooms[0].Length - 1 && rooms[r][c + 1])
                                counter++;
                        }
                    }

                return counter / 2;
            }
        }

        class Reader
        {
            readonly IEnumerator<string> _enumerator;

            public Reader(IEnumerable<string> lines)
            {
                _enumerator = lines.GetEnumerator();
            }

            public string NextOrNull()
            {
                if (!_enumerator.MoveNext())
                    return null;

                return _enumerator.Current;
            }

            public string Next()
            {
                if (!_enumerator.MoveNext())
                    throw new ApplicationException("End of input");

                return _enumerator.Current;
            }
        }
    }
}
