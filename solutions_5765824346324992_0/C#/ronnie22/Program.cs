using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2
{
    class Program
    {
        static char[] delim = { ' ' };
        static void Main(string[] args)
        {
            TextReader input = File.OpenText("../../input.in");
            TextWriter output = File.CreateText("../../output.out");
            int n_case = int.Parse(input.ReadLine());

            for (int caso = 1; caso <= n_case; caso++)
            {
                long ris;
                string[] line = input.ReadLine().Split(delim);
                long b = long.Parse(line[0]);
                long n = long.Parse(line[1]);
                line = input.ReadLine().Split(delim);
                long[] mb = new long[b];
                long minM = long.MaxValue;
                long idMin=0;
                for(int i=0;i<b;i++)
                {
                    mb[i] = long.Parse(line[i]);
                    if (minM >= mb[i]) 
                    {
                        minM = mb[i];
                        idMin = i+1;
                    } 
                }
                //calcolo MCD - MCM
                long mcm = mb[0];
                long mcd = mb[0];
                for (int i = 1; i < b; i++)
                {
                    mcd = MCD(mcm, mb[i]);
                    mcm = (mcm * mb[i]) / mcd;
                }

                //calcolo persone in mcm
                long pers = 0;
                for (int i = 0; i < b; i++)
                {
                    pers += mcm / mb[i];
                }

                n = n % pers;
                if (n <= b)
                {
                    if (n == 0)
                    {
                        ris = idMin;
                    }
                    else
                    {
                        ris = n;
                    }
                }
                else
                {
                    SortedSet<Pair> pq = new SortedSet<Pair>();
                    for (int i = 0; i < b; i++)
                    {
                        pq.Add(new Pair(i+1,mb[i]));
                    }
                    n = n - b;

                    for (long j = 0; j < n-1; j++) 
                    {
                        Pair min = pq.Min;
                        pq.Remove(min);
                        min.num += mb[min.id - 1];
                        pq.Add(min);
                    }
                    ris = pq.Min.id;
                }
                output.WriteLine("Case #" + caso + ": " + ris);
            }
            input.Close();
            output.Close();
        }

        static long MCD(long a, long b) 
        {
            if (a < b) return MCD(b,a);
            if (b == 0) return a;
            return MCD(b, a % b);
        }
    }

    class Pair : IComparable<Pair> 
    {
        public long id;
        public long num;

        public Pair(long id, long n) 
        {
            this.id = id;
            this.num = n;
        }

        public int CompareTo(Pair other)
        {
 	        if(num==other.num)
            {
                return Math.Sign(id - other.id);
            }
            return Math.Sign(num - other.num);
        }
    }
}
