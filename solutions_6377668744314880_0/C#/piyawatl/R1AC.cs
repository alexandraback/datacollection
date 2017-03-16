using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2015
{
    class R1AC_Logging
    {
        const bool logEnabled = false;
        static string baseFileName = "C-small-attempt0";
        string inputFile = baseFileName + ".in";
        string outputFile = baseFileName + ".out";
        string logFile = baseFileName + ".log";
        StreamReader reader;
        StreamWriter writer;
        StreamWriter logWriter;
        private void Log(string message)
        {
            if (!logEnabled) return;
            logWriter.WriteLine(message);
        }

        private string Result { get; set; }

        private int N { get; set; }
        private List<Point> Points { get; set; }
        private List<Point> Temp { get; set; }
        private List<Point> ConvexHull { get; set; }
        
        private class Point : IComparable<Point>
        {
            public long X { get; set; }
            public long Y { get; set; }
            public int Index { get; set; }
            public Point Anchor { get; set; }
            public int MinCut { get; set; }

            public Point(long x, long y, int originalIndex)
            {
                X = x;
                Y = y;
                Index = originalIndex;
                MinCut = Int32.MaxValue;
            }

            public int CompareTo(Point other)
            {
                var ccw = (this.X - Anchor.X) * (other.Y - Anchor.Y) - (this.Y - Anchor.Y) * (other.X - Anchor.X);
                return (ccw > 0) ? 1 : (ccw < 0) ? -1 : -(int)(Math.Abs(other.X - Anchor.X) - Math.Abs(this.X - Anchor.X));
            }

            public override string ToString()
            {
                return String.Format("{0}:({1},{2}):{3}", Index, X, Y, MinCut);
            }
        }

        private void ReadInput()
        {
            char[] sep = { ' ' };
            N = Int32.Parse(reader.ReadLine());
            Points = new List<Point>();
            for (int i = 0; i < N; i++)
            {
                var line = reader.ReadLine().Split(sep);
                Points.Add(new Point(Int32.Parse(line[0]), Int32.Parse(line[1]), i));
            }
        }

        private void Solve()
        {
            var builder = new StringBuilder("");
            if (N <= 3)
            {
                for (int i = 0; i < N; i++)
                {
                    builder.AppendLine();
                    builder.Append(0);
                }
                Result = builder.ToString();
                return;
            }

            var minIndex = 0;
            var minX = Points[0].X;
            var minY = Points[0].Y;
            for (int i = 1; i < Points.Count; i++)
            {
                if (Points[i].Y < minY)
                {
                    minIndex = i;
                    minY = Points[i].Y;
                }
            }
            Point bottom = Points[minIndex];

            Temp = new List<Point>(Points);
            Temp.Remove(bottom);
            foreach (var point in Temp)
            {
                point.Anchor = bottom;
            }
            Temp.Sort();

            ConvexHull = new List<Point>();
            ConvexHull.Add(bottom);
            ConvexHull.Add(Temp[0]);

            for (int i = 1; i < Temp.Count; i++)
            {
                int count = ConvexHull.Count;
                var anchor = ConvexHull[count - 2];
                var turn = ConvexHull[count - 1];
                var dest = Temp[i];
                turn.Anchor = anchor;
                dest.Anchor = anchor;
                if (dest.CompareTo(turn) > 0)
                {
                    ConvexHull.Add(dest);
                }
                else
                {
                    ConvexHull[count - 1] = dest;
                }
            }

            foreach (var point in ConvexHull)
            {
                point.MinCut = 0;
            }

            foreach (var point in ConvexHull)
            {
                Temp = new List<Point>(Points);
                Temp.Remove(point);
                foreach (var tempPoint in Temp)
                {
                    tempPoint.Anchor = point;
                }

                Temp.Sort();
                for (int i=0;i<Temp.Count;i++)
                {
                    Temp[i].MinCut = Math.Min(Temp[i].MinCut, i);
                }
            }

            for (int i = 0; i < N; i++)
            {
                builder.AppendLine();
                builder.Append(Points[i].MinCut);
            }
            Result = builder.ToString();
        }

        public void Run()
        {
            reader = new StreamReader(inputFile);
            writer = new StreamWriter(outputFile);
            if (logEnabled)
                logWriter = new StreamWriter(logFile);
            try
            {
                string s = reader.ReadLine();
                int T = Int32.Parse(s);
                for (int t = 1; t <= T; t++)
                {
                    Log("Start Case #" + t);
                    ReadInput();
                    Solve();
                    writer.WriteLine(String.Format("Case #{0}: {1}", t, Result));
                    Log("End Case #" + t);
                }
            }
            finally
            {
                reader.Close();
                writer.Close();
                if (logEnabled)
                    logWriter.Close();
            }
        }
        static void Main(string[] args)
        {
            new R1AC_Logging().Run();
        }
    }
}
