//#define ONLINE_JUDGE
#define DEBUG

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

class Program
{

    static int tests = 2;

#if (ONLINE_JUDGE)
    static TextReader r = Console.In;
    static TextWriter w = Console.Out;
#else
    static string path = @"C:\Y\Prog\GoogleCodeJam\2015\Этап2\2\";
    static string answerFile = "0{0}Answer.txt";
    static string resultFile = "0{0}Result.txt";
    static string sourceFile = "0{0}Source.txt";
    
    static TextReader r;
    static TextWriter w;
#endif

    static void Main(string[] args)
    {
        for (int i = 1; i <= tests; i++)
        {
#if (!ONLINE_JUDGE)
            r = new StreamReader(string.Format(path + sourceFile, i));
            w = new StreamWriter(string.Format(path + resultFile, i), false);
#endif
            string s = r.ReadLine();
            int cases = Convert.ToInt32(s);
            for (int j = 0; j < cases; j++)
                solve(j+1);
#if (!ONLINE_JUDGE)
            w.Flush(); w.Close();
            Console.WriteLine("CASE: {0}", i);
            string answer = File.ReadAllText(string.Format(path + answerFile, i));
            string result = File.ReadAllText(string.Format(path + resultFile, i));
            if (answer != result)
            {
                Console.WriteLine("FAIL:");
                Console.WriteLine("Result" + Environment.NewLine + result);
                Console.WriteLine("Answer" + Environment.NewLine + answer);
            }
            else
                Console.WriteLine("OK");
#endif
        }
    }

    public static void solve(int c)
    {
        int res = int.MaxValue;
        string[] b = r.ReadLine().Split(' ');
        int x = Convert.ToInt32(b[0]);
        int y = Convert.ToInt32(b[1]);
        int t = Convert.ToInt32(b[2]);

        //int[] dx = { 0, 0, 1, -1 };
        //int[] dy = { 1, -1, 0, 0 };

        int n = x * y;
        bool[,] occ = new bool[x, y]; 
        for (long i = 0; i < (1 << x * y); i++)
        {
            int cnt = 0;
            for (int j = 0; j <= n - 1; j++)
                if ( (i & (1 << j)) > 0 ) 
                {                
                    occ[j/y, j%y] = true;
                    cnt++;
                }
                else
                {
                    occ[j / y, j % y] = false;
                }
            if (cnt != t) continue;
            int cur = 0;
            for (int xi = 0; xi < (x-1); xi++)
                for (int yi = 0; yi < y; yi++)
                    if (occ[xi, yi] && occ[xi + 1, yi])
                        cur++;
            for (int xi = 0; xi < x; xi++)
                for (int yi = 0; yi < (y - 1); yi++)
                    if (occ[xi, yi] && occ[xi, yi + 1])
                        cur++;
            
                //for (int d = 0; d < dx.Length; d++)            
                    //{
                    //    int xn = xi + dx[d];
                    //    int yn = xi + dy[d];
                    //    if (xn < 0 || xn >= x) continue;
                    //    if (yn < 0 || yn >= y) continue;
                    //    if (occ[xi, yi] && occ[xn, yn]) 
                    //        cur++;
                    //}
            res = Math.Min(res, cur);
        }
        w.WriteLine("Case #{0}: {1}", c, res); 
    }

}
