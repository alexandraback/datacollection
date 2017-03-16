using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApplication2
{
    class Program
    {
        private static long loadedember(long T, long[] Mk)
        {
            long[] load = new long[Mk.Length];
            long sum = 0;
            for (int i = 0; i < Mk.Length; i++)
            {
                load[i] = T / Mk[i] + 1;//(long)Math.Ceiling((double)T / Mk[i]);
                sum += load[i];
            }

            return sum;
        }

        private static long logsearchT(long N, long[] Mk)
        {
            //long prevT = 0;
            if (loadedember(0, Mk) >= N) return 0;
            long T = 0;
            long lastjump = 2;
            int dir = 1;
           /* while (lastjump != 1)
            {
                T += lastjump;
                long ember = loadedember(T, Mk);
                if ((ember - N) * dir >= 0)
                {
                    dir *= -1;
                    lastjump /= 2;
                }
                lastjump *= 2;
            }*/

            long prevT = T;
            long ember = loadedember(T, Mk);
            bool firstpass = true;
            while (Math.Abs(lastjump) >= 1)
            {
                prevT = T;
                do
                {
                    T += lastjump;
                    if (firstpass) lastjump *= 2;
                    ember = loadedember(T, Mk);
                } while (ember*dir <= N*dir);
                dir *= -1;
                lastjump *= -1;
                lastjump /= 2;
                if (firstpass) lastjump /= 2;
                firstpass = false;
            }
            if (dir == 1) return T;
            else return prevT;
        }

        static long simfromT(long T, long N, long[] Mk)
        {
            long ember = loadedember(T, Mk);
            if (ember == N)
            {
                //return simfromT(T - 1, N, Mk);
                for (int i = Mk.Length-1; i >= 0; i--)
                {
                    if (T % Mk[i] == 0)
                    {
                         return i+1;
                    }
                }
            }
            while (true)//dealwithit
            {
                T++;
                for (int i = 0; i < Mk.Length; i++)
                {
                    if (T % Mk[i] == 0)
                    {
                        ember++;
                        if (ember == N) return i+1;
                    }
                }
            }
        }

        static void Main(string[] args)
        {
           //  StreamReader sr = new StreamReader("B-small-attempt1.in");
         //    StreamWriter sw = new StreamWriter("B-small-attempt1.out");

            StreamReader sr = new StreamReader("B-large.in");
            StreamWriter sw = new StreamWriter("B-large.out");
          //    StreamReader sr = new StreamReader("B.in");
      //          StreamWriter sw = new StreamWriter("B.out");
            int T = Int32.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                //int N = Int32.Parse(sr.ReadLine());
                string[] line = sr.ReadLine().Split(' ');
                long B = Int64.Parse(line[0]);
                long N = Int64.Parse(line[1]);
                line = sr.ReadLine().Split(' ');
                long[] line2 = new long[line.Length];
                for (int j = 0; j < line.Length; j++)
                {
                    line2[j] = Int64.Parse(line[j]);
                }

                long time = logsearchT(N, line2);
                long id = simfromT(time, N, line2);

                sw.WriteLine("Case #{0}: {1}", i + 1,  id);
                sw.Flush();
            }
            sr.Close();
            sw.Flush();
            sw.Close();
        }

    }
}
