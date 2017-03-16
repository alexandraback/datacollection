using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            string fileName = "A-small-attempt1";

            StreamReader reader = new StreamReader(@"c:\users\alon\gcj\"+fileName+".in");
            StreamWriter writer = new StreamWriter(@"c:\users\alon\gcj\" + fileName + ".out");


            int T = int.Parse(reader.ReadLine());

            for (int i = 1; i <= T; i++)
            {
                bool[] flags = new bool[16];

                for(int j=0;j<16;j++) flags[j] = false;


                int row = int.Parse(reader.ReadLine());
                int[] items1 = readRow(reader, row);

                row = int.Parse(reader.ReadLine());
                int[] items2 = readRow(reader, row);

                //now we should find if there is only one common

                int common = -1;

                for (int j = 0; j < 4 && common != -2; j++)
                {
                    for (int k = 0; k < 4 && common != -2; k++)
                    {
                        if(items1[j]==items2[k]) {
                            if (common == -1)
                                common = items1[j];
                            else
                                common = -2;
                        }   
                    }
                }

                

                
                writer.Write("Case #{0}: ", i);

                if (common > 0)
                    writer.WriteLine(common);
                else if (common == -2)
                    writer.WriteLine("Bad magician!");
                else
                    writer.WriteLine("Volunteer cheated!");

                
            }

            writer.Close();
        }

        static int[] readRow(StreamReader reader, int row)
        {
            for (int j = 1; j < row; j++) reader.ReadLine();

            string[] values = reader.ReadLine().Split(' ');

            int[] items = new int[4];

            for (int j = 0; j < 4; j++)
                items[j] = int.Parse(values[j]);

            for (int j = row + 1; j <= 4; j++) reader.ReadLine();

            return items;
        }
    }
}
