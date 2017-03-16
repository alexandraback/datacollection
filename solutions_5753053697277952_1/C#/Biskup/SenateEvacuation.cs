using System;
using System.Collections.Generic;
using System.IO;
using System.Numerics;

namespace Qualification
{
    public class SenateEvacuation
    {
        [STAThread]
        public static void Main(string[] args)
        {
            var sr = new StreamReader("A-large.in");
            var sw = new StreamWriter("output.txt");
            var srd = new StreamDataRead(sr);

            int _case = Convert.ToInt32(srd.GetNext());

            for (int tc = 0; tc < _case; tc++)
            {
                int n = Convert.ToInt32(srd.GetNext());
                Int32[] a = new Int32[n];
                int ttt = 0;
                for (int i = 0; i < n; i++)
                {
                    a[i] = Convert.ToInt32(srd.GetNext());
                    ttt += a[i];
                }

                sw.Write(String.Format("Case #{0:G}:", tc + 1));

                bool f = true;
                while (f)
                {
                    f = false;
                    int ii = -1;
                    int jj = -1;
                    Int32 iCur = 0;
                    Int32 jCur = 0;
                    for (int i = 0; i < n; i++)
                    {
                        if (a[i] > iCur)
                        {
                            f = true;
                            iCur = a[i];
                            ii = i;
                            if (a[i]-1 > jCur && ttt!=3)
                            {
                                jCur = a[i]-1;
                                jj = i;
                            }
                            continue;
                        }
                        if (a[i] > jCur && ttt != 3)
                        {
                            f = true;
                            jCur = a[i];
                            jj = i;
                        }
                    }
                    if (f)
                    {
                        sw.Write(String.Format(" "));
                        if (ii >= 0)
                        {
                            sw.Write(String.Format("{0:G}", Convert.ToChar(65 + ii)));
                            a[ii]--;
                            ttt--;
                        }
                        if (jj >= 0)
                        {
                            sw.Write(String.Format("{0:G}", Convert.ToChar(65 + jj)));
                            a[jj]--;
                            ttt--;
                        }
                    }
                }

                sw.Write(String.Format("\n"));
            }

            sr.Close();
            sw.Close();
        }
    }
}