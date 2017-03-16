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
                    int N = int.Parse(str);

                    List<int> lstdata = new List<int>();
                    str = sr.ReadLine();
                    strs = str.Split(new char[] { ' ' });
                    for (int i = 0; i < N; i++) {
                        lstdata.Add(int.Parse(strs[i]));
                    }

                    Console.Write("Case #" + (ip + 1) + ": ");
                    sw.Write("Case #" + (ip + 1) + ": ");

                    string sres = prob.Solve(N, lstdata);
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

        public static string Solve(int N, List<int> lstdata) {
            int icnt = 0;
            int imaxdif = 0;

            for (int i = 0; i < N-1; i++) {
                int idif = lstdata[i] - lstdata[i + 1];
                imaxdif = Math.Max(idif, imaxdif);
                icnt += Math.Max(0, idif);
            }

            int icntcst = 0;
            for (int i = 0; i < N - 1; i++) {
                if (lstdata[i] < imaxdif)
                    icntcst += lstdata[i];
                else
                    icntcst += imaxdif;
            }

            return icnt.ToString() + " " + icntcst.ToString();
        }


    }
}
