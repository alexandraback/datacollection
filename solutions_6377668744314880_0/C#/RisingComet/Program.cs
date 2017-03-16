using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Delicious_Fruit_Eurobeat_Remix
{
    class Program
    {
        static int T;
        static int curtest = 0;

        static void Main(string[] args)
        {
            StreamReader inputreader;
            StreamWriter outputwriter;
            String[] read;

            int N = 0;
            int[] xs;
            int[] ys;
            int[] log;
            double[] thetas;
            int count = 0;
            int curmincount;
            int minmincount;
            int minx, miny, maxx, maxy;

            int loop;
            int loop2;
            int loop3;

            inputreader = new StreamReader("../../input.txt");
            outputwriter = new StreamWriter("../../output.txt");

            read = inputreader.ReadLine().Split(' ');

            T = Convert.ToInt32(read[0]);

            while (curtest < T)
            {
                read = inputreader.ReadLine().Split(' ');

                N = Convert.ToInt32(read[0]);
                xs = new int[N];
                ys = new int[N];
                log = new int[N];
                thetas=new double[N];
                minx = 1000000;
                maxx = -1000000;
                miny = 1000000;
                maxy = -1000000;

                loop = 0;
                while (loop < N) { read = inputreader.ReadLine().Split(' '); xs[loop] = Convert.ToInt32(read[0]); ys[loop] = Convert.ToInt32(read[1]);
                    if (xs[loop]<minx) minx=xs[loop];
                    if (ys[loop] < miny) miny = ys[loop];
                    if (xs[loop] > maxx) maxx = xs[loop];
                    if (ys[loop] < maxy) maxy = ys[loop];
                    loop += 1; }

                loop = 0;
                while (loop < N)
                {
                    if ((xs[loop] == minx) || (xs[loop] == maxx) || (ys[loop] == miny) || (ys[loop] == maxy)) { log[loop] = 0; }
                    else
                    {
                        loop2=0;
                        while(loop2<N)
                        {
                            if (loop2 == loop) thetas[loop2] = double.NaN;
                            else thetas[loop2] = Math.Atan2((double)(ys[loop] - ys[loop2]), (double)(xs[loop] - xs[loop2]));
                            loop2+=1;
                        }
                        Array.Sort(thetas);
                        minmincount = N; curmincount = N; count = 0;
                        loop2=0;
                        while(loop2<N)
                        {
                            if (Double.IsNaN(thetas[loop2])==false)
                            {
                                loop3 = loop2+1;
                                if (loop3 >= N) loop3 = 0;
                                count = 0;
                                while (true)
                                {
                                    if (((thetas[loop3] > thetas[loop2]) && (thetas[loop3] < thetas[loop2] + Math.PI)) || (thetas[loop3] < thetas[loop2] - Math.PI)) count += 1;
                                    loop3 += 1;
                                    if (loop3 >= N) loop3 = 0;
                                    if (loop3 == loop2) break;
                                }
                                curmincount = count;
                                count = 0;
                                while (true)
                                {
                                    if (((thetas[loop3] < thetas[loop2]) && (thetas[loop3] > thetas[loop2] - Math.PI)) || (thetas[loop3] > thetas[loop2] + Math.PI)) count += 1;
                                    loop3 += 1;
                                    if (loop3 >= N) loop3 = 0;
                                    if (loop3 == loop2) break;
                                }
                                if (count < curmincount) curmincount = count;
                                if (curmincount < minmincount) minmincount = curmincount;
                            }
                            loop2+=1;
                        }
                        log[loop] = minmincount;
                    }
                    loop += 1;
                }

                outputwriter.WriteLine(String.Format("Case #{0}:", curtest + 1));
                loop = 0;
                while (loop < N)
                {
                    outputwriter.WriteLine(String.Format("{0}", log[loop]));
                    loop += 1;
                }

                curtest++;
            }

            inputreader.Close();
            outputwriter.Close();
        }
    }
}
