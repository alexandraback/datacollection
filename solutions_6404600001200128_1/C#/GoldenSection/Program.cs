using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace GCJ
{
    class Program
    {
        static void Main(string[] args)
        {
            string inFileName = @"D:\Users\feiyan\GCJ\A\a-large.in";
            string outFileName = @"D:\Users\feiyan\GCJ\A\a-large.out";
            StreamReader reader = new StreamReader(inFileName);
            StreamWriter writer = new StreamWriter(outFileName);

            int T = int.Parse(reader.ReadLine());
            for (int cid = 1; cid <= T; ++cid)
            {
                int n = int.Parse(reader.ReadLine());
                string[] strArray = reader.ReadLine().Split();
                List<int> array = new List<int>();
                foreach(string str in strArray)
                {
                    array.Add(int.Parse(str));
                }
                writer.WriteLine("Case #{0}: {1} {2}", cid, Method1(n, array), Method2(n, array));
            }

            reader.Close();
            writer.Close();
        }

        static int Method1(int n, List<int> array)
        {
            int ret = 0;
            for (int i = 1; i < n; ++i)
            {
                if (array[i - 1] > array[i])
                {
                    ret += array[i - 1] - array[i];
                }
            }
            return ret;
        }

        static int Method2(int n, List<int> array)
        {
            int rate = 0;
            for (int i = 1; i < n; ++i)
            {
                if (array[i - 1] - array[i] > rate)
                {
                    rate = array[i - 1] - array[i];
                }
            }

            int ret = 0;
            for (int i = 0; i < n - 1; ++i)
            {
                if (array[i] < rate)
                {
                    ret += array[i];
                }
                else
                {
                    ret += rate;
                }
            }
            return ret;
        }
    }
}
