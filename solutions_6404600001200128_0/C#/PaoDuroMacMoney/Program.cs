using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    class Program
    {
        static ISolver g_Solver = new Solver();
        static String Path
        {
            get
            {
                return @"D:\Rodrigo\Desenvolvimento\Google\";
            }
        }
        static void Main(string[] args)
        {
            StreamReader v_InputStream = new StreamReader(Path + "A-small-attempt0 (1).in");
            int v_NumberOfCases = Convert.ToInt32(v_InputStream.ReadLine());

            StreamWriter v_Writer = new StreamWriter(Path + "Output.txt");
            for (int i = 1; i <= v_NumberOfCases; i++)
            {
                v_Writer.WriteLine(String.Format("Case #{0}: {1}", i, g_Solver.Solve(v_InputStream)));
            }
            v_InputStream.Close();
            v_Writer.Flush();
            v_Writer.Close();
        }
    }
}
