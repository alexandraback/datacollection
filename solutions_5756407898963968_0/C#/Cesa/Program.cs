using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Magic_Trick
{
    class Program
    {
        static string filename = "input.txt";
        static void Main(string[] args)
        {
            string [] first=new string[4]{"asd","ads","afa","fdf"};
            string[] second = new string[4];
            int cases;
            string tmp;
            int firstRow;
            int SecondRow;
            StreamReader sr = new StreamReader(filename);
            StreamWriter sw = new StreamWriter("output.txt");
            cases = Convert.ToInt16(sr.ReadLine());
            string number="";
            for(int i=1;i<=cases;i++)
            {
                firstRow = Convert.ToInt16(sr.ReadLine())-1;
                first = new string[4] { sr.ReadLine(), sr.ReadLine(), sr.ReadLine(), sr.ReadLine() };
                first = first[firstRow].Split(' ');

                SecondRow = Convert.ToInt16(sr.ReadLine()) - 1;
                second = new string[4] { sr.ReadLine(), sr.ReadLine(), sr.ReadLine(), sr.ReadLine() };
                second = second[SecondRow].Split(' ');
                int cont = 0;
                for (int j = 0; j < 4; j++) 
                {
                    if (first.Contains(second[j]))
                    {
                        cont++;
                        number = second[j];
                    }
                }
                if (cont == 0)
                    sw.WriteLine("Case #" + i + ": Volunteer cheated!");
                else
                {
                    if (cont == 1)
                        sw.WriteLine("Case #" + i + ": " + number);
                    else
                        sw.WriteLine("Case #" + i + ": Bad magician!");
                }
            }
            sr.Close();
            sw.Close();
        }
    }
}
