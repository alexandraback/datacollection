using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace test {
    public class Ctest {
        public void main(String FileName) {
            FileStream fs, fs2;
            StreamReader sr = null;
            StreamWriter sw = null;

            try {
                fs = new FileStream(FileName, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
                sr = new StreamReader(fs, Encoding.Default);
                fs2 = new FileStream("output.txt", FileMode.Create, FileAccess.ReadWrite, FileShare.Read);
                sw = new StreamWriter(fs2, Encoding.Default);

                //header
                string str = sr.ReadLine();

                int iSize = int.Parse(str);

                for (int ip = 0; ip < iSize; ip++) {
                    string[] strs;
                    str = sr.ReadLine();
                    strs = str.Split(new char[] { ' ' });
                    int B = int.Parse(strs[0]);
                    int N = int.Parse(strs[1]);

                    List<int> lstdata = new List<int>();
                    str = sr.ReadLine();
                    strs = str.Split(new char[] { ' ' });
                    for (int i = 0; i < B; i++) {
                        lstdata.Add(int.Parse(strs[i]));
                    }

                    Console.Write("Case #" + (ip + 1) + ": ");
                    sw.Write("Case #" + (ip + 1) + ": ");

                    string sres = prob.Solve(N, B, lstdata);
                    Console.WriteLine(sres);
                    sw.WriteLine(sres);
                }
            } catch (Exception ex) {
                Console.WriteLine(ex.Message);
            } finally {
                if (sr != null)
                    sr.Close();
                if (sw != null)
                    sw.Close();
            }

            return;
        }
    }

    public class prob {
        static long modul = 1000000007;

        public static string Solve(int N, int B, List<int> lstdata) {
            int icnt = 0;
            List<double> cq = new List<double>();

            if (N <= lstdata.Count || N == 1)
                return N.ToString();


            int imax = 0;
            for (int i = 0; i < lstdata.Count; i++) {
                cq.Add(lstdata[i]);
                if (lstdata[i] > imax)
                    imax = lstdata[i];
            }

            double ic = 0;
            double lt = 0;
            double ut = (double)imax * (double)N;
            while (true) {
                double ct = Math.Floor((lt + ut) / 2.0);

                ic = 0;
                for (int i = 0; i < B; i++) {
                    ic += Math.Floor(ct / cq[i]) + 1;
                }

                if (ut - lt < 100)
                    break;

                if (ic < (double)N - 0.5) {
                    lt = ct;
                } else {
                    ut = ct;
                }
            }

            ic = 0;
            for (int i = 0; i < B; i++) {
                double ib = Math.Floor(lt / cq[i]) + 1;
                ic += ib;
                cq[i] = cq[i] * ib;
            }
            while (ic < (double)N - 0.5) {
                double mind = 1.0e+16;

                for (int i = 0; i < B; i++) {
                    if (cq[i] < mind - 0.5) {
                        mind = cq[i];
                        icnt = i;
                    }
                }

                cq[icnt] += (double)lstdata[icnt];
                ic += 1.0;
            }

            return (icnt + 1).ToString();
        }


    }
}
