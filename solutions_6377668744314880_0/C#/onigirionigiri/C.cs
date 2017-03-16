using System;
using System.IO;
using System.Text;
using System.Collections;
using System.Diagnostics;
using System.Collections.Generic;
using System.Numerics;
using System.Linq;

public class ClassName
{
    public static void Main()
    {
        new ClassName().Entry();
    }//Main

    StreamReader sr = new StreamReader(@"C:\Users\user1\Downloads\C-small-attempt1.in");
    StreamWriter sw = new StreamWriter(@"C:\Users\user1\Documents\Visual Studio 2012\Projects\GCJ\GCJ\C.txt");


    void Entry()
    {
        int T = intRead();
        for (int i = 0; i < T; i++)
        {
            var res = Solve();
            //sw.WriteLine("Case #1:\n");
            Write("Case #" + (i + 1) + ": ");
            foreach (var item in res)
            {
                Write(item.ToString());
            }//foreach item
        }//for i
        sw.Close();
        sr.Close();
    }

    private int[] Solve()
    {
        int n = intRead();
        var res = Enumerable.Repeat(int.MaxValue, n).ToArray();
        var x = new int[n];
        var y = new int[n];
        for (int i = 0; i < n; i++)
        {
            var tmp = intSplit(' ');
            x[i] = tmp[0];
            y[i] = tmp[1];
        }//for i
        if (n == 1)
        {
            return new int[1];
        }//if
        List<int> cx;
        List<int> cy;
        ConvexHull(x, y, out cx, out cy);
        for (int i = 0; i < cx.Count; i++)
        {
            for (int k = 0; k < n; k++)
            {
                if (cx[i] == x[k] && cy[i] == y[k])
                {
                    res[k] = 0;
                }//if
            }//for k
            for (int j = 0; j < cx.Count; j++)
            {
                if (cx[i]==cx[j]&&cy[i]==cy[j])
                {
                    continue;
                }//if
                for (int k = 0; k < n; k++)
                {
                    int sign = Math.Sign(TriangleArea(cx[i], cy[i], cx[j], cy[j], x[k], y[k]));
                    if (sign<0)
                    {
                        continue;
                    }//if
                    int cnt = 0;
                    for (int t = 0; t < n; t++)
                    {
                        if (Math.Sign(TriangleArea(cx[i], cy[i], cx[j], cy[j], x[t], y[t]))>0)
                        {
                            cnt++;
                        }//if
                    }//for t
                    res[k] = Math.Min(res[k], cnt);
                }//for k
            }//for j
        }//for i

        return res;
    }


    /// <summary>
    /// varified by SRM313 DIV1 hard BasketballStrategy
    /// 三角形の面積を求める
    /// O(1)
    /// <returns>面積</returns>
    public static long TriangleArea(long x0, long y0, long x1, long y1, long x2, long y2)
    {
        long x = x0 - x1; long y = y0 - y1;
        long xx = x0 - x2; long yy = y0 - y2;
        return x * yy - xx * y;
    }//TriangleArea

    /// <summary>
    /// varified by SRM401 DIV1 Hard NCool
    /// ２次元凸包を求める
    /// x でソートする
    /// 直線の時は、端以外は２重に出てくる
    ///  O( n log n )
    /// </summary>
    /// <param name="x">点の x 座標</param>
    /// <param name="y">点の y 座標</param>
    /// <param name="nx">凸包の点の x 座標</param>
    /// <param name="ny">凸包の点の y 座標</param>
    public static void ConvexHull(int[] x, int[] y, out List<int> nx, out List<int> ny)
    {
        int[] cx = (int[])x.Clone();
        int[] cy = (int[])y.Clone();
        Array.Sort(cx, cy);

        List<int> ux; List<int> uy;
        List<int> dx; List<int> dy;
        MakeHull(cx, cy, out ux, out uy, true);
        MakeHull(cx, cy, out dx, out dy, false);

        nx = new List<int>();
        ny = new List<int>();
        int cnt = ux.Count;
        for (int i = 0; i < cnt; i++)   //上半分
        {
            nx.Add(ux[i]);
            ny.Add(uy[i]);
        }//for i

        //下半分。端を重複させないようにする
        if (ux[cnt - 1] == dx[dx.Count - 1] && uy[cnt - 1] == dy[dy.Count - 1])
        {
            dx.RemoveAt(dx.Count - 1);
            dy.RemoveAt(dy.Count - 1);
        }
        for (int i = dx.Count - 1; i >= 1; i--)
        {
            nx.Add(dx[i]);
            ny.Add(dy[i]);
        }//forrev i
        if (ux[0] != dx[0] || uy[0] != dy[0])
        {
            nx.Add(dx[0]);
            ny.Add(dy[0]);
        }
    }//ConvexHull

    /// <summary>
    /// 上または下の凸包を求める
    /// O( n )
    /// </summary>
    /// <param name="cx"></param>
    /// <param name="cy"></param>
    /// <param name="nx"></param>
    /// <param name="ny"></param>
    /// <param name="up"></param>
    private static void MakeHull(int[] cx, int[] cy, out List<int> nx, out List<int> ny, bool up)
    {
        int len = cx.Length;
        List<int> x = new List<int>();
        List<int> y = new List<int>();
        MakeUnique(cx, cy, up, len, x, y);
        MakeHull(x, y, out nx, out ny, up);
    }//MakeHull

    /// <summary>
    /// x 座標が同じものを消す
    /// O( n )
    /// </summary>
    /// <param name="cx"></param>
    /// <param name="cy"></param>
    /// <param name="up"></param>
    /// <param name="len"></param>
    /// <param name="x"></param>
    /// <param name="y"></param>
    private static void MakeUnique(int[] cx, int[] cy, bool up, int len, List<int> x, List<int> y)
    {
        for (int i = 0; i < len; )
        {
            int index = i;
            int j = i + 1;
            for (; j < len && cx[j] == cx[index]; j++)
            {
                if (up && cy[index] < cy[j]) index = j;
                if (!up && cy[index] > cy[j]) index = j;
            }//for j
            x.Add(cx[index]);
            y.Add(cy[index]);
            i = j;
        }//for i
    }//MakeUnique

    /// <summary>
    /// 凸包を追加していく
    /// O( n )
    /// </summary>
    /// <param name="x"></param>
    /// <param name="y"></param>
    /// <param name="nx"></param>
    /// <param name="ny"></param>
    /// <param name="up"></param>
    private static void MakeHull(List<int> x, List<int> y, out List<int> nx, out List<int> ny, bool up)
    {
        nx = new List<int>();
        ny = new List<int>();
        int cnt = x.Count;
        for (int i = 0; i < cnt; i++)
        {
            if (nx.Count < 2)
            {
                nx.Add(x[i]);
                ny.Add(y[i]);
                continue;
            }//if
            do
            {
                int c = nx.Count;
                int x0 = x[i] - nx[c - 1]; int y0 = y[i] - ny[c - 1];
                int x1 = x[i] - nx[c - 2]; int y1 = y[i] - ny[c - 2];
                int sign = x0 * y1 - x1 * y0;
                if (up && sign > 0) break;
                if (!up && sign < 0) break;
                nx.RemoveAt(nx.Count - 1);
                ny.RemoveAt(ny.Count - 1);
            } while (nx.Count >= 2);
            nx.Add(x[i]);
            ny.Add(y[i]);
        }//for i
    }//MakeHull



    void Write(string str)
    {
        Console.WriteLine(str);
        sw.WriteLine(str);
    }

    string strRead()
    {
        return sr.ReadLine();
    }

    int intRead()
    {
        return int.Parse(sr.ReadLine());
    }

    long longRead()
    {
        return long.Parse(sr.ReadLine());
    }

    double doubleRead()
    {
        return double.Parse(sr.ReadLine());
    }

    string[] strSplit(char c)
    {
        return sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries);
    }

    int[] intSplit(char c)
    {
        return Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries), int.Parse);
    }

    long[] longSplit(char r)
    {
        return Array.ConvertAll<string, long>(sr.ReadLine().Split(new char[] { r }, StringSplitOptions.RemoveEmptyEntries), long.Parse);
    }

    double[] doubleSplit(char c)
    {
        return Array.ConvertAll<string, double>(sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries), double.Parse);
    }

}//ClassName