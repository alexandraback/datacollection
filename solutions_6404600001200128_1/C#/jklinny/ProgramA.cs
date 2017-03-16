using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Code_Jam_Round_1a___A
{
    class ProgramA
    {
        static void Main(string[] args)
        {
            string filename = "A-large.in";
            string filenameout = "A-large.out";
            string[] lines = System.IO.File.ReadAllLines(@"C:\users\jake.linenthal\documents\code jam\" + filename);
            string res = "";
            int t = Int32.Parse(lines[0]);

            for (int i = 0; i < t; i++)
            {
                int n = Int32.Parse(lines[2 * i + 1]);
                int[] arr = new int[n];
                String[] arrst = lines[2 * i + 2].Split(' ');
                for(int k = 0; k < n; k++) {
                    arr[k] = Int32.Parse(arrst[k]);
                }

                int y = 0;
                for (int k = 1; k < n; k++)
                {
                    if (arr[k] < arr[k - 1]) y += arr[k - 1] - arr[k];
                }

                int x = 0;
                int maxRate = 0;
                for (int k = 1; k < n; k++)
                {
                    if (arr[k] < arr[k - 1])
                    {
                        if (arr[k - 1] - arr[k] > maxRate)
                        {
                            maxRate = arr[k - 1] - arr[k];
                        }
                    }
                }

                int addedToNext;
                int numDisapp;
                for (int k = 0; k < n - 1; k++)
                {
                    //numDisapp = arr[k] - arr[k - 1];
                    if (arr[k] > maxRate) x += maxRate;
                    if (arr[k] <= maxRate) x += arr[k];
                    
                }


                res += "Case #" + (i + 1) + ": " + y + " " + x + "\n";
            }
            using (System.IO.StreamWriter file = new System.IO.StreamWriter(@"C:\users\jake.linenthal\documents\code jam\" + filenameout))
            {
                //write solution
                file.Write(res);
            }
        }
    }
}
