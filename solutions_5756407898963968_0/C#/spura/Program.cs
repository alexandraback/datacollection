using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ_2014_Qualification
{
    class Program
    {
        static void Main(string[] args)
        {
            string sInFileName = "c:/in.txt";
            string sOutFileName = "c:/out.txt";

            string sIn = File.ReadAllText(sInFileName);
            StringReader oSR = new StringReader(sIn);

            StringBuilder oAnswer = new StringBuilder();

            // read number of cases
            int T = int.Parse(oSR.ReadLine());

            // case by case
            for (int i = 0; i < T; i++)
            {
                // read case
                int nFirstAnswer = int.Parse(oSR.ReadLine());
                int[,] aCase1 = ReadCase(oSR);
                int nSecondAnswer = int.Parse(oSR.ReadLine());
                int[,] aCase2 = ReadCase(oSR);

                // solve case
                int? nFound = null;
                bool bBadMag = false;
                for (int j = 0; j < 4; j++)
                {
                    int k = aCase1[nFirstAnswer - 1, j];
                    for (int l = 0; l < 4; l++)
                    {
                        int m = aCase2[nSecondAnswer - 1, l];
                        if (k == m)
                        {
                            if (nFound.HasValue)
                                bBadMag = true;
                            else nFound = k;
                        }
                    }
                }

                // write answer
                oAnswer.AppendFormat("Case #{0}: ", i + 1);
                if (bBadMag)
                    oAnswer.Append("Bad magician!");
                else if (nFound.HasValue)
                    oAnswer.Append(nFound.Value);
                else oAnswer.Append("Volunteer cheated!");

                oAnswer.AppendLine();
            }

            string sOut = oAnswer.ToString();
            File.WriteAllText(sOutFileName, sOut);
        }

        static int[,] ReadCase(StringReader oSR)
        {
            int[,] aCase = new int[4, 4];

            for (int j = 0; j < 4; j++)
            {
                string sLine = oSR.ReadLine();
                string[] aLine = sLine.Split(' ');
                for (int k = 0; k < 4; k++)
                {
                    string s = aLine[k];
                    int nK = int.Parse(s);
                    aCase[j, k] = nK;
                }
            }

            return aCase;
        }
    }
}
