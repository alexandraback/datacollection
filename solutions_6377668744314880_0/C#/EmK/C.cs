using System;
using System.IO;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Numerics;



public class PointInt {
    public long X { get; set; }
    public long Y { get; set; }

    public PointInt() {

    }

    public PointInt(int x, int y) {
        this.X = x;
        this.Y = y;
    }

    public static PointInt operator +(PointInt p1, PointInt p2) {
        return new PointInt { X = p1.X + p2.X, Y = p1.Y + p2.Y };
    }

    public static PointInt operator -(PointInt p1, PointInt p2) {
        return new PointInt { X = p1.X - p2.X, Y = p1.Y - p2.Y };
    }

    public override bool Equals(object obj) {
        if (obj == null || GetType() != obj.GetType()) {
            return false;
        }
        var p = obj as PointInt;
        return this.X == p.X && this.Y == p.Y;
    }

    public override int GetHashCode() {
        return base.GetHashCode();
    }

    public long Norm {
        get {
            return 1L * X * X + 1L * Y * Y;
        }
    }

    public override string ToString() {
        return string.Format("({0},{1})", X, Y);
    }
}

public static class GeometryIntUtility {
    static public long DotProduct(PointInt p1, PointInt p2) {
        return (long)p1.X * p2.X + (long)p1.Y * p2.Y;
    }

    static public long CrossProduct(PointInt p1, PointInt p2) {
        return (long)p1.X * p2.Y - (long)p1.Y * p2.X;
    }

    static public int CCW(PointInt p1, PointInt p2, PointInt p3) {
        p2 -= p1;
        p3 -= p1;
        var cross = CrossProduct(p2, p3);
        if (cross > 0) return +1;
        if (cross < 0) return -1;
        if (p2.X * p3.X < 0 || p2.Y * p3.Y < 0) return +2;
        if (p2.Norm < p3.Norm) return -2;
        return 0;
    }

    static private void Traverse(List<PointInt> result, IEnumerable<PointInt> polygon, int t) {
        foreach (var p in polygon) {
            while (result.Count >= t
                && CCW(result[result.Count - 2], result[result.Count - 1], p) <= 0) {
                result.RemoveAt(result.Count - 1);
            }
            result.Add(p);
        }
    }

    static public List<PointInt> ConvexHull(List<PointInt> polygon) {
        int n = polygon.Count;
        if (n <= 3) return polygon.ToList();
        polygon.Sort((p1, p2) => {
            if (p1.Y != p2.Y) return p1.Y.CompareTo(p2.Y);
            return p1.X.CompareTo(p2.X);
        });
        var result = new List<PointInt>(2 * n);
        Traverse(result, polygon, 2);
        Traverse(result, polygon.AsEnumerable().Reverse(), result.Count + 1);
        return result;
    }

    static public bool OnSegment(PointInt p1, PointInt p2, PointInt q) {
        var distanceP1AndQ = (p1 - q).Norm;
        var distanceP2AndQ = (p2 - q).Norm;
        var distanceP1AndP2 = (p2 - p1).Norm;
        var r = distanceP1AndP2 - distanceP1AndQ - distanceP2AndQ;
        if (r < 0) return false;
        //return 4 * distanceP1AndQ * distanceP2AndQ == r * r;
        return BigInteger.One * 4 * distanceP1AndQ * distanceP2AndQ == BigInteger.One * r * r;
    }
}
partial class Solver {
    public void Run() {
        var t = ni();
        int caseNo = 1;
        while (t-- > 0) {

            var N = ni();
            var points = new List<PointInt>();
            var toIndex = new Dictionary<PointInt, int>();

            for (int i = 0; i < N; i++) {
                int x = ni();
                int y = ni();
                var p = new PointInt(x, y);
                points.Add(p);
                toIndex[p] = i;
            }

            var ans = new int[N];
            for (int i = 0; i < N; i++) {
                ans[i] = int.MaxValue;
            }

            for (int i = 0; i < (1 << N); i++) {
                var target = new List<PointInt>();
                for (int j = 0; j < N; j++) {
                    if ((i & (1 << j)) != 0) {
                        target.Add(points[j]);
                    }
                }
                int removed = N - target.Count;
                var convex = GeometryIntUtility.ConvexHull(target);
                foreach (var p in convex) {
                    for (int j = 0; j < N; j++) {
                        if (points[j] == p) {
                            ans[j] = Math.Min(ans[j], removed);
                        }
                    }
                }
                for (int j = 0; j < convex.Count; j++) {
                    int j2 = (j + 1) % convex.Count;
                    for (int k = 0; k < N; k++) {
                        if (GeometryIntUtility.OnSegment(convex[j], convex[j2], points[k])) {
                            ans[k] = Math.Min(ans[k], removed);
                        }
                    }
                }
            }

            cout.WriteLine("Case #{0}:", caseNo++);
            foreach (var a in ans) {
                cout.WriteLine(a);
            }
        }
    }
}

// PREWRITEN CODE BEGINS FROM HERE
partial class Solver : Scanner {
    public static void Main(string[] args) {
        /*new Solver(@"2
5
0 0
10 0
10 10
0 10
5 5
9
0 0
5 0
10 0
0 5
5 5
10 5
0 10
5 10
10 10", Console.Error).Run();*/
        new Solver(Console.In, Console.Out).Run();
    }

    TextReader cin;
    TextWriter cout;

    public Solver(TextReader reader, TextWriter writer)
        : base(reader) {
        this.cin = reader;
        this.cout = writer;
    }
    public Solver(string input, TextWriter writer)
        : this(new StringReader(input), writer) {
    }

    public int ni() {
        return NextInt();
    }
    public long nl() {
        return NextLong();
    }
    public string ns() {
        return Next();
    }
}

public class Scanner {
    private TextReader Reader;
    private Queue<String> TokenQueue = new Queue<string>();
    private CultureInfo ci = CultureInfo.InvariantCulture;

    public Scanner()
        : this(Console.In) {
    }

    public Scanner(TextReader reader) {
        this.Reader = reader;
    }

    public int NextInt() { return Int32.Parse(Next(), ci); }
    public long NextLong() { return Int64.Parse(Next(), ci); }
    public double NextDouble() { return double.Parse(Next(), ci); }
    public string[] NextArray(int size) {
        var array = new string[size];
        for (int i = 0; i < size; i++) array[i] = Next();
        return array;
    }
    public int[] NextIntArray(int size) {
        var array = new int[size];
        for (int i = 0; i < size; i++) array[i] = NextInt();
        return array;
    }

    public long[] NextLongArray(int size) {
        var array = new long[size];
        for (int i = 0; i < size; i++) array[i] = NextLong();
        return array;
    }

    public String Next() {
        if (TokenQueue.Count == 0) {
            if (!StockTokens()) throw new InvalidOperationException();
        }
        return TokenQueue.Dequeue();
    }

    public bool HasNext() {
        if (TokenQueue.Count > 0)
            return true;
        return StockTokens();
    }

    private bool StockTokens() {
        while (true) {
            var line = Reader.ReadLine();
            if (line == null) return false;
            var tokens = line.Trim().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            if (tokens.Length == 0) continue;
            foreach (var token in tokens)
                TokenQueue.Enqueue(token);
            return true;
        }
    }
}
