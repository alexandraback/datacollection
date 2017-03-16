using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            string inFileName = @"D:\Users\feiyan\GCJ\B\b-large.in";
            string outFileName = @"D:\Users\feiyan\GCJ\B\b-large.out";
            StreamReader reader = new StreamReader(inFileName);
            StreamWriter writer = new StreamWriter(outFileName);

            int T = int.Parse(reader.ReadLine());
            for (int cid = 1; cid <= T; ++cid)
            {
                string[] tokens = reader.ReadLine().Split();
                int B = int.Parse(tokens[0]);
                long N = long.Parse(tokens[1]);
                tokens = reader.ReadLine().Split();
                List<long> M = new List<long>();
                foreach(string item in tokens)
                {
                    M.Add(long.Parse(item));
                }
                writer.WriteLine("Case #{0}: {1}", cid, Solve(B, N, M));
            }

            reader.Close();
            writer.Close();
        }

        static int Solve(int B, long N, List<long> M)
        {
            int ret = 0;
            long lower = 0, upper = M.Max() * N, mid;
            while (lower < upper)
            {
                mid = (lower + upper) / 2;
                long cut = 0;
                long available = 0;
                foreach (long m in M)
                {
                    cut += mid / m;
                    if (mid % m > 0)
                    {
                        cut++;
                    }
                    else
                    {
                        available++;
                    }
                }

                if (cut >= N)
                {
                    upper = mid - 1;
                }
                else if (available < N - cut)
                {
                    lower = mid + 1;
                }
                else
                {
                    long count = 0;
                    for (int i = 0; i < B && ret == 0; ++i)
                    {
                        if (mid % M[i] == 0)
                        {
                            count++;
                            if (count == N - cut)
                            {
                                ret = i + 1;
                            }
                        }
                    }
                    break;
                }
            }

            if (ret == 0)
            {
                mid = lower;
                long cut = 0;
                long available = 0;
                foreach (long m in M)
                {
                    cut += mid / m;
                    if (mid % m > 0)
                    {
                        cut++;
                    }
                    else
                    {
                        available++;
                    }
                }
                long count = 0;
                for (int i = 0; i < B && ret == 0; ++i)
                {
                    if (mid % M[i] == 0)
                    {
                        count++;
                        if (count == N - cut)
                        {
                            ret = i + 1;
                        }
                    }
                }
            }

            return ret;
        }
    }
}
